data MyList t = Nil | Const t (MyList t)

toList :: MyList t -> [t]
toList Nil = []
toList (Const a b) = [a] ++ (toList b)