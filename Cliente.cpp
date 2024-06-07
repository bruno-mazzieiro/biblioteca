#include "Cliente.hpp"
#include "Livro.hpp"
#include "Biblioteca.hpp"
#include <algorithm>
#include <iostream>

// Construtor
Cliente::Cliente(const std::string& nome, const std::string& endereco, const std::string& telefone,
                 const std::string& email, const std::string& senha)
    : nome(nome), endereco(endereco), telefone(telefone), email(email), senha(senha) {}

// Getters
const std::string& Cliente::getIdentificador() const {
    return identificador;
}

const std::string& Cliente::getNome() const {
    return nome;
}

const std::string& Cliente::getEndereco() const {
    return endereco;
}

const std::string& Cliente::getTelefone() const {
    return telefone;
}

const std::string& Cliente::getEmail() const {
    return email;
}

const std::string& Cliente::getSenha() const {
    return senha;
}

const std::vector<Livro*>& Cliente::getLivrosEmprestados() const {
    return livrosEmprestados;
}

const std::vector<double>& Cliente::getMultasPendentes() const {
    return multasPendentes;
}

// Setters
void Cliente::setIdentificador(const std::string& identificador) {
    this->identificador = identificador;
}

void Cliente::setNome(const std::string& nome) {
    this->nome = nome;
}

void Cliente::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

void Cliente::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}

void Cliente::setEmail(const std::string& email) {
    this->email = email;
}

void Cliente::setSenha(const std::string& senha) {
    this->senha = senha;
}

// Funcionalidades - Interação com Livros
void Cliente::pagarMulta(Livro* livro) {
    // Implementação para pagar a multa associada a um livro
    auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), livro);
    if (it != livrosEmprestados.end()) {
        auto index = std::distance(livrosEmprestados.begin(), it);
        multasPendentes[index] = 0; // Considerando que pagar multa zera o valor da multa pendente
        std::cout << "Multa paga para o livro " << livro->retornarIdentificador() << ".\n";
    }
}

void Cliente::reservarLivro(Livro* livro) {
    // Implementação para reservar um livro
    if (livro->retornarStatus(livro->retornarIdentificador()) == "0") { // Verifica se o livro está disponível
        livrosEmprestados.push_back(livro);
        livro->retornarStatus(1); // Marca o livro como emprestado
        std::cout << "Livro " << livro->retornarIdentificador() << " reservado pelo cliente " << nome << ".\n";
    } else {
        std::cout << "Livro " << livro->retornarIdentificador() << " não está disponível para reserva.\n";
    }
}

void Cliente::devolverLivro(Livro* livro) {
    // Implementação para devolver um livro
    auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), livro);
    if (it != livrosEmprestados.end()) {
        livrosEmprestados.erase(it);
        livro->retornarStatus(2); // Marca o livro como em processo de devolução
        std::cout << "Livro " << livro->retornarIdentificador() << " devolvido pelo cliente " << nome << ".\n";
    } else {
        std::cout << "O livro " << livro->retornarIdentificador() << " não está emprestado por " << nome << ".\n";
    }
}



void Cliente::consultarStatusEmprestimo(Livro* livro) {
    // Implementação para consultar o status do empréstimo de um livro
    auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), livro);
    if (it != livrosEmprestados.end()) {
        std::cout << "O livro " << livro->retornarIdentificador() << " está atualmente emprestado por " << nome << ".\n";
    } else {
        std::cout << "O livro " << livro->retornarIdentificador() << " não está emprestado por " << nome << ".\n";
    }
}

// Funcionalidades - Autenticação e Acesso
bool Cliente::fazerLogin(const std::string& usuario, const std::string& senha) {
    return (this->email == usuario || this->identificador == usuario) && this->senha == senha;
}

// Funcionalidades - Busca e Consulta
void Cliente::consultarStatusEmprestimo(Livro* livro) {
    // Implementação para consultar o status do empréstimo de um livro
    auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), livro);
    if (it != livrosEmprestados.end()) {
        std::cout << "O livro " << livro->retornarIdentificador() << " está atualmente emprestado por " << nome << ".\n";
    } else {
        std::cout << "O livro " << livro->retornarIdentificador() << " não está emprestado por "
