#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h";
#include "canal.h";

using namespace std;

class CanalVoz : public Canal {
public:
    Mensagem ultimaMensagem;
};

#endif