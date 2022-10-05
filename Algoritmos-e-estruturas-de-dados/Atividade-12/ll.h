// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html

typedef struct reg celula;
struct reg {
   int     chave, v;
   celula *prox;
};

celula *insere (int, int, celula *);
celula *busca (int, celula *);
