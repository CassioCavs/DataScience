// ALGORITIMO PARA ORDENAÇÂO BUBLLE SORT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

// Função para trocar duas strings
void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Função de comparação para ordenar números decimais em strings
int compare(const void *a, const void *b) {
    double num1, num2;
    sscanf(*(const char **)a, "%lf", &num1);
    sscanf(*(const char **)b, "%lf", &num2);
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    FILE *arquivo;
    char linha[SIZE];
    char *linhas[SIZE];
    int numLinhas = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("dados_gerados.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê as linhas do arquivo e armazena em um array de strings
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Remove o caractere de nova linha, se presente
        linha[strcspn(linha, "\n")] = 0;

        // Aloca memória para a linha e armazena no array
        linhas[numLinhas] = strdup(linha);

        // Incrementa o contador de linhas
        numLinhas++;
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Chama a função de ordenação
    qsort(linhas, numLinhas, sizeof(char *), compare);

    // Imprime as linhas ordenadas
    printf("Linhas ordenadas:\n");
    for (int i = 0; i < numLinhas; i++) {
        printf("%s\n", linhas[i]);

        // Libera a memória alocada para cada linha
        free(linhas[i]);
    }

    return 0;
}
