{-
No mundo das artes marciais mistas (ou MMA) existe uma discussão de quem 
deve ser o melhor lutador(a) de todos considerando todas as classes de peso. 
Assim, vamos criar um ranking que deve ser calculado de acordo com o cartel 
de cada um deles. Cada cartel contém a quantidade de vitórias, a quantidade 
de derrotas, a quantidade de empates e a quantidade de lutas sem resultado. 
As vitórias ainda podem ser por decisão dos juizes ou por nocaute/submissão. 
Considerando este elementos, vamos criar um ranking de acordo com as regras 
de pontuação abaixo:

- Vitória por noucate/submissão = 5
- Vitória por decisão = 3
- Derrota = -2
- Sem resultado = 1

Desta forma, crie um programa em Haskell que recebe uma lista tuplas de cinco 
elementos (uma string e quatro inteiros) representando respectivamente: Nome do 
lutador, Vitorias Nocaute/Submissao, Vitorias Decisao, Derrotas, Sem Resultado. 
Cada tupla tupla representa um lutador. Seu programa deve calcular o ranking de 
cada lutador e retornar uma String com o nome do lutador de maior pontuação. 

OBS: Você pode consultar o site https://www.sherdog.com/ para testar seu programa 
com os carteis de alguns lutadores reais. -}


type LutadorPontos = (String, Int, Int, Int, Int)
type LutadorTotalPontos = (String, Int)

converterTupla :: LutadorPontos -> LutadorTotalPontos --converte elemento por elemento da lista LutadorPontos
converterTupla (nome, vn, vd, d, sn) = (nome, vn+vd+d+sn)

converterListaTupla :: [LutadorPontos] -> [LutadorTotalPontos] --retorna a lista de tuplas já convertidas para o tipo LutadorTotalPontos
converterListaTupla = map converterTupla

snds :: [LutadorTotalPontos] -> [Int]
snds = map snd

retornaMax :: [(String, Int)] -> Int
retornaMax [] = 0
retornaMax l = maximum (snds l)

conferirLutador :: [LutadorTotalPontos] -> [LutadorTotalPontos]
conferirLutador (l:ls) | snd l == (retornaMax (l:ls)) = [l]
                       | otherwise = conferirLutador ls

stringLutador :: [(String, Int)] -> String
stringLutador (l:ls) = fst l

lutadorMaiorPontuacao :: [LutadorPontos] -> String
lutadorMaiorPontuacao (l:ls) = stringLutador (conferirLutador (converterListaTupla (l:ls)))

-- PARA TESTE: lutadorMaiorPontuacao [("A", 5, 3, -2, 1), ("B", 10, 0, 0, 2), ("C", 0, 6, -4, 0)]