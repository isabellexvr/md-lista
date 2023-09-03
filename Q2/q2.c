#include <stdio.h>
#include <time.h>

int main(){

    int n = 3, bool, time;
    double z;

    time = clock();

    printf("2\n");
    while ((clock() - time) / CLOCKS_PER_SEC < 60) {
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