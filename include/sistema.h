#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <vector>

#include "canal.h";
#include "usuario.h";
#include "servidor.h";

using namespace std;

class Sistema {
public:
    vector<Usuario> usuarios;
    vector<Servidor> servidores;
    Usuario* usuarioAtual;
    Servidor* servidorAtual;
    Canal* canalAtual;
};

#endif