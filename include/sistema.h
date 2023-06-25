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
    vector<Usuario *> usuarios;
    vector<Servidor *> servidores;
    Usuario *usuarioAtual;
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
        
        //usuarios.clear();
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

    bool login(string email, string senha){
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

};

#endif