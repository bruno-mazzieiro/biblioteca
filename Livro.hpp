#ifndef Livro_H
#define Livro_H 

#include <iostream>
#include <string>

class Livro {
	
	private:
		int identificadorLivro;
		string tituloLivro;
		string autorLivro;
		int anoPublicacao;
		string generoLivro;
		string condicaoLivro;
		int statusLivro;				//0 - Disponivel; 1 - Emprestado; 2 - Em processo de devolucao; 3 - Outro
		string localizacaoLivro;		
		
	public:
		Livro (int, string, string, int, string, string, int, string);
		Livro (int, string, string, int, string);
		Livro (int);
		int retornarIdentificador();
		string retornarStatus (int);
		string retornarLocalizacao(int);
		string retornarCondicao (int);
	
};




#endif