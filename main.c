#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

int main(void) {
  int op, posicao;
  op=0;
	struct nodo *novoNodo;
	struct desc_LSE *novaprimeiro;
  
  while(1){
	 printf("\n");
	 printf("\n =======================================================\n" );
    setbuf(stdin,NULL);
  printf("1.Cria primeiro\n2.Insere\n3.Remove\n4.Consulta\n5.Imprime\n6.Sair\nEscolha uma opcao:");
    setbuf(stdin,NULL);
  scanf("%i", &op);
  setbuf(stdin,NULL);
    printf("\n =======================================================\n" );
  switch(op){
    case 1:
    novaprimeiro=crialista();
  
    break;
    case 2:
      novoNodo=crianodo();
      novaprimeiro=insere(novaprimeiro, novoNodo );
		break;
	 
    break;
    case 3:
    printf("\n =======================================================\n" );
    printf("digite a posicao da remocao\n");
	setbuf(stdin,NULL);
	scanf("%d",&posicao);
	printf("\n =======================================================\n" );
    removelista(novaprimeiro, posicao);
    break;

    case 4:
    imprime(novaprimeiro);
    pesquisa(novaprimeiro);
    break;

    case 5:
    imprime(novaprimeiro);

    break;

    case 6:
    return 0;
    break;
    
    default:
    printf("Opção Inválida!");
  }}
  return 0;
}
