//Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. Calcule e mostre o total do seu salário no referido mês.
#include <stdio.h>
#include <stdlib.h>

typedef struct salarioMes{
    double valorHora;
    double qtdHorasTrabalhadas;
    double salario;
} salarioMes;

void imprimirSalario(salarioMes *sal);
int calcSalario(double valorHora, double qtdHorasTrabalhadas);

void lerValores(){
    double valorHora;
    double qtdHorasTrabalhadas;
    printf("Digite o valor da hora: ");
    scanf("%lf", & valorHora);
    printf("Digite a quantidade de horas trabalhadas: ");
    scanf("%lf", &qtdHorasTrabalhadas);
    calcSalario(valorHora, qtdHorasTrabalhadas);
}

int calcSalario(double valorHora, double qtdHorasTrabalhadas){
    salarioMes *sal = (salarioMes*)malloc(sizeof(salarioMes));
    if(sal == NULL){
        printf("\n\nAlocação de memória falhou");
        return 1;
    }
    sal->valorHora = valorHora;
    sal->qtdHorasTrabalhadas = qtdHorasTrabalhadas;
    sal->salario = sal->valorHora*sal->qtdHorasTrabalhadas;
    imprimirSalario(sal);
    return 0;
}

void imprimirSalario(salarioMes *sal){
    printf("\n\n========= RESULTADO =========\n");
    printf("Valor da hora: %.2lf\n", sal->valorHora);
    printf("Quantidade de horas trabalhadas: %.2lf\n", sal->qtdHorasTrabalhadas);
    printf("Salario a receber no mes: R$%.2lf\n", sal->salario);
    printf("=============================");
    free(sal);
}

int main(){
    lerValores();
    return 0;
}