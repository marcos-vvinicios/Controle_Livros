## Requisitos Funcionais (exemplos)
 1.	O sistema deve permitir o cadastro de livros, incluindo título, autor, código e quantidade disponível.
 2.	O sistema deve permitir o cadastro de leitores, armazenando nome, identificação e contato.
 3.	O sistema deve registrar o empréstimo de um livro, vinculando o leitor, o livro e a data de empréstimo.
 4.	O sistema deve registrar a devolução de um livro, atualizando a disponibilidade no acervo.
 5.	O sistema deve gerar relatórios ou listagens de livros disponíveis, emprestados e histórico de empréstimos.

## Requisitos Não Funcionais (exemplos)
 1.	O sistema deve funcionar em modo texto (terminal), sem interface gráfica.
 2.	O sistema deve garantir a integridade dos dados, impedindo empréstimos de livros indisponíveis.
 3.	O sistema deve ser simples e rápido, respondendo às ações do usuário em tempo imediato.

## Tabela E/P/S
Tipo        | Descrição                                | Exemplo no sistema
----------- | ---------------------------------------- | -----------------------------------------------
Entrada     | Dados do livro digitados pelo usuário    | Título, Autor, Código, Quantidade
Entrada     | Dados do leitor digitados pelo usuário   | Nome, ID, Contato
Entrada     | Dados do empréstimo                       | Código do livro, ID do leitor, Data do empréstimo
Processamento | Cálculo e atualização da quantidade de livros disponíveis | Atualizar estoque ao emprestar ou devolver
Processamento | Verificação de disponibilidade do livro | Bloquear empréstimo se quantidade = 0
Processamento | Armazenamento do histórico de empréstimos | Registrar transações no sistema
Saída       | Exibição de livros disponíveis e emprestados | Mostrar listas de livros e status
Saída       | Confirmação de cadastro ou operação     | "Livro cadastrado com sucesso!"
Saída       | Relatórios de histórico                  | Exibir todos os empréstimos realizados

