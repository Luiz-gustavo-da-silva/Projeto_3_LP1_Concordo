#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <string>
#include <vector>
#include "canal.h"

class Servidor
{
public:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;
    vector<Canal *> canais;
    vector<int> participantesIDs;

    bool verificaUsuarioDono(int id)
    {
        if (usuarioDonoId == id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void setDescricao(string descricao)
    {
        this->descricao = descricao;
    }

    void setCodigoConvite(string codigoConvite){
        this->codigoConvite = codigoConvite;
    }

    void adicionarUsuarioNoServidor(int id)
    {

        participantesIDs.push_back(id);
    }

    void listaUsuariosServidor()
    {
        for (int id : participantesIDs)
        {
            std::cout << "ID do usuário: " << id << std::endl;
        }
    }
};

#endif