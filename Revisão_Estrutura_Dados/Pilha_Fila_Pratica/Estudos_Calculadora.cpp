# include <stdio.h>

//	3.Assinaturas das funções
float somar (float num1, float num2);
float subtrair (float num1, float num2);
float multiplicar (float num1, float num2);
float dividir (float num1, float num2);

int main() {
	// BÁSICO
//	1. Para mostrar número inteiros
	int numint;
	printf("--- Teste Codigo Cpp ---\n");
	printf("\nDigite um numero inteiro : ");
	scanf ("%i", &numint);
	printf("   Seu numero e %i", numint);
//	2. Para formatar/mostrar números flutuantes
	float numfloat;
	printf("\nDigite um numero com virgula : ");
	scanf("%f", &numfloat);
	printf("   Seu numero e %.2f", numfloat);
	printf("\n\n");
	// FUNÇÕES
	float vlr1, vlr2;
	printf("Digite o primeiro valor : ");
	scanf("%f", &vlr1);
	printf("Digite o segundo valor : ");
	scanf("%f", &vlr2);
//	----
	printf("\nUtilizando os valores citados, as operacoes ficam : ");
	printf("\n    SOMAR : %.f + %.f = %.1f",  vlr1, vlr2, somar(vlr1, vlr2));
	if (vlr1 > vlr2)
		printf("\n    SUBTRAIR : %.f - %.f = %.1f",  vlr1, vlr2, subtrair(vlr1, vlr2));
	else
		printf("\n    SUBTRAIR : %.f - %.f = %.1f",  vlr2, vlr1, subtrair(vlr1, vlr2));
	printf("\n    MULTIPLICAR : %.f * %.f = %.1f",  vlr1, vlr2, multiplicar(vlr1, vlr2));
	if (vlr1 > vlr2)
		printf("\n    SUBTRAIR : %.f / %.f = %.1f",  vlr1, vlr2, dividir(vlr1, vlr2));
	else
		printf("\n    SUBTRAIR : %.f / %.f = %.1f",  vlr2, vlr1, dividir(vlr1, vlr2));
	// FILAS
	
}

// 3.Cabeçalhos das funções
float somar (float num1, float num2){
	float Resultado;
	Resultado = num1 + num2;
	return(Resultado);
}
float subtrair (float num1, float num2){
	float Resultado;
	if (num1 > num2)
		Resultado = num1 - num2;
	else
		Resultado = num2 - num1;
	return(Resultado);
}
float multiplicar (float num1, float num2) {
	float Resultado;
	Resultado = num1 * num2;
	return (Resultado);
}
float dividir (float num1, float num2) {
	float Resultado;
	if (num1 > num2)
		Resultado = num1 / num2;
	else
		Resultado = num2 / num1;
	return (Resultado);
}
