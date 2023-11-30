// ALGORITIMO PARA ORDENAÇÂO MERGE SORT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

// Função de mesclagem para o Merge Sort
void merge(char **arr, int left, int mid, int right, char **temp) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criar arrays temporários
    char **leftArr = (char **)malloc(n1 * sizeof(char *));
    char **rightArr = (char **)malloc(n2 * sizeof(char *));

    // Copiar dados para os arrays temporários leftArr[] e rightArr[]
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Mesclar os arrays temporários de volta em arr[left..right]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = left; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        double numLeft, numRight;
        sscanf(leftArr[i], "%lf", &numLeft);
        sscanf(rightArr[j], "%lf", &numRight);

        if (numLeft <= numRight) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de leftArr[], se houver algum
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de rightArr[], se houver algum
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Liberar memória dos arrays temporários
    free(leftArr);
    free(rightArr);
}

// Função de ordenação Merge Sort
void mergeSort(char **arr, int left, int right, char **temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Classificar a primeira e a segunda metades
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);

        // Mesclar as metades classificadas
        merge(arr, left, mid, right, temp);
    }
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

    // Criar array temporário para uso no Merge Sort
    char **temp = (char **)malloc(numLines * sizeof(char *));

    // Ordenar as linhas usando o Merge Sort
    mergeSort(lines, 0, numLines - 1, temp);

    // Imprimir as linhas ordenadas
    printf("Linhas ordenadas:\n");
    for (int i = 0; i < numLines; i++) {
        printf("%s", lines[i]);
    }

    // Liberar a memória alocada
    free(temp);
    freeLines(lines, numLines);

    return 0; // Encerrar o programa com código de sucesso
}

