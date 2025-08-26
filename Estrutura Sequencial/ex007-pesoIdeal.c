//Tendo como dados de entrada a altura de uma pessoa, construa um algoritmo que calcule seu peso ideal.
//FÓRMULA: (72.7*altura) - 58
#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    double altura;
    double pesoIdeal;
} Pessoa;

void ler(Pessoa *p){
    printf("Digite a altura da pessoa: ");
    scanf("%lf", &p->altura);
}

void imprimir(Pessoa *p){
    printf("\n\n========= RESULTADO =========\n");
    printf("Altura da pessoa: %.2lf\n", p->altura);
    printf("Peso ideal da pessoa: %.2lf\n", p->pesoIdeal);
    printf("=============================");
}

void calcular(Pessoa *p){
    p->pesoIdeal = (72.7*p->altura)-58;
}

int processarPesoIdeal(){
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    if(p == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    ler(p);
    calcular(p);
    imprimir(p);
    free(p);
    return 0;
}

int main(){
    processarPesoIdeal();
    return 0;
}

