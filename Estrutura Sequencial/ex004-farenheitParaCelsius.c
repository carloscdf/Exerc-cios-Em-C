//Faça um Programa que peça a temperatura em graus Farenheit, transforme e mostre a temperatura em graus Celsius. 
//FORMULA: C = (5 * (F-32) / 9).
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperatura{
    double farenheit;
    double celsius;
} Temperatura;

void imprimir(Temperatura *t);

void lerTemperatura(Temperatura *t){
    printf("Digite a temperatura em farenheit: ");
    scanf("%lf", &t->farenheit);
}

int converterParaCelsius(){
    Temperatura *t = (Temperatura*)malloc(sizeof(Temperatura));
    if(t == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    lerTemperatura(t);
    t->celsius = (5*(t->farenheit-32)/9);
    imprimir(t);
    free(t);
    return 0;
}

void imprimir(Temperatura *t){
    printf("\n\n========= RESULTADO =========\n");
    printf("Temperatura em Farenheit: %.2lfºF\n", t->farenheit);
    printf("Temperatura em Celsius: %.2lfºC\n", t->celsius);
    printf("=============================");
}

int main(){
    converterParaCelsius();
    return 0;
}