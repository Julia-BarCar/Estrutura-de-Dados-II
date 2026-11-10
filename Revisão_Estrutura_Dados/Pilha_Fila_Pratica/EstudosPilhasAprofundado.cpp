# include <stdio.h>
# define MAXSIZE 15 // Declara que o tamanho MAXSIZE é de tamanho 15
struct stack { // Declaração da estrutura "stack"
	int stk[MAXSIZE]; // Onde os elementos da pilha vão ser armazenados
	int top; // Funciona como o índice que aponta para o topo da pilha
};
typedef struct stack STACK;  // Dá  um apelido para a struct stack de apenas STACK
STACK s; // Declara uma variável real s do tipo STACK; Uma pilha que pode ser usada em todo o programa
void push(void); // Mostra pro código que quando a função for usada deve inserir um novo elemento no topo da pilha
int pop(void); // Mostra que a função  deve remover e retornar um elemento ao topo da pilha
void display(void); // Mostra que a função exibe os elementos da pilha
// O void indica que não  há parâmetros a serem recebidos
int main () {
	int escolha; // Cria variável inteira "escolha"
	s.top = -1; // Localiza o topo atual da pilha como -1
	
	printf("OPERACOES POSSIVEIS:\n"); // ? Corrigido: /n ? \n
	while (true) {
		printf ("\n ----------------- ");
		printf ("\n  1 --> PUSH");
        printf ("\n  2 --> POP");
        printf ("\n  3 --> DISPLAY");
        printf ("\n  4 --> SAIR");
		printf ("\n ----------------- ");
		printf("\nDigite sua escolha : ");
		scanf ("%d", &escolha);
		
		switch (escolha) {
			case 1:
				push(); // Chama a função push mostrada anteriormente
				break; // Impede os outros casos de rodar
			case 2:
				pop();// Chama a função pop mostrada anteriormente
				break; // Impede os outros casos de rodar
			case 3:
				display();// Chama a função display mostrada anteriormente
				break; // Impede os outros casos de rodar
			case 4:
				return(0); // Sai da função
		}
		fflush(stdin); // Limpa o buffer de entrada do teclado
	}
}
void push () { // Para configurar o push
	int num;
	if (s.top == (MAXSIZE - 1)) { // ? Corrigido: verifica se a pilha está cheia
		printf ("\nPILHA CHEIA"); 
	} else {
		printf ("\nDigite o elemento : "); // Pede o número a ser colocado
		scanf ("%d", &num);
		s.top = s.top + 1; // Sobe um elemento da lista para o topo ficar livre
		s.stk[s.top] = num; // Salva o novo número da pilha
		printf ("\nELEMENTO INSERIDO : %d", num); // ? Corrigido: adicionado %d e num
	}
}
int pop () { // Para configurar o pop
    int num;
    if (s.top == - 1) { // Verifica se o topo é -1, a pilha está vazia e não há nada para remover
        printf ("\n Pilha vazia!");
        return (s.top); // Retorna -1
    } else {
        num = s.stk[s.top]; // Salva o elemento no topo de  num
        printf ("\n Elemento retirado: %d", s.stk[s.top]); // Mostra qual elemento foi retirado do topo da lista
        s.top = s.top - 1; // Volta uma posição na pilha
    }
    return(num);
}
void display () { // Para configurar o display
    int i;
    if (s.top == -1) { // Verifica se a pilha está vazia
      printf ("\n Pilha vazia!");
	} else {
      printf ("\n Elementos na pilha:");
      for (i = s.top; i >= 0; i--) // Mostra cada elemento da pilha do topo até o índice 0, nessa ordem
        printf ("\n %d", s.stk[i]);
    }
    printf("\n");
}
