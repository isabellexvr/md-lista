#include <stdio.h>

int extendMDC(int n1, int n2, int resto, int *addressA, int *addressB){
    int a=1, b=0, quociente, candidateS, s, t, mdc;
    
    *addressA = n1;
    *addressB = n2;
    
    while( (n2!=0) && (n1 % n2 != 0) ){
        resto = n1 % n2;
        quociente = n1 / n2;
        candidateS = a - (b * quociente);
        a = b;
        b = candidateS;
        n1 = n2; 
        n2 = resto; 
    }
    
    s = candidateS;
    mdc = n2;
    
    t = (mdc - (*addressA * s) ) / *addressB;
    
    if(s < 0){
        s += *addressB;
    }else if(s >= *addressB){
        s = s % *addressB;
    }
    
    printf("Valor do inverso de a mod b: %d\n", s);
    
    return candidateS;
}

int main()
{
    int numero1, numero2;
    printf("Questão 7: Encontrar o inverso de a mod b.\n");
    printf("Insira os inteiros a e b:\n");

    scanf("%d%d", &numero1, &numero2);
    
    extendMDC(numero1, numero2, 0, &numero1, &numero2);
    
    return 0;
}