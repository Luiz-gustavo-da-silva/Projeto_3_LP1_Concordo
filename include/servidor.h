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
    string codigoConvite = "";
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

    void setCodigoConvite(string codigoConvite)
    {
        this->codigoConvite = codigoConvite;
    }

    bool verificaCodigoConvite(string codigoConvite)
    {
        if (codigoConvite == this->codigoConvite)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void adicionarUsuario(int id)
    {

        participantesIDs.push_back(id);
    }

    vector <int> listaUsuariosServidor()
    {
        return participantesIDs;
    }
};

#endif