#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct desc_LSE *crialista() {
  struct desc_LSE *novolista=
      (struct desc_LSE *)malloc(sizeof(struct desc_LSE));
  novolista->tamanho = 0;
  novolista->primeiro= NULL;
  return novolista;
}
struct nodo *crianodo() {
  struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
  novoElemento->informacao = NULL;
  novoElemento->prox = NULL;
  novoElemento->anterior=NULL;
  struct musica *novaMusica = (struct musica *)malloc(sizeof(struct musica));
  

  char titulo[256], artista[256], letra[256];
  int codigo = 0;
  printf("\n =======================================================\n" );
  printf("Nome da musica:");
  setbuf(stdin, NULL);
  scanf("%s", titulo);
  printf("Nome da artista:");
  setbuf(stdin, NULL);
  scanf("%s", artista);
  printf("Nome da letra:");
  setbuf(stdin, NULL);
  scanf("%s", letra);
  printf("digite codigo:");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  printf("\n =======================================================\n" );
  ////////inserir dados no novo
  strcpy(novaMusica->titulo, titulo);
  strcpy(novaMusica->artista, artista);
  strcpy(novaMusica->letra, letra);
  novaMusica->codigo = codigo;
  novoElemento->prox = NULL;
  novoElemento->anterior=NULL;
  novoElemento->informacao = novaMusica;

  return novoElemento;
}
///////////////////inserir no incio
struct desc_LSE *insere(struct desc_LSE *minhaprimeiro, struct nodo *novoElemento){
	struct nodo *aux = minhaprimeiro->primeiro;
	int posicao=0,listapos=0;
	printf("informe a posicao a ser alocado: ");
	scanf("%i", &posicao);
	if(minhaprimeiro->primeiro==NULL){
		minhaprimeiro->primeiro=novoElemento;
		minhaprimeiro->tamanho++;
		printf("LISTA VAZIA inserindo na primeira posicao:");
		}else{////inserindo inicio
			if(posicao==0){
				novoElemento->prox=aux;
				aux->anterior=novoElemento;
				minhaprimeiro->primeiro=novoElemento;
				minhaprimeiro->tamanho++;
				printf("inserido na primeira posicao");
				
				}else{
				if(posicao>=minhaprimeiro->tamanho){
				while(aux->prox!=NULL){
					aux->anterior=aux;
					aux=aux->prox;
					}
					aux->prox=novoElemento;
					novoElemento->anterior=aux;
					minhaprimeiro->tamanho++;
					printf("inserindo no fim");
			}else{
				while(aux->prox!=NULL){
					aux->anterior=aux;
					aux=aux->prox;
					listapos++;
					if(listapos==posicao){
					novoElemento->prox=aux;
					novoElemento->anterior=aux->anterior;
					aux->anterior->prox=novoElemento;
					aux->anterior=novoElemento;
					minhaprimeiro->tamanho++;	
					}
					}
			}	
			}
			}return minhaprimeiro;
	}

//////void insere(struct desc_LSE *minhaprimeiro, struct nodo *novoElemento) {
//////  int posicao = 0;
 ////// setbuf(stdin,NULL);
//////  printf("insira a posicao:");
//////	scanf("%i", &posicao);

 ////// if ((minhaprimeiro->primeiro== NULL) ||
   //////   (posicao == 0)) { // insercao no inicio da primeiro
  //////  novoElemento->prox = minhaprimeiro->primeiro;
 //////   novoElemento->anterior= NULL;
  //////  minhaprimeiro->primeiro=novoElemento;
 //////   novoElemento->prox->anterior=novoElemento;
 //////   minhaprimeiro->tamanho++;
 //////   return;
 ////// } else {
 //////   struct nodo *aux = minhaprimeiro->primeiro;
 //////   int primeiroPos = 0;
 //////   if (minhaprimeiro->tamanho < posicao) {
 //////     while (aux->prox != NULL) {
 //////       aux = aux->prox;
 //////     }
 //////     aux->prox=novoElemento;
//////      minhaprimeiro->tamanho++;
//////      return;
//////    } else { // posicao valida na primeiroinsere na posicao
//////      struct nodo *anterior;
//////      while (aux!= NULL) {
//////        anterior = aux;
//////        aux = aux->prox;
//////        primeiroPos++;
//////        if (primeiroPos == posicao) {
//////         novoElemento->prox = aux;
 //////         anterior->prox = novoElemento;
 //////         minhaprimeiro->tamanho++;
//////          return;
 //////       }}}}}
struct desc_LSE *removelista(struct desc_LSE *minhaprimeiro, int posicao){
	struct nodo *aux = minhaprimeiro->primeiro;
 if(minhaprimeiro->primeiro==NULL){
	 printf("LISTA VAZIA");
	 return 0;
	 }
  if((minhaprimeiro->tamanho==0) || (posicao > minhaprimeiro->tamanho)){
    printf("A posicao não é valida");
    printf ("\n");
  }
  else{
    if(posicao==0){
			minhaprimeiro->primeiro=aux->prox;
			minhaprimeiro->tamanho--;
			printf("\nremovido do inicio da lista\n");
		}else{ 
			if(posicao==minhaprimeiro->tamanho-1){
				while(aux->prox!=NULL){
				aux->anterior=aux;
				aux=aux->prox;
				}
				printf("auxprox é NULL");
				aux=aux->anterior;
				aux->prox=NULL;
				minhaprimeiro->tamanho--;
				printf("\nremovido no fim da lista\n");
			}else{
			int primeiroPos=0;///criar um contador 
			
			while(aux->prox != NULL){
				aux->anterior = aux;
				aux = aux->prox;
				primeiroPos++;
				if(primeiroPos == posicao){
					aux->anterior->prox = aux->prox;///o apont do anterior passa para o apont do aux ou seja pula uma casa
					aux->prox->anterior=aux->anterior;
					minhaprimeiro->tamanho--;
					printf("\nremovido no meio da lista\n");
			
				}}}}}return minhaprimeiro;}
struct nodo *pesquisa(struct desc_LSE *minhaprimeiro){
  
  int codigo;
  printf("informe o codigo da musica:");
  setbuf(stdin, NULL);
  scanf("%i", &codigo);
  struct nodo *aux = minhaprimeiro->primeiro;
  while(aux!=NULL){
  
    if(aux->informacao->codigo==codigo){
		printf("\n =======================================================\n" );
     printf("\n titulo:%s\n Artista:%s \n Letra:%s\n codigo: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
     printf("\n =======================================================\n" );
      return 0;
    }
    aux=aux->prox;
  }return 0;}
void imprime(struct desc_LSE *minhaprimeiro){
  struct nodo *aux = minhaprimeiro->primeiro;
  printf(" =======================================================\n" );
  while(aux!=NULL){
	  printf(" elemento --------------\n" );
     printf("\n titulo:%s\n Artista:%s \n Letra:%s\n codigo: %i \n", aux->informacao->titulo, aux->informacao->artista,aux->informacao->letra,aux->informacao->codigo);
    aux=aux->prox;
    
}
  printf(" =======================================================\n" );
}
