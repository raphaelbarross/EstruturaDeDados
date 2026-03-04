#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TAM 10

typedef struct{
    int R, F;
    int vet[TAM];
}filavet;

void enfileirar(int valor, filavet *p){
    if (p -> R == TAM-1){
        printf("\n Fila Cheia!");
        exit(0);
    }
    
    p -> R++;
    p -> vet[p -> R] = valor;
}

int desenfileirar (filavet *p){
    int aux;
    
    if (p -> F == TAM){
        printf("\nFila Vazia!");
        exit(1);
    }  
 
    aux = p -> vet[p -> F];
    p -> F++;
    return aux;
} 

int main(void){
    filavet fila;
    int valor;
    fila.R = -1;
    fila.F = 0;
 
    for(int i=0; i< TAM; i++){
        printf("Digite o valor a ser enfileirado: \n");
        scanf("%d", &valor);
        enfileirar(valor, &fila);
    }
 
    for(int i=0; i < TAM; i++){
        printf("\n%d", desenfileirar(&fila));
   }
 return(0);
} 