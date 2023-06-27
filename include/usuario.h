/**
 * @file usuario.h
 * @brief Declaração da classe Usuario.h.
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Classe que representa um usuário.
 */
class Usuario {

public:
    /**
     * @brief ID do usuário.
     */
    int id;

    /**
     * @brief Nome do usuário.
     */
    string nome;

    /**
     * @brief Email do usuário.
     */
    string email;

    /**
     * @brief Senha do usuário.
     */
    string senha;

    /**
     * @brief Retorna o ID do usuário.
     * @return O ID do usuário.
     */
    int returnaId();
};

#endif
