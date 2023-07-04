/**
 * @file servidor.h
 * @brief Declaração da classe Servidor.h
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <string>

#include <vector>
#include "canal.h"
#include "canalTexto.h"
#include "canalVoz.h"

using namespace std;

/**
 * @brief Classe que representa um servidor.
 */
class Servidor
{
public:
    /**
     * @brief ID do usuário dono do servidor.
     */
    int usuarioDonoId;

    /**
     * @brief Nome do servidor.
     */
    string nome;

    /**
     * @brief Descrição do servidor.
     */
    string descricao;

    /**
     * @brief Código de convite do servidor.
     */
    string codigoConvite = "";

    /**
     * @brief Vetor de ponteiros para os canais do servidor.
     */
    vector<Canal *> canais;

    /**
     * @brief Vetor de IDs dos participantes do servidor.
     */
    vector<int> participantesIDs;
    
    /**
     * @brief Destrutor da classe servidor
     */
    ~Servidor()
    {
        for (Canal *canal : canais)
        {
            delete canal;
        }
    }

    /**
     * @brief Verifica se o usuário é o dono do servidor.
     * @param id ID do usuário a ser verificado.
     * @return true se o usuário é o dono do servidor, false caso contrário.
     */
    bool verificaUsuarioDono(int id);

    /**
     * @brief Define a descrição do servidor.
     * @param descricao Descrição do servidor.
     */
    void setDescricao(string descricao);

    /**
     * @brief Define o código de convite do servidor.
     * @param codigoConvite Código de convite do servidor.
     */
    void setCodigoConvite(string codigoConvite);

    /**
     * @brief Verifica se o código de convite fornecido corresponde ao do servidor.
     * @param codigoConvite Código de convite a ser verificado.
     * @return true se o código de convite é válido, false caso contrário.
     */
    bool verificaCodigoConvite(string codigoConvite);

    /**
     * @brief Adiciona um usuário ao servidor.
     * @param id ID do usuário a ser adicionado.
     */
    void adicionarUsuario(int id);

    /**
     * @brief Retorna um vetor com os IDs dos participantes do servidor.
     * @return Vetor de IDs dos participantes do servidor.
     */
    vector<int> listaUsuariosServidor();

    /**
     * @brief Imprime o conjunte de canais cadastrados no servidor.
     */
    void listarCanais();

    /**
     * @brief Retorna um vetor com os IDs dos participantes do servidor.
     * @return Vetor de IDs dos participantes do servidor.
     */
    void criarCanal(string nome, string tipo);

    
    
};

#endif
