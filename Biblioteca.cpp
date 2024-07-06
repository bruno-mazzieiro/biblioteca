#include "Biblioteca.hpp"
#include "Cliente.hpp"
#include "Livro.hpp"

using namespace std;

Livro* Biblioteca::cadastrarLivro(int identificador_livro, string titulo_livro, string autor_livro, int ano_publicacao, string genero_livro, string condicao_livro, int status_livro, string localizacao_livro) {
    for (const Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            return nullptr;
        }
    }
    livros.push_back(Livro(identificador_livro, titulo_livro, autor_livro, ano_publicacao, genero_livro, condicao_livro, status_livro, localizacao_livro));
    return &livros.back();
}

Livro* Biblioteca::editarPropriedades(int identificador_livro, string multa, int condicao_livro, int status_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            livro.retornarCondicao(condicao_livro);
            livro.retornarStatus(status_livro);
            return &livro;
        }
    }
    return nullptr;
}

Livro* Biblioteca::localizarLivro(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            return &livro;
        }
    }
    return nullptr;
}

Livro* Biblioteca::multar(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro && livro.retornarStatus(identificador_livro) == "Emprestado") {
            auto agora = chrono::system_clock::now();
            auto duracao = chrono::duration_cast<chrono::hours>(agora - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            if (diasPassados > 15) {
                int diasAtraso = diasPassados - 15;
                livro.multa = diasAtraso * 1.0;
                livro.statusLivro = 2;
            }
            return &livro;
        }
    }
    return nullptr;
}

string Biblioteca::receberLivro(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            livro.retornarStatus(1);
            return "Livro recebido.";
        }
    }
    return "Livro não encontrado.";
}

string Biblioteca::cadastroCliente() {
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
        string identificador = nome.substr(0, 2) + telefone.substr(telefone.length() - 4);
        for (const Cliente& cliente : clientes) {
            if (cliente.getIdentificador() == identificador) {
                return "Erro: Já existe um cliente com o mesmo identificador.";
            }
        }
        Cliente novoCliente(nome, endereco, telefone, email, senha);
        novoCliente.setIdentificador(identificador);
        clientes.push_back(novoCliente);
        return "Cliente cadastrado com sucesso. ID: " + identificador;
    } catch (const invalid_argument& e) {
        return e.what();
    }
}

string Biblioteca::receberPagamento(int identificador_livro) {
    for (Livro &livro : livros) {
        if (livro.retornarIdentificador() == identificador_livro) {
            if (livro.retornarStatus(identificador_livro) == "Multado") {
                cout << "O valor da multa é: " << livro.multa << " reais." << endl;
                double valorPago;
                cout << "Digite o valor pago pelo cliente: ";
                cin >> valorPago;
                if (valorPago == livro.multa) {
                    livro.retornarStatus(1);
                    livro.multa = 0;
                    return "Pagamento realizado com sucesso. Multa paga.";
                } else {
                    return "Valor errado. Multa não paga.";
                }
            } else {
                return "Livro não possui multa pendente.";
            }
        }
    }
    return "Livro não encontrado.";
}

string Biblioteca::enviarNotificacao() {
    auto hoje = chrono::system_clock::now();
    for (Livro &livro : livros) {
        if (livro.retornarStatus(livro.retornarIdentificador()) == "Emprestado") {
            auto duracao = chrono::duration_cast<chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasRestantes = 15 - diasPassados;
            if (diasRestantes <= 5 && diasRestantes > 0) {
                cout << "Faltam " << diasRestantes << " dias para o seu empréstimo do livro " << livro.retornarIdentificador() << " acabar." << endl;
            }
        }
    }
    return "Notificações enviadas.";
}

string Biblioteca::enviarCobranca() {
    auto hoje = chrono::system_clock::now();
    for (Livro &livro : livros) {
        if (livro.retornarStatus(livro.retornarIdentificador()) == "Multado") {
            auto duracao = chrono::duration_cast<chrono::hours>(hoje - livro.dataEmprestimo).count();
            int diasPassados = duracao / 24;
            int diasAtraso = diasPassados - 15;
            if (diasAtraso > 0) {
                cout << "Você não devolveu o livro até a data de vencimento. Devido a isso, agora você tem uma multa de " << livro.multa << " reais." << endl;
            }
        }
    }
    return "Cobranças enviadas.";
}
