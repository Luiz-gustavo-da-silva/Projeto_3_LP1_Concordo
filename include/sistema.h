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
    Servidor *servidorAtual;
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

    vector<int> retornaIdsUsuarios()
    {

        vector<int> ids;

        for (const Usuario *usuario : usuarios)
        {
            ids.push_back(usuario->id);
        }

        return ids;
    }

    bool usuarioExiste(string email)
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

    Servidor * retornaServidor(string nome){

        for (Servidor *server : servidores)
        {
            if (server->nome == nome)
            {
                return server;
            }
        }

    }

    void listarServidores(){

        for (Servidor *server : servidores)
        {
            cout << server->nome << endl;
        }

    }

    void removerServidor(string nome) {
    for (auto it = servidores.begin(); it != servidores.end(); ++it) {
        if ((*it)->nome == nome) {
            delete *it;  
            servidores.erase(it);
            break;  
        }
    }

    
}

};

#endif