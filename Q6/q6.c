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
    
    printf("Valor de s: %d\n", s);
    printf("Valor de t: %d\n", t);
    
    return candidateS;
}

int main()
{
    int numero1, numero2;
    printf("Questão 6: Encontrar os coeficientes s e t da combinação linear.\n");
    printf("Insira os dois números inteiros, a e b, da combinação linear:\n");

    scanf("%d%d", &numero1, &numero2);
    
    extendMDC(numero1, numero2, 0, &numero1, &numero2);
    
    return 0;
}
