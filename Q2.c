#include <stdio.h>
#include <math.h>

// Função para calcular o valor do montante ao fim de cada mês
double calcularMontanteMensal(double aporte, double taxaJuros, int tempo) {
    double montante;
    montante = aporte * (1 + taxaJuros) * ((pow((1 + taxaJuros), tempo) - 1) / taxaJuros);
    return montante;
}

int main() {
    double aporte, taxaJuros;
    int tempo;

    // Entrada de dados
    printf("Digite o tempo em meses: ");
    scanf("%d", &tempo);
    
    printf("Digite o valor do aporte mensal: ");
    scanf("%lf", &aporte);

    printf("Digite a taxa de juros mensal (em decimal): ");
    scanf("%lf", &taxaJuros);

    // Cálculo e exibição do montante ao fim de cada mês
    for (int mes = 1; mes <= tempo; mes++) {
        double montante = calcularMontanteMensal(aporte, taxaJuros, mes);
        printf("Montante ao fim do mes %1d: R$ %.2f\n", mes, montante);
    }

    return 0;
}

