// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html

#include "ll.h"
#include <stdlib.h>

// Esta função insere uma nova celula
// no começo de uma lista encadeada. A nova celula
// tem conteudo x e seu prox vale p (que pode
// NULL.)
// Devolve a célula recem criada.

celula *
insere (int ch, int v, celula *p)
{
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->chave = ch;
   nova->v = v;
   nova->prox = p;
   return nova;
}


// Esta função recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endereço de uma celula cuja chave seja x.
// Se tal celula não existe, devolve NULL.

celula *
busca (int x, celula *le)
{
   celula *p;
   p = le;
   while (p != NULL && p->chave != x)
      p = p->prox;
   return p;
}
