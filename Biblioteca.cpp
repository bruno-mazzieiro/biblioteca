#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Livro.hpp"
#include "Biblioteca.hpp"

// Função para cadastrar um novo livro na biblioteca
Livro* Biblioteca::cadastrarLivro(int identificador_livro, std::string titulo_livro, std::string autor_livro, int ano_publicacao, std::string genero_livro, std::string condicao_livro, int status_livro, std::string localizacao_livro) {
    for (const Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) { // Verifica se o livro já existe
            return nullptr; // Retorna nullptr se o livro já está cadastrado
        }
    }
    livros.push_back(Livro(identificador_livro, titulo_livro, autor_livro, ano_publicacao, genero_livro, condicao_livro, status_livro, localizacao_livro)); // Adiciona o novo livro ao vetor
    return &livros.back(); // Retorna um ponteiro para o novo livro
}

// Função para editar as propriedades de um livro
Livro* Biblioteca::editarPropriedades(std::string multa, int condicao_livro, int status_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) { // Localiza o livro pelo identificador
            std::cout << "Condicao multa: " << multa << std::endl;
            std::cout << "Altere a condicao da multa se necessario:" << std::endl;
            std::cin >> multa; // Atualiza a multa
            std::cout << "Insira a condicao do livro " << identificador_livro << std::endl;
            std::cin >> condicao_livro; // Atualiza a condição do livro
            std::cout << "Insira o status de disponibilidade do livro " << identificador_livro << std::endl;
            std::cin >> status_livro; // Atualiza o status do livro
            livro.setCondicaoLivro(condicao_livro);
            livro.setStatusLivro(status_livro);
            livro.setMulta(multa);
            return &livro; // Retorna um ponteiro para o livro atualizado
        }
    }
    return nullptr;
}

// Função para localizar um livro pelo identificador
Livro* Biblioteca::localizarLivro(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) { // Verifica se o identificador corresponde
            return &livro; // Retorna um ponteiro para o livro encontrado
        }
    }
    return nullptr; // Retorna nullptr se o livro não foi encontrado
}

// Função para aplicar uma multa a um livro emprestado
Livro* Biblioteca::multar(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro && livro.statusLivro == 1) { // Verifica se o livro está emprestado
            auto agora = std::chrono::system_clock::now(); // Obtém a data atual
            auto duracao = std::chrono::duration_cast<std::chrono::hours>(agora - livro.dataEmprestimo).count(); // Calcula a duração do empréstimo em horas
            int diasPassados = duracao / 24; // Converte a duração para dias

            if (diasPassados > 15) { // Verifica se o livro está atrasado
                int diasAtraso = diasPassados - 15; // O prazo de empréstimo é de 15 dias, após isso é atraso.
                livro.multa = diasAtraso * 1.0; // Calcula a multa (1 real por dia de atraso)
                livro.statusLivro = 2; // Atualiza o status do livro para "atrasado"
            }

            return &livro; // Retorna um ponteiro para o livro multado
        }
    }
    return nullptr; // Retorna nullptr se o livro não foi encontrado ou não está emprestado
}

// Função para receber um livro de volta e mudar o status para "disponível"
std::string Biblioteca::receberLivro(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) { // Verifica se o livro foi encontrado
            livro.statusLivro = 1; // Atualiza o status do livro para disponível
            return "Livro recebido."; // Retorna mensagem de sucesso
        }
    }
    return "Livro não encontrado."; // Retorna mensagem de erro se o livro não for encontrado
}

// Função para gerar o identificador do cliente
std::string gerarIdentificador(const std::string& nome, const std::string& telefone) {
    if (nome.length() < 2 || telefone.length() < 4) { // Verifica se o nome e o telefone têm o comprimento mínimo necessário
        throw std::invalid_argument("Nome deve ter pelo menos 2 caracteres e telefone deve ter pelo menos 4 dígitos.");
    }
    std::string id = nome.substr(0, 2) + telefone.substr(telefone.length() - 4); // Gera o identificador usando as duas primeiras letras do nome e os quatro últimos dígitos do telefone
    return id;
}

// Função de cadastro de cliente
std::string Biblioteca::cadastroCliente() {
    int idade;
    std::string nome, endereco, telefone, email, senha;

    std::cout << "Digite o nome do cliente: ";
    std::cin >> nome;
    std::cout << "Digite a idade do cliente: ";
    std::cin >> idade;
    std::cout << "Digite o endereco do cliente: ";
    std::cin >> endereco;
    std::cout << "Digite o telefone do cliente: ";
    std::cin >> telefone;
    std::cout << "Digite o email do cliente: ";
    std::cin >> email;
    std::cout << "Digite a senha do cliente: ";
    std::cin >> senha;

    try {
        std::string identificador = gerarIdentificador(nome, telefone);

        for (const Cliente& cliente : clientes) {
            if (cliente.getIdentificador() == identificador) { // Verifica se o identificador já existe
                return "Erro: Já existe um cliente com o mesmo identificador.";
            }
        }

        Cliente novoCliente(nome, endereco, telefone, email, senha); // Cria um novo cliente
        novoCliente.setIdentificador(identificador);

        clientes.push_back(novoCliente); // Adiciona o novo cliente ao vetor de clientes

        return "Cliente cadastrado com sucesso. ID: " + identificador; // Retorna mensagem de sucesso
    } catch (const std::invalid_argument& e) {
        return e.what(); // Retorna mensagem de erro em caso de exceção
    }
}

// Função para receber o pagamento de uma multa
std::string Biblioteca::receberPagamento(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            if (livro.statusLivro == 2) { // Verifica se o livro está com multa pendente
                std::cout << "O valor da multa é: " << livro.multa << " reais." << std::endl;
                double valorPago;
                std::cout << "Digite o valor pago pelo cliente: ";
                std::cin >> valorPago;

                if (valorPago == livro.multa) { // Verifica se o valor pago corresponde à multa
                    livro.statusLivro = 1; // Atualiza o status do livro para disponível novamente
                    livro.multa = 0; // Zera o valor da multa
                    return "Pagamento realizado com sucesso. Multa paga."; // Retorna mensagem de sucesso
                } else {
                    enviarCobranca(); // Envia cobrança se o valor estiver incorreto
                    return "Valor errado. Multa não paga. Enviando cobrança."; // Retorna mensagem de erro
                }
            } else {
                return "Livro não possui multa pendente."; // Retorna mensagem se o livro não tem multa pendente
            }
        }
    }
    return "Livro não encontrado."; // Retorna mensagem se o livro não foi encontrado
}

// Função para enviar notificações sobre empréstimos
std::string Biblioteca::enviarNotificacao() {
    auto hoje = std::chrono::system_clock::now(); // Data atual

    for (Livro &livro : livros) {
        if (livro.statusLivro == 1) { // Verifica se o livro está emprestado
            auto duracao = std::chrono::duration_cast<std::chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasRestantes = 15 - diasPassados; // Supondo que o empréstimo é de 15 dias

            if (diasRestantes <= 5 && diasRestantes > 0) { // Verifica se faltam 5 dias ou menos
                std::cout << "Faltam " << diasRestantes << " dias para o seu empréstimo do livro " << livro.tituloLivro << " acabar." << std::endl;
            }
        }
    }

    return "Notificações enviadas."; // Retorna mensagem de sucesso
}

// Função para enviar cobranças sobre multas pendentes
std::string Biblioteca::enviarCobranca() {
    auto hoje = std::chrono::system_clock::now(); // Data atual

    for (Livro &livro : livros) {
        if (livro.statusLivro == 2) { // Verifica se o livro está com multa pendente
            auto duracao = std::chrono::duration_cast<std::chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasDeEmprestimo = 15;
            int diasAtraso = diasPassados - diasDeEmprestimo;
            if (diasAtraso > 0) { // Verifica se há atraso
                auto dataFinal = livro.dataEmprestimo + std::chrono::hours(diasDeEmprestimo * 24);
                time_t dataFinalTimeT = std::chrono::system_clock::to_time_t(dataFinal);
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d", localtime(&dataFinalTimeT));
                std::cout << "Você não devolveu o livro até a data " << buffer << ". Devido a isso, agora você tem uma multa de " << livro.multa << " reais." << std::endl;
            }
        }
    }

    return "Cobranças enviadas."; // Retorna mensagem de sucesso
}

#endif
