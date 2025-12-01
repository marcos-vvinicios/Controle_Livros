//HEADER BIBLIOTECA
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX 50

//structs

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

//AUX FUNCTIONS
void limpBuffer();
void pause();

//FUNCOES LIVROS
void cadastroLivro(Livro livros[], int *totaLivros);
void listLivros(Livro livros[], int *totallivros);

//FUNCOES BENEFICIARIOS
void cadastrarBeneficiario(Beneficiario beneficiarios[], int *totalBeneficiarios);
void listBeneficiarios(Beneficiario beneficiarios[], int *totalBeneficiarios);


//FUNCOES EMPRESTIMOS
void realizarEmprest(Livro livros[], int *totalLivros, Emprestimo emprestimos[], int *totalEmprestimo);
void registrarDev(Livro livros[], int *totalLivros, Emprestimo emprestimos[], int *totalEmprestimo);
void listEmprestimos(Emprestimo emprestimos[], int *total);


//MENU
int showMenu();



#endif