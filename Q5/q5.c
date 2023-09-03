#include <stdio.h> 
int main() { 
    int resto, n1, n2; 
    scanf("%d%d", &n1, &n2); 

    while(n2!=0){ 
        resto = n1%n2; 
        n1 = n2; 
        n2 = resto; 
    } 
    printf("%d\n", n1); 
    return 0;
}