{- Uma função que exiber a expressão dada como entrada -}

data Expr = Lit Int | Add Expr Expr | Sub Expr Expr

aval :: Expr -> Int
aval (Lit n) = n

showExpr :: Expr -> String
showExpr (Lit n) = show (aval(Lit n))
showExpr (Add (Lit a) (Lit b)) = showExpr (Lit a) ++ "+" ++ showExpr (Lit b)
showExpr (Sub (Lit a) (Lit b)) = showExpr (Lit a) ++ "-" ++ showExpr (Lit b)
