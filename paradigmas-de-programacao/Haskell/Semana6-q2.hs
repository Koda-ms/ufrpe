{-Crie um programa em Haskell que leia um arquivo "romano.txt" onde cada linha
 possui um número romano e deve gerar um arquivo "arabico.txt" que contém a 
 conversão de cada número romano do arquivo de entrada em um número arábico 
 (sistema numérico que utilizamos) ao longo de suas linhas.

Os romanos escreviam números usando as letras I, V, X, L, C, D, M.
 1  => I
10  => X
 7  => VII
Assuma que os números a serem convertidos vão de 0 até 3000. Pesquise na Internet 
as regras para as numerações romanas (por exemplo, em 
http://www.novaroma.org/via_romana/numbers.html). Abaixo segue algumas conversões:

O número 1990 é MCMXC: 
1000=M 900=CM 90=XC

2008 é escrito como MMVIII:
2000=MM 8=VIII

Dica: implemente uma função "numeral" que talvez (tipo Maybe) converta um numeral 
romano para uma String representando o número arábico.-}

main :: IO()
main = do putStrLn "Lendo o arquivo"
          x <- readFile "romano.txt"
          putStrLn x
          print (conversorRomanoArabico (lines x))
          writeFile "arabico.txt" (unlines (conversorRomanoArabico (lines x)))

--Correspondência de cada número base em romano com seu respectivo arábico.
numeral :: Char -> Int
numeral 'I' = 1
numeral 'V' = 5
numeral 'X' = 10
numeral 'L' = 50
numeral 'C' = 100
numeral 'D' = 500
numeral 'M' = 1000

--Recebe uma lista de caracteres e converte cada um em seu respectivo número arábico com auxílio da função acima.
converterRomano :: [Char] -> [Int]
converterRomano = map numeral

--Recebe a lista de inteiros e organiza os números para facilitar na soma feita na primeira função desse código.
tratarArabico :: [Int] -> [Int]
tratarArabico [] = []
tratarArabico [x] = [x]
tratarArabico (x:y:xs) = (if x < y then -x else x) : tratarArabico (y:xs)

--Primeiro, converte String por String em romano no seu correspondente número arábico na função converterRomano.
--Segundo, trata essa nova lista na função acima.
converterArabico :: String -> [Int]
converterArabico = tratarArabico . converterRomano

--De fato, trata a lista de String do arquivo.
--Retorna um lista de listas contendo os números que será somados na função abaixo e se tornar os arábicos correspondentes
tratarString ::[String] -> [[Int]]
tratarString [] = []
tratarString l = map converterArabico l

--Função principal do programa. Recebe a lista de String do arquivo.
--Quando esta lista pssar por todas as função acima, somarLista retona a soma dos números resultando nos arábicos
somarLista :: [String] -> [Int]
somarLista = map sum . tratarString

--Função principal do código
conversorRomanoArabico :: [String] -> [String]
conversorRomanoArabico l = map show (somarLista l)