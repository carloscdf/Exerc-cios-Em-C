//Faça um Programa que calcule a área de um quadrado, em seguida mostre o dobro desta área para o usuário.
#include <stdio.h>
#include <stdlib.h>

typedef struct Quadrado{
    float lado;
    float area;
    float dobroArea;
} Quadrado;

void ler(Quadrado *q){
    printf("Digite o lado do quadrado: ");
    scanf("%f", &q->lado);
}

void imprimir(Quadrado *q){
    printf("\n========= RESULTADO =========\n");
    printf("Lados: %.2f\n", q->lado);
    printf("Area: %.2f\n", q->area);
    printf("Dobro da area: %.2f", q->dobroArea);
    printf("\n=============================");
}

void calcArea(Quadrado *q){
    q->area = q->lado*q->lado;
    q->dobroArea = q->area*2;
}

int processarArea(){
    Quadrado *q = (Quadrado*) malloc(sizeof(Quadrado));
    if(q == NULL){ 
        printf("\n\nAlocação de memória falhou");
        return 1;    
    }
    ler(q);
    calcArea(q);
    imprimir(q);
    free(q);
    return 0;
} 

int main(){
    processarArea();
    return 0;
}