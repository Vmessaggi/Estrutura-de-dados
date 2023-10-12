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
        printf("Erro de aloca��o...\n");
        exit(0);
    }
    return inicio;
}

void insereInicio(LISTA* lista){
    node *novo = (node*) malloc (sizeof(node));
    if(novo == NULL){
        printf("Erro de aloca��o...\n");
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
        printf("Erro de aloca��o...\n");
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
        printf("Erro de aloca��o...\n");
        exit(0);
    }
    printf("Informe o valor do novo elemento\n");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    //At� aqui igual aos outros "insere"
    if((*lista) == NULL || novo->num <= (*lista)->num){
        //NULL ou menor ou igual ao valor de num no primeiro n�
        novo->prox = (*lista);
        *lista = novo;
    }else{
        node *tmp = *lista;
        /*enquanto o pr�ximo n� de tmp n�o for nulo (ou seja, enquanto n�o chegarmos ao final da lista)
         e o valor num no pr�ximo n� for menor que o valor num no novo n� */
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
        printf("Lista j� esta vazia...\n");
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
    printf("Informe o valor da lista que ser� removido:\n");
    scanf("%d", &escolhido);
    node *anterior = NULL;
    node *tmp = *lista;
    while(tmp != NULL && tmp->num != escolhido){
        //Anterior � atualizado para apontar para tmp, e tmp � movido para o pr�ximo n� na lista (tmp->prox).
        anterior = tmp;
        tmp = tmp->prox;
    }
    //Se tmp for NULL, � o elemento que era procurado pois n�o recebeu ->prox, por isso � nulo.
    if(tmp != NULL){
        if(anterior != NULL){
            /*O elemento a ser removido n�o � o primeiro n� da lista. Nesse caso, antNode->prox � atualizado
            para apontar para o n� seguinte a tmp o que faz com que tmp seja removido da lista.*/
            anterior->prox = tmp->prox;
        }else{
            /* Se anterior for NULL, o elemento a ser removido � o primeiro n� da lista.
            O ponteiro de in�cio da lista (*lista) � atualizado para apontar para o pr�ximo n�
            ap�s tmp, tamb�m removendo tmp da lista.*/
            *lista = tmp->prox;
        }
        free(tmp);
        printf("Elemento removido\n");
    }else{
        printf("Elemento n�o localizado na lista\n");
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
        //Igual a fun��o exibe
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
        //Igual a fun��o exibe
    }
    do{
        change = 0;
        node *atual = *lista;
        while (atual->prox != NULL){
            if(atual->num > atual->prox->num){
                //Compara��o entre o valor armazenado no n� atual (atual->num) e o valor armazenado no pr�ximo n� (atual->prox->num).
                int temp = atual->num;
                //temporario recebe o valor do n� atual e logo ap�s o n� atual recebe o valor do pr�ximo n�.
                atual->num = atual->prox->num;
                atual->prox->num = temp;
                //O valor do pr�ximo n� vai ser igual ao tempor�rio acontecendo o swap(troca).
                change = 1;
                //Flag que demonstra que houve troca.
            }
            atual = atual->prox;
        }
    }while(change == 1);
    /*Vai executar a troca at� o change ser igual a zero, pois depois de acontecer uma troca, quer garantir que est�
    tudo certo pois � feita uma troca de cada vez.*/
    printf("Lista ordenada\n");
}

void main(){
    setlocale(LC_ALL,"Portuguese");
    LISTA *lista = criarLista();
    int op;
    do{
        printf("1)Inserir no in�cio\n");
        printf("2)Inserir no final\n");
        printf("3)Inserir ordenadamente\n");
        printf("4)Exibir lista\n");
        printf("5)Libera lista\n");
        printf("6)Remove in�cio\n");
        printf("7)Remove fim\n");
        printf("8)Remove por escolha do usu�rio\n");
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
                    printf("Op��o inv�lida!\n");
                }
                break;
        }
    }while(op != 0);
}
