//MODULO UTILITARIOS

#include <stdio.h>
#include "biblioteca.h"

// FUNÇÕES AUX

void limpBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause() {
    printf("\nPressione Enter...");
    getchar();
}

int showMenu(){
    int opcao;
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
    return opcao;
}