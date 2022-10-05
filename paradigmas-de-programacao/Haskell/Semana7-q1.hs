{-Utilizando a linguagem funcional Haskell, defina uma função bag 
que recebe uma lista de elementos e retorna uma lista de pares, onde 
o primeiro elemento de cada par é um elemento da lista original e o 
segundo é o número de ocorrências deste elemento. Nesta segunda lista, 
cada elemento só ocorre uma vez. Por exemplo, bag [a,b,a,c,a,b] = [(a,3),(b,2),(c,1)]. -}

contaOcorrencia :: (Eq t) => [t] -> [(t,Int)]
contaOcorrencia [] = []
contaOcorrencia (l:ls) = (l, length (filter (==l) (l:ls))) : contaOcorrencia (filter (/=l) (l:ls))

bag :: (Eq t) => [t] -> [(t,Int)]
bag = contaOcorrencia