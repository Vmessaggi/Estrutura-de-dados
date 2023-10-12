#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct NO{
    int num;
    struct NO *prox;
}NO;

void iniciarFila(NO **fila,int nume){
    NO *novo = (NO*)malloc(sizeof(NO));
    if(novo != NULL){
        novo->num = nume;
        novo->prox = NULL;
        if(*fila == NULL){
            *fila = novo;
        }else{
            NO *aux = *fila;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }else{
        printf("\nErro ao alocar memória!\n");
    }
}

NO* removerFila(NO **fila){
    NO *remover = NULL;
    if((*fila) != NULL){
        remover = *fila;
        *fila = remover->prox;
    }else{
        printf("\nFila vazia!...\n");
    }
    return remover;
}

void Imprime(NO *fila){
    printf("\n---------FILA-------\n");
    while(fila != NULL){
        printf("%d\t",fila->num);
        fila = fila->prox;
    }
    printf("\n---------------------\n");
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    NO *fila = NULL;
    NO *r = NULL;
    int op, nume;
    do{
        printf("\nEscolha uma opção: ");
        printf("\n1)Iniciar fila");
        printf("\n2)Retirar da fila");
        printf("\n3)Imprimir fila");
        printf("\n0)Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            fflush(stdin);
            printf("\nDigite um número: ");
            scanf("%d",&nume);
            fflush(stdin);
            iniciarFila(&fila,nume);
            break;
        case 2:
            r = removerFila(&fila);
            if(r != NULL){
                printf("\nElento removido com sucesso!\n");
                free(r);
            }else{
                printf("\nSem nó para ser removido!\n");
            }
            break;
        case 3:
            Imprime(fila);
            break;
        default:
            if(op != 0){
                printf("\nOpção Inválida!\n");
            }
        }
    }while(op != 0);
    while (fila != NULL) {
        NO* temp = fila;
        fila = fila->prox;
        free(temp);
    }
return 0;
}
