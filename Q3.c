#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a entrada é um número
int isNumber(char c) {
    return (c >= '0' && c <= '9');
}

// Função para verificar a autorização com base no último dígito da placa e no dia da semana
int verificarAutorizacao(char placa[], char diaSemana[]) {
    int tam = strlen(placa);

    char ultimoDigito = placa[tam - 1];
    int digito = ultimoDigito - '0';

    // Verificar se o carro pode circular com base no último dígito e no dia da semana
    if ((strcmp(diaSemana, "SEGUNDA-FEIRA") == 0 && (digito == 0 || digito == 1)) ||
        (strcmp(diaSemana, "TERCA-FEIRA") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(diaSemana, "QUARTA-FEIRA") == 0 && (digito == 4 || digito == 5)) ||
        (strcmp(diaSemana, "QUINTA-FEIRA") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(diaSemana, "SEXTA-FEIRA") == 0 && (digito == 8 || digito == 9))) {
        return 0; // Não autorizado
    } else {
        return 1; // Autorizado para outros casos
    }
}

int main() {
    char placa[20];
    char diaSemana[20];

    printf("Digite a placa do carro: ");
    scanf("%19s", placa);  // Limita a leitura a 19 caracteres para evitar estouro de buffer

    printf("Digite o dia da semana: ");
    scanf("%19s", diaSemana);

    // Converte o nome do dia da semana para maiúsculas
    for (int i = 0; diaSemana[i]; i++) {
        diaSemana[i] = toupper(diaSemana[i]);
    }
    
    // Verifica se a placa tem um formato válido
    if (!((strlen(placa) == 7 || strlen(placa) == 8) &&
          (isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
           isNumber(placa[strlen(placa) - 1])))) {
        printf("Placa invalida\n");    
        return 0;
    }
    
    // Verifica se o nome do dia da semana é válido
    if (strcmp(diaSemana, "SEGUNDA-FEIRA") != 0 &&
        strcmp(diaSemana, "TERCA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUARTA-FEIRA") != 0 &&
        strcmp(diaSemana, "QUINTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SEXTA-FEIRA") != 0 &&
        strcmp(diaSemana, "SABADO") != 0 &&
        strcmp(diaSemana, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    int autorizado = verificarAutorizacao(placa, diaSemana);

    if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("%s Nao ha proibicao no fim de semana\n", placa, diaSemana);
    } else if (autorizado) {
        printf("%s pode circular %s\n", placa, diaSemana);
    } else {
        printf("%s nao pode circular %s\n", placa, diaSemana);
    }
    
    return 0;
}

