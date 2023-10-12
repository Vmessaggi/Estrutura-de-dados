#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

struct Node{
    int num;
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
    scanf("%d",&novo->num);
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
    scanf("%d",&novo->num);
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

void insereOrdenado(LISTA* lista) {
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro de alocação...\n");
        exit(0);
    }
    printf("Informe o valor do novo elemento\n");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    //Até aqui igual aos outros "insere"
    if((*lista) == NULL || novo->num <= (*lista)->num){
        //NULL ou menor ou igual ao valor de num no primeiro nó
        novo->prox = (*lista);
        *lista = novo;
    }else{
        node *tmp = *lista;
        /*enquanto o próximo nó de tmp não for nulo (ou seja, enquanto não chegarmos ao final da lista)
         e o valor num no próximo nó for menor que o valor num no novo nó */
        while (tmp->prox != NULL && tmp->prox->num < novo->num) {
            tmp = tmp->prox;
        }
        novo->prox = tmp->prox;
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
            printf("%5d", tmp->num);
            tmp = tmp->prox;
        }
    }
    printf("\n");
}

void libera(LISTA* lista){
    if((*lista) == NULL){
        printf("LISTA VAZIA...\n");
    }else{
        node *tmp;
        while((*lista) != NULL){
            tmp = *lista;
            *lista = (*lista)->prox;
            free(tmp);
        }
    }
}

int removeInicio(LISTA* lista){
    if((*lista) != NULL){
        node *proxNode, *tmp;
        tmp = *lista;
        *lista = tmp->prox;
        free(tmp);
        printf("Elemento removido com sucesso...\n");
    }else{
        printf("Lista já esta vazia...\n");
    }
}

int removeFinal(LISTA* lista){
    node *antNode, *tmp;
    tmp = *lista;
    if((*lista) != NULL && tmp->prox == NULL){
        *lista = NULL;
        free(tmp);
        printf("Elemento removido com sucesso...\n");
    }else if((*lista) != NULL){
        while(tmp->prox != NULL){
            antNode = tmp;
            tmp = tmp->prox;
        }
        antNode->prox = NULL;
        free(tmp);
        printf("Elemento removido com sucesso...\n");
    }else{
        printf("Lista ja esta vazia...\n");
    }
}

void removeEscolhido(LISTA* lista) {
    exibe(lista);
    int escolhido;
    printf("Informe o valor da lista que será removido:\n");
    scanf("%d", &escolhido);
    node *anterior = NULL;
    node *tmp = *lista;
    while(tmp != NULL && tmp->num != escolhido){
        //Anterior é atualizado para apontar para tmp, e tmp é movido para o próximo nó na lista (tmp->prox).
        anterior = tmp;
        tmp = tmp->prox;
    }
    //Se tmp for NULL, é o elemento que era procurado pois não recebeu ->prox, por isso é nulo.
    if(tmp != NULL){
        if(anterior != NULL){
            /*O elemento a ser removido não é o primeiro nó da lista. Nesse caso, antNode->prox é atualizado
            para apontar para o nó seguinte a tmp o que faz com que tmp seja removido da lista.*/
            anterior->prox = tmp->prox;
        }else{
            /* Se anterior for NULL, o elemento a ser removido é o primeiro nó da lista.
            O ponteiro de início da lista (*lista) é atualizado para apontar para o próximo nó
            após tmp, também removendo tmp da lista.*/
            *lista = tmp->prox;
        }
        free(tmp);
        printf("Elemento removido\n");
    }else{
        printf("Elemento não localizado na lista\n");
    }
}
void removeIgual(LISTA* lista){
    //Exclui um elemento igual da lista, exemplo, se estiver 1 2 2 3 3, vai virar 1 2 3.
    node *atual = *lista;
    node *anterior = NULL;
    int troca;
    if (*lista == NULL) {
        printf("LISTA VAZIA\n");
        exit(0);
        //Igual a função exibe
    }
    do{
        troca = 0;
        while(atual != NULL && atual->prox != NULL){
        if(atual->num == atual->prox->num){
            if(anterior == NULL){
                *lista = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }
            free(atual);
            atual = anterior;
            troca = 1;
        }
        anterior = atual;
        atual = atual->prox;
        }
    }while(troca != 0);
}

void Ordena(LISTA* lista){
    int change; //Flag para identificar se houve uma troca de elemento
    if (*lista == NULL) {
        printf("LISTA VAZIA\n");
        exit(0);
        //Igual a função exibe
    }
    do{
        change = 0;
        node *atual = *lista;
        while (atual->prox != NULL){
            if(atual->num > atual->prox->num){
                //Comparação entre o valor armazenado no nó atual (atual->num) e o valor armazenado no próximo nó (atual->prox->num).
                int temp = atual->num;
                //temporario recebe o valor do nó atual e logo após o nó atual recebe o valor do próximo nó.
                atual->num = atual->prox->num;
                atual->prox->num = temp;
                //O valor do próximo nó vai ser igual ao temporário acontecendo o swap(troca).
                change = 1;
                //Flag que demonstra que houve troca.
            }
            atual = atual->prox;
        }
    }while(change == 1);
    /*Vai executar a troca até o change ser igual a zero, pois depois de acontecer uma troca, quer garantir que está
    tudo certo pois é feita uma troca de cada vez.*/
    printf("Lista ordenada\n");
}

void main(){
    setlocale(LC_ALL,"Portuguese");
    LISTA *lista = criarLista();
    int op;
    do{
        printf("1)Inserir no início\n");
        printf("2)Inserir no final\n");
        printf("3)Inserir ordenadamente\n");
        printf("4)Exibir lista\n");
        printf("5)Libera lista\n");
        printf("6)Remove início\n");
        printf("7)Remove fim\n");
        printf("8)Remove por escolha do usuário\n");
        printf("9)Ordena a lista\n");
        printf("10)Remove igual na lista\n");
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
                insereOrdenado(lista);
                system("cls");
                break;
            case 4:
                system("cls");
                exibe(lista);
                break;
            case 5:
                system("cls");
                libera(lista);
                system("cls");
                break;
            case 6:
                system("cls");
                removeInicio(lista);
                system("cls");
                break;
            case 7:
                system("cls");
                removeFinal(lista);
                system("cls");
                break;
            case 8:
                system("cls");
                removeEscolhido(lista);
                system("cls");
                break;
            case 9:
                system("cls");
                Ordena(lista);
                system("cls");
                break;
            case 10:
                system("cls");
                Ordena(lista);
                exibe(lista);
                removeIgual(lista);
                system("cls");
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
