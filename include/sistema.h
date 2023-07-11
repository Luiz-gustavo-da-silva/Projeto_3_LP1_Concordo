/**
 * @file sistema.h
 * @brief Declaração da classe Sistema.h.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>

#include "canal.h"
#include "usuario.h"
#include "servidor.h"
#include "mensagem.h"

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
     * @brief Variável que faz o controle dos ids dos usuaários criados
     */
    int id = 0;

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
     */
    void adicionarUsuarioNoServidor(string nome, string codigoConvite);

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
     * @brief Lista os nomes dos Usu*(arios associados ao Servidor atualmente selecionado.
     */
    void listaUsuariosServidor();

    /**
     * @brief Lista os nomes de todos os Usuarios do sistema.
     */
    void listarUsuarios();

    /**
     * @brief Entra em um canal com o nome fornecido no Servidor atualmente selecionado.
     * @param nome Nome do canal a ser acessado.
     * @return true se a entrada no canal foi bem-sucedida, false caso contrário.
     */
    bool entrarCanal(string nome);

    /**
     * @brief Sai do canal atualmente selecionado.
     * @return true se a saída do canal foi bem-sucedida, false caso contrário.
     */
    bool sairCanal();

    /**
     * @brief Verifica se o Usuario está associado a um canal.
     * @return true se o Usuario está associado a um canal, false caso contrário.
     */
    bool verificaUsuarioNoCanal();

    /**
     * @brief Envia uma mensagem para o canal atualmente selecionado.
     * @param mensagem Conteúdo da mensagem a ser enviada.
     */
    void enviarMensagem(string mensagem);

    /**
     * @brief Exibe as mensagens do canal atualmente selecionado.
     * Se não houver nenhuma mensagem para exibir, exibe uma mensagem de aviso.
     */
    void printMensagens();

    /**
     * @brief Chama os métodos salvarUsuarios e salvarServidores para salvar as informações
     * dos usuários e servidores nos arquivos externos.
     */
    void salvar();

    /**
     * @brief Chama os métodos carregarUsuarios e carregarServidores para resgatar as informações
     * dos usuários e servidores nos arquivos externos.
     */
    void carregar();

    // metodo só para teste !!!
    void printUsuario()
    {
        for (Usuario *usuario : usuarios)
        {
            cout << usuario->id << endl;
            cout << usuario->email << endl;
            cout << usuario->senha << endl;
        }
    }

    // metodo só para teste !!!
    void printServidor()
    {
        for (Servidor *servidor : servidores)
        {
            cout << servidor->usuarioDonoId << endl;
            cout << servidor->nome << endl;
            cout << servidor->descricao << endl;
            cout << servidor->codigoConvite << endl;

            servidor->listarCanais();
            for (int n : servidor->listaUsuariosServidor())
            {
                cout << n << endl;
            }

            for (Canal *canal : servidor->canais)
            {
                if (CanalTexto *texto = dynamic_cast<CanalTexto *>(canal))
                {
                    for (Mensagem m : texto->mensagens)
                    {
                        cout << m.enviadaPor << endl;
                        cout << m.dataHora << endl;
                        cout << m.conteudo << endl;
                    }
                }
                else if (CanalVoz *voz = dynamic_cast<CanalVoz *>(canal))
                {
                    cout << voz->ultimaMensagem.enviadaPor << endl;
                    cout << voz->ultimaMensagem.dataHora << endl;
                    cout << voz->ultimaMensagem.conteudo << endl;
                }
            }
        }
    }

    /**
     * @brief Faz o controle dos ids na criação dos usuários;
     * @return Retorna o próximo id
     */
    int proximoId()
    {
        this->id = this->id + 1;
        cout << this->id << endl;
        return this->id;
    }

private:

    /**
     * @brief Salva no arquivo externo usuarios.txt as informações referentes aos usuários do sistema.
     */
    void salvarUsuarios();

    /**
     * @brief Salva no arquivo externo servidores.txt as informações referentes aos servidores do sistema.
     */
    void salvarServidores();

    /**
     * @brief Recupera os dados referentes aos usuários no arquivo externo e adiciona na aplicação.
     */
    void carregarUsuarios();

    /**
     * @brief Recupera os dados referentes aos servidores no arquivo externo e adiciona na aplicação.
     */
    void carregarServidores();
};

#endif
