#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
#include <stdlib.h>

typedef struct{
  int chave;
}REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
  PONT inicio;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void exibirLista(LISTA* l);
PONT buscaSequencial(LISTA* l, int);
PONT buscaSequencialExc(LISTA* l, int, PONT* ant);
bool inserirElemLista(LISTA* l, REGISTRO reg);
bool excluirElemLista(LISTA* l, int ch);

void main(){
  LISTA l;
  REGISTRO reg;
  int op;
  PONT p;

  do{
  	  printf("\n\nEscolha uma opcao:\n");
	  printf("1- Inicializar lista\n");
	  printf("2- Mostrar tamanho da lista:\n");
	  printf("3- Exibir lista:\n");
	  printf("4- Busca sequencial:\n");
	  printf("5- Inserir elemento na lista:\n");
	  printf("6- Excluir elemento da lista:\n");
	  scanf("%i", &op);
	
	  switch (op){
	    case 1:
	      printf("Inicializando lista...\n");
	      inicializarLista(&l);
	      break;
	    case 2:
	      printf("Mostrando tamanho da lista...\n");
	      printf("\n\nTamanho da lista: %i", tamanho(&l));
	      break;
	    case 3:
	      printf("Ezibindo lista...\n");
	      exibirLista(&l);
	      break;
	    case 4:
	      printf("Bunscando sequencialmente...\n");
	      printf("Digite a chave: \n");
	      scanf("%i", &reg.chave);
	      p = buscaSequencial(&l, reg.chave);
	      printf("Chave: %i", p);
	      break;
	     case 5:
	       printf("Inserindo elemento...\n");
	      
	       printf("Informe a chave: ");
	       scanf("%i", &reg.chave);
	       inserirElemLista(&l, reg);
	       break;
	    case 6:
	      printf("Excluindo elemento...\n");
	      printf("Informe a chave: \n");
	      scanf("%i", &reg.chave);
	      excluirElemLista(&l, reg.chave);
	      break;
	  
	  default:
	   printf("\n\nOpção inválida!");
	  }
  }while(op!=0);
  
}

void inicializarLista(LISTA* l){
  l->inicio = NULL;
}

int tamanho(LISTA* l){
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
  
}

void exibirLista(LISTA* l){
  PONT end = l->inicio;
  printf("Lista: ");
  while(end != NULL){
    printf("%i ", end->reg.chave);
    end = end->prox;
  }
  printf("\n");
}

PONT buscaSequencial(LISTA* l, int ch){
  PONT pos = l->inicio;
  while (pos != NULL){
    if(pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
}

PONT buscaSequencialExc(LISTA* l, int ch, PONT* ant){
  *ant = NULL;
  PONT atual = l->inicio;
  while ((atual != NULL) && (atual->reg.chave<ch)) {
    *ant = atual;
    atual = atual->prox;
  }
  if ((atual != NULL) && (atual->reg.chave == ch)) return atual;
  return NULL;
}

bool inserirElemLista(LISTA* l, REGISTRO reg) {
	int ch = reg.chave;
	PONT ant, i;
	i = buscaSequencialExc(l,ch,&ant);
	if (i != NULL) return false;
	i = (PONT) malloc(sizeof(ELEMENTO));
	i->reg = reg;
	if (ant == NULL) {
		i->prox = l->inicio;
		l->inicio = i;
	} else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}


bool excluirElemLista(LISTA* l, int ch){
  PONT ant, i;
  i = buscaSequencialExc(l,ch,&ant);
  if (i == NULL) return false;
  if (ant == NULL) l->inicio = i->prox;
  else ant->prox = i->prox;
  free(i);
  return true;
}
