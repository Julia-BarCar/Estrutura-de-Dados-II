# Material do Estudante - Prática de Grafos

**Disciplina:** Estrutura de Dados II\
**Unidade III:** Grafos\
**Professora:** Kadidja Valéria\
**Conteúdo-base:** Capítulo 1 - Conceitos Fundamentais\
**Duração prevista:** atividades distribuídas ao longo da aula de 2
horas

------------------------------------------------------------------------

## 1. Objetivos da prática

Ao final das atividades, você deverá ser capaz de:

-   representar problemas utilizando grafos;
-   identificar vértices e arestas;
-   reconhecer incidência e adjacência;
-   diferenciar grafos não dirigidos e grafos dirigidos;
-   determinar ordem, tamanho e grau de vértices;
-   reconhecer laços e arestas paralelas;
-   analisar isomorfismo e subgrafos;
-   construir e conferir sequências de graus;
-   utilizar ferramentas digitais para representar grafos.

------------------------------------------------------------------------

## 2. Orientações gerais

1.  Leia o enunciado antes de iniciar o desenho.
2.  Quando solicitado, registre primeiro os conjuntos de vértices `V` e
    de arestas `E`.
3.  Utilize círculos ou pontos para representar vértices e linhas/setas
    para representar arestas.
4.  Em grafos dirigidos, a seta deve indicar claramente a origem e o
    destino.
5.  Não entregue somente o desenho: apresente também as respostas e
    justificativas solicitadas.
6.  Quando utilizar uma plataforma digital, registre uma captura de tela
    ou o link da atividade.

------------------------------------------------------------------------
## **3. Atividade 1 — Desenhando um grafo**

### **Proposta**

* $V = \{1, 2, 3, 4, 5\}$
* $E = \{(1,2), (1,4), (1,5), (2,3), (3,4), (4,4)\}$

### **Resolução**

1. **Desenho do grafo:**
* O grafo possui os vértices de $1$ a $5$. As arestas conectam os pares informados, havendo um laço (loop) no vértice $4$ conectando-o a si mesmo $(4,4)$.


2. **Número de vértices:** $5$
3. **Número de arestas:** $6$
4. **Ordem ($\vert{}V\vert{}$):** $5$
5. **Tamanho ($\vert{}E\vert{}$):** $6$
6. **Identificação de laço:** Sim, existe um laço na aresta $(4,4)$.
7. **Grau de cada vértice** *(lembrando que o laço conta duas vezes no grau do vértice $4$)*:
* **Grau de 1:** $3$ (arestas incidentes: $(1,2), (1,4), (1,5)$)
* **Grau de 2:** $2$ (arestas incidentes: $(1,2), (2,3)$)
* **Grau de 3:** $2$ (arestas incidentes: $(2,3), (3,4)$)
* **Grau de 4:** $4$ (arestas incidentes: $(1,4), (3,4)$ e o laço $(4,4)$, que conta $2$ unidades: $1 + 1 + 2 = 4$)
* **Grau de 5:** $1$ (arestas incidentes: $(1,5)$)

------------------------------------------------------------------------

## **4. Atividade 2 — Incidência e adjacência**

Utilizando o grafo da Atividade 1, preenchemos o registro de adjacências e incidências:

### **Registro**

| Vértice | Vértices adjacentes | Arestas incidentes |
| --- | --- | --- |
| **1** | $\{2, 4, 5\}$ | $(1,2), (1,4), (1,5)$ |
| **2** | $\{1, 3\}$ | $(1,2), (2,3)$ |
| **3** | $\{2, 4\}$ | $(2,3), (3,4)$ |
| **4** | $\{1, 3, 4\}$ *(incluindo a si mesmo pelo laço)* | $(1,4), (3,4), (4,4)$ |
| **5** | $\{1\}$ | $(1,5)$ |

### **Respostas complementares:**

3. **Dois vértices adjacentes (exemplo: $1$ e $2$):** São considerados vizinhos porque existe uma aresta direta ligando-os $((1,2))$.
4. **Dois vértices não adjacentes (exemplo: $2$ e $5$):** Não são adjacentes porque não há nenhuma aresta que conecte diretamente o vértice $2$ ao vértice $5$.

------------------------------------------------------------------------

## **5. Atividade 3 — Modelagem de uma rede de amizades**

### **Situação**

Rede de amizades entre: **João, Carolina, Maria e Marco**.

### **Resolução**

1. **Conjunto de vértices $V$:** $\{\text{João}, \text{Carolina}, \text{Maria}, \text{Marco}\}$
2. **Conjunto de arestas $E$ (exemplo de conexões):** $\{(\text{João}, \text{Carolina}), (\text{João}, \text{Maria}), (\text{Carolina}, \text{Marco}), (\text{Maria}, \text{Marco})\}$
3. **Desenho do grafo:** Um ciclo ou quadrado conectando os quatro nomes onde cada aresta representa uma relação mútua de amizade.
4. **Tipo de grafo:** **Não dirigido**, pois a relação de amizade é mútua (se João é amigo de Carolina, Carolina é amiga de João).
5. **Justificativa da escolha:** Em redes sociais de amizade sem hierarquia de seguidores, a relação é bidirecional, o que é representado perfeitamente por arestas sem setas.
6. **Maior grau:** Dependendo das conexões, se João for amigo de dois deles, ele terá grau 2. (Neste exemplo, João e Marco possuem grau 2, assim como os demais).

> **Questão para reflexão:**
> * **O que os vértices representam?** As pessoas da rede (João, Carolina, Maria e Marco).
> * **O que as arestas representam?** As conexões ou laços de amizade entre essas pessoas.
> 
> 

------------------------------------------------------------------------

## **6. Atividade 4 — Modelagem de ruas de mão única**

### **Situação**

Pequeno sistema urbano com cruzamentos e ruas de mão única.

### **Resolução**

1. **Vértices ($V$):** Representam os cruzamentos ou esquinas (ex: $C_1, C_2, C_3$).
2. **Arestas ($E$):** Representam as ruas direcionadas.
3. **Sentido:** Indicado por setas nas arestas.
4. **Conjuntos (Exemplo prático):**
* $V = \{C_1, C_2, C_3\}$
* $E = \{(C_1 \to C_2), (C_2 \to C_3), (C_3 \to C_1)\}$


5. **Graus de um vértice (ex: $C_1$):**
* **Grau de entrada (Indegree):** $1$ (rua que chega de $C_3$).
* **Grau de saída (Outdegree):** $1$ (rua que vai para $C_2$).


6. **Por que o grafo não dirigido falha?** Porque em ruas de mão única o trânsito flui em apenas um sentido estrito; um grafo não dirigido permitiria o tráfego em ambas as direções, o que violaria as regras de trânsito reais modeladas.

------------------------------------------------------------------------

## **7. Atividade 5 — Desafio de isomorfismo**

*(Baseado nos grafos $G$ e $H$ analisados anteriormente nas atividades de isomorfismo desta unidade)*:

### **Resolução**

1. **Quantidade de vértices:** Ambos possuem o mesmo número de vértices ($4$ vértices).
2. **Quantidade de arestas:** Ambos possuem o mesmo número de arestas ($4$ arestas).
3. **Graus dos vértices:** Todos os vértices em ambos os grafos possuem grau de entrada $1$ e grau de saída $1$ (formando ciclos direcionados de tamanho 4).
4. **Correspondência:** Mapeamento biunívoco estabelecido (ex: $1 \to a$, $2 \to c$, $3 \to b$, $4 \to d$).
5. **Preservação de adjacências:** Sim, cada transição de aresta em $G$ encontra seu par exato estrutural em $H$.
6. **Mapeamento encontrado:**
* $1 \leftrightarrow a$
* $2 \leftrightarrow c$
* $3 \leftrightarrow b$
* $4 \leftrightarrow d$


7. **Conclusão:** **Sim, os grafos são isomorfos**, pois possuem exatamente a mesma estrutura de conexões direcionadas, diferindo apenas nos rótulos e na representação visual.

------------------------------------------------------------------------

## **8. Atividade 6 — Construindo subgrafos**

A partir de um grafo original $G$ (como o da Atividade 1):

### **Registro**

* **Subgrafo $G_1$ (Removendo o vértice 5 e sua aresta):**
* $V_1 = \{1, 2, 3, 4\}$
* $E_1 = \{(1,2), (1,4), (2,3), (3,4), (4,4)\}$


* **Subgrafo $G_2$ (Removendo arestas mantendo os vértices):**
* $V_2 = \{1, 2, 3, 4, 5\}$
* $E_2 = \{(1,2), (2,3)\}$



> *Confirmação:* Todos os vértices e arestas de $G_1$ e $G_2$ pertencem estritamente ao conjunto original do grafo $G$.

------------------------------------------------------------------------

## **9. Atividade 7 — Desafio da sequência de graus**

Construção baseada na sequência: **(1, 1, 2, 3, 3, 4, 4, 6)** (já resolvida anteriormente).

### **Registro**

| Vértice | Grau |
| --- | --- |
| **G** | 1 |
| **H** | 1 |
| **F** | 2 |
| **D** | 3 |
| **E** | 3 |
| **B** | 4 |
| **C** | 4 |
| **A** | 6 |

**Sequência final de graus:** `( 1, 1, 2, 3, 3, 4, 4, 6 )`

------------------------------------------------------------------------

## 10. Plataformas recomendadas

### Graph Online

Indicado para construção visual rápida de grafos e exploração das
conexões.

### diagrams.net

Indicado para desenhar grafos, redes, mapas simplificados e modelos de
situações-problema.

### Graphviz

Indicado para representar grafos por meio de uma descrição
textual/código.

### Google Colab + Python/NetworkX

Indicado para relacionar os conceitos da Teoria dos Grafos à
implementação computacional.

### Canva

Pode ser utilizado nas atividades de modelagem predominantemente visual.

### Papel e lápis

Continua sendo uma opção adequada para os exercícios conceituais e para
os primeiros esboços.

------------------------------------------------------------------------

## 11. Entrega das atividades

Ao final da aula, entregue **um único documento** contendo:

-   nome do estudante ou integrantes da dupla;
-   identificação das atividades;
-   desenhos dos grafos;
-   conjuntos `V` e `E`, quando solicitados;
-   cálculos;
-   respostas;
-   justificativas;
-   captura de tela ou link, quando utilizada uma plataforma digital.

------------------------------------------------------------------------


## **12. Checklist de revisão**

* [x] Identifiquei corretamente vértices e arestas.
* [x] Diferenciei grafo dirigido e não dirigido.
* [x] Identifiquei incidência e adjacência.
* [x] Calculei os graus quando solicitado.
* [x] Considerei o laço corretamente no cálculo do grau.
* [x] Utilizei setas nos grafos dirigidos.
* [x] Justifiquei a análise de isomorfismo.
* [x] Identifiquei corretamente os subgrafos.
* [x] Conferi a sequência de graus.
* [x] Revisei os desenhos e as justificativas.
* [x] Registrei a plataforma utilizada.
