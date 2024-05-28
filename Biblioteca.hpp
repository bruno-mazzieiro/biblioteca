#ifndef Biblioteca_H
#define Biblioteca_H 

#include <iostream>
#include <string>

class Biblioteca { 

          private:
                   string localizarLivro (int);// percorrer a string até identificar a localização
                   string multar(int); // recebe o statusEmprestimo, informa o valor da multa e muda o status (1 real por dia de atraso)
                   string editarPropriedades(string,int,int); // condicao do livro, status do livro (disponivel ou emprestado) 
                    //e status do emprestimo (pagamento atrasado etc)
                   string acervo(string);//mostrar o titulo dos livros
                   string cadastrarLivro(int,string,string,int,string,string,int,string); // dados do livro 
                   string receberLivro(int);
                   string cadastroCliente(int;string;string;int;string);// dados do cliente
                   string receberPagamento(int); // status da multa
                   
          public:  
                  string enviarNotificacao();
                  string enviarCobranca();
                   
