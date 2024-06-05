#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Livro.hpp"
#include "Biblioteca.hpp"

Livro*  Biblioteca::cadastrarLivro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro){
                    for(const Livro &livro : livros){
                        if(livro.identificadorLivro == identificador_livro){
                            return nullptr;
                        }
                    }
                    livros.push_back(Livro(identificador_livro, titulo_livro, autor_livro, ano_publicacao, genero_livro, condicao_livro, status_livro, localizacao_livro));
                    return &livros.back();
                }
                
                  // if livro ja existente, mensagem: livro qnt + 1; else realiza cadastro
                
                // statusEmprestimo(multa paga ou nao), statusCondição(desgaste), statusLivro(disponivel ou n)
                Livro*  Biblioteca::editarPropriedades(string multa,int condicao_livro,int status_livro){
                    for(const Livro &livro : livros){
                        if(livro.identificadorLivro == identificador_livro){
                          cout<<"Condicao multa:"<<multa<<endl;
                          cout<<"Altere a condicao da multa se necessario:"<<endl;
                          cin<<multa;
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
    Livro* multar(int identificador_livro) {
        for (Livro &livro : livros) {
            if (livro.identificadorLivro == identificador_livro && livro.status == 1) {
                // Data atual
                auto agora = std::chrono::system_clock::now();
                
                // Cálculo da diferença em dias
                auto duracao = std::chrono::duration_cast<std::chrono::hours>(agora - livro.dataEmprestimo).count();
                int diasPassados = duracao / 24;

                if (diasPassados > 15) {
                    int diasAtraso = diasPassados - 15;
                    livro.multa = diasAtraso * 1.0; // 1 real por dia de atraso
                    livro.status = 2; // Status "atrasado"
                }

                return &livro;
            }
        } 
          return nullptr;
    }
                   // recebe status,recebe data, calcula os dias de atraso, calcula a multa, muda o status do emprestimo para atrasado
//data recebida faca o calculo do prazo de entrega sendo que a pessoa pode ficar 15 dias com livro, depois calcule a multa a ser paga que sera 1 real a cada dia de atraso. Alem disso tenha uma variavel que mude o status do emprestimo para pagamentoa atrasad

              //mostrar o livro
                        for(const Livro &livro : livros){
                            cout << livro.identificadorLivro <<" "<< livro.autorLivro << endl;
                        }
                  
// Recebe um livro de volta e muda o status para "disponível"
string Biblioteca::receberLivro(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            livro.statusLivro = 1; // 1 indica que o livro está disponível
            return "Livro recebido.";
        }
    }
    return "Livro não encontrado.";
}

// Função para gerar o identificador do cliente
string gerarIdentificador(const string& nome, const string& telefone) {
    if (nome.length() < 2 || telefone.length() < 4) {
        throw invalid_argument("Nome deve ter pelo menos 2 caracteres e telefone deve ter pelo menos 4 dígitos.");
    }
    string id = nome.substr(0, 2) + telefone.substr(telefone.length() - 4);
    return id;
}

// Cadastro de cliente
string Biblioteca::cadastroCliente() {
    // Pedir dados do cliente
    int idade;
    string nome, endereco, telefone, email, senha;

    cout << "Digite o nome do cliente: ";
    cin >> nome;
    cout << "Digite a idade do cliente: ";
    cin >> idade;
    cout << "Digite o endereco do cliente: ";
    cin >> endereco;
    cout << "Digite o telefone do cliente: ";
    cin >> telefone;
    cout << "Digite o email do cliente: ";
    cin >> email;
    cout << "Digite a senha do cliente: ";
    cin >> senha;

    try {
        string identificador = gerarIdentificador(nome, telefone);

        // Verifica se o identificador já existe
        for (const Cliente& cliente : clientes) {
            if (cliente.getIdentificador() == identificador) {
                return "Erro: Já existe um cliente com o mesmo identificador.";
            }
        }

        Cliente novoCliente(nome, endereco, telefone, email, senha); // Utiliza a senha fornecida pelo usuário
        novoCliente.setIdentificador(identificador);

        clientes.push_back(novoCliente);

        return "Cliente cadastrado com sucesso. ID: " + identificador;
    } catch (const invalid_argument& e) {
        return e.what();
    }
}

// Função para receber o pagamento de uma multa
string Biblioteca::receberPagamento(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            if (livro.statusLivro == 2) { // 2 indica que o livro está com multa pendente
                cout << "O valor da multa é: " << livro.multa << " reais." << endl;
                double valorPago;
                cout << "Digite o valor pago pelo cliente: ";
                cin >> valorPago;
                
                if (valorPago == livro.multa) {
                    livro.statusLivro = 1; // 1 indica que o livro está disponível novamente
                    livro.multa = 0; // Zera o valor da multa
                    return "Pagamento realizado com sucesso. Multa paga.";
                } else {
                    // Se o valor pago não corresponder à multa, chamar função enviarCobranca (a ser implementada)
                    enviarCobranca();
                    return "Valor errado. Multa não paga. Enviando cobrança.";
                }
            } else {
                return "Livro não possui multa pendente.";
            }
        }
    }
    return "Livro não encontrado.";
}

          public:  

string Biblioteca::enviarNotificacao() {
    auto hoje = chrono::system_clock::now(); // Data atual

    for (Livro &livro : livros) {
        if (livro.statusLivro == 1) { // 1 indica que o livro está emprestado
            // Supondo que dataEmprestimo é do tipo chrono::system_clock::time_point
            auto duracao = chrono::duration_cast<chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasRestantes = 15 - diasPassados; // Supondo que o empréstimo é de 15 dias

            if (diasRestantes <= 5 && diasRestantes > 0) {
                cout << "Faltam " << diasRestantes << " dias para o seu empréstimo do livro " << livro.tituloLivro << " acabar." << endl;
            }
        }
    }

    return "Notificações enviadas.";
}


string Biblioteca::enviarCobranca() {
    auto hoje = chrono::system_clock::now(); // Data atual

    for (Livro &livro : livros) {
        if (livro.statusLivro == 2) { // 2 indica que o livro está com multa pendente
            auto duracao = chrono::duration_cast<chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasDeEmprestimo = 15;
            int diasAtraso = diasPassados - diasDeEmprestimo;
            if (diasAtraso > 0) {
                auto dataFinal = livro.dataEmprestimo + chrono::hours(diasDeEmprestimo * 24);
                time_t dataFinalTimeT = chrono::system_clock::to_time_t(dataFinal);
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d", localtime(&dataFinalTimeT));
                cout << "Você não devolveu o livro até a data " << buffer << ". Devido a isso, agora você tem uma multa de " << livro.multa << " reais." << endl;
            }
        }
    }

    return "Cobranças enviadas.";
}
