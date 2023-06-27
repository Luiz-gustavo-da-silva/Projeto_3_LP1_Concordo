/**
 * @file servidor.cpp
 * @brief Implementação da classe Servidor.
 */

#include "../include/servidor.h"

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Verifica se o usuário com o ID fornecido é o dono do servidor.
 * @param id ID do usuário.
 * @return True se o usuário for o dono do servidor, False caso contrário.
 */
bool Servidor::verificaUsuarioDono(int id)
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

/**
 * @brief Define a descrição do servidor.
 * @param descricao Descrição do servidor.
 */
void Servidor::setDescricao(string descricao)
{
    this->descricao = descricao;
}

/**
 * @brief Define o código de convite do servidor.
 * @param codigoConvite Código de convite do servidor.
 */
void Servidor::setCodigoConvite(string codigoConvite)
{
    this->codigoConvite = codigoConvite;
}

/**
 * @brief Verifica se o código de convite fornecido corresponde ao código de convite do servidor.
 * @param codigoConvite Código de convite a ser verificado.
 * @return True se o código de convite for válido, False caso contrário.
 */
bool Servidor::verificaCodigoConvite(string codigoConvite)
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

/**
 * @brief Adiciona um usuário ao servidor.
 * @param id ID do usuário a ser adicionado.
 */
void Servidor::adicionarUsuario(int id)
{
    participantesIDs.push_back(id);
}

/**
 * @brief Retorna um vetor contendo os IDs dos usuários do servidor.
 * @return Vetor de IDs dos usuários do servidor.
 */
vector<int> Servidor::listaUsuariosServidor()
{
    return participantesIDs;
}
