#include "Livro.hpp"

#include <iostream>
#include <string>

using namespace std;

// Construtor completo da classe Livro
// Inicializa todos os atributos do objeto Livro
Livro::Livro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro) {
    
    // Inicialização dos atributos com os parâmetros fornecidos
    this->identificadorLivro = identificador_livro;
    this->tituloLivro = titulo_livro;
    this->autorLivro = autor_livro;
    this->anoPublicacao = ano_publicacao;
    this->generoLivro = genero_livro;
    this->condicaoLivro = condicao_livro;
    this->statusLivro = status_livro;
    this->localizacaoLivro = localizacao_livro; 
    
}

// Construtor parcial da classe Livro
// Inicializa alguns atributos do objeto Livro
Livro::Livro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro) {
    
    // Inicialização dos atributos com os parâmetros fornecidos
    // Os atributos não fornecidos podem ser inicializados com valores padrão
    this->identificadorLivro = identificador_livro;
    this->tituloLivro = titulo_livro;
    this->autorLivro = autor_livro;
    this->anoPublicacao = ano_publicacao;
    this->generoLivro = genero_livro;
   
}
// Construtor básico da classe Livro
// Inicializa apenas o identificador do livro
Livro::Livro(int identificador_livro) {
    
    // Inicialização do identificador com o parâmetro fornecido
    // Os outros atributos podem ser inicializados com valores padrão
    this->identificadorLivro = identificador_livro;

}

// Função para retornar o identificador do livro
int Livro::retornarIdentificador() {
    
    // Retorna o identificador do livro
     return this->identificadorLivro;
}

// Função para retornar o status do livro com base no identificador fornecido
string Livro::retornarStatus(int identificador_livro) {
    
    // Retorna o status do livro
    if (this->identificadorLivro == identificador_livro) {
        if (this->statusLivro == 0) {
            return "Livro indisponível";
        } else {
            return "Livro disponível";
        }
    }
    return "Insira um Id válido";
}

// Função para retornar a localização do livro com base no identificador fornecido
string Livro::retornarLocalizacao(int identificador_livro) {
    
    // Retorna a localização do livro
    if (this->identificadorLivro == identificador_livro) {
        if (this->localizacaoLivro == "Desconhecida") {
            return "Localização desconhecida";
        } else {
            return this->localizacaoLivro;
        }
    }
    return "Insira um Id válido";
}
    


// Função para retornar a condição do livro com base no identificador fornecido
string Livro::retornarCondicao(int identificadorLivro) {
    
    // Retorna a condição do livro
    if (this->identificadorLivro == identificadorLivro) {
        if (this->condicaoLivro == "Desconhecida") {
            return "Condição desconhecida";
        } else {
            return this->condicaoLivro;
        }
    }
    return "Insira um Id válido";
    
}