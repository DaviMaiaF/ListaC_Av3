#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fun��o para verificar se a entrada � um n�mero
int isNumber(char c) {
    return (c >= '0' && c <= '9');
}

// Fun��o para verificar a autoriza��o com base no �ltimo d�gito da placa e no dia da semana
int verificarAutorizacao(char placa[], char diaSemana[]) {
    int tam = strlen(placa);
    if (tam < 7) {
        printf("Placa inv�lida.\n");
        return 0;
    }

    char ultimoDigito = placa[tam - 1];

    if (!isNumber(ultimoDigito)) {
        printf("Placa inv�lida. O �ltimo caractere da placa n�o � um n�mero.\n");
        return 0;
    }

    int digito = ultimoDigito - '0';

    // Converte o nome do dia da semana para min�sculas para compara��o sem distin��o entre mai�sculas e min�sculas
    char diaSemanaLower[20];  // Array com espa�o suficiente para armazenar a string convertida para min�sculas
    for (int i = 0; diaSemana[i] && i < sizeof(diaSemanaLower) - 1; i++) {
        diaSemanaLower[i] = tolower(diaSemana[i]);
        diaSemanaLower[i + 1] = '\0';  // Garante que a string seja terminada corretamente
    }

    // Verificar se o carro pode circular com base no �ltimo d�gito e no dia da semana
    if ((strcasecmp(diaSemanaLower, "segunda-feira") != 0 || (digito != 0 && digito != 1)) &&
        (strcasecmp(diaSemanaLower, "terca-feira") != 0 || (digito != 2 && digito != 3)) &&
        (strcasecmp(diaSemanaLower, "quarta-feira") != 0 || (digito != 4 && digito != 5)) &&
        (strcasecmp(diaSemanaLower, "quinta-feira") != 0 || (digito != 6 && digito != 7)) &&
        (strcasecmp(diaSemanaLower, "sexta-feira") != 0 || (digito != 8 && digito != 9))) {
        return 1; // Autorizado
    } else {
        return 0; // N�o autorizado
    }
}

int main() {
    char placa[20];
    char diaSemana[20];

    printf("Digite a placa do carro: ");
    scanf("%19s", placa);  // Limita a leitura a 19 caracteres para evitar estouro de buffer

    printf("Digite o dia da semana: ");
    scanf("%19s", diaSemana);  // Limita a leitura a 19 caracteres para evitar estouro de buffer

    int autorizado = verificarAutorizacao(placa, diaSemana);

    if (autorizado) {
        printf("Autorizado a circular neste dia.\n");
    } else {
        if (strcasecmp(diaSemana, "sabado") == 0 || strcasecmp(diaSemana, "domingo") == 0) {
            printf("N�o existe proibi��o neste dia (fim de semana).\n");
        } else {
            printf("N�o autorizado a circular neste dia ou dia da semana n�o reconhecido.\n");
        }
    }

    return 0;
}

