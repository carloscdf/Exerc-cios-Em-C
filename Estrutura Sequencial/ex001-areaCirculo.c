//Faça um Programa que peça o raio de um círculo, calcule e mostre sua área.
#include <stdio.h>
#include <math.h>

typedef struct circulo{
    double raio;
    double area;
} circulo;

void calcArea(circulo *c){
    double PI = 3.14;
    c->area = PI*pow(c->raio, 2);
}

int main(){
    circulo circulo1;
    circulo *ponteiroCirculo = &circulo1;
    ponteiroCirculo->raio = 3;
    calcArea(&circulo1);
    printf("O raio é: %f", (*ponteiroCirculo).raio);
    printf("A área é: %f", ponteiroCirculo->area);
    return 0;
}