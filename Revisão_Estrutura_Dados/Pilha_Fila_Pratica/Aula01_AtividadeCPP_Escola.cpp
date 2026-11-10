/* Escreva um algoritmo que solicite: Nome, Sexo, Idade e N Notas de N Alunos em uma Turma.
  E, ao final, apresente:
  1) Total de alunos cadastrados;.......................................................ok
  2) Média da idade dos alunos da turma;................................................ok
  3) Quantidade de alunos aprovados;....................................................ok
     3.1) Quantidade de alunos reprovados; .............................................ok
  4) Percentual de aprovação por sexo masculino e feminino;.............................ok
  5) Relatório de alunos aprovados;.....................................................ok
  6) Permitir ao usuário configurar a quantidade de provas e média de aprovação.........ok
*/

#include <stdio.h>
#include <locale.h>

struct Aluno {
    char Nome[30];
    char Sexo;
    int Idade;
    float Notas[10];
    bool Aprovacao;
};

int main(){
    setlocale(LC_ALL, "Portuguese");
    
// == VARIÁVEIS == //
    int QtdAlunos, QtdProvas, QtdAprovados = 0, QtdReprovados = 0;
    int SomaIdades = 0;  // Inicializado para evitar lixo de memória
    int Mulheres = 0, Homens = 0, MulheresAprovadas = 0, HomensAprovados = 0;
    float SomaNotas = 0, MediaGeral = 0, MediaAluno = 0;
    struct Aluno Turma[100];
    
    printf("Digite a quantidade de alunos na turma: ");
    scanf("%i", &QtdAlunos);
    
    printf("Digite a quantidade de provas: ");
    scanf("%i", &QtdProvas);
    
    printf("Digite a média para aprovação: ");
    scanf("%f", &MediaGeral);
    printf("\n");

    for (int i = 0; i < QtdAlunos; i++) {
// NOME //
        printf("Nome aluno %i: ", i + 1);
        scanf("%s", &Turma[i].Nome);
// SEXO //
        printf("Sexo de %s [M/F]: ", Turma[i].Nome);
        scanf(" %c", &Turma[i].Sexo);
	// Verificação da resposta, guardando quantas mulheres e quantos homens //
        if (Turma[i].Sexo == 'F' || Turma[i].Sexo == 'f') {
            Mulheres++;
        } else if (Turma[i].Sexo == 'M' || Turma[i].Sexo == 'm') {
            Homens++;
        }
// IDADE //
        printf("Idade de %s: ", Turma[i].Nome);
        scanf("%i", &Turma[i].Idade);
        SomaIdades += Turma[i].Idade;
// NOTAS //
        SomaNotas = 0;
        
        for(int n = 0; n < QtdProvas; n++){
            printf("   Nota %i: ", n + 1);
            scanf("%f", &Turma[i].Notas[n]);
            SomaNotas += Turma[i].Notas[n];
        }
        MediaAluno = SomaNotas / QtdProvas;
        
// APROVAÇÃO //
        if (MediaAluno >= MediaGeral) {
            Turma[i].Aprovacao = true;
            printf("Média de %s: %.2f - APROVADO\n\n", Turma[i].Nome, MediaAluno);
            QtdAprovados++;
            if (Turma[i].Sexo == 'F' || Turma[i].Sexo == 'f') {
                MulheresAprovadas++;  // Conta mulheres aprovadas
            } else {
                HomensAprovados++;  // Conta homens aprovados
            }
        } else {
            Turma[i].Aprovacao = false;
            printf("Média de %s: %.2f - REPROVADO\n\n", Turma[i].Nome, MediaAluno);
            QtdReprovados++;  // Contador novo para reprovados
        }
    }
    
// == INFORMAÇÕES TURMA == //
    printf("\n\n ====== INFORMAÇÕES GERAIS ====== ");
    printf("\nTotal de alunos cadastrados: %i", QtdAlunos);
    printf("\n      Mulheres: %i", Mulheres);
    printf("\n      Homens: %i", Homens);
    float MediaIdades = SomaIdades / QtdAlunos;
    printf("\nMédia das idades: %.2f anos", MediaIdades);
    printf("\n\n ====== APROVAÇÕES ====== ");
    printf("\nAlunos aprovados: %i", QtdAprovados);
    printf("\nAlunos reprovados: %i", QtdReprovados);
    if (Mulheres > 0) {
        float percMulheres = (float)MulheresAprovadas / Mulheres * 100;
        printf("\nAprovação mulheres: %.1f%% (%i/%i)", percMulheres, MulheresAprovadas, Mulheres);
    } else if (Homens > 0) {
        float percHomens = (float)HomensAprovados / Homens * 100;
        printf("\nAprovação homens: %.1f%% (%i/%i)", percHomens, HomensAprovados, Homens);
    }
    printf("\n\n ...... RELATÓRIO DE APROVADOS ...... \n");
    for (int i = 0; i < QtdAlunos; i++) {
        if (Turma[i].Aprovacao) {
            printf("- %s (%.2f)\n", Turma[i].Nome, 
                   (Turma[i].Notas[0] + Turma[i].Notas[1]) / 2.0f);
        }
    }
}
