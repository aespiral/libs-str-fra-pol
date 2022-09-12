#include <stdlib.h>
#include <stdio.h>

int mystrlen(char* s) {
    int i = 0;
    while (s[i] != 0) 
        i++;
    return i;
}

char* mystrcpy(char* dest, char* orig) {
    int i;
    for(i=0; orig[i]!=0; i++)
        dest[i] = orig[i];
    dest[i]=0;
    return dest;
}

char* mystrcpy_imm(char* dest, char* orig) {
    int tam = mystrlen(orig);
    char* res = (char*) malloc(tam * sizeof(char)+1);
    mystrcpy(res,orig);
    return res;
}

int main() {
    char alocado[10];
    char* nao_alocado;
    char b[] = "oi";
    char c[] = "ya";

    mystrcpy(alocado, b);  // Versao mutavel 
    nao_alocado = mystrcpy_imm(NULL, c);  // Versao imutavel 

    puts(alocado);
    puts(nao_alocado);
}