// MODULO LIVROS

#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

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