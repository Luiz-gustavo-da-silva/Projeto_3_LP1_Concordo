/**
 * @file canaltexto.h
 * @brief Declaração da classe CanalTexto.h
 */

#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
#include <string>
#include <vector>

#include "mensagem.h"
#include "canal.h"

using namespace std;

/**
 * @brief Classe que representa um canal de texto.
 * @details Um canal de texto é uma subclasse da classe Canal e contém um vetor de mensagens.
 */
class CanalTexto : public Canal {
public:
    /**
     * @brief Vetor de mensagens no canal de texto.
     */
    vector <Mensagem> mensagens;
};

#endif
