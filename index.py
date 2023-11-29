import pandas as pd
from sqlalchemy import create_engine

# Defina a URL de conexão do banco de dados
DATABASE_URL = "postgresql://postgres:1234@localhost/projeto giras"

# Crie uma instância de Engine
engine = create_engine(DATABASE_URL)

# Execute uma consulta SQL bruta
query = """
    SELECT Resultado.id, Resultado.nome_algoritmo, Resultado.tam_dado, Resultado.temp_exec, Result_Hard.hardware_id
    FROM Resultado
    JOIN Result_Hard ON Resultado.id = Result_Hard.resultado_id
    WHERE Result_Hard.hardware_id = 2;
"""

# Execute a consulta e obtenha os resultados em um DataFrame do pandas
df = pd.read_sql(query, engine)

# Salve o DataFrame em um arquivo CSV
df.to_csv('dados_do_bancoid2.csv', index=False)
