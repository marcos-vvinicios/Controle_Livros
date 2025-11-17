 /*Projeto: Controle de Livros
/Autor: Marcos Vinicius / Jackson Silva
Data de criação: 15/11/2025

Descrição: Programa em C para gerenciar o empréstimo e devolução de livros em uma biblioteca.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


// CRIAR STRUCTS
typedef struct {
 char codigo[20];
 char titulo[100];
 char autor[100];
 int quant;
 int dispo;
} Livro;

typedef struct {
 char id[20];
 char nome[100];
 char telefone[15];
}Beneficiario;

typedef struct {
 char codigoLivro[20];
 char idBeneficiario[20];
 char dataEmprestimo[11];
 char status[20]; // "EMPRESTADO" ou "DEVOLVIDO"
} Emprestimo;

// FUNÇÕES AUX

void limpBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause() {
    printf("\nPressione Enter...");
    getchar();
}

// FUNÇÕES PRINCIPAIS DE LIVROS

void cadastroLivro(Livro livros[], int *totaLivros) {
 printf("\n--- Cadastro de Livro ---\n");
 printf("Insira o codigo do livro: ");
 scanf("%s", livros[*totaLivros].codigo);
 limpBuffer();
 printf("Insira o titulo do livro: ");
 fgets(livros[*totaLivros].titulo, 100, stdin);
 livros[*totaLivros].titulo[strcspn(livros[*totaLivros].titulo, "\n")] = 0; // Remove newline
 printf("Insira o autor do livro: ");
 fgets(livros[*totaLivros].autor, 100, stdin);
 livros[*totaLivros].autor[strcspn(livros[*totaLivros].autor, "\n")] = 0;
 printf("Insira a quantidade de livros: ");
 scanf("%d", &livros[*totaLivros].quant);
 livros[*totaLivros].dispo = livros[*totaLivros].quant;
 (*totaLivros)++;
 printf("\nLivro cadastro com sucesso!\n");
}

void listLivros(Livro livros[], int *totallivros) {
 printf("\n--- Lista de Livros ---\n");
 if (*totallivros == 0) {
     printf("Nenhum livro cadastrado.\n");
     return;
 }
    for (int i = 0; i < *totallivros; i++) {
     printf("\nCodigo do Livro: %s\n", livros[i].codigo);
     printf("Titulo do Livro: %s\n", livros[i].titulo);
     printf("Autor do Livro: %s\n", livros[i].autor);
     printf(" Livros Disponiveis: %d de %d\n", livros [i].dispo, livros[i].quant);
    }
}

//FUNÇÕES PRINCIPAIS DE BENEFICIARIOS

void cadastrarBeneficiario(Beneficiario beneficiarios[], int *totalBeneficiarios) {
 printf("\n--- Cadastro de Beneficiario ---\n");
 printf("Insira o ID do Beneficiario: ");
 scanf("%s", beneficiarios[*totalBeneficiarios].id);
 limpBuffer();
 printf("Insira o nome do Beneficiario: ");
 fgets(beneficiarios[*totalBeneficiarios].nome, 100, stdin);
 beneficiarios[*totalBeneficiarios].nome[strcspn(beneficiarios[*totalBeneficiarios].nome, "\n")] = 0;
 printf("Insira o telefone do Beneficiario: ");
 scanf("%s", beneficiarios[*totalBeneficiarios].telefone);
 (*totalBeneficiarios)++;
 printf("\nBeneficiario cadastrado com sucesso!\n");
}

void listBeneficiarios(Beneficiario beneficiarios[], int *totalBeneficiarios) {
     printf("\n--- Lista de Beneficiarios ---\n");
 if (*totalBeneficiarios == 0) {
  printf("Nenhum Beneficiario cadastrado.\n");
  return;
 }
 for (int i = 0; i < *totalBeneficiarios; i++) {
  printf("\nID do Beneficiario: %s\n", beneficiarios[i].id);
  printf("Nome do Beneficiario: %s\n", beneficiarios[i].nome);
  printf("Telefone do Beneficiario: %s\n", beneficiarios[i].telefone);
  printf("-------------------------------\n");
 }
}

// FUNÇÕES PRINCIPAIS DE EMPRÉSTIMO

void realizarEmprest(Livro livros[], int *totalLivros, Emprestimo emprestimos[], int *totalEmprestimo) {
 char codigoLivro[20];
 printf("\n--- Realizar Emprestimo ---\n");
 printf("Insira o codigo do livro a ser emprestado: ");
 scanf("%s", codigoLivro);
 limpBuffer();

 int livencontrado = -1;
 for (int i = 0; i < *totalLivros; i++) {
  if (strcmp(livros[i].codigo, codigoLivro) == 0) {
   livencontrado = i;
   break;
  }
 }
 if (livencontrado == -1) {
  printf("Livro nao encontrado.\n");
  return;
 }

 if (livros[livencontrado].dispo <=0) {
  printf("Livro indisponivel para emprestimo.\n");
  return;
 }
 strcpy(emprestimos[*totalEmprestimo].codigoLivro, codigoLivro);
 printf("ID do Beneficiario: ");
 scanf("%s", emprestimos[*totalEmprestimo].idBeneficiario);
 printf("Data do Emprestimo (DD/MM/AAAA): ");
 scanf("%s", emprestimos[*totalEmprestimo].dataEmprestimo);
 strcpy(emprestimos[*totalEmprestimo].status, "EMPRESTADO");

 livros[livencontrado].dispo--;
 (*totalEmprestimo)++;

 printf("\nEmprestimo realizado com sucesso!\n");
}

void registrarDev(Livro livros[], int *totalLivros, Emprestimo emprestimos[], int *totalEmprestimo) {
 char codigoLivro[20], id[20];
 printf("\n--- Registrar Devolucao ---\n");
 printf("\nInsira o codigo do livro a ser devolvido: ");
 scanf("%s", codigoLivro);
 printf("Insira o ID do beneficiario: ");
 scanf("%s", id);

 for (int i = 0; i < *totalEmprestimo; i++) {
  if (strcmp(emprestimos[i].codigoLivro, codigoLivro) == 0 &&
      strcmp(emprestimos[i].idBeneficiario, id) == 0 &&
      strcmp(emprestimos[i].status, "EMPRESTADO") == 0) {

   strcpy(emprestimos[i].status, "DEVOLVIDO");
   for (int j = 0; j < *totalEmprestimo; j++) {
    if (strcmp(livros[j].codigo, codigoLivro) == 0) {
     livros[j].dispo++;
     break;
    }
   }
   printf("\nDevolucao registrada com sucesso!\n");
   return;
      }

 }
 printf("Emprestimo nao encontrado para o livro e beneficiario fornecidos.\n");
}

void listEmprestimos(Emprestimo emprestimos[], int *total) {
     printf("\n--- Lista de Emprestimos ---\n");
     int contagem = 0;
 for (int i = 0; i < *total; i++) {
  if (strcmp(emprestimos[i].status, "EMPRESTADO") == 0) {
   printf("\nCodigo do Livro: %s\n", emprestimos[i].codigoLivro);
   printf("ID do Beneficiario: %s\n", emprestimos[i].idBeneficiario);
   printf("Data do Emprestimo: %s\n", emprestimos[i].dataEmprestimo);
   printf("Status do Emprestimo: %s\n", emprestimos[i].status);
   printf("-------------------------------\n");
   contagem++;
  }
 }
 if (contagem == 0) {
  printf("Nenhum emprestimo esta ativo.\n");
 }
}

// FUNÇÃO MAIN

int main(void) {
system("cls");
 printf("Iniciando o Projeto Integrador...\n");

 Livro livros[MAX];
 Beneficiario beneficiarios[MAX];
 Emprestimo emprestimos[MAX];

 int totalLivros = 0;
 int totalBeneficiarios = 0;
 int totalEmprestimo = 0;
 int opcao;


 printf("\n----------------------------------\n");
 printf("         SISTEMA BIBLIOTECARIO      \n");
 printf("\n----------------------------------\n");


 do {
  printf("\n--- Menu Principal ---\n");
  printf("1. Cadastrar Livro\n");
  printf("2. Listar Livros\n");
  printf("3. Cadastrar Beneficiario\n");
  printf("4. Listar Beneficiarios\n");
  printf("5. Realizar Emprestimo\n");
  printf("6. Registrar Devolucao\n");
  printf("7. Listar Emprestimos Ativos\n");
  printf("8. Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  limpBuffer();

  switch (opcao)
  {
   case 1:
    if (totalLivros < MAX) {
     cadastroLivro(livros, &totalLivros);
    } else {
     printf("Capacidade máxima de livros atingida.\n");
    } pause();
    break;

   case 2:
    listLivros(livros, &totalLivros);
    pause();
    break;

   case 3:
    if (totalBeneficiarios < MAX) {
     cadastrarBeneficiario(beneficiarios, &totalBeneficiarios);
    } else {
     printf("Capacidade máxima de beneficiários atingida.\n");
    } pause();
    break;

   case 4:
    listBeneficiarios(beneficiarios, &totalBeneficiarios);
    pause();
    break;

   case 5:
    realizarEmprest(livros, &totalLivros, emprestimos, &totalEmprestimo);
    pause();
    break;

   case 6:
    registrarDev(livros, &totalLivros, emprestimos, &totalEmprestimo);
    pause();
    break;

   case 7:
    listEmprestimos(emprestimos, &totalEmprestimo);
    pause();
    break;

   case 8:
    printf("\nFechando o Sistema...");
    break;

   default:
    printf("\nOpção inválida. Tente novamente.\n");
    pause();
  }
 }
 while (opcao != 8);
  return 0;
 }


