//Faça um Programa que peça a temperatura em graus Celsius, transforme e mostre em graus Farenheit.
//FORMULA: F = (C * 9/5)+32.
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperatura{
    double farenheit;
    double celsius;
} Temperatura;

void lerTemperatura(Temperatura *t){
    printf("Digite a temperatura em celsius: ");
    scanf("%lf", &t->celsius);
}

void imprimir(Temperatura *t){
    printf("\n\n========= RESULTADO =========\n");
    printf("Temperatura em Celsius: %.2lfºC\n", t->celsius);
    printf("Temperatura em Farenheit: %.2lfºF\n", t->farenheit);
    printf("=============================");
}

void converterParaFarenheit(Temperatura *t){
    t->farenheit = (t->celsius * 9.0/5.0)+32.0;
}

int processarTemperatura(){
    Temperatura *t = (Temperatura*)malloc(sizeof(Temperatura));
    if(t == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    lerTemperatura(t);
    converterParaFarenheit(t);
    imprimir(t);
    free(t);
    return 0;
}

int main(){
    processarTemperatura();
    return 0;
}