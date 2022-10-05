{-A APAC (Agência Pernambucana de Águas e Clima) deseja fazer uma análise
sobre dados das suas Plataformas de Coleta de Dados (PCD). Cada plataforma
possui sensores que detectam diversas variáveis do ambiente e clima como
precipitação de chuva (mm), velocidade do vento (km/h), dentre outros. 
Estes dados são registrados em observações onde cada observação possui os 
seguintes campos (com seus respectivos tipos): id da PCD (inteiro), local 
(String), dia (inteiro), mês (inteiro), ano (inteiro), precipitação de chuva 
(real), e velocidade do vento (real).

Assim, crie um programa em Haskell com a seguinte função:

- localMaisVentos: recebe como parâmetros uma lista de observações, e um 
inteiro relacionado a um ano de busca. Sua função deve retornar uma String 
relacionada ao nome do local da PCD cuja soma das velocidade de ventos para 
o ano passado como parâmetro é a maior dentre todas as PCDs. -}


import Data.List
import Data.Ord

data Observacao = Observacao { idPCD :: Int
, local :: String
, dia :: Int
, mes :: Int
, ano :: Int
, pchuva :: Float
, velocidadeVento :: Float
} deriving (Show)
type Obs2 = (String, Float)

filtrarPorAno :: [Observacao] -> Int -> [Observacao]
filtrarPorAno l x = filter (\(Observacao _ _ _ _ a _ _) -> a == x) l

converterTupla :: Observacao -> Obs2
converterTupla obs = (local obs, velocidadeVento obs)

converterListaTupla :: [Observacao] -> [Obs2]
converterListaTupla = map converterTupla

filtrarCidades :: [(String, Float)] -> [String]
filtrarCidades = map fst

removerCidadesRepetidas :: [Obs2] -> [String]
removerCidadesRepetidas l = nub (filtrarCidades l)

funcaoCompara :: [Obs2] -> [[Obs2]]
funcaoCompara lo = (map (\x -> (filter (\y -> x == (fst y))  lo)) (removerCidadesRepetidas lo))

somarVelocidade :: [(String,Float)] -> (String,Float)
somarVelocidade (l:ls) = (fst l, foldl (+) 0 (map (snd) (l:ls)))

somarVelocidadeTotal :: [[(String,Float)]] -> [(String,Float)]
somarVelocidadeTotal [] = []
somarVelocidadeTotal (l:ls) = [somarVelocidade l] ++ somarVelocidadeTotal ls

--FUNÇÃO PRINCIPAL DO PROGRMAMA
--UNS TESTES:
--localMaisVentos [Observacao 123 "Recife" 1 1 2021 1.0 1.5, Observacao 234 "Recife" 2 2 2021 1.5 2.0, Observacao 345 "Olinda" 3 3 2020 2.0 2.5] 2021
--localMaisVentos [Observacao 123 "Olinda" 1 1 2022 1.0 1.5, Observacao 234 "Jaboatao" 2 2 2022 1.5 3.0, Observacao 345 "Olinda" 3 3 2020 2.0 2.5] 2022

localMaisVentos :: [Observacao] -> Int-> String
localMaisVentos (l:ls) ano = fst (maximumBy (comparing snd) (somarVelocidadeTotal (funcaoCompara (converterListaTupla (filtrarPorAno (l:ls) ano)))))