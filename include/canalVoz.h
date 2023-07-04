/**
 * @file canalvoz.h
 * @brief Declaração da classe CanalVoz.h
 */

#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <iostream>
#include <string>

#include "mensagem.h"
#include "canal.h"

using namespace std;

/**
 * @brief Classe que representa um canal de voz.
 * @details Um canal de voz é uma subclasse da classe Canal e contém a informação da última mensagem.
 */
class CanalVoz : public Canal {
public:
    /**
     * @brief Última mensagem enviada no canal de voz.
     */
    Mensagem ultimaMensagem;

};

#endif
