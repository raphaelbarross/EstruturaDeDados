#include <stdio.h>
#include <stdlib.h>

// definição do nó

typedef struct lista{
    int dado;
    struct lista *link;
}no;

// função para criar a lista encadeada

no *crialista(int n){
    no *ini, *p, *ult;
    int valor;
    ini = ult = NULL;

    for(int i = 1; i <= n; i++){
        printf("\nDigite o valor %d da lista:", i);
        scanf("%d", &valor);
        p = (no*)malloc(sizeof(no));
        p -> dado = valor;
        p -> link = NULL;

        if(ult != NULL){
            ult -> link = p;
        }
        else{
            ini = p;
        }
        ult = p;
    }

    return ini;
}

// função para printar a lista encadeada

void escrevelista(no *p){
    while (p != NULL){
        printf("%d\t", p -> dado);
        p = p -> link;
    }
}

// main

int main(){
    no *primeira;
    int n;

    printf("Criando uma lista encadeada! \n");

    do{
        printf("\nEntre com o número de nós: ");
        scanf("%d", &n);
    }while(n < 0);

    primeira = crialista(n);

    if(primeira != NULL){
        printf("\nLista Criada");
        printf("\n");
        escrevelista(primeira);
    }
    else{
        printf("\nLista Vazia!");
    }

    return(0);
}
