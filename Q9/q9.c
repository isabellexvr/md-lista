#include <stdio.h> 

int inverse(int n1, int n2, int resto, int *addressA, int *addressB){
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
        
    return s;
}

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
    int n = 3, mdcCandidato, answer = 0, flag=1;
    
    int m[n], b[n], a[n], M = 1, Mn[n], sArr[n];
    printf("Questão 9: Encontrar a solução única de três congruências utilizando o teorema chinês do resto.\n");
    for( int i = 0 ; i < n ; i++ ){
        printf("Insira os valores de a, b e m para a congruencia %d:\n", i + 1);
        scanf("%d %d %d", &a[i], &b[i], &m[i]);
        if(a[i] != 1){
            //verificar se a e m sao primos entre si
            if (euclides(a[i], m[i]) != 1){
                printf("Para essa congruencia, a e m não são coprimos, logo, não há uma congruência equivalente onde o a é 1.\n");
                return 0;
            }
            int numA = a[i], numB = m[i], bInverse, oldB = b[i];
            // nova congruencia:
            // novo a = 1; novo b = inverso(a,m)*b; novo m = m
            bInverse  = inverse(a[i], m[i], 0, &numA, &numB);
            b[i] = bInverse * oldB;
            a[i] = 1;
        }
    }

    for( int i = 0 ; i < n ; i++ ){
        if(i==n-1){
            break;
        }else if(euclides(a[i], a[i+1])!=1){
            flag = 0;
        }
    }
    
    for( int i = 0 ; i < n ; i++ ){
        if(i==n-1){
            break;
        }else if(euclides(m[i], m[i+1])!=1){
            flag = 0;
        }
    }
    
    if(flag==0){
        printf("Nao ha solucoes para esse sistema, pois, ou os valores de a não são coprimos entre si, ou os valores de m não são coprimos entre si.");
        return 0;
    }else{
        
        for(int i = 0 ; i < n ; i++){
            M *= m[i];
        }
        
        for( int i = 0 ; i < n ; i++ ){
            Mn[i] = (M/m[i]);
            int a,b;
            sArr[i] = extendMDC( (M/m[i]), m[i], 0, &a, &b);
        }
        
        for( int i = 0 ; i < n ; i++ ){
             answer += (Mn[i]*b[i]*sArr[i]);
        }
        
        answer = answer % M;
        
        printf("Essas sao as %d congruencias:\n", n);
        for(int i=0;i<n;i++){
            printf("Congruencia %d: X ≡ %d mod %d\n", i+1, b[i], m[i]);
        }
        
        printf("O valor de X eh: %d\n", answer);
    }
    
    return 0;
}