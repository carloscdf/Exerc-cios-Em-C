/*
João Papo-de-Pescador, homem de bem, comprou um microcomputador para controlar o 
rendimento diário de seu trabalho. Toda vez que ele traz um peso de peixes maior
que o estabelecido pelo regulamento de pesca do estado de São Paulo (50 quilos) 
deve pagar uma multa de R$ 4,00 por quilo excedente. João precisa que você faça 
um programa que leia a variável peso (peso de peixes) e calcule o excesso. 
Gravar na variável excesso a quantidade de quilos além do limite e na variável 
multao valor da multa que João deverá pagar. 
Imprima os dados do programa com as mensagens adequadas.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Multa{
    double pesoPeixes;
    double pesoExcedente;
    double multaValor;
    double multao;
}Multa;

void ler(Multa *m){
    printf("Digite o peso dos peixes em kilos: ");
    scanf("%lf", &m->pesoPeixes);
}

void imprimir(Multa *m){
    printf("\n\n========= RESULTADO =========\n");
    printf("Peso dos peixes: %.2lfkg\n", m->pesoPeixes);
    printf("Peso dos peixes excedido: %.2lfkg\n", m->pesoExcedente);
    printf("Multa por kilo excedente: R$%.2lf\n", m->multaValor);
    printf("Multa final a pagar: R$%.2lf\n", m->multao);
    printf("=============================");
}

void calcular(Multa *m){
    m->multaValor = 4.0;
    m->pesoExcedente = m->pesoPeixes-50.0;
    m->multao = m->pesoExcedente*m->multaValor;
}

int processarMulta(){
    Multa *m = (Multa*)malloc(sizeof(Multa));
    if(m == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    ler(m);
    calcular(m);
    imprimir(m);
    free(m);
    return 0;
}

int main(){
    processarMulta();
    return 0;
}