//MODULO DE BENEFICIARIOS

#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

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