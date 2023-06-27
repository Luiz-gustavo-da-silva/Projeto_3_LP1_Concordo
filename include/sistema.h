/**
 * @file sistema.h
 * @brief Declaração da classe Sistema.h.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <vector>

#include "canal.h"
#include "usuario.h"
#include "servidor.h"

using namespace std;

/**
 * @brief Classe que representa o sistema.
 */
class Sistema
{
public:
    /**
     * @brief Vetor de ponteiros para objetos da classe Usuario.
     */
    vector<Usuario *> usuarios;

    /**
     * @brief Vetor de ponteiros para objetos da classe Servidor.
     */
    vector<Servidor *> servidores;

    /**
     * @brief Ponteiro para o objeto Usuario atualmente logado.
     */
    Usuario *usuarioAtual = nullptr;

    /**
     * @brief Ponteiro para o objeto Servidor atualmente selecionado.
     */
    Servidor *servidorAtual = nullptr;

    /**
     * @brief Ponteiro para o objeto Canal atualmente selecionado.
     */
    Canal *canalAtual;

    /**
     * @brief Destrutor da classe Sistema.
     */
    ~Sistema();

    /**
     * @brief Cadastra um objeto Usuario no sistema.
     * @param usuario Ponteiro para o objeto Usuario a ser cadastrado.
     */
    void cadastrarUsuario(Usuario *usuario);

    /**
     * @brief Verifica se um Usuario com o email fornecido já existe no sistema.
     * @param email Email do Usuario a ser verificado.
     * @return true se o Usuario existe, false caso contrário.
     */
    bool usuarioExiste(string email);

    /**
     * @brief Realiza o login de um Usuario no sistema.
     * @param email Email do Usuario a ser logado.
     * @param senha Senha do Usuario a ser logado.
     * @return true se o login foi bem-sucedido, false caso contrário.
     */
    bool login(string email, string senha);

    /**
     * @brief Realiza o logout do Usuario atualmente logado.
     */
    void logout();

    /**
     * @brief Verifica se há um Usuario logado no sistema.
     * @return true se houver um Usuario logado, false caso contrário.
     */
    bool verificaUsuarioLogado();

    /**
     * @brief Cria um objeto Servidor e o adiciona ao sistema.
     * @param servidor Ponteiro para o objeto Servidor a ser criado.
     */
    void criarServidor(Servidor *servidor);

    /**
     * @brief Verifica se um Servidor com o nome fornecido já existe no sistema.
     * @param nome Nome do Servidor a ser verificado.
     * @return true se o Servidor existe, false caso contrário.
     */
    bool servidorExiste(string nome);

    /**
     * @brief Retorna um ponteiro para o Servidor com o nome fornecido.
     * @param nome Nome do Servidor a ser retornado.
     * @return Ponteiro para o Servidor com o nome fornecido ou nullptr se não encontrado.
     */
    Servidor *retornaServidor(string nome);

    /**
     * @brief Lista os nomes de todos os servidores do sistema.
     */
    void listarServidores();

    /**
     * @brief Remove um Servidor com o nome fornecido do sistema.
     * @param nome Nome do Servidor a ser removido.
     */
    void removerServidor(string nome);

    /**
     * @brief Retorna um ponteiro para o Usuario com o email fornecido.
     * @param email Email do Usuario a ser retornado.
     * @return Ponteiro para o Usuario com o email fornecido ou nullptr se não encontrado.
     */
    Usuario *retornaUsuario(string email);

    /**
     * @brief Adiciona o Usuario atualmente logado a um Servidor com o nome e código de convite fornecidos.
     * @param nome Nome do Servidor ao qual o Usuario será adicionado.
     * @param codigoConvite Código de convite do Servidor ao qual o Usuario será adicionado.
     * @return 1 se o Usuario foi adicionado com sucesso, 2 se o código de convite é inválido e 3 se o Servidor não foi encontrado.
     */
    int adicionarUsuarioNoServidor(string nome, string codigoConvite);

    /**
     * @brief Verifica se o Usuario está associado a um Servidor.
     * @return true se o Usuario está associado a um Servidor, false caso contrário.
     */
    bool verificaUsuarioNoServidor();

    /**
     * @brief Remove a associação do Usuario atual com o Servidor.
     */
    void sairServidor();

    /**
     * @brief Retorna um ponteiro para o Servidor atualmente selecionado.
     * @return Ponteiro para o Servidor atualmente selecionado.
     */
    Servidor *retornaServidorAtual();

    /**
     * @brief Lista os nomes dos Usuarios associados ao Servidor atualmente selecionado.
     */
    void listaUsuariosServidor();

    /**
     * @brief Lista os nomes de todos os Usuarios do sistema.
     */
    void listarUsuarios();
};

#endif
