/*Faça um programa para uma loja de tintas. O programa deverá pedir o 
tamanho em metros quadrados da área a ser pintada. Considere que 
a cobertura da tinta é de 1 litro para cada 3 metros quadrados e 
que a tinta é vendida em latas de 18 litros, que custam R$ 80,00. 
Informe ao usuário a quantidades de latas de tinta a serem compradas 
e o preço total.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LATA_LITROS 18
#define LATA_PRECO 80

typedef struct Tinta{
    double tamanhoArea;
    double qtdLitros;
    int qtdLatas;
    double precoTotal;
}Tinta;

void ler(Tinta *tinta){
    printf("Digite o tamanho em m² da area a ser pintada: ");
    scanf("%lf", &tinta->tamanhoArea);
}

void imprimir(Tinta *tinta){
    printf("\n\n========= RESULTADO =========\n");
    printf("Tamanho da area: %.2lfm²\n", tinta->tamanhoArea);
    printf("Preco de 18 litros de lata de tinta: R$%.2lf\n", LATA_PRECO);
    printf("Quantidade de litros de tinta necessario: %.2lfL\n", tinta->qtdLitros);
    printf("Quantidade de latas de 18L necesarias: %d\n", tinta->qtdLatas);
    printf("Preco total: R$%.2lf\n", tinta->precoTotal);
    printf("=============================");
}

void calcular(Tinta *tinta){
    tinta->qtdLitros = tinta->tamanhoArea/3.0; 
    tinta->qtdLatas = (int)ceil(tinta->qtdLitros/LATA_LITROS); //arredonda para cima e converte a saida em inteiro
    tinta->precoTotal = tinta->qtdLatas*LATA_PRECO;
}

int processarTinta(){
    Tinta *tinta = (Tinta*)malloc(sizeof(Tinta));
    if(tinta == NULL){
        printf("\n\nAlocação de memoria falhou");
        return 1;
    }
    ler(tinta);
    calcular(tinta);
    imprimir(tinta);
    free(tinta);
    return 0;
}

int main(){
    processarTinta();
    return 0;
}
