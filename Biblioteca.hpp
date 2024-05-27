#ifndef Biblioteca_H
#define Biblioteca_H 

#include <iostream>
#include <string>

class Biblioteca { 

          private:
                   string localizarLivro (int);
                   string multar(int); // recebe o statusEmprestimo, valor da multa e muda o status 
                   string editarPropriedades(string,int,int); // condicao do livro, status do livro e status do emprestimo
                   
                   string acervo(string);
                   string cadastrarLivro(int,string,string,int,string,string,int,string); // dados do livro 
                   string receberLivro(int);
                   string cadastroCliente(int;string;string;int;string);// dados do cliente
                   string receberPagamento(int); // status da multa
                   
          public:  
                  string enviarNotificacao();
                  string enviarCobranca();
                   
