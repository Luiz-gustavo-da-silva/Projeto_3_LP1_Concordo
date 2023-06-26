#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario {

public:
    int id;
    string nome;
    string email;
    string senha;

    int returnaId(){
        return this->id;
    }
};

#endif