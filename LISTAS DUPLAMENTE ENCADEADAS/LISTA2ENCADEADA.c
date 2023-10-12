#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
}No;

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memória!\n");
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;
    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista)
                (*lista)->anterior = NULL;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
}

No* ultimo(No **lista){
    No *aux = *lista;
    while(aux->proximo)
        aux = aux->proximo;
    return aux;
}

void imprimir(No *no){
    printf("\nLista: ");
    while(no){
        printf(" %d |", no->valor);
        no = no->proximo;
    }
    printf("\n");
}

void imprimirContrario(No *no){
    printf("\nLista: ");
    while(no){
        printf(" %d |", no->valor);
        no = no->anterior;
    }
    printf("\n");
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int opcao, valor, anterior;
    No *removido, *lista = NULL;
    do{
        printf("1)Inserir ordenadamente\n");
        printf("2)Remove por escolha do usuário\n");
        printf("3)Exibir lista crescente\n");
        printf("4)Exibir lista descrescente\n");
        printf("0)Sair\n");
        scanf("%d",&opcao);
        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 2:
            imprimir(lista);
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 3:
            imprimir(lista);
            break;
        case 4:
            imprimirContrario(ultimo(&lista));
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);
     while (lista) {
    No *temp = lista;
    lista = lista->proximo;
    free(temp);
    }
    return 0;
}
