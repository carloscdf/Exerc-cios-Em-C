//Faça um Programa que peça a temperatura em graus Celsius, transforme e mostre em graus Farenheit.
//FORMULA: F = (C * 9/5)+32.
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperatura{
    double farenheit;
    double celsius;
} Temperatura;

void imprimir(Temperatura *t);

void lerTemperatura(Temperatura *t){
    printf("Digite a temperatura em celsius: ");
    scanf("%lf", &t->celsius);
}

int converterParaFarenheit(){
    Temperatura *t = (Temperatura*)malloc(sizeof(Temperatura));
    if(t == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    lerTemperatura(t);
    t->farenheit = (t->celsius * 9/5)+32;
    imprimir(t);
    free(t);
    return 0;
}

void imprimir(Temperatura *t){
    printf("\n\n========= RESULTADO =========\n");
    printf("Temperatura em Celsius: %.2lfºC\n", t->celsius);
    printf("Temperatura em Farenheit: %.2lfºF\n", t->farenheit);
    printf("=============================");
}

int main(){
    converterParaFarenheit();
    return 0;
}
