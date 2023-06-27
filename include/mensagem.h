/**
 * @file mensagem.h
 * @brief Declaração da classe Mensagem.h
 */

#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Classe que representa uma mensagem.
 */
class Mensagem {
public:
    /**
     * @brief Data e hora da mensagem.
     */
    string dataHora;

    /**
     * @brief Identificador da entidade que enviou a mensagem.
     */
    int enviadaPor;

    /**
     * @brief Conteúdo da mensagem.
     */
    string conteudo;
};

#endif
