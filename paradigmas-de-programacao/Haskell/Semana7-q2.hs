import Data.List
import Data.Ord
{-A APAC (Agência Pernambucana de Águas e Clima) deseja fazer uma análise
 sobre dados das suas Plataformas de Coleta de Dados (PCD). Cada plataforma 
 possui sensores que detectam diversas variáveis do ambiente e clima como 
 precipitação de chuva (mm), velocidade do vento (km/h), dentre outros. Estes 
 dados são registrados em observações onde cada observação possui os seguintes 
 campos (com seus respectivos tipos): id da PCD (inteiro), dia (inteiro), mês 
 (inteiro), ano (inteiro), precipitação de chuva (real), e velocidade do vento 
 (real).

Assim, crie um programa em Haskell com a seguinte função:

- diaMaisChuvosoAno: recebe como parâmetros uma lista de observações, e um inteiro 
relacionado a um ano de busca. Sua função deve retornar uma String no formato 
"DD/MM/AAAA" com o dia de maior precipitação para o ano passado como parâmetro. 
Como podem existir observações de diferentes PCDs para um mesmo dia, considere a 
observação da PCD com maior valor de precipitação. -}


data Obs = Obs { idPCD :: Int
, dia :: Int
, mes :: Int
, ano :: Int
, pchuva :: Float
, velocidadeVento :: Float
} deriving (Show)
type Obs2 = ((Int, Int, Int), Float)

filtrarPorAno :: [Obs] -> Int -> [Obs]
filtrarPorAno l x = filter (\(Obs _ _ _ a _ _) -> a == x) l

converterTupla :: Obs -> Obs2
converterTupla obs = ((dia obs, mes obs, ano obs), pchuva obs) --Necessário comparar as datas

converterListaTupla :: [Obs] -> [Obs2]
converterListaTupla = map converterTupla

listaData :: [Obs] -> [(Int,Int,Int)]
listaData l = map fst (converterListaTupla l)

removerDatasRepetidas :: [Obs] -> [(Int,Int,Int)]
removerDatasRepetidas l = nub (listaData l)

funcaoComparaData :: [Obs] -> [[Obs2]]
funcaoComparaData lo = map (\x -> filter (\y -> x == fst y)  (converterListaTupla lo)) (removerDatasRepetidas lo)

maxPrecipitacaoMesmaData :: [Obs2] -> Obs2
maxPrecipitacaoMesmaData (l:ls) = (fst l, maximum (map snd (l:ls)))

maiorPrecipitação :: [[Obs2]] -> [Obs2]
maiorPrecipitação = map maxPrecipitacaoMesmaData

formatarData :: (Int,Int,Int) -> String
formatarData (a,b,c) = show a++"/"++show b++"/"++show c

--Teste:
--[Obs 1 3 2 2020 5.2 9.2, Obs 2 3 2 2022 8.2 5.6, Obs 3 3 2 2020 6.2 7.2, Obs 4 10 3 2021 10.0 2.3] 2020

diaMaisChuvosoAno :: [Obs] -> Int -> String
diaMaisChuvosoAno (l:ls) ano = formatarData (fst (maximumBy (comparing snd) (maiorPrecipitação (funcaoComparaData (filtrarPorAno (l:ls) ano)))))