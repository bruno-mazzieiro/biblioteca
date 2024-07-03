# Sistema de Biblioteca Avançado

## 1. Apresentação do Problema

O Sistema de Biblioteca Avançado propõe-se a resolver os desafios enfrentados pelas bibliotecas no gerenciamento eficiente de seus recursos, incluindo o controle de estoque de livros, o acompanhamento de empréstimos e devoluções, notificações de devolução atrasada, notícias sobre a chegada de novos livros e o gerenciamento de multas. A melhoria nesses processos se tornará um diferencial de mercado, aumentando a comodidade dos leitores e aproximando cliente e estabelecimento comercial.

### User Story

**Operação:** Sistema de Biblioteca Avançado  
**Descrição:** Como um assíduo leitor, desejo encontrar uma biblioteca que me dê um feedback constante sobre a chegada de novos livros, status de um empréstimo e gerenciamento de multas. Assim, geraria mais comodidade e melhoraria minha comunicação com a biblioteca como leitor.

**Critérios de Aceitação:**
- Posso olhar o status de empréstimo de cada livro;
- Devo receber notificação com a chegada de novos livros;
- Posso olhar o acervo de livros disponíveis na biblioteca;
- Posso gerar boletos para o pagamento de multas;
- Posso emprestar meus livros à biblioteca;
- Posso agendar o empréstimo de um livro.

## 2. Visão Geral da Solução

A solução proposta é um programa em C++ que oferece uma interface para gerenciar uma biblioteca. Ele oferece as seguintes funcionalidades: 
- Adicionar e remover livros do acervo
- Cadastrar e remover usuários
- Realizar empréstimos e devoluções de livros 
- Aplicar e cobrar multas
- Gerar boletos 
- Notificar clientes sobre a chegada de novos livros
- Receber empréstimos de usuários 
- Agendamento/fila para empréstimos

## 3. Estrutura do Projeto

O projeto é organizado da seguinte forma:

biblioteca
│ README.txt # Documentação do projeto
│ main.cpp # Arquivo principal do programa
│
├───include
│ biblioteca.hpp # Cabeçalho da classe Biblioteca
│ cliente.hpp # Cabeçalho da classe Cliente
│ livro.hpp # Cabeçalho da classe Livro
│
├───src
│ biblioteca.cpp # Implementação da classe Biblioteca
│ cliente.cpp # Implementação da classe Cliente
│ livro.cpp # Implementação da classe Livro
│
└───docs
# Documentação adicional


## 4. Instruções de Instalação

Para instalar e configurar o sistema, siga estas etapas:

1. Certifique-se de ter um compilador C++ instalado em seu sistema, como o GCC ou o Visual Studio.
2. Clone o repositório:
    ```sh
    git clone https://github.com/usuario/nome-do-repositorio.git
    ```
3. Navegue até o diretório do projeto:
    ```sh
    cd nome-do-repositorio
    ```
4. Compile os arquivos fonte utilizando o compilador C++:
    ```sh
    g++ -o biblioteca main.cpp src/biblioteca.cpp src/cliente.cpp src/livro.cpp -I include/
    ```
5. Execute o arquivo executável gerado:
    ```sh
    ./biblioteca
    ```

## 5. Instruções de Uso

Para usar o programa, siga estas instruções:

1. Execute o arquivo executável:
    ```sh
    ./biblioteca
    ```
2. Utilize o menu interativo para realizar as operações desejadas, como adicionar livros, cadastrar usuários, emprestar e devolver livros, etc.
3. Siga as instruções fornecidas pelo programa para interagir com ele.

## 6. Principais Dificuldades

Durante o desenvolvimento do projeto, algumas das principais dificuldades enfrentadas incluíram:
- Implementação eficiente das notificações de devolução atrasada e gerenciamento de multas.
- Lidar com casos complexos de interações entre usuários e livros em um ambiente concorrente.
- Garantir a robustez do sistema e a correta manipulação de erros e exceções.

## 7. Comentários no Código

Para facilitar o entendimento e a manutenção do código, foram adicionados comentários explicativos nas partes mais complexas, algoritmos, e decisões importantes.

## Autores

- Davi Braga (https://github.com/azevedo660)
- Daniel Andrade (https://github.com/DanielAndrade19)
- Júlia Camelo (https://github.com/juliacamelo)
- Lauro Emmanuel (https://github.com/LauroEmma)
- Bruno Mazzieiro (https://github.com/bruno-mazzieiro)
- João Duque (https://github.com/joaoduquef)


## Contato

Para mais informações, entre em contato pelo e-mail: tp_pds2@ufmg.com


