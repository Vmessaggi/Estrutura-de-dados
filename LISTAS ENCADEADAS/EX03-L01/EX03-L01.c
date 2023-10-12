#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int num;
    struct No *prox;
}NO;

int lernum(){
    int nume;
    printf("Digite um número: ");
    scanf("%d",&nume);
    return nume;
}

NO* Empilhar(NO *topo){
    NO *novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){
        printf("\nErro de alocação...\n");
        return NULL;
        exit(0);
    }else{
        novo->num = lernum();
        novo->prox = topo;
        return novo;
    }
}

NO* Desempilhar(NO **topo){
    if((*topo) != NULL){
        NO *remover = *topo;
        *topo = remover->prox;
        return remover;
    }else{
        printf("\nLista vazia!\n");
        return NULL;
    }
}

void Imprime(NO *topo){
    printf("---------PILHA-------\n");
    while(topo != NULL){
        printf("\t%d",topo->num);
        topo = topo->prox;
    }
    printf("\n---------------------");
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    NO *topo=NULL;
    NO *remover = NULL;
    int op;
    do{
        printf("\nEscolha uma opção: ");
        printf("\n1)Empilhar");
        printf("\n2)Desempilhar");
        printf("\n3)Imprimir pilha");
        printf("\n0)Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            topo = Empilhar(topo);
            break;
        case 2:
            remover = Desempilhar(&topo);
            if(remover != NULL){
                printf("\nElento removido com sucesso!\n");
            }else{
                printf("\nSem nó para ser removido!\n");
            }
            break;
        case 3:
            Imprime(topo);
            break;
        default:
            if(op != 0){
                printf("\nOpção Inválida!\n");
            }
        }
    }while(op != 0);
return 0;
}
