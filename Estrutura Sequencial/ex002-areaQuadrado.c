//Faça um Programa que calcule a área de um quadrado, em seguida mostre o dobro desta área para o usuário.
#include <stdio.h>
#include <stdlib.h>

typedef struct quadrado{
    float lado;
    float area;
} quadrado;

void imprimirResultado(quadrado *q,float dobroArea);

int calcArea(float lado){
    quadrado *q = (quadrado*) malloc(sizeof(quadrado)); //alocação na heap ao invés de stack
    if(q == NULL){ //verifica se a memória foi alocada corretamente
        printf("Digite a temperatura em farenheit: ");
        return 1;    
    }
    q->lado = lado;
    q->area = q->lado*q->lado;
    float dobroArea = q->area*2;
    imprimirResultado(q, dobroArea);
    free(q);
    return 0;
} 

void lerValores(){
    float lado;

    printf("Digite o lado do quadrado: ");
    scanf("%f", &lado);

    calcArea(lado);
}

void imprimirResultado(quadrado *q, float dobroArea){
    printf("\n========= RESULTADO =========\n");
    printf("Lados: %.2f\n", q->lado);
    printf("Area: %.2f\n", q->area);
    printf("Dobro da area: %.2f", dobroArea);
    printf("\n=============================");
}

int main(){
    lerValores();
    return 0;
}