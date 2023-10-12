#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node{
    float num;
    struct Node *prox;
};
typedef struct Node node;
typedef node *LISTA;

LISTA* criarLista(){
    LISTA *inicio = (LISTA*) malloc (sizeof(LISTA));
    if(inicio != NULL){
        *inicio=NULL;
    }else{
        printf("Erro de alocação...\n");
        exit(0);
    }
    return inicio;
}

void insereInicio(LISTA* lista){
    node *novo = (node*) malloc (sizeof(node));
    if(novo == NULL){
        printf("Erro de alocação...\n");
        exit(0);
    }
    printf("Informe o valor do novo elemento:\n");
    scanf("%f",&novo->num);
    novo->prox=(*lista);
    *lista = novo;
}

void insereFinal(LISTA* lista){
    node *novo = (node*) malloc (sizeof(node));
    if(novo == NULL){
        printf("Erro de alocação...\n");
        exit(0);
    }
    printf("Informe o valor do novo elemento:\n");
    scanf("%f",&novo->num);
    novo->prox = NULL;
    if((*lista) == NULL){
        *lista = novo;
    }else{
        node *tmp;
        tmp = (*lista);
        while (tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void exibe(LISTA* lista){
    if((*lista) == NULL){
        printf("LISTA VAZIA...\n");
    }else{
        node *tmp;
        tmp = (*lista);
        while(tmp != NULL){
            printf("%.2f\t", tmp->num);
            tmp = tmp->prox;
        }
    }
    printf("\n");
}

LISTA* removerNPrimeirosNos(LISTA* lista, int n) {
    node *atual = *lista;
    int contador = 0;
    while (atual != NULL && contador < n - 1) {
        node *temp = atual;
        atual = atual->prox;
        free(temp);
        contador++;
    }
    if (atual != NULL) {
        *lista = atual->prox;
        free(atual);
    }
    return lista;
}

void main(){
    setlocale(LC_ALL,"Portuguese");
    LISTA *lista = criarLista();
    int op,n;
    do{
        printf("1)Inserir no início\n");
        printf("2)Inserir no final\n");
        printf("3)Exibir lista\n");
        printf("4)Retirar n's primeiros nós\n");
        printf("0)Sair\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                system("cls");
                insereInicio(lista);
                system("cls");
                break;
            case 2:
                system("cls");
                insereFinal(lista);
                system("cls");
                break;
            case 3:
                system("cls");
                exibe(lista);
                break;
            case 4:
                system("cls");
                printf("Digite a quantidade de nós a ser retirada: ");
                scanf("%d",&n);
                removerNPrimeirosNos(lista,n);
                break;
            default:
                system("cls");
                if(op != 0){
                    printf("Opção inválida!\n");
                }
                break;
        }
    }while(op != 0);
}
