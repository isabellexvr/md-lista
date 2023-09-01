#include <stdio.h> 

int extendMDC(int n1, int n2, int resto, int *addressA, int *addressB){
    int a=1, b=0, quociente, candidateS, s, mdc;
    
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
    
    if(candidateS < 0){
       candidateS += *addressB;
    }
    
    return candidateS;
}

int euclides(int A, int D){

    if(A % D == 0){
        return D;
    }else{
        return euclides(D, (A % D));
    }
}

int main() { 
    int n, mdcCandidato, answer = 0, flag=1;
    
    printf("Quantas congruências lineares serão? ");
    scanf("%d", &n);
    
    int divisores[n], restos[n], M = 1, Mn[n], sArr[n];
    
    
    for( int i = 0 ; i < n ; i++ ){
        printf("Valores de b e m:\n");
        scanf("%d %d", &restos[i], &divisores[i]);
    }
    
    for( int i = 0 ; i < n ; i++ ){
        if(i==n-1){
            break;
        }else if(euclides(divisores[i], divisores[i+1])!=1){
            flag = 0;
        }
    }
    
    if(flag==0){
        printf("Nao ha solucoes para esse sistema.");
        return 0;
    }else{
        
        for(int i = 0 ; i < n ; i++){
            M *= divisores[i];
        }
        
        for( int i = 0 ; i < n ; i++ ){
            Mn[i] = (M/divisores[i]);
            int a,b;
            sArr[i] = extendMDC( (M/divisores[i]), divisores[i], 0, &a, &b);
        }
        
        for( int i = 0 ; i < n ; i++ ){
             answer += (Mn[i]*restos[i]*sArr[i]);
        }
        
        answer = answer % M;
        
        printf("Essas sao as %d congruencias:\n", n);
        for(int i=0;i<n;i++){
            printf("Congruencia %d: X ≡ %d mod %d\n", i+1, restos[i], divisores[i]);
        }
        
        printf("O valor de X eh: %d\n", answer);
    }
    
    return 0;
}