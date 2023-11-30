import pandas as pd
from scipy.stats import ttest_ind , t


caminho_do_csv = r"C:\Users\hvell\Desktop\cesupa\.py\teste_hip\dados_do_banco.csv"
df = pd.read_csv(caminho_do_csv)

algoritmo1 = 'Quick Sort'
algoritmo2 = 'Merge Sort'


dados_algoritmo1 = df[df['nome_algoritmo'] == algoritmo1]['temp_exec']
dados_algoritmo2 = df[df['nome_algoritmo'] == algoritmo2]['temp_exec']

graus_de_liberdade = len(dados_algoritmo1) + len(dados_algoritmo2) - 2
alpha = 0.05

statistic, p_value = ttest_ind(dados_algoritmo1, dados_algoritmo2)

intervalo_confianca = t.interval(1 - alpha, graus_de_liberdade, loc=dados_algoritmo1.mean() - dados_algoritmo2.mean(),
                                 scale=((dados_algoritmo1.std()**2 / len(dados_algoritmo1)) + (dados_algoritmo2.std()**2 / len(dados_algoritmo2)))**0.5)

print(f"Intervalo de Confiança para a Diferença das Médias: {intervalo_confianca}")


if p_value < alpha:
    print(f"Rejeitar a hipótese nula. Há evidência suficiente para sugerir que os tempos de execução de {algoritmo1} e {algoritmo2} são diferentes.")
else:
    print(f"Não há evidência suficiente para sugerir que os tempos de execução de {algoritmo1} e {algoritmo2} são diferentes.")

