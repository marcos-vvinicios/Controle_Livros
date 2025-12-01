 /*Projeto: Controle de Livros
/Autor: Marcos Vinicius / Jackson Silva
Data de criação: 15/11/2025

Descrição: Programa em C para gerenciar o empréstimo e devolução de livros em uma biblioteca.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"

// MODULO  MAIN

int main() {
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
        opcao = showMenu();


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


