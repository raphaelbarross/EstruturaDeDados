#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// struct pilhavet, base para todas as Estruturas de Dados utilizadas

typedef struct{
	int vet[TAM];
	int topo;
}pilhavet;

// função que armazena um código binário em uma pilha de acordo com número inserido pelo usuário

int empilharBinario(int valor, pilhavet *p){
	if(p -> topo == TAM-1){
		printf("\nPilha cheia");
		exit(0);
	}
	
	int bin[50];
	int i = 0;
	
	while(valor > 0){
		bin[i] = valor % 2;
		valor = valor / 2;
		i++;
	}
	
	for(int j = 0; j < i; j++){
		p -> topo++;
		p -> vet[p -> topo] = bin[j];
	}	
	
	return i;
}

// função que esvazia todos os elementos de uma pilha

int desempilhar(pilhavet *p){
	if(p -> topo < 0){
		printf("\nPilha vazia");
		exit(1);
	}
	int aux = p -> vet[p -> topo];
	p -> topo--;
	return aux;
}

int main(){
	pilhavet pilha;
	int num, cont;
	pilha.topo = -1;
	
	printf("Digite um número para transformar em binário: ");
	scanf("%d", &num);
	cont = empilharBinario(num, &pilha);
	
	for(int i = 0; i < cont; i++){
		printf("\n%d", desempilhar(&pilha));
	}
}