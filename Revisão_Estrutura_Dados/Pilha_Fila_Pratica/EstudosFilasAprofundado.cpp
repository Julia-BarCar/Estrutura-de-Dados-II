#include<stdio.h>
#include <stdlib.h> // Necessário para usar malloc e exit
struct Fila { // Declaração da estrutura "Fila"
	int capacidade; // Tamanho máximo da fila
	float *dados; // Ponteiro para o array onde os elementos serão armazenados
	int primeiro; // Índice do primeiro elemento da fila (frente)
	int ultimo; // Índice do último elemento da fila (fundo)
	int nItens; // Quantidade atual de elementos na fila
};
void criarFila(struct Fila *f, int c) { // Inicializa a fila com capacidade c
	f->capacidade = c; // Define a capacidade máxima
	f->dados = (float*) malloc (f->capacidade * sizeof(float)); // Aloca memória para o array de elementos
	f->primeiro = 0; // O primeiro elemento começa no índice 0
	f->ultimo = -1; // -1 indica que a fila está vazia
	f->nItens = 0; // Começa com 0 elementos
}
void inserir(struct Fila *f, int v) { // Insere um elemento no final da fila
	if(f->ultimo == f->capacidade-1) // Se chegou no fim do array...
		f->ultimo = -1; // ...volta para o início (fila circular)
	f->ultimo++; // Avança o índice do último
	f->dados[f->ultimo] = v; // Insere o elemento na posição correta
	f->nItens++; // Atualiza a contagem de elementos
}
int remover(struct Fila *f) { // Remove e retorna o elemento do início da fila
	int temp = f->dados[f->primeiro++]; // Salva o primeiro elemento e avança o índice
	if(f->primeiro == f->capacidade) // Se chegou no fim do array...
		f->primeiro = 0; // ...volta para o início (fila circular)
	f->nItens--; // Atualiza a contagem de elementos
	return temp; // Retorna o elemento removido
}
int estaVazia(struct Fila *f) { // Verifica se a fila está vazia
	return (f->nItens==0); // Retorna verdadeiro (1) se não há elementos
}
int estaCheia(struct Fila *f) { // Verifica se a fila está cheia
	return (f->nItens == f->capacidade); // Retorna verdadeiro (1) se atingiu a capacidade máxima
}
void mostrarFila(struct Fila *f){ // Exibe todos os elementos da fila
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){ // Percorre do primeiro ao último elemento
		printf("%.1f\t",f->dados[i++]); // Imprime o elemento com 2 casas decimais e avança o índice
		if (i == f->capacidade) // Se chegou no fim do array...
			i=0; // ...volta para o início (fila circular)
	}
	printf("\n\n"); // Pula duas linhas após exibir a fila
}
int main () {
	int opcao, capa; // opcao guarda a escolha do menu; capa guarda a capacidade da fila
	float valor; // Guarda o valor a ser inserido ou removido
	struct Fila umaFila; // Declara uma variável do tipo Fila
	// Cria a fila com a capacidade definida pelo usuário
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa); // Inicializa a fila com a capacidade informada
	// Apresenta o menu em loop até o usuário sair
	while(true){
		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				exit(0); // Encerra o programa
			case 1: // Insere elemento
				if (estaCheia(&umaFila)) // Verifica se há espaço disponível
					printf("\nFila Cheia!!!\n\n");
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&umaFila, valor); // Insere o valor no final da fila
				}
				break;
			case 2: // Remove elemento
				if (estaVazia(&umaFila)) // Verifica se há elementos para remover
					printf("\nFila vazia!!!\n\n");
				else {
					valor = remover(&umaFila); // Remove o primeiro elemento da fila
					printf("\n%.1f removido com sucesso\n\n", valor); 
				}
				break;
			case 3: // Mostrar fila
				if (estaVazia(&umaFila)){ // Verifica se há elementos para exibir
					printf("\nFila vazia!!!\n\n");
				}
				else {
					printf("\nConteudo da fila => ");
					mostrarFila(&umaFila); // Exibe todos os elementos da fila
				}
				break;
			default: // Caso o usuário digite uma opção inválida
				printf("\nOpcao Invalida\n\n");
		}
	}
}
