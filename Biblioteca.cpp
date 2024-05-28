          private:                  
                   string localizarLivro (int);
                   // Percorrer a string ate identificar a posicao com a mesma id inserida pelo usuario
                   // pedir a id, for,  
                   string multar(int); 
                   // recebe status,recebe data, calcula os dias de atraso, calcula a multa, muda o status do emprestimo para atrasado

                 // if existe no acervo-> editar propriedade/ else n'ao existe -> livros indisponivel no acervo e/ou emprestado
                   string editarPropriedades(string,int,int); 
                   // statusEmprestimo(multa paga ou nao), statusCondição(desgaste), statusLivro(disponivel ou n)
                   string cadastrarLivro(int,string,string,int,string,string,int,string); 
                  // if livro ja existente, mensagem: livro qnt + 1; else realiza cadastro
                   string acervo(string);
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
