#include "Livro.hpp"

#include <iostream>
#include <string>

using namespace std;

// Construtor completo da classe Livro
// Inicializa todos os atributos do objeto Livro
Livro::Livro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro) {
    
    // Inicialização dos atributos com os parâmetros fornecidos
    this->identificador_livro = identificador_livro;
    this->titulo_livro = titulo_livro;
    this->autor_livro = autor_livro;
    this->ano_publicacao = ano_publicacao;
    this->genero_livro = genero_livro;
    this->condicao_livro = condicao_livro;
    this->status_livro = status_livro;
    this->localizacao_livro = localizacao_livro; 
    
}

// Construtor parcial da classe Livro
// Inicializa alguns atributos do objeto Livro
Livro::Livro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro) {
    
    // Inicialização dos atributos com os parâmetros fornecidos
    // Os atributos não fornecidos podem ser inicializados com valores padrão
    this->identificador_livro = identificador_livro;
    this->titulo_livro = titulo_livro;
    this->autor_livro = autor_livro;
    this->ano_publicacao = ano_publicacao;
    this->genero_livro = genero_livro;
    this->condicao_livro = "Desconhecida";
    this->status_livro = 0;
    this->localizacao_livro = "Desconhecida";

}

// Construtor básico da classe Livro
// Inicializa apenas o identificador do livro
Livro::Livro(int identificador_livro) {
    
    // Inicialização do identificador com o parâmetro fornecido
    // Os outros atributos podem ser inicializados com valores padrão
    this->identificador_livro = identificador_livro;
    this->titulo_livro = "Desconhecido";
    this->autor_livro = "Desconhecido";
    this->ano_publicacao = 0;
    this->genero_livro = "Desconhecido";
    this->condicao_livro = "Desconhecida";
    this->status_livro = 0;
    this->localizacao_livro = "Desconhecida";
}

// Função para retornar o identificador do livro
int Livro::retornarIdentificador() {
    
    // Retorna o identificador do livro
     return this->identificador_livro;
}

// Função para retornar o status do livro com base no identificador fornecido
string Livro::retornarStatus(int identificador_livro) {
    
    // Retorna o status do livro
    if (this->identificador_livro == identificador_livro) {
        if (this->status_livro == 0) {
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
    if (this->identificador_livro == identificador_livro) {
        if (this->localizacao_livro == "Desconhecida") {
            return "Localização desconhecida";
        } else {
            return this->localizacao_livro;
        }
    }
    return "Insira um Id válido";
}
    


// Função para retornar a condição do livro com base no identificador fornecido
string Livro::retornarCondicao(int identificador_livro) {
    
    // Retorna a condição do livro
    if (this->identificador_livro == identificador_livro) {
        if (this->condicao_livro == "Desconhecida") {
            return "Condição desconhecida";
        } else {
            return this->condicao_livro;
        }
    }
    return "Insira um Id válido";
    
}
