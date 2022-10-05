typedef struct spq {
    int *v;
    int N; // Espa�o total dispon�vel
    int m; // �ltima posi��o ocupada
} *pq;

static void constroiHeap (int m, int v[]);
static void peneira (int m, int v[]);
void heapsort (int n, int v[]);

static void corrigeSubindo (int m, int v[]);
pq criapq(int N);
void insere(pq p, int k);
int extraimax(pq p);
void imprimepq(pq p);
