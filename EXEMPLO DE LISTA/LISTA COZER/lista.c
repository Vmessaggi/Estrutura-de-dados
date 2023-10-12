#include <stdio.h>
#include <stdlib.h>

struct Node{//criando o tipo do elemento da lista
    int num;// Dado armazenado no n�
    struct Node *prox;// Ponteiro para o pr�ximo n� na lista
};

typedef struct Node node;//apelido
typedef node *LISTA;//declara��o ponteiro da cabe�a da lista | apelido LISTA para um ponteiro de tipo node. Ou seja, um ponteiro que aponta para um n� da lista.

LISTA* criarLista(){
    LISTA *inicio =(LISTA*) malloc (sizeof(LISTA));//aloca cabe�a da lista
    if(inicio != NULL){
        *inicio=NULL;
    }else{
        printf("Erro na aloca��o...\n");
        exit(0);
    }
    return inicio;
}
// A fun��o criarLista() alocar� mem�ria para a cabe�a da lista, inicializar� essa cabe�a com NULL (indicando uma lista vazia) e retornar� um ponteiro para essa cabe�a. Isso � fundamental para iniciar o processo de constru��o e manipula��o da lista encadeada.

void insereInicio(LISTA* lista){
    node *novo = (node*) malloc (sizeof(node));//declara e aloca
    if(novo == NULL) {
        printf ("Erro na aloca��o...\n");
        exit(0);
    }
    printf ("Informe valor do Novo elemento\n");
    scanf ("%d", &novo->num) ;
    novo->prox=(*lista);
    *lista = novo;
}
// a fun��o insereInicio() alocar� mem�ria para um novo n�, ler� o valor do novo elemento do usu�rio, configurar� o ponteiro prox do novo n� para apontar para o primeiro n� atual da lista e, finalmente, atualizar� a cabe�a da lista para apontar para o novo n�, tornando-o o novo primeiro elemento.

void insereFinal (LISTA* lista){
    node *novo = (node*) malloc (sizeof(node));// Declara e aloca espa�o para o novo n�
    if(novo == NULL) {
        printf("Erro na aloca��o...\n");
        exit(0);
    }
    printf ("Informe valor do Novo elemento\n");
    scanf ("%d", &novo->num);
    novo->prox = NULL; // Configura o pr�ximo n� como nulo, pois ser� o �ltimo
    if ((*lista) == NULL) {// Verifica se a lista est� vazia
        *lista = novo;// Se estiver vazia, o novo n� se torna o primeiro n�
    }else{
        node *tmp;// Vari�vel tempor�ria para percorrer a lista
        tmp = (*lista);
        while (tmp->prox != NULL) {// Encontra o �ltimo n� atual da lista
            tmp = tmp->prox;
        }
        tmp->prox = novo;// Configura o pr�ximo do �ltimo n� para apontar para o novo n�
    }
}
//ELSE:  esse trecho do c�digo encontra o �ltimo n� atual da lista, que � o n� cujo campo prox � NULL. Ent�o, ele atualiza o campo prox desse �ltimo n� para apontar para o novo n�, inserindo assim o novo n� no final da lista. Isso garante que a lista mantenha sua estrutura encadeada, com todos os n�s conectados na ordem correta.

void insereOrdenado(LISTA* lista) {
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocacao...\n");
        exit(0);
    }
    printf("Informe valor do Novo elemento\n");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    if((*lista) == NULL || novo->num <= (*lista)->num){
        novo->prox = (*lista);
        *lista = novo;
    }else{
        node *tmp = *lista;
        while (tmp->prox != NULL && tmp->prox->num < novo->num) {
            tmp = tmp->prox;
        }
        novo->prox = tmp->prox;
        tmp->prox = novo;
    }
}


void exibe(LISTA* lista){
    if( (*lista) == NULL) {
        printf ("LISTA VAZIA...\n");
    }else{
        node *tmp;// Vari�vel tempor�ria para percorrer a lista
        tmp = (*lista);
        while (tmp != NULL) {// Percorre a lista at� o final
            printf("%5d", tmp->num);// Imprime o valor do n� atual
            tmp = tmp->prox;// Move para o pr�ximo n�
        }
    }
    printf ("\n");
}

//No loop while (tmp != NULL):tmp aponta primeiro para o n� com o valor 10, depois para o n� com o valor 20 e finalmente para o n� com o valor 30.O loop percorre todos os n�s da lista.
//No loop while (tmp->prox != NULL):tmp aponta inicialmente para o n� com o valor 10, depois para o n� com o valor 20. O loop percorre apenas os dois primeiros n�s da lista.

void libera(LISTA* lista){
    if((*lista) == NULL) {
        printf ("LISTA VAZIA...\n");
    }else{
        node *tmp;
        while ((*lista) != NULL){
            tmp = *lista;
            *lista = (*lista)->prox;
            free(tmp);
        }
    }
}

void ordena(LISTA* lista){
    if (*lista == NULL) {
        printf("LISTA VAZIA...\n");
    }
    int trocou;
    do{
        trocou = 0;
        node *atual = *lista;
        while (atual->prox != NULL){
            if(atual->num > atual->prox->num){
                int temp = atual->num;
                atual->num = atual->prox->num;
                atual->prox->num = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    }while(trocou);
    printf("Lista ordenada com sucesso!...\n");
}

void removeInicio(LISTA* lista){
    if((*lista) != NULL){
        node *tmp;
        tmp = *lista;
        *lista = tmp->prox;
        free(tmp);
        printf ("Elemento removido com sucesso...\n");
    }else{
        printf("Lista ja esta vazia... \n");
    }
}

void removeFinal (LISTA* lista){
    node *antNode, *tmp;
    tmp = *lista;
    if ((*lista) != NULL && tmp->prox == NULL) {//se s� existe um elemento na lista
        *lista = NULL;
        free (tmp);
        printf ("Elemento removido com sucesso...\n");
    }else if((*lista) != NULL){// Se a lista n�o est� vazia
        while (tmp->prox !=NULL){
            antNode = tmp;
            tmp = tmp->prox;
        }
        antNode->prox = NULL;// Define o pr�ximo do pen�ltimo n� como NULL
        free(tmp);
        printf ("Elemento removido com sucesso...\n");
    }else{
        printf("Lista ja esta vazia...\n");
    }
}

void removeEspecifico(LISTA* lista) {
    int elm;
    printf("Informe o valor a ser removido:\n");
    scanf("%d", &elm);
    node *antNode = NULL;
    node *tmp = *lista;
    while(tmp != NULL && tmp->num != elm){
        antNode = tmp;
        tmp = tmp->prox;
    }
    if(tmp != NULL){
        if(antNode != NULL){
            antNode->prox = tmp->prox;
        }else{
            *lista = tmp->prox;
        }
        free(tmp);
        printf("Elemento removido com sucesso...\n");
    }else{
        printf("Elemento nao encontrado na lista...\n");
    }
}

void removeIguais(LISTA* lista) {
    if (*lista == NULL) {
        printf("LISTA VAZIA...\n");
        return;
    }
    int elm;
    printf("Informe o valor a ser removido repetido:\n");
    scanf("%d", &elm);
    node *antNode = NULL;
    node *tmp = *lista;
    int removeu = 0;
    while (tmp != NULL) {
        if (tmp->num == elm) {
            node *aux = tmp;
            tmp = tmp->prox;
            free(aux);
            if(antNode == NULL){
                *lista = tmp;
            }else{
                antNode->prox = tmp;
            }
            removeu = 1;
        }else{
            antNode = tmp;
            tmp = tmp->prox;
        }
    }
    if(removeu){
        printf("Elementos iguais removidos com sucesso...\n");
    }else{
        printf("Elemento digitado nao encontrado ou nao repetido\n");
    }
}


int main(){
    LISTA *lista = criarLista();
    int opcao;
    do{
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Inserir ordenado\n");
        printf("4 - Exibir lista\n");
        printf("5 - Liberar lista\n");
        printf("6 - Ordenar lista\n");
        printf("7 - Remover no inicio\n");
        printf("8 - Remover no final\n");
        printf("9 - Remover especifico\n");
        printf("10 - Remover iguais\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                system("clear");
                insereInicio(lista);
            break;
            case 2:
                system("clear");
                insereFinal(lista);
            break;
            case 3:
                system("clear");
                insereOrdenado(lista);
            break;
            case 4:
                system("clear");
                exibe(lista);
            break;
            case 5:
                system("clear");
                libera(lista);
            break;
            case 6:
                system("clear");
                ordena(lista);
            break;
            case 7:
                system("clear");
                removeInicio(lista);
            break;
            case 8:
                system("clear");
                removeFinal(lista);
            break;
            case 9:
                system("clear");
                removeEspecifico(lista);
            break;
            case 10:
                system("clear");
                removeIguais(lista);
            break;
            case 0:
            break;
            default:
                printf("Opcao nao exitente\n");
                break;
        }
    }while(opcao != 0);
    libera(lista);
    free(lista);
    return 0;
}
