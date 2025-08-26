//Faça um Programa que peça o raio de um círculo, calcule e mostre sua área.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Circulo{
    double raio;
    double area;
} Circulo;

void ler(Circulo *c){
    printf("Digite o raio do circulo: ");
    scanf("%lf", &c->raio);
}

void imprimir(Circulo *c){
    printf("\n\n========= RESULTADO =========\n");
    printf("O raio do circulo é: %.2lf\n", c->raio);
    printf("A area do circulo é: %.2lf\n", c->area);
    printf("=============================");
}

void calcArea(Circulo *c){
    double PI = 3.14;
    c->area = PI*pow(c->raio, 2);
}

int processarArea(){
    Circulo *c = (Circulo*)malloc(sizeof(Circulo));
    if(c == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    ler(c);
    calcArea(c);
    imprimir(c);
    free(c);
    return 0;
}

int main(){
    processarArea();
    return 0;
}