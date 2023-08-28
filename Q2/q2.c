#include <stdio.h>
#include <math.h>

int main(){

    int n = 3, bool;
    double z;

    printf("2\n");
    while (1) {
        bool = 1;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                bool = 0;
                break;
            }
        }

        if (bool) {
            printf("%d\n", n);
        }

        n += 2;
    }
    
    return 0;
}