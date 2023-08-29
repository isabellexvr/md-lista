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

int main(){
    int number, candidatePrime = 2;
    scanf("%d", &number);

    while (number >= 1 && candidatePrime <= number){
        if(!isPrime(candidatePrime)){
            candidatePrime ++;
            continue;
        }

        if(number % candidatePrime == 0){
            printf("%d\n", candidatePrime);
            number = number / candidatePrime;
            continue;
        }else{
            candidatePrime = getNextPrime(candidatePrime);
            continue;
        }
    }
    
    return 0;
}
