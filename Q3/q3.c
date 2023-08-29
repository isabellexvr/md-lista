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

int main(){
    int i, number;
    scanf("%d", &number);

    for(i=number;i>=2;i--){
        if(i%2==0){
            continue;
        }else{
            if(isPrime(i)){
                if(number%i==0){
                    printf("%d\n", i);
                }
            }
        }
    }

    
    return 0;
}
