# include <stdio.h>

/**
Um código que solicite ao usuário dois números reais e apresente :
	1) A soma entre eles;
	2) A subtração do primeiro pelo segundo;
	3) A multiplicação entre eles;
	4) A divisão do primeiro pelo segundo;
	5) O resto da divisão do primeiro pelo segundo;
**/

// Assinatura das funções
float subtrair(float num1, float num2);
float somar(float num1, float num2);
float multiplicar(float num1, float num2);
float dividir(float num1, float num2);

int main () {
	float vlr1, vlr2;
	printf ("Informe o primeiro valor : ");
	scanf ("%f", &vlr1);
	printf ("Informe o segundo valor : ");
	scanf ("%f", &vlr2);
	
	printf ("\nA soma de %.1f + %.1f e igual a %.1f", vlr1, vlr2, somar(vlr1, vlr2));
	printf ("\nA subtracao de %.1f - %.1f e igual a %.1f", vlr1, vlr2, subtrair(vlr1, vlr2));
	printf ("\nA multiplicacao de %.1f * %.1f e igual a %.1f", vlr1, vlr2, multiplicar(vlr1, vlr2));
	printf ("\nA divisao de %.1f / %.1f e igual a %.1f", vlr1, vlr2, dividir(vlr1, vlr2));
	printf ("\n		O resto da divisao de %.1f % %.1f e igual a %.1f", vlr1, vlr2, dividir(vlr1, vlr2));
}

// Criação do cabeçalho da função SOMAR
float somar(float num1, float num2) {
	float Resultado;
	Resultado = num1 + num2;
	return(Resultado);
}

// Criação do cabeçalho da função SUBTRAIR
float subtrair(float num1, float num2) {
	float Resultado;
	Resultado = num1 - num2;
	return(Resultado);
}

// Criação do cabeçalho da função MULTIPLICAR
float multiplicar(float num1, float num2) {
	float Resultado;
	Resultado = num1 * num2;
	return(Resultado);
}

// Criação do cabeçalho da função DIVIDIR
float dividir(float num1, float num2) {
	float Resultado;
	if (num2 == 0) {
		printf("Não é possível dividir um número por zero!")
	} else {
		Resultado = num1 / num2;
		return(Resultado);
	}
}

// Criação do cabeçalho da função RESTODIVIDIR
float restodividir(float num1, float num2) {
	float Resultado, Resto;
	Resultado = num1 % num2;
	return(Resultado);
}
