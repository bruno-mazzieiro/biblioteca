#include <iostream>
#include Biblioteca.hpp

Livro*  Biblioteca::cadastrarLivro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro){
                    for(const Livro &livro : livros){
                        if(livro.identificadorLivro == identificador_livro){
                            return nullptr;
                        }
                    }
                    livros.push_back(Livro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro));
                    return &contas.back();
                }
                
                  // if livro ja existente, mensagem: livro qnt + 1; else realiza cadastro
                
                // statusEmprestimo(multa paga ou nao), statusCondição(desgaste), statusLivro(disponivel ou n)
                Livro*  Biblioteca::editarPropriedades(string multa,int condicao_livro,int status_livro){
                    for(const Livro &livro : livros){
                        if(livro.identificadorLivro == identificador_livro){
                                //adicionar um para alterar o status da multa se pago ou nao
                            cout<< "Insira a condicao do livro"<< identificador_livro << endl;
                            cin<<condicao_livro;
                            cout<<"Insira o status de disponibilidade do livro"<< identificador_livro << endl;
                            cin<<status_livro
                        }
                } 
                }
                
                // Percorrer a string ate identificar a posicao com a mesma id inserida pelo usuario      
                Livro*  Biblioteca::localizarLivro (int identificador_livro){
                        for(Livro &livro : livros){
                            if(livro.identificadorLivro = identificador_livro ){
                                return localizacoLivro;
                            }
                        }
                }
                   
                Livro*  Biblioteca::multar(int); 
                   // recebe status,recebe data, calcula os dias de atraso, calcula a multa, muda o status do emprestimo para atrasado
//data recebida faca o calculo do prazo de entrega sendo que a pessoa pode ficar 15 dias com livro, depois calcule a multa a ser paga que sera 1 real a cada dia de atraso. Alem disso tenha uma variavel que mude o status do emprestimo para pagamentoa atrasad
                 
                        for(const Livro &livro : livros){
                            cout << livro.identificadorLivro <<" "<< livro.autorLivro << endl;
                        }
                   
                    //cout dos titulos dos livros
                   string receberLivro(int);
                    //mudança do status de emprestimo (disponivel)
                   string cadastroCliente(int;string;string;int;string);
                    //
                   string receberPagamento(int); 
                    //mudanca statusEmprestimo, 

//funcao pagar multa: criar uma variável Pagamento, se o valor do pagamento for igual ao da Multa o valor será quitado.
pagamento - multa = multa;

          public:  
                  string enviarNotificacao();
                    // dia do vencimento + 15, cout da quantidade de dias que faltam
                    // enviar notificacao dos ultimos 5 dias;
                  string enviarCobranca();
                    // if multa > 0 envia notificacao com o valor da multa


 // para o tamanho da biblioteca, consderar o maior num de id 
