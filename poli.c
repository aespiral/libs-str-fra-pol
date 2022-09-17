#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 32
#define TOL 1.e-6

/*
 * Representação de polinomio
 * nome(x) = c_n . x^n + c_n-1 . x^(n-1) + ... + c_1 . x + c_0
 * - nome
 * - grau (n)
 * - coeficientes
 */
typedef struct {
    char nome;
    int grau;
    float* coefs;
} POLI;

POLI* make(char letra, int max_expoente, float* cs) {
    POLI* res = (POLI*) malloc(sizeof(POLI));
    res->nome = letra;
    res->grau = max_expoente;
    int i;
    res->coefs = (float*) malloc( (max_expoente + 1) * sizeof(float) );
    for (i=0; i<=max_expoente; i++)
        res->coefs[i] = cs[i];
    return res;
}

/*
 * Funções
 */

float avaliar(POLI* p, float a) {
    return 0.0; // TODO: calcular p(a)
}

float raiz(POLI* p) {
    return 0.0;
    // retorna uma raiz do polinomio; se houver 2 ou mais, retorna 1 qq
    // funciona para n == 1 e n == 2 (báskara)
}

/*
 * Melhorias possiveis no Pretty Print:
 * - Em vez de mostrar 2.000, 3.000, etc., mostrar 2 , 3 , etc.
 * - Em vez de mostrar 1.000 . x^algo (ou 1 . x^algo), mostrar x^algo
 */
void pprint(POLI* p) {
    printf("%c(x) = ", p->nome);
    // Os casos n == 0 e n == 1 sao tratados a parte
    //   apenas para evitar escrever x^1 e x^0
    if (p->grau == 0){
        printf("%.3f\n", p->coefs[0]);
        return; // dica: o return termina a funcao 
        // eh como se tudo daqui para baixo fosse um 'else'
    } 
    if (p->grau == 1){
        printf("%.3f . x", p->coefs[1]);
        if (p->coefs[0] > TOL)
            printf(" + %.3f", p->coefs[0]);
        putchar('\n');
        return;
    }

    printf("%.3f . x^%d", p->coefs[p->grau], p->grau);
    int i;
    for(i=p->grau-1; i >= 2; i = i - 1) {
        if (p->coefs[i] > TOL)
            printf(" + %.3f . x^%d", p->coefs[i],i);
    }
    if (p->coefs[1] > TOL)
        printf(" + %.3f . x", p->coefs[1]);
    if (p->coefs[0] > TOL)
        printf(" + %.3f", p->coefs[0]);
    putchar('\n');
}

bool normalizado(POLI* p) {
    return p->coefs[p->grau] > TOL;
}

void normalizar(POLI* p) {
    int i = p->grau; 
    while(p->coefs[i] < TOL) 
        i = i - 1;
    p->grau = i;
}

// somar

// derivar

// multiplicar por escalar (constante)

// multiplicar por x

// multiplicar 2 polinomios

int main() {
    float cq[3] = {1.0,5.0,2.7};
    POLI* q = make('q', 2, cq);
    pprint(q);

    float cp1[2] = {4.7,0.575};
    POLI* p1 = make('k',1,cp1);
    pprint(p1);

    float cp2[3] = {3.5,0.5,0.0};
    POLI* p2 = make('w',3,cp2);
    pprint(p2);

    float cp3[1] = {0.0};
    POLI* p3 = make('z',1,cp3);

    // Exemplo de polinomio normalizado
    puts("--------");
    pprint(p1);
    if (normalizado(p1))
        printf("O polinomio %c estah normalizado.\n", p1->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p1->nome);

    // Exemplo de polinomio nao normalizado
    puts("--------");
    float cp4[5] = {4.0,7.5,1.0,0.0,0.0};
    POLI* p4 = make('s',5,cp4);
    pprint(p4);
    if (normalizado(p4))
        printf("O polinomio %c estah normalizado.\n", p4->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p4->nome);

    // Normalizando
    puts("--------");
    normalizar(p4);
    pprint(p4);
    if (normalizado(p4))
        printf("O polinomio %c estah normalizado.\n", p4->nome);
    else
        printf("O polinomio %c nao estah normalizado\n", p4->nome);
}