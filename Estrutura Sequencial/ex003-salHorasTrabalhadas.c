//Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. Calcule e mostre o total do seu salário no referido mês.
#include <stdio.h>
#include <stdlib.h>

typedef struct SalarioMes{
    double valorHora;
    double qtdHorasTrabalhadas;
    double salario;
} SalarioMes;

void ler(SalarioMes *sal){
    printf("Digite o valor da hora: ");
    scanf("%lf", &sal->valorHora);
    printf("Digite a quantidade de horas trabalhadas: ");
    scanf("%lf", &sal->qtdHorasTrabalhadas);
}

void imprimir(SalarioMes *sal){
    printf("\n\n========= RESULTADO =========\n");
    printf("Valor da hora: %.2lf\n", sal->valorHora);
    printf("Quantidade de horas trabalhadas: %.2lf\n", sal->qtdHorasTrabalhadas);
    printf("Salario a receber no mes: R$%.2lf\n", sal->salario);
    printf("=============================");
}

void calcSalarioMes(SalarioMes *sal){
    sal->salario = sal->valorHora*sal->qtdHorasTrabalhadas;
}

int processarSalario(){
    SalarioMes *sal = (SalarioMes*)malloc(sizeof(SalarioMes));
    if(sal == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    ler(sal);
    calcSalarioMes(sal);
    imprimir(sal);
    free(sal);
    return 0;
}

int main(){
    processarSalario();
    return 0;
}