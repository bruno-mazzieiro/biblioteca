#include "Biblioteca.hpp"
#include "Livro.hpp"
#include "Cliente.hpp"
#include <iostream>

int main() {
    Biblioteca biblioteca;
    using namespace std;

    int escolha;
    do {
        cout << "\n===== Biblioteca =====\n";
        cout << "1. Cadastrar Livro\n";
        cout << "2. Editar Propriedades do Livro\n";
        cout << "3. Localizar Livro\n";
        cout << "4. Multar Livro\n";
        cout << "5. Receber Livro\n";
        cout << "6. Cadastrar Cliente\n";
        cout << "7. Receber Pagamento\n";
        cout << "8. Enviar Notificações\n";
        cout << "9. Enviar Cobranças\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                int id, ano, status;
                string titulo, autor, genero, condicao, localizacao;
                cout << "ID do Livro: ";
                cin >> id;
                cout << "Título do Livro: ";
                cin >> titulo;
                cout << "Autor do Livro: ";
                cin >> autor;
                cout << "Ano de Publicação: ";
                cin >> ano;
                cout << "Gênero do Livro: ";
                cin >> genero;
                cout << "Condição do Livro: ";
                cin >> condicao;
                cout << "Status do Livro (1 - Disponível, 2 - Emprestado, 3 - Multado): ";
                cin >> status;
                cout << "Localização do Livro: ";
                cin >> localizacao;

                Livro* livro = biblioteca.cadastrarLivro(id, titulo, autor, ano, genero, condicao, status, localizacao);
                if (livro) {
                    cout << "Livro cadastrado com sucesso.\n";
                } else {
                    cout << "Erro: Livro com ID " << id << " já existe.\n";
                }
                break;
            }
            case 2: {
                int id, condicao, status;
                string multa;
                cout << "ID do Livro: ";
                cin >> id;
                cout << "Nova Condição do Livro: ";
                cin >> condicao;
                cout << "Novo Status do Livro: ";
                cin >> status;
                cout << "Nova Multa: ";
                cin >> multa;

                Livro* livro = biblioteca.editarPropriedades(id, multa, condicao, status);
                if (livro) {
                    cout << "Propriedades do livro editadas com sucesso.\n";
                } else {
                    cout << "Erro: Livro com ID " << id << " não encontrado.\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "ID do Livro: ";
                cin >> id;

                Livro* livro = biblioteca.localizarLivro(id);
                if (livro) {
                    cout << "Livro localizado: " << livro->retornarIdentificador() << " - " << livro->retornarStatus(id) << "\n";
                } else {
                    cout << "Erro: Livro com ID " << id << " não encontrado.\n";
                }
                break;
            }
            case 4: {
                int id;
                cout << "ID do Livro: ";
                cin >> id;

                Livro* livro = biblioteca.multar(id);
                if (livro) {
                    cout << "Livro multado. Multa atual: " << livro-> multa << "\n";
                } else {
                    cout << "Erro: Livro com ID " << id << " não encontrado ou não está emprestado.\n";
                }
                break;
            }
            case 5: {
                int id;
                cout << "ID do Livro: ";
                cin >> id;

                string resultado = biblioteca.receberLivro(id);
                cout << resultado << "\n";
                break;
            }
            case 6: {
                string resultado = biblioteca.cadastroCliente();
                cout << resultado << "\n";
                break;
            }
            case 7: {
                int id;
                cout << "ID do Livro: ";
                cin >> id;

                string resultado = biblioteca.receberPagamento(id);
                cout << resultado << "\n";
                break;
            }
            case 8: {
                string resultado = biblioteca.enviarNotificacao();
                cout << resultado << "\n";
                break;
            }
            case 9: {
                string resultado = biblioteca.enviarCobranca();
                cout << resultado << "\n";
                break;
            }
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (escolha != 0);

    return 0;
}
