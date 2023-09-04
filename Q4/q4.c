#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int bool = 1;

    if(n < 2){
        bool = 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if(n % i == 0){
            bool = 0;
            break;
        }
    }

    return bool;
}

int getNextPrime(int n){
    int newPrime = n + 1;
    while (!isPrime(newPrime)){
        newPrime ++;
    }

    return newPrime;
}

int fator(int x, int y, int *addressA, int *addressB){
    int candidatePrime = 2, mmc=1, mdc=1;
    *addressA = x;
    *addressB = y;


    while (x >= 1 && y>=1 && candidatePrime <= x || candidatePrime <= y){
        if(!isPrime(candidatePrime)){
            candidatePrime ++;
            continue;
        }

        if(x % candidatePrime == 0 && y % candidatePrime == 0){
            x = x / candidatePrime;
            y = y / candidatePrime;
            mmc = mmc*candidatePrime;
            mdc = mdc*candidatePrime;
            continue;
        }else if(x % candidatePrime == 0){
            x = x / candidatePrime;
            mmc = mmc*candidatePrime;
            continue;
        }else if(y % candidatePrime == 0){
            y = y / candidatePrime;
            mmc = mmc*candidatePrime;
            continue;
        }else{
            candidatePrime = getNextPrime(candidatePrime);
            continue;
        }
    }
    
    printf("MMC(%d, %d) = %d\nMDC(%d, %d) = %d\n", *addressA, *addressB, mmc, *addressA, *addressB, mdc);
}

int main(){
    int valorA, valorB;
    printf("Questão 4: Determinar o mdc e o mdc de dois inteiros com base em seus fatores primos.\n");
    printf("Insira os dois números:\n");

    scanf("%d%d", &valorA, &valorB);


    fator(valorA, valorB, &valorA, &valorB);

    return 0;
}
