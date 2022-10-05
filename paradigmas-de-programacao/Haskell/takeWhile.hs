twhile :: (a->Bool) -> [a] -> [a]
twhile f [] = []
twhile f (a:as) | f a == False = []
				| otherwise = a:(twhile f as)
				
--Expressão lambda: (\x -> mod x 10 ==0) [lista]