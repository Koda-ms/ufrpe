{- Questão 2: 
Crie uma função "somaFats :: Int -> Int" 
que recebe um inteiro e deve retornar a soma 
dos fatoriais de 0 até n. -}

fat :: Int -> Int
fat 0 = 1
fat 1 = 1 --Redundante

fatorial :: Int -> Int
fatorial 0 = fat 0
fatorial 1 = fat 1 --Redundante
fatorial n = n * fatorial (n-1)

somaFat :: Int -> Int
somaFat 0 = fatorial 0
somaFat 1 = fatorial 1 + fatorial 0
somaFat m = fatorial m + somaFat (m-1)