/**
 * @file sistema.cpp
 * @brief Implementação da classe Sistema.
 */

#include "../include/sistema.h"

using namespace std;

/**
 * @brief Destrutor da classe Sistema.
 * Libera a memória alocada para os objetos do vetor de usuários e servidores.
 */
Sistema::~Sistema()
{
    for (auto objeto : usuarios)
    {
        delete objeto;
    }

    for (auto objeto : servidores)
    {
        delete objeto;
    }
}

/**
 * @brief Cadastra um novo usuário no sistema.
 * @param usuario Ponteiro para o objeto do tipo Usuario a ser cadastrado.
 */
void Sistema::cadastrarUsuario(Usuario *usuario)
{
    usuarios.push_back(usuario);
}

/**
 * @brief Verifica se um usuário com o email fornecido já existe no sistema.
 * @param email Email a ser verificado.
 * @return True se o usuário existe, False caso contrário.
 */
bool Sistema::usuarioExiste(string email)
{
    for (const Usuario *usuario : usuarios)
    {
        if (usuario->email == email)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Realiza o login de um usuário no sistema.
 * @param email Email do usuário.
 * @param senha Senha do usuário.
 * @return True se o login for bem-sucedido, False caso contrário.
 */
bool Sistema::login(string email, string senha)
{
    for (Usuario *usuario : usuarios)
    {
        if (usuario->email == email && usuario->senha == senha)
        {
            usuarioAtual = usuario;
            return true;
        }
    }
    return false;
}

/**
 * @brief Realiza o logout do usuário atual.
 */
void Sistema::logout()
{
    usuarioAtual = nullptr;
}

/**
 * @brief Verifica se há um usuário logado no sistema.
 * @return True se houver um usuário logado, False caso contrário.
 */
bool Sistema::verificaUsuarioLogado()
{
    if (usuarioAtual == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief Cria um novo servidor no sistema.
 * @param servidor Ponteiro para o objeto do tipo Servidor a ser criado.
 */
void Sistema::criarServidor(Servidor *servidor)
{
    servidores.push_back(servidor);
}

/**
 * @brief Verifica se um servidor com o nome fornecido já existe no sistema.
 * @param nome Nome do servidor.
 * @return True se o servidor existe, False caso contrário.
 */
bool Sistema::servidorExiste(string nome)
{
    for (const Servidor *server : servidores)
    {
        if (server->nome == nome)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Retorna um ponteiro para o objeto Servidor com o nome fornecido.
 * @param nome Nome do servidor.
 * @return Ponteiro para o objeto Servidor, ou nullptr se o servidor não for encontrado.
 */
Servidor *Sistema::retornaServidor(string nome)
{
    for (Servidor *server : servidores)
    {
        if (server->nome == nome)
        {
            return server;
        }
    }
    return nullptr;
}

/**
 * @brief Lista os nomes de todos os servidores do sistema.
 */
void Sistema::listarServidores()
{
    for (Servidor *server : servidores)
    {
        cout << server->nome << endl;
    }
}

/**
 * @brief Remove um servidor do sistema com o nome fornecido.
 * @param nome Nome do servidor a ser removido.
 */
void Sistema::removerServidor(string nome)
{
    for (auto it = servidores.begin(); it != servidores.end(); ++it)
    {
        if ((*it)->nome == nome)
        {
            delete *it;
            servidores.erase(it);
            break;
        }
    }
}

/**
 * @brief Retorna um ponteiro para o objeto Usuario com o email fornecido.
 * @param email Email do usuário.
 * @return Ponteiro para o objeto Usuario, ou nullptr se o usuário não for encontrado.
 */
Usuario *Sistema::retornaUsuario(string email)
{
    for (Usuario *usuario : usuarios)
    {
        if (usuario->email == email)
        {
            return usuario;
        }
    }
    return nullptr;
}

/**
 * @brief Adiciona um usuário ao servidor com o nome e código de convite fornecidos.
 * @param nome Nome do servidor.
 * @param codigoConvite Código de convite do servidor.
 * @return 1 se o usuário foi adicionado com sucesso, 2 se o código de convite estiver incorreto, 3 se o servidor não for encontrado.
 */
int Sistema::adicionarUsuarioNoServidor(string nome, string codigoConvite)
{
    for (Servidor *servidor : servidores)
    {
        if (servidor->nome == nome)
        {
            if (servidor->verificaCodigoConvite(codigoConvite))
            {
                servidor->adicionarUsuario(usuarioAtual->id);
                servidorAtual = servidor;
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 3;
}

/**
 * @brief Verifica se há um usuário logado em um servidor.
 * @return True se houver um usuário logado em um servidor, False caso contrário.
 */
bool Sistema::verificaUsuarioNoServidor()
{
    if (servidorAtual == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief Remove o usuário logado do servidor atual.
 */
void Sistema::sairServidor()
{
    servidorAtual = nullptr;
}

/**
 * @brief Retorna um ponteiro para o objeto Servidor atual.
 * @return Ponteiro para o objeto Servidor atual.
 */
Servidor *Sistema::retornaServidorAtual()
{
    return this->servidorAtual;
}

/**
 * @brief Lista os nomes dos usuários do servidor atual.
 */
void Sistema::listaUsuariosServidor()
{
    vector<int> ids = servidorAtual->listaUsuariosServidor();

    for (int i = 0; i < ids.size(); i++)
    {
        for (const Usuario *usuario : usuarios)
        {
            if (usuario->id == ids[i])
            {
                cout << usuario->nome << endl;
            }
        }
    }
}

/**
 * @brief Lista os nomes de todos os usuários do sistema.
 */
void Sistema::listarUsuarios()
{
    for (const Usuario *usuario : usuarios)
    {
        cout << usuario->nome << endl;
    }
}
