#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <vector>

#include "canal.h"
#include "usuario.h"
#include "servidor.h"

using namespace std;

class Sistema
{
public:
    // fazer o encapsulamento desses dados!!!
    vector<Usuario *> usuarios;
    vector<Servidor *> servidores;
    Usuario *usuarioAtual = nullptr;
    Servidor *servidorAtual = nullptr;
    Canal *canalAtual;

    ~Sistema()
    {
        // Desalocar objetos do vetor

        for (auto objeto : usuarios)
        {
            delete objeto;
        }

        for (auto objeto : servidores)
        {
            delete objeto;
        }

        // usuarios.clear();
    }

    void cadastrarUsuario(Usuario *usuario)
    {
        usuarios.push_back(usuario);
    }

    bool usuarioExiste(string email)
    {
        for (const Usuario *usuario : usuarios)
        {
            cout << usuario->nome << endl;
            /*if (usuario->email == email)
            {
                return true;
            }*/
        }

        return false;
    }

    bool login(string email, string senha)
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

    void logout()
    {
        usuarioAtual = nullptr;
    }

    bool verificaUsuarioLogado()
    {
        if (usuarioAtual == nullptr)
        {
            return false;
        }
        return true;
    }

    void criarServidor(Servidor *servidor)
    {
        servidores.push_back(servidor);
    }

    bool servidorExiste(string nome)
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

    Servidor *retornaServidor(string nome)
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

    void listarServidores()
    {

        for (Servidor *server : servidores)
        {
            cout << server->nome << endl;
        }
    }

    void removerServidor(string nome)
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

    Usuario *retornaUsuario(string email)
    {

        for (Usuario *usuario : usuarios)
        {
            if (usuario->email == email)
            {
                return usuario;
            }
        }
    }

    int adicionarUsuarioNoServidor(string nome, string codigoConvite)
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

    bool verificaUsuarioNoServidor()
    {
        if (servidorAtual == nullptr)
        {
            return false;
        }
        return true;
    }

    void sairServidor()
    {
        usuarioAtual = nullptr;
    }

    Servidor *retornaServidorAtual()
    {
        return this->servidorAtual;
    }

    void listaUsuariosServidor()
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
    void listarUsuarios()
    {
        for (const Usuario *usuario : usuarios)
        {
            cout << usuario->nome << endl;
        }
    }
};

#endif