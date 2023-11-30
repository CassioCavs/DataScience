import pandas as pd

# Carregar os dados do CSV para um DataFrame
df = pd.read_csv('D:\codes\projetogiras\dados_do_bancoid2.csv')

# Visualizar as primeiras linhas do DataFrame
print(df.head())

# Calcular estatísticas descritivas para cada algoritmo e tamanho de amostra
estatisticas = df.groupby(['nome_algoritmo', 'tam_dado']).agg({
    'temp_exec': ['mean', 'std', 'min', 'max', 'count']
}).reset_index()

# Renomear as colunas para facilitar a interpretação
estatisticas.columns = ['nome_algoritmo', 'tam_dado', 'media', 'desvio_padrao', 'minimo', 'maximo', 'quantidade']

# Visualizar as estatísticas descritivas
print(estatisticas)
