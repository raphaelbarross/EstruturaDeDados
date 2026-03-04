#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char  nome[100];
    int   idade;
    float salario;
} Funcionario;

int main(void) {
    int n;
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &n);

    Funcionario *funcs = (Funcionario*) malloc(n * sizeof(Funcionario));

    float somaSalarios = 0.0f;

    for (int i = 0; i < n; i++) {
        printf("\nFuncionario %d\n", i + 1);

        printf("Nome: ");
        scanf(" %99[^\n]", funcs[i].nome);
        printf("Idade: ");
        scanf("%d", &funcs[i].idade);
        printf("Salario: ");
        scanf("%f", &funcs[i].salario);
        
        somaSalarios += funcs[i].salario;
    }

    printf("\n--- Funcionarios cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] Nome: %s | Idade: %d | Salario: %.2f\n",
               i + 1, funcs[i].nome, funcs[i].idade, funcs[i].salario);
    }

    float media = somaSalarios / n;
    printf("\nMedia salarial da equipe: %.2f\n", media);

    return 0;
}