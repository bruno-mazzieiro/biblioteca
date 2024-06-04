#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>
#include <memory>

class Livro;
class Biblioteca;

class Cliente {
public:
  // Construtor
  Cliente(const std::string& nome, const std::string& endereco, const std::string& telefone,
         const std::string& email);

  // Getters
  const std::string& getIdentificador() const;
  const std::string& getNome() const;
  const std::string& getEndereco() const;
  const std::string& getTelefone() const;
  const std::string& getEmail() const;
  const std::vector<Livro*>& getLivrosEmprestados() const;
  const std::vector<double>& getMultasPendentes() const;

  // Setters
  void setIdentificador(const std::string& identificador);
  void setNome(const std::string& nome);
  void setEndereco(const std::string& endereco);
  void setTelefone(const std::string& telefone);
  void setEmail(const std::string& email);

  // Funcionalidades - Interação com Livros
  void pagarMulta(Livro* livro);
  void reservarLivro(Livro* livro);
  void devolverLivro(Livro* livro);
  void receberNotificacao(const std::string& mensagem);
  void consultarStatusEmprestimo(Livro* livro);

  // Funcionalidades - Autenticação e Acesso
  bool fazerLogin(const std::string& usuario, const std::string& senha);

  // Funcionalidades - Busca e Consulta
  void localizarLivro(const std::string& termoBusca);

private:
  // Atributos
  std::string identificador;
  std::string nome;
  std::string endereco;
  std::string telefone;
  std::string email;
  std::vector<Livro*> livrosEmprestados;
  std::vector<double> multasPendentes;
};

#endif // CLIENTE_HPP
