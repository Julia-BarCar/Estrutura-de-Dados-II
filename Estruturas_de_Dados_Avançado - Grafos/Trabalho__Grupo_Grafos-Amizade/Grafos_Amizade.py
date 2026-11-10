"""Trabalho em grupo - Grafos e amizades: 35 vertices em 7 nucleos de 5.

Rede inicial da professora preservada: 6 usuarios e 8 amizades.
Cada nucleo inclui o nome de um integrante. Seis nucleos incluem
um usuario original; o setimo inclui quatro personagens ficticios.
Sem dependencias externas. Python 3.9+.
"""
from collections import deque
from itertools import combinations

INTEGRANTES = (
    "Aloisio Veleda", "Giovanna Nascimento", "Guilherme Brito",
    "Isabela Cristina", "Julia Barreira", "Pedro Paulo", "Tiago Freire",
)

ORIGINAIS = ("Ana", "Bruno", "Carla", "Diego", "Elisa", "Felipe")
ARESTAS_ORIGINAIS = (
    ("Ana", "Bruno"), ("Ana", "Carla"), ("Bruno", "Carla"),
    ("Bruno", "Diego"), ("Carla", "Elisa"), ("Diego", "Elisa"),
    ("Diego", "Felipe"), ("Elisa", "Felipe"),
)

# Sao EXATAMENTE 5 vertices por nucleo, contando o integrante.
# Os personagens sao exemplos para a resolucao, nao dados pessoais reais.
NUCLEOS = {
    "Aloisio Veleda": ("Aloisio Veleda", "Ana", "Bia", "Caio", "Duda"),
    "Giovanna Nascimento": ("Giovanna Nascimento", "Bruno", "Eva", "Fred", "Gabi"),
    "Guilherme Brito": ("Guilherme Brito", "Carla", "Hugo", "Iris", "Joao"),
    "Isabela Cristina": ("Isabela Cristina", "Diego", "Katia", "Leo", "Mila"),
    "Julia Barreira": ("Julia Barreira", "Elisa", "Nina", "Otavio", "Pietra"),
    "Pedro Paulo": ("Pedro Paulo", "Felipe", "Rafa", "Sara", "Tomas"),
    "Tiago Freire": ("Tiago Freire", "Ursula", "Vitor", "Wesley", "Yara"),
}


def montar_rede(ampliada=False):
    """Retorna lista de adjacencia de grafo simples e nao direcionado."""
    usuarios = set(ORIGINAIS)
    arestas = list(ARESTAS_ORIGINAIS)
    if ampliada:
        for integrante, grupo in NUCLEOS.items():
            assert grupo[0] == integrante and len(grupo) == 5
            usuarios.update(grupo)
            # Uma estrela de quatro amizades por integrante: desenho claro.
            for colega in grupo[1:]:
                arestas.append((integrante, colega))
        # O ultimo nucleo, sem usuario original, liga-se a Ana.
        arestas.append(("Tiago Freire", "Ana"))
    rede = {nome: set() for nome in usuarios}
    for a, b in arestas:
        if a == b or a not in rede or b not in rede or b in rede[a]:
            raise ValueError(f"Aresta invalida ou duplicada: {a} / {b}")
        rede[a].add(b)
        rede[b].add(a)
    return {nome: sorted(vizinhos) for nome, vizinhos in sorted(rede.items())}


def indicadores(rede):
    graus = {usuario: len(vizinhos) for usuario, vizinhos in rede.items()}
    soma_graus = sum(graus.values())
    if soma_graus % 2:
        raise AssertionError("Soma dos graus precisa ser par")
    n = len(rede)
    e = soma_graus // 2
    return {"vertices": n, "arestas": e, "soma_graus": soma_graus,
            "densidade": 2 * e / (n * (n - 1)) if n > 1 else 0.,
            "graus": graus}


def validar(rede):
    for a, amigos in rede.items():
        if a in amigos or len(amigos) != len(set(amigos)):
            raise AssertionError(f"Laco ou duplicacao em {a}")
        for b in amigos:
            if b not in rede or a not in rede[b]:
                raise AssertionError(f"Amizade nao reciproca: {a}, {b}")
    return True


def caminho_bfs(rede, origem, destino):
    """Menor caminho em numero de arestas."""
    if origem not in rede or destino not in rede:
        raise ValueError("Usuario nao encontrado")
    fila = deque([origem])
    anterior = {origem: None}
    while fila:
        atual = fila.popleft()
        if atual == destino:
            caminho = []
            while atual is not None:
                caminho.append(atual)
                atual = anterior[atual]
            return list(reversed(caminho))
        for vizinho in rede[atual]:
            if vizinho not in anterior:
                anterior[vizinho] = atual
                fila.append(vizinho)
    return None


def componentes(rede):
    restantes = set(rede)
    resultado = []
    while restantes:
        inicio = min(restantes)
        grupo = set([inicio]); pilha = [inicio]; restantes.remove(inicio)
        while pilha:
            for vizinho in rede[pilha.pop()]:
                if vizinho in restantes:
                    restantes.remove(vizinho)
                    grupo.add(vizinho)
                    pilha.append(vizinho)
        resultado.append(grupo)
    return resultado


def recomendar(rede, minimo_comuns=2):
    """Sugere pares ainda sem amizade, com amigos em comum."""
    sugestoes = []
    for a, b in combinations(sorted(rede), 2):
        if b not in rede[a]:
            comuns = sorted(set(rede[a]) & set(rede[b]))
            if len(comuns) >= minimo_comuns:
                sugestoes.append((a, b, comuns))
    return sorted(sugestoes, key=lambda x: (-len(x[2]), x[0], x[1]))


def exibir(rede, titulo):
    x = indicadores(rede)
    print(f"\n{titulo}: {x['vertices']} usuarios; {x['arestas']} amizades; "
          f"soma dos graus {x['soma_graus']}; densidade {x['densidade']:.2%}")
    for nome, grau in sorted(x['graus'].items(), key=lambda i: (-i[1], i[0])):
        print(f"{nome:<23} grau {grau:>2} | {', '.join(rede[nome])}")
    maior = max(x['graus'].values())
    print("Mais conectado(s):", ", ".join(
        sorted(nome for nome, g in x['graus'].items() if g == maior)))


def main():
    inicial, completa = montar_rede(False), montar_rede(True)
    validar(inicial); validar(completa)
    assert indicadores(inicial)['vertices'] == 6
    assert indicadores(inicial)['arestas'] == 8
    assert indicadores(completa)['vertices'] == 35
    assert indicadores(completa)['arestas'] == 37
    assert len(componentes(completa)) == 1
    exibir(inicial, "REDE ORIGINAL")
    exibir(completa, "REDE AMPLIADA")
    for rede, rotulo in [(inicial, "Original"), (completa, "Ampliada")]:
        caminho = caminho_bfs(rede, "Ana", "Felipe")
        print(f"{rotulo}: Ana -> Felipe = {' -> '.join(caminho)} ({len(caminho)-1} arestas)")
    d0 = indicadores(inicial)['densidade']
    d1 = indicadores(completa)['densidade']
    print(f"Variacao de densidade: {(d1-d0)*100:+.2f} pontos percentuais")
    print("Recomendacoes (ate 5):")
    for a,b,comuns in recomendar(completa)[:5]:
        print(f"  {a} + {b}: {len(comuns)} amigo(s) em comum: {', '.join(comuns)}")

if __name__ == '__main__':
    main()
