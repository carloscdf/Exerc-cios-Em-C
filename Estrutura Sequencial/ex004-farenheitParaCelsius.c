//Faça um Programa que peça a temperatura em graus Farenheit, transforme e mostre a temperatura em graus Celsius. 
//FORMULA: C = (5 * (F-32) / 9).
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperatura{
    double farenheit;
    double celsius;
} Temperatura;

void lerTemperatura(Temperatura *t){
    printf("Digite a temperatura em farenheit: ");
    scanf("%lf", &t->farenheit);
}

void imprimir(Temperatura *t){
    printf("\n\n========= RESULTADO =========\n");
    printf("Temperatura em Farenheit: %.2lfºF\n", t->farenheit);
    printf("Temperatura em Celsius: %.2lfºC\n", t->celsius);
    printf("=============================");
}

void converterParaCelsius(Temperatura *t){
    t->celsius = (5.0*(t->farenheit-32.0)/9.0);
}

int processarTemperatura(){
    Temperatura *t = (Temperatura*)malloc(sizeof(Temperatura));
    if(t == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    lerTemperatura(t);
    converterParaCelsius(t);
    imprimir(t);
    free(t);
    return 0;
}

int main(){
    processarTemperatura();
    return 0;
}