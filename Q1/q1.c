#include <stdio.h>
#include <math.h>

int main()
{
    int bool, f, n;
    printf("Questão 1: Determinar se dado número é primo ou não.\n");
    printf("Insira o número:\n");
    scanf("%d", &n);

    bool = 1;

    if(n < 2){
        bool = 0;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if(n % i == 0){
            bool = 0;
            break;
        }
    }

    if(bool){
        printf("É primo\n");
    }else{
        printf("Não é primo\n");
    }
    
    return 0;
}
