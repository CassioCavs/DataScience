# Projeto de Análise de Algoritmos de Ordenação

## Introdução

O projeto visa determinar o algoritmo de ordenação mais eficiente entre Bubble Sort, Merge Sort e Quick Sort, utilizando inferência estatística. Os alunos terão a oportunidade de aprimorar habilidades em C, Python (Pandas, NumPy) e análise estatística.

## Grupo
Andrey Ranieri, Douglas Gobitsch, Cássio Cavalcante, Cauã Guerreiro e Henrique Velloso

## Objetivo

O principal objetivo é realizar uma análise estatística rigorosa para identificar o algoritmo mais eficaz. Isso inclui a implementação dos algoritmos em C, a coleta de dados de desempenho e a aplicação de testes estatísticos.

## Competências Desenvolvidas

1. **Programação em C:**
   - Implementação correta dos algoritmos.

2. **Gerenciamento de Dados:**
   - Coleta e armazenamento de dados.
   - Uso de estruturas de dados.

3. **Estatística:**
   - Análise descritiva, testes de hipótese e intervalos de confiança.

4. **Python (Pandas e NumPy):**
   - Importação e análise de dados.
   - Cálculos estatísticos.

5. **Compreensão de Algoritmos:**
   - Escolha apropriada de algoritmos em termos de eficiência.

6. **Comunicação e Apresentação:**
   - Elaboração de relatórios detalhados.
   - Apresentação clara dos resultados.

## Atividades

1. **Definição do Escopo:**
   - Identificação de tamanhos de amostra e perfis de hardware a serem considerados.

2. **Implementação em C:**
   - Garantir que Bubble Sort, Merge Sort e Quick Sort estejam funcionando corretamente.

3. **Coleta de Dados:**
   - Execução dos algoritmos para diferentes tamanhos de amostra (por exemplo, 100, 1000, 10000 elementos).
   - Registro do tempo de processamento (em microssegundos) para cada execução.
   - Registro detalhado do hardware: tipo de processador, quantidade de RAM e sistema operacional.

4. **Armazenamento em Banco de Dados:**
   - Configuração de um banco de dados para armazenar os dados coletados.
   - Criação de tabelas para armazenar resultados de tempo de processamento e informações do hardware.
   - Garantir que os registros tenham um identificador único.

5. **Análise Inicial dos Dados:**
   - Utilização do Python para importar os dados do banco de dados em um DataFrame do Pandas.
   - Realização de uma análise inicial dos dados, calculando médias, desvios padrão e outras estatísticas descritivas para cada algoritmo e tamanho de amostra.

6. **Testes de Hipótese:**
   - Comparação do desempenho dos algoritmos.
   - Registro dos resultados dos testes de hipótese.

7. **Cálculo de Intervalos de Confiança:**
   - Cálculo de intervalos de confiança para os tempos de processamento de cada algoritmo.
   - Avaliação da precisão das medições.
   
8. **Preparação de Relatórios e Apresentações:**
   - Elaboração de relatórios detalhados descrevendo resultados, análises estatísticas e conclusões.
   - Preparação de apresentação para compartilhar os resultados com a turma.
--- 

**Resultados:**
### Hardware 1

| Nome Algoritmo | Tam Dado | Média    | Desvio Padrão | Mínimo  | Máximo  | Quantidade |
|----------------|----------|----------|---------------|---------|---------|------------|
| Bubble Sort    | 100      | 0.052297 | 0.004201      | 0.04691 | 0.06049 | 20         |
| Bubble Sort    | 1000     | 0.373720 | 0.023253      | 0.33580 | 0.42230 | 10         |
| Bubble Sort    | 10000    | 2.973900 | 0.079668      | 2.91800 | 3.16800 | 10         |
| Bubble Sort    | 100000   | 6.542400 | 0.096843      | 6.43800 | 6.71700 | 10         |
| Merge Sort     | 100      | 0.055168 | 0.002621      | 0.05014 | 0.05900 | 20         |
| Merge Sort     | 1000     | 0.355460 | 0.009169      | 0.34050 | 0.36720 | 10         |
| Merge Sort     | 10000    | 2.871300 | 0.024887      | 2.83900 | 2.91300 | 10         |
| Merge Sort     | 100000   | 6.371500 | 0.062188      | 6.30300 | 6.49300 | 10         |
| Quick Sort     | 100      | 0.055002 | 0.003852      | 0.05080 | 0.06508 | 20         |
| Quick Sort     | 1000     | 0.365550 | 0.012945      | 0.34860 | 0.39840 | 20         |
| Quick Sort     | 10000    | 2.907500 | 0.065939      | 2.83000 | 3.10600 | 20         |
| Quick Sort     | 100000   | 6.516550 | 0.044697      | 6.44800 | 6.59700 | 20         |

### Hardware 2

| Nome Algoritmo | Tam Dado | Média      | Desvio Padrão | Mínimo  | Máximo  | Quantidade |
|----------------|----------|------------|---------------|---------|---------|------------|
| Bubble Sort    | 10000    | 4.630800   | 0.581851      | 4.033   | 5.445   | 10         |
| Bubble Sort    | 100000   | 9.046300   | 0.627223      | 8.657   | 10.810  | 10         |
| Merge Sort     | 10000    | 4.321400   | 0.382211      | 4.059   | 5.232   | 10         |
| Quick Sort     | 100000   | 145.466667 | 13.005640     | 126.900 | 160.000 | 6          |
