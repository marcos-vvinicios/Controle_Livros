//MODULO EMPRESTIMOS

#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

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