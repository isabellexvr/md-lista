#include <stdio.h> 
int main() { 
    int resto, n1, n2; 

    printf("Questão 5: Determinar o MDC de dois números inteiros com base no algoritmo de Euclides.\n");
    printf("Insira os dois números inteiros:\n");

    scanf("%d%d", &n1, &n2); 

    while(n2!=0){ 
        resto = n1%n2; 
        n1 = n2; 
        n2 = resto; 
    } 
    printf("%d\n", n1); 
    return 0;
}