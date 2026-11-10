# 🎳 Red-Black Bowling

O **Red-Black Bowling** é um jogo educativo voltado para o ensino de **Árvores Rubro-Negras**, desenvolvido para a disciplina de **Estruturas de Dados II** do curso de Ciência da Computação.

O projeto tem como referência o simulador interativo de Árvores Rubro-Negras do **Virtual Labs**, desenvolvido pelo **IIIT Hyderabad** (*International Institute of Information Technology, Hyderabad, Índia*), acessível em:  
🔗 [Simulador Virtual Labs - IIIT Hyderabad](https://ds2-iiith.vlabs.ac.in/exp/red-black-tree/red-black-tree-oprations/simulation/redblack.html)

---

## 📖 Sobre o Projeto

O objetivo principal do **Red-Black Bowling** é transformar conceitos teóricos e complexos de Árvores Rubro-Negras em uma experiência dinâmica e interativa. 

Para isso, o jogo emprega uma mecânica temática inspirada no boliche: cada bola lançada representa um novo valor que deve ser inserido na árvore. Durante a partida, o jogador abandona a posição passiva de mero observador e assume o controle ativo das decisões de inserção, verificação de conflitos e rebalanceamento da estrutura.

### Engenharia Reversa e Inovação Pedagógica
O desenvolvimento partiu de uma proposta de engenharia reversa e reuso de modelos a partir de ferramentas educacionais existentes (como o visualizador do *IIIT Hyderabad*). 

Enquanto os simuladores tradicionais realizam as operações de forma automatizada — onde o usuário apenas assiste à construção —, o Red-Black Bowling introduz um **upgrade funcional e pedagógico**: o jogador precisa analisar ativamente os casos de conflito (como a cor do tio), escolher entre recoloração e rotação, e aplicar as regras fundamentais da estrutura para garantir que a árvore permaneça balanceada e válida.

## 🎯 Objetivo

O objetivo principal é permitir que o aluno compreenda, de forma prática e visual, como funciona o **balanceamento de uma Árvore Rubro-Negra**.

Em vez de apenas visualizar uma árvore sendo construída, o jogador precisa:

* decidir o caminho de inserção de cada valor;
* identificar conflitos entre nós vermelhos;
* analisar a cor do tio;
* escolher entre **recoloração** e **rotação**;
* manter as propriedades da Árvore Rubro-Negra durante a partida.

Dessa forma, conceitos teóricos de ED II são transformados em decisões realizadas diretamente pelo jogador.

---

## 🔎 Engenharia Reversa e Modelo Reutilizado

### Modelo utilizado

O projeto utiliza como referência a ideia de **visualizadores e jogos educativos de estruturas de dados**, nos quais operações de árvores são representadas visualmente para facilitar sua compreensão.

A proposta da atividade solicita justamente a análise de um jogo ou visualizador existente e seu aprimoramento por meio de uma nova mecânica baseada em estruturas avançadas.

### Limitação identificada

Uma limitação desse tipo de abordagem é que o usuário pode assumir uma posição predominantemente passiva, apenas observando as operações realizadas pela estrutura.

O **Red-Black Bowling** procura transformar esse processo em uma decisão ativa.

Quando ocorre um conflito na árvore, o jogador precisa analisar a situação e escolher a operação de correção adequada.

Assim, o aluno não apenas observa o balanceamento: ele precisa **identificar o caso e tomar a decisão**.

---

## 🌳 Estrutura de Dados

A estrutura escolhida para o projeto é a:

**Árvore Rubro-Negra (Red-Black Tree)**

A atividade define que o upgrade baseado nessa estrutura deve trabalhar conceitos como:

* propriedades das cores dos nós;
* altura-preta;
* recoloramento;
* rotações.

No jogo, esses conceitos são utilizados diretamente na mecânica.

---

## 🎮 Mapeamento: ED II → Gameplay

| Conceito de ED II          | No jogo                                                                |
| -------------------------- | ---------------------------------------------------------------------- |
| Nó / chave                 | Cada bola lançada representa um novo valor que será inserido na árvore |
| Inserção                   | O jogador lança uma bola e acompanha sua inserção na árvore            |
| Árvore de Busca Binária    | O jogador decide se o valor deve seguir para a esquerda ou direita     |
| Cor do nó                  | Cada pino possui uma cor: vermelho ou preto                            |
| Conflito vermelho-vermelho | Situação que exige uma decisão do jogador                              |
| Tio                        | Nó destacado para auxiliar na identificação do caso de balanceamento   |
| Recoloração                | Ação escolhida quando o tio é vermelho                                 |
| Rotação                    | Ação escolhida quando o tio é preto ou nulo                            |
| Altura-preta               | Utilizada como multiplicador da pontuação                              |
| Vidas                      | Penalização pelas decisões incorretas                                  |
| Pontuação                  | Recompensa pelas decisões corretas e pelo balanceamento da árvore      |

Essa tradução dos conceitos teóricos em ações de gameplay corresponde diretamente à proposta da atividade, que exige que as propriedades da estrutura sejam utilizadas como mecânicas ativas do jogo.

---

## 🔄 Core Loop

O ciclo principal do jogo funciona da seguinte maneira:

```text
Lançar bola
     ↓
Inserir valor na árvore
     ↓
Escolher caminho
(esquerda / direita)
     ↓
Verificar propriedades da
Árvore Rubro-Negra
     ↓
Conflito?
   ↙       ↘
 Não       Sim
 ↓          ↓
Continuar   Analisar o tio
              ↓
       ┌──────┴──────┐
       ↓             ↓
   Tio vermelho   Tio preto/nulo
       ↓             ↓
   Recolorir       Rotacionar
       └──────┬──────┘
              ↓
       Árvore balanceada
              ↓
          Pontuação
              ↓
        Próxima bola
```

O jogador repete esse processo até completar as cinco bolas ou perder todas as vidas.

---

## 🧠 Regras utilizadas

O jogo trabalha principalmente com as propriedades fundamentais da Árvore Rubro-Negra:

### 1. Cores

Cada nó possui uma das duas cores:

* 🔴 Vermelho
* ⚫ Preto

### 2. Conflito vermelho-vermelho

Um nó vermelho não pode possuir um filho vermelho.

Quando essa situação aparece durante uma inserção, o jogo interrompe o fluxo e solicita uma decisão do jogador.

### 3. Altura-preta

Os caminhos da raiz até as folhas devem manter a mesma quantidade de nós pretos.

A altura-preta também participa do sistema de pontuação do jogo.

### 4. Rebalanceamento

Quando ocorre um conflito:

**Tio vermelho → Recolorir**

**Tio preto ou nulo → Rotacionar**

Essas regras são apresentadas ao jogador durante a partida.

---

## 🏆 Sistema de Pontuação

O jogo possui um sistema de pontuação para incentivar decisões corretas.

### Recoloração

Uma recoloração correta concede:

**+15 pontos**

### Rotação

Uma rotação correta concede:

**+25 pontos**

### Bola completa

Após o balanceamento da árvore, a pontuação da bola considera a altura-preta:

```text
Pontuação = pontuação base × altura-preta
```

Uma bola concluída sem erros recebe uma pontuação base maior.

Essas regras estão implementadas diretamente na lógica do jogo.

---

## ❤️ Sistema de Vidas

O jogador começa com:

**❤️ ❤️ ❤️ — 3 vidas**

Uma decisão incorreta resulta na perda de uma vida.

Caso todas as vidas sejam perdidas, a partida termina.

O sistema de vidas cria uma consequência para decisões incorretas e transforma o conhecimento da estrutura em uma parte necessária para avançar no jogo.

---

## 🏆 Condição de Vitória

O jogador vence ao inserir e balancear corretamente as **5 bolas**, mantendo as propriedades da Árvore Rubro-Negra.

Ao final, o jogo apresenta a pontuação obtida.

---

## 💥 Condição de Derrota

O jogador perde quando suas **3 vidas são esgotadas** devido a decisões incorretas.

A condição de derrota está relacionada diretamente às regras da estrutura: erros na navegação ou no processo de balanceamento prejudicam a construção correta da árvore.

Essa relação entre a falha do jogador e a quebra das regras da estrutura atende ao objetivo da atividade de associar a condição de derrota à degradação ou violação das propriedades algorítmicas.

---

## ⚙️ Tecnologias utilizadas

* **HTML5**
* **CSS3**
* **JavaScript**
* **SVG**
* **LocalStorage**

Não são necessárias bibliotecas ou frameworks externos para executar o projeto.

---

## ▶️ Como executar

O projeto é uma aplicação web estática.

Para executar:

1. Baixe ou clone o projeto.
2. Abra o arquivo:

```text
red_black_bowling.html
```

3. Execute o arquivo em um navegador moderno.

Não é necessário instalar dependências.

---

## 📂 Estrutura do projeto

Atualmente, o projeto está concentrado em um único arquivo:

```text
Red-Black-Bowling/
└── red_black_bowling.html
```

Dentro do arquivo estão implementados:

* interface do jogo;
* estilização;
* modelo da Árvore Rubro-Negra;
* inserção de nós;
* rotações;
* recoloração;
* renderização da árvore;
* sistema de pontuação;
* sistema de vidas;
* recorde;
* fluxo da partida.

---

## 👨‍🏫 Contexto da Atividade

Este projeto foi desenvolvido para a atividade prática de **Design de Jogos de ED II**, cujo objetivo é aplicar conceitos de Estruturas de Dados II no design de jogos educativos.

A atividade propõe que os estudantes atuem como **Game Designers especializados em softwares educativos**, realizando engenharia reversa de um modelo existente e criando uma melhoria funcional ou pedagógica baseada em Árvores AVL, Rubro-Negras ou B/B+.

Neste projeto, a estrutura escolhida foi a **Árvore Rubro-Negra**, e seus conceitos foram transformados em decisões e desafios dentro do gameplay.

## 👥 Integrantes

**Nome:** Pedro Paulo Rodrigues Cardoso, Tiago Alves Freire, Júlia Barreira de Carvalho, Guilherme Brito da Silva, Alísio Veleda Tavazes Neto, Giovanna Nascimento Lima, isablea Cristina Araujo

**Disciplina:** Estruturas de Dados II

**Curso:** Ciência da Computação

**Professora:** Kadidja Valéria

**Ano:** 2026
