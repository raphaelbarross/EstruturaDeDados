#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// struct pilhavet, base para todas as Estruturas de Dados utilizadas

typedef struct{
	int vet[TAM];
	int topo;
}pilhavet;

// função que empilha todos os elementos dentro de uma pilha

void empilhar(int valor, pilhavet *p){
	if(p -> topo == TAM-1){
		printf("\nPilha cheia");
		exit(0);
	}
	p -> topo++;
	p -> vet[p -> topo] = valor;
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

// função que printa os valores da pilha em binário

void binario(int valor){
	if(valor == 0){
		printf(0);
		return;
	}
	
	int bin[50];
	int i;
	while(valor > 0){
		bin[i] = valor % 2;
		valor = valor / 2;
		i++;
	}
	
	for(int j = i - 1; j >= 0; j--){
		printf("%d", bin[j]);
	}
}

int main(){
	pilhavet pilha;
	int num;
	pilha.topo = -1;
	
	for(int i = 0; i < TAM; i++){
		printf("Digite um número para empilhar: ");
		scanf("%d", &num);
		empilhar(num, &pilha);
	}
	
	for(int i = 0; i < TAM; i++){
		num = desempilhar(&pilha);
		printf("\n%d -> ", num);
		binario(num);
	}
}