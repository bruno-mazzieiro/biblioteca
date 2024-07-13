#ifndef Livro_H
#define Livro_H 

#include <iostream>
#include <string>

class Livro {
	
	private:
		int identificadorLivro;
		std::string tituloLivro;
		std::string autorLivro;
		int anoPublicacao;
		std::string generoLivro;
		std::string condicaoLivro;
		int statusLivro;				//0 - Disponivel; 1 - Emprestado; 2 - Em processo de devolucao; 3 - Outro
		std::string localizacaoLivro;	
		std::string multa;	
		
	public:
		//Construtores
		Livro (int, std::string, std::string, int, std::string, std::string, int, std::string);
		Livro (int, std::string, std::string, int, std::string);
		Livro (int);

		//Getters
  		const int& retornarIdentificador() const;
		const std::string& retornarStatus(int) const;
  		const std::string& retornarLocalizacao(int) const;
  		const std::string& retornarCondicao(int) const;


	
};




#endif