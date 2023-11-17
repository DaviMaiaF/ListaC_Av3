#include <stdio.h>
#include <string.h>

// Função para obter o valor de um caractere romano
int valor(char c) {
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    return -1;
}

// Função para converter o número romano para inteiro
int numeroRomanoParaInteiro(char *s) {
    int res = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int val1 = valor(s[i]);

        if (s[i + 1] != '\0') {
            int val2 = valor(s[i + 1]);

            if (val1 >= val2) {
                res = res + val1;
            } else {
                res = res + val2 - val1;
                i++;
            }
        } else {
            res = res + val1;
        }
    }

    return res;
}

// Função para converter número decimal para binário
void decimalParaBinario(int decimal) {
    int binario[1000];
    int i = 0;

    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void decimalParaHexadecimal(int decimal) {
    char hexadecimalNum[20];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10) {
            hexadecimalNum[index] = remainder + 48;
        } else {
            hexadecimalNum[index] = remainder + 87;
        }

        index++;
        decimal = decimal / 16;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimalNum[i]);
    }

    printf("\n");
}

int main() {
    char numeroRomano[20];
    scanf("%s", numeroRomano);
    int resultado = numeroRomanoParaInteiro(numeroRomano);
    printf("%s na base 2: ", numeroRomano);
    decimalParaBinario(resultado);
    printf("%s na base 10: %d\n", numeroRomano, resultado);
    printf("%s na base 16: ", numeroRomano);
    decimalParaHexadecimal(resultado);

    return 0;
}
