// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct dupla {
    int dado;
    struct dupla *elink, *dlink;
} no;
 
 no* crialde (int n) {
     no *ini = NULL, *p;
     int valor;
     
     for(int i = 1; i <=n; i++) {
         printf("\nDigite o valor %d da lista: ", i);
         scanf("%d", &valor);
         
         p = (no*) malloc(sizeof(no));
         p->dado = valor;
         
         p->elink = ini; 
         p->dlink = NULL;
         
         if(ini != NULL)
            ini->dlink = p;
            
            ini = p;
     }
     return ini;
 }
 
 void escrevelista(no *p) {
     printf("\nLista: ");
     while(p != NULL) {
         printf("%d\t", p->dado);
         p = p->elink ;
     }
 }
 int main() {
     no *primeira;
     int n;
    
     printf("\nCriando uma lista duplamente encadeada");
     
     do {
         printf("\nEntre com o numero de nos: ");
         scanf("%d", &n);
     } while(n < 0);
     
     primeira = crialde(n);
     
     if(primeira != NULL) {
         printf("\nLista criada");
         escrevelista(primeira);
     } else {
         printf("\nLista Vazia");
     }
 }