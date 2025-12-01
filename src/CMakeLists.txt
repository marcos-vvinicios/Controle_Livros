cmake_minimum_required(VERSION 4.0)
project(Sistema_bibliotecario_pi C)

set(CMAKE_C_STANDARD 17)

add_executable(Sistema_bibliotecario_pi
        main.c
        biblioteca.h
        emprestimos.c
        utilitarios.c
        beneficiarios.c
        livros.c)
