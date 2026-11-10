# Trabalho em grupo - Grafos e amizades

Atividade de **Estrutura de Dados II** sobre a representação de relações de amizade com um **grafo simples e não direcionado**. O exercício utiliza como referência a rede social do material didático **ConectaUDF**.

## Integrantes

- Aloisio Veleda - https://github.com/aloisiodev-byt/Estrutura-de-Dados-II
- Giovanna Nascimento - https://github.com/giovannalima19/Estrutura_de_dados_II
- Guilherme Brito - https://github.com/Guilhermoviski/estrutura-de-dados-II
- Isabela Cristina - https://github.com/isawott/estruturas-dados-II
- Julia Barreira - https://github.com/Julia-BarCar/Estrutura-de-Dados-II
- Pedro Paulo - https://github.com/PedroPaulo-exe/Estrutura_de_Dados_II-Kadidja
- Tiago Freire - https://github.com/tiggofreire/estrutura-de-dados-II

## Proposta

A rede inicial tem **6 usuários e 8 amizades**. Sua ampliação, seguindo a orientação informada em sala, possui **35 vértices no total**, distribuídos em **7 núcleos de 5 vértices**. Na rede ampliada aparecem os sete integrantes, os seis usuários da rede inicial e 22 personagens fictícios. As amizades representadas são fictícias, usadas exclusivamente no exercício.

As oito amizades iniciais foram preservadas. A rede ampliada é conectada, não possui laços nem arestas duplicadas, e permite analisar graus, caminhos e recomendações por amigos em comum.

## Resultados

| Indicador | Rede original | Rede ampliada |
|---|---:|---:|
| Vértices | 6 | 35 |
| Arestas | 8 | 37 |
| Soma dos graus | 16 | 74 |
| Densidade | 53,33% | 6,22% |

A densidade diminuiu apesar do aumento de 29 amizades: a quantidade de pares possíveis passou de 15 para 595.

## Arquivos da entrega

- **`Relatorio_Grafos_Amizades.docx`**: relatório com identificação do grupo, dois desenhos, tabela de graus, cálculos, respostas e conclusão.
- **`grafos_amizades.py`**: programa Python com as redes original e ampliada, cálculos, busca de caminhos e sugestões de amizade.
- **`README.md`**: apresentação do trabalho e instruções de execução.

Os desenhos e a tabela de graus já estão incorporados ao documento Word. Não há dependência de PNGs, CSVs ou arquivos de testes separados.

## Como executar

Requisito: Python 3.9 ou superior, sem bibliotecas externas. Abra o terminal nesta pasta e execute:

```powershell
python grafos_amizades.py
```

O programa imprime o número de usuários, amizades, densidades, graus e análises da rede.

## Referência didática

Caderno do Estudante **Projeto ConectaUDF: redes sociais com grafos**, disponibilizado pela professora Kadidja Valéria. O nome **Grafos e amizades** identifica este trabalho em grupo e a ampliação para 35 vértices corresponde à orientação relatada em sala.
