// Código em C++ Parar treinar o uso de filas
#include<stdio.h>
#include <stdlib.h>

// Estrutura inicial utilizando fila
struct Fila {
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 
};

// um void para se iniciar aspropriedades da fila de maneira que não retorne nada
void criarFila(struct Fila *f, int c) { 
	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}

// Para inserir um elemento na fila
void inserir(struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;
	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido
}

// Para remover um elemento da fila
int remover(struct Fila *f) { // pega o item do comeÃ§o da fila
	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	f->nItens--;  // um item retirado
	return temp;
}

// Para verificra sea fila está vazia
int estaVazia(struct Fila *f) { // retorna verdadeiro se a fila está¡ vazia
	return (f->nItens==0);
}

// Parar verificar se a fila atingiu o tamanho máximo
int estaCheia(struct Fila *f) { // retorna verdadeiro se a fila estÃ¡ cheia
	return (f->nItens == f->capacidade);
}

// Para mostrar a fila
void mostrarFila(struct Fila *f){
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%.2f\t",f->dados[i++]);
		if (i == f->capacidade)
			i=0;
	}
	printf("\n\n");
}

// Estrutura principal com um gancho para as ações configuradas acima
int main () {
	int opcao, capa;
	float valor;
	struct Fila umaFila;
	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);
	// apresenta menu
	while(true){
		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0: exit(0);
			case 1: // insere elemento
				if (estaCheia(&umaFila))
					printf("\nFila Cheia!!!\n\n");
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila, valor);
				}
				break;
			case 2: // remove elemento
				if (estaVazia(&umaFila))
					printf("\nFila vazia!!!\n\n");
				else {
					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ; 
				}
				break;
				case 3: // mostrar fila
					if (estaVazia(&umaFila)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);
					}
					break;
				default:
					printf("\nOpcao Invalida\n\n");
		}
	}
}
