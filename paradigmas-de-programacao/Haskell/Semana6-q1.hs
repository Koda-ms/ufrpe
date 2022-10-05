import System.IO
import Data.Char
import Data.List hiding (length)
{-Assumindo que os dados de vacina para o COVID-19 estejam em um arquivo 
"vacina.txt" e que as linhas representam dados das pessoas que participam 
do estudo e estão estruturadas da seguinte forma:

[id];[idade];[placebo];[reação]

onde [id] representa um inteiro identificando uma pessoa, [idade] informa a 
idade da pessoa, [placebo] caso seja "true" indica que a vacina tomada é um 
placebo, caso seja "false" indica que realmente foi a vacina sendo testada, 
e [reação] pode ser "nenhuma" caso não tenha tido reação, "leve" caso tenha 
tido algum sintoma leve, "forte" caso tenha sentido algum sintoma forte.

Crie um programa em Haskell deve ler este arquivo e imprimir na saída padrão 
as seguintes informações:

- A razão de pessoas que tomaram placebo;

- A razão de pessoas que não tomaram placebo;

- A razão de pessoas que tomaram a vacina (não foi placebo) não tiveram reação;

- Quantidade de pessoas acima de 50 anos que tomaram a vacina (não foi placebo) 
e tiveram algum tipo de reação;-}

main :: IO()
main = do putStrLn "Lendo o arquivo"
          x <- readFile "vacina.txt"
          print (razaoEhPlacebo (lines x))
          print (razaoNaoEhPlacebo (lines x))
          print (razaoVacinaSemReacao (lines x))
          print (qtdAcima50ComReacao (map substituirPontoVirgula(lines x)))

substituirPontoVirgula :: String -> [String]
substituirPontoVirgula st = words [if c == ';' then ' ' else c|c <- st]

ehPlacebo :: [[String]] -> Int
ehPlacebo [] = 0
ehPlacebo (l:ls) | l !! 2 == "True" = 1 + ehPlacebo ls
                 | otherwise = ehPlacebo ls

razaoEhPlacebo :: [String] -> Float
razaoEhPlacebo [] = 0
razaoEhPlacebo l = fromIntegral (ehPlacebo (map substituirPontoVirgula l)) / fromIntegral(length l)

naoEhPlacebo :: [[String]] -> Int
naoEhPlacebo [] = 0
naoEhPlacebo (l:ls) | l !! 2 == "False" = 1 + naoEhPlacebo ls
                    | otherwise = naoEhPlacebo ls

razaoNaoEhPlacebo :: [String] -> Float
razaoNaoEhPlacebo [] = 0
razaoNaoEhPlacebo l = fromIntegral (naoEhPlacebo (map substituirPontoVirgula l)) / fromIntegral(length l)

vacinaSemReacao :: [[String]] -> Int
vacinaSemReacao [] = 0
vacinaSemReacao (l:ls) | (l !! 2 == "False") && (l !! 3 == "nenhum") = 1 + vacinaSemReacao ls
                       | otherwise = vacinaSemReacao ls

razaoVacinaSemReacao :: [String] -> Float
razaoVacinaSemReacao [] = 0
razaoVacinaSemReacao l = fromIntegral (vacinaSemReacao (map substituirPontoVirgula l)) / fromIntegral(length l)

qtdAcima50ComReacao :: [[String]] -> Int
qtdAcima50ComReacao [] = 0
qtdAcima50ComReacao (l:ls) | (l !! 2 == "True") && (l !! 3 /= "nenhum") && (read(l !! 1) >= 50) = 1 + qtdAcima50ComReacao ls
                           | otherwise = qtdAcima50ComReacao ls