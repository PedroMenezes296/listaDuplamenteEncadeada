struct musica{
char titulo[256];
char artista[256];
char letra[256];
int codigo;
int execucoes;
};
struct nodo{
struct nodo *prox, *anterior;
struct musica *informacao;
};
struct desc_LSE{
struct nodo *primeiro;
int tamanho;
};
struct nodo *crianodo();

struct desc_LSE *crialista();

struct desc_LSE *removelista(struct desc_LSE *minhaprimeiro, int posicao);
struct nodo *pesquisa(struct desc_LSE *minhaprimeiro);
struct desc_LSE	*insere(struct desc_LSE *minhaprimeiro, struct nodo *novoElemento);
////void insere(struct desc_LSE *minhaprimeiro, struct nodo *novo_elemento);
int tamanho(struct desc_LSE *minhaprimeiro);
void imprime(struct desc_LSE *minhaprimeiro);
