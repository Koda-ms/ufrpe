{- Questão 1:
Assumindo a estrutura de sinônimos abaixo:

type Nome = String
type Idade = Int
type Telefone = Int
type Pessoa = (Nome, Idade , Telefone)

Crie uma função que recebe quatro pessoas e 
deve retornar uma String contendo nome e telefone 
das pessoas cujas idades são maiores ou iguais a 
média das idades das quatro pessoas passadas como 
parâmetro. -}

type Nome = String
type Idade = Int
type Telefone = Int
type Pessoa = (Nome, Idade, Telefone)

nome :: Pessoa -> Nome
nome (n, i, t) = n

idade :: Pessoa -> Idade
idade (n, i, t) = i

telefone :: Pessoa -> Telefone
telefone (n, i, t) = t

mediaIdade :: Pessoa -> Pessoa -> Pessoa -> Pessoa -> Float
mediaIdade x y w z = fromIntegral(idade x + idade y + idade w + idade z) / 4

mostrarDados :: Pessoa -> String
mostrarDados (n, i, t) = n ++ " - " ++ show t

pessoaMaiorIdade :: Pessoa -> Float -> String
pessoaMaiorIdade x media | fromIntegral(idade x) >= media = mostrarDados x ++ " | "
                         | otherwise = " "

conferirPessoas :: Pessoa -> Pessoa -> Pessoa -> Pessoa -> String                       
conferirPessoas x y w z = (pessoaMaiorIdade x (mediaIdade x y w z)) ++ (pessoaMaiorIdade y (mediaIdade x y w z)) ++ (pessoaMaiorIdade w (mediaIdade x y w z)) ++ (pessoaMaiorIdade z (mediaIdade x y w z))