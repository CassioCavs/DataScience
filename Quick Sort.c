// ALGORITIMO PARA ORDENAÇÂO QUICK SORT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

// Função de comparação para o Quick Sort
int compare(const void *a, const void *b) {
    double numA, numB;
    sscanf(*(const char **)a, "%lf", &numA);
    sscanf(*(const char **)b, "%lf", &numB);

    if (numA < numB) return -1;
    if (numA > numB) return 1;
    return 0;
}

// Função para ler linhas do arquivo e armazená-las em um array
int readLinesFromFile(const char *filename, char ***lines, int *numLines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0; // Indica falha
    }

    // Contar o número de linhas no arquivo
    int count = 0;
    char buffer[SIZE]; // Ajuste conforme necessário
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }
    rewind(file);

    // Alocar memória para armazenar as linhas
    *lines = (char **)malloc(count * sizeof(char *));
    if (!*lines) {
        fclose(file);
        return 0; // Falha na alocação de memória
    }

    // Ler as linhas do arquivo
    for (int i = 0; i < count; i++) {
        (*lines)[i] = (char *)malloc(SIZE * sizeof(char)); // Ajuste conforme necessário
        if (!fgets((*lines)[i], SIZE, file)) {
            perror("Erro ao ler o arquivo");
            fclose(file);
            return 0; // Falha na leitura do arquivo
        }
    }

    fclose(file);
    *numLines = count;
    return 1; // Sucesso
}

// Função para liberar a memória alocada para as linhas
void freeLines(char **lines, int numLines) {
    for (int i = 0; i < numLines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    const char *filename = "dados_gerados.txt"; // Substitua pelo nome do seu arquivo

    char **lines;
    int numLines;

    if (!readLinesFromFile(filename, &lines, &numLines)) {
        return 1; // Encerrar o programa com código de erro
    }

    // Ordenar as linhas usando o Quick Sort
    qsort(lines, numLines, sizeof(char *), compare);

    // Imprimir as linhas ordenadas
    printf("Linhas ordenadas:\n");
    for (int i = 0; i < numLines; i++) {
        printf("%s", lines[i]);
    }

    // Liberar a memória alocada
    freeLines(lines, numLines);

    return 0; // Encerrar o programa com código de sucesso
}
