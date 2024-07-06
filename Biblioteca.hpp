#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP 

#include <iostream>
#include <string>
#include <vector>
#include "Livro.hpp"
#include "Cliente.hpp"

class Biblioteca {
private:
    std::vector<Livro> livros; // armazenar todos os livros em um vetor
    std::vector<Cliente> clientes; // armazenar todos os clientes em um vetor

public:
    // Métodos para manipulação de livros
    Livro* cadastrarLivro(int identificador_livro, std::string titulo_livro, std::string autor_livro, int ano_publicacao, std::string genero_livro, std::string condicao_livro, int status_livro, std::string localizacao_livro);
    Livro* editarPropriedades(int identificador_livro, std::string multa, int condicao_livro, int status_livro);
    Livro* localizarLivro(int identificador_livro);
    Livro* multar(int identificador_livro);
    std::string receberLivro(int identificador_livro);
    
    // Métodos para manipulação de clientes
    std::string cadastroCliente();
    std::string receberPagamento(int identificador_livro);
    
    // Métodos de notificação
    std::string enviarNotificacao();
    std::string enviarCobranca();
};

#endif
