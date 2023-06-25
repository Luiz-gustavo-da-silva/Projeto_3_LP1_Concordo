#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <string>
#include <vector>
#include "canal.h"

class Servidor {
public:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;
    vector<Canal*> canais;
    vector<int> participantesIDs;
};

#endif