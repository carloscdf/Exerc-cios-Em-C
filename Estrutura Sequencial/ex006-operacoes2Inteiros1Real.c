/*Faça um Programa que peça 2 números inteiros e um número real. Calcule e mostre:
o produto do dobro do primeiro com metade do segundo .
a soma do triplo do primeiro com o terceiro.
o terceiro elevado ao cubo.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Numeros{
    int n1;
    int n2;
    double n3;
    double resultadoProduto;
    double resultadoSoma;
    double resultadoCubo;
} Numeros;

void ler(Numeros *numeros){
    printf("Digite um numero inteiro: ");
    scanf("%d", &numeros->n1);
    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &numeros->n2);
    printf("Digite um número real: ");
    scanf("%lf", &numeros->n3);
}

void imprimir(Numeros *n){
    printf("\n\n========= RESULTADO =========\n");
    printf("Primeiro numero inteiro: %d\n", n->n1);
    printf("Segundo numero inteiro: %d\n", n->n2);
    printf("Numero real: %.2lf\n\n", n->n3);
    printf("O produto do dobro do primeiro com metade do segundo: %.2lf\n", n->resultadoProduto);
    printf("A soma do triplo do primeiro com o terceiro: %.2lf\n", n->resultadoSoma);
    printf("O terceiro elevado ao cubo: %.2lf\n", n->resultadoCubo);
    printf("=============================");
}

void calcularNumeros(Numeros *n){
    n->resultadoProduto = (n->n1*2)*(n->n2/2.0);
    n->resultadoSoma = (n->n1*3)+n->n3;
    n->resultadoCubo = pow(n->n3, 3);
}

int processarCalculos(){
    Numeros *n = (Numeros*)malloc(sizeof(Numeros));
    if(n == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    ler(n);
    calcularNumeros(n);
    imprimir(n);
    free(n);
    return 0;
}

int main(){
    processarCalculos();
    return 0;
}

