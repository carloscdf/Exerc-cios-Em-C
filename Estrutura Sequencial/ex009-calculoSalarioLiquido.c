/*
Faça um Programa que pergunte quanto você ganha por hora e o número de horas 
trabalhadas no mês. Calcule e mostre o total do seu salário no referido mês, 
sabendo-se que são descontados:
- 11% para o Imposto de Renda (IR)
- 8% para o INSS
- 5% para o Sindicato

O programa deve mostrar:
+ Salário Bruto : R$
- IR (11%)      : R$
- INSS (8%)     : R$
- Sindicato (5%): R$
= Salário Líquido: R$
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Descontos{
    double ir;
    double inss;
    double sindicato;
} Descontos;

typedef struct FolhaPagamento{
    double valorHora;
    int horasTrabalhadas;
    double salarioBruto;
    double pagoIr;
    double pagoInss;
    double pagoSindicato;
    double salarioLiquido;
} FolhaPagamento;

void ler(FolhaPagamento *fp){
    printf("Digite quanto voce ganha por hora: ");
    scanf("%lf", &fp->valorHora);
    printf("Digite quantas foram as horas trabalhadas: ");
    scanf("%d", &fp->horasTrabalhadas);
}

void imprimir(FolhaPagamento *fp, Descontos *d){
    printf("\n\n========= RESULTADO =========\n");
    printf("Valor da hora: R$%.2lf\n", fp->valorHora);
    printf("Horas trabalhadas: %d\n", fp->horasTrabalhadas);
    printf("Salario bruto: R$%.2lf\n", fp->salarioBruto);
    printf("Valor pago ao Imposto de Renda (%.2lf%%): R$%.2lf\n", d->ir, fp->pagoIr);
    printf("Valor pago ao INSS (%.2lf%%): R$%.2lf\n", d->inss, fp->pagoInss);
    printf("Valor pago ao Sindicato (%.2lf%%): R$%.2lf\n", d->sindicato, fp->pagoSindicato);
    printf("Salario liquido: R$%.2lf\n", fp->salarioLiquido);
    printf("=============================");
}

void calcularSalario(FolhaPagamento *fp, Descontos *d){
    d->ir = 11;
    d->inss = 8;
    d->sindicato = 5;
    fp->salarioBruto = fp->valorHora*fp->horasTrabalhadas;
    fp->pagoIr = fp->salarioBruto * (d->ir/100);
    fp->pagoInss = fp->salarioBruto * (d->inss/100);
    fp->pagoSindicato = fp->salarioBruto * (d->sindicato/100);
    fp->salarioLiquido = fp->salarioBruto - (fp->pagoIr + fp->pagoInss + fp->pagoSindicato); 
}


int processarSalarioLiquido(){
    FolhaPagamento *fp = (FolhaPagamento*)malloc(sizeof(FolhaPagamento));
    Descontos *d = (Descontos*)malloc(sizeof(Descontos));
    if(fp == NULL){
        printf("\n\nAlocação de FolhaPagamento falhou");
        return 1;
    }
    if(d == NULL){
        printf("\n\nAlocação de Descontos falhou");
        return 1;
    }
    ler(fp);
    calcular(fp, d);
    imprimir(fp, d);
    free(d);
    free(fp);
    return 0;
}

int main(){
    processarSalarioLiquido();
    return 0;
}
