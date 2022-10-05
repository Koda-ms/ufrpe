// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html

#include "ll.h"
#include <stdlib.h>

// Esta fun��o insere uma nova celula
// no come�o de uma lista encadeada. A nova celula
// tem conteudo x e seu prox vale p (que pode
// NULL.)
// Devolve a c�lula recem criada.

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


// Esta fun��o recebe um inteiro x e uma
// lista encadeada le de inteiros e devolve
// o endere�o de uma celula cuja chave seja x.
// Se tal celula n�o existe, devolve NULL.

celula *
busca (int x, celula *le)
{
   celula *p;
   p = le;
   while (p != NULL && p->chave != x)
      p = p->prox;
   return p;
}
