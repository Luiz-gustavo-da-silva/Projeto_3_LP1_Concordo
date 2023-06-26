#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "./include/usuario.h"
#include "./include/sistema.h"
#include "./include/servidor.h"

vector<string> quebrarString(const string &linhaComando)
{
    vector<string> comandos;

    size_t pos1 = linhaComando.find(' ');
    size_t pos2 = linhaComando.find(' ', pos1 + 1);
    size_t pos3 = linhaComando.find(' ', pos2 + 1);

    string comando = linhaComando.substr(0, pos1);
    string info1 = linhaComando.substr(pos1 + 1, pos2 - pos1 - 1);
    string info2 = linhaComando.substr(pos2 + 1, pos3 - pos2 - 1);
    string info3 = linhaComando.substr(pos3 + 1);

    comandos.push_back(comando);
    comandos.push_back(info1);
    comandos.push_back(info2);
    comandos.push_back(info3);

    return comandos;
}

int main()
{

    string linhaComando;
    Usuario *novoUsuario;
    Sistema *sistema = new Sistema();
    Servidor *servidor;
    vector<string> comandos;
    int id = 1;

    while (true)
    {
        getline(cin, linhaComando);

        comandos = quebrarString(linhaComando);

        if (comandos.size() == 0)
        {
            cout << "Comando inválido." << endl;
            return 0;
        }

        if (comandos[0] == "create-user")
        {
            // Lógica para criar um usuário

            if (sistema->usuarioExiste(comandos[1]))
            {
                cout << "Usuário já existe!" << endl;
            }
            else
            {
                novoUsuario->id = id;
                novoUsuario->email = comandos[1];
                novoUsuario->senha = comandos[2];
                novoUsuario->nome = comandos[3];
                id++;

                cout << "Usuário criado" << endl;
            }

            // cout << comandos[0] << comandos[1] << comandos[2]  << comandos[3] << endl;
        }
        else if (comandos[0] == "login")
        {
            // Lógica para fazer login

            if (sistema->usuarioExiste(comandos[1]))
            {
                if (sistema->login(comandos[1], comandos[2]))
                {
                    cout << "Logado como " << comandos[1] << endl;
                }
                else
                {
                    cout << "Senha ou usuário inválidos!" << endl;
                }
            }
            else
            {
                cout << "Usuário não existente por favor crie um login na nossa aplicação!" << endl;
            }

            // cout << comandos[0] << comandos[1] << comandos[2] << endl;
        }
        else if (comandos[0] == "quit")
        {
            cout << "Saindo do Concordo" << endl;
            break;
            return 0;
        }
        else if (comandos[0] == "disconnect")
        {
            // Lógica para fazer logout
            if (sistema->verificaUsuarioLogado())
            {
                cout << "Desconectando usuário" << sistema->usuarioAtual->email << endl;
                sistema->logout();
            }
            else
            {
                cout << "Não está conectado" << endl;
            }
        }
        else if (comandos[0] == "create-server")
        {
            // Lógica para criar um servidor
            if (sistema->verificaUsuarioLogado())
            {

                if (!sistema->servidorExiste(comandos[1]))
                {

                    servidor->nome = comandos[1];
                    servidor->usuarioDonoId = sistema->usuarioAtual->id;
                    sistema->criarServidor(servidor);

                    cout << "Servidor criado" << endl;
                }
                else
                {
                    cout << "Servidor com esse nome já existe" << endl;
                }
            }
            else
            {
                cout << "Não está conectado" << endl;
            }
        }
        else if (comandos[0] == "set-server-desc")
        {
            // Lógica para mudar a descrição de um servidor (Não vai funcionar)

            if (sistema->servidorExiste(comandos[1]))
            {

                if (sistema->retornaServidor(comandos[1])->verificaUsuarioDono(sistema->usuarioAtual->id))
                {
                    sistema->retornaServidor(comandos[1])->setDescricao(comandos[2]);
                    cout << "Descrição do servidor '" << comandos[1] << "' modificada!" << endl;
                }
                else
                {
                    cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
                }
            }
            else
            {
                cout << "Servidor '" << comandos[1] << "' não existe" << endl;
            }
        }
        else if (comandos[0] == "set-server-invite-code")
        {
            // Lógica para Setar código de convite para o servidor

            if (sistema->servidorExiste(comandos[1]))
            {

                if (sistema->retornaServidor(comandos[1])->verificaUsuarioDono(sistema->usuarioAtual->id))
                {
                    if (comandos[2] != "")
                    {
                        sistema->retornaServidor(comandos[1])->setCodigoConvite(comandos[2]);

                        cout << "Código de convite do servidor '" << comandos[1] << "' modificado!" << endl;
                    }
                    else
                    {
                        sistema->retornaServidor(comandos[1])->setCodigoConvite("");

                        cout << "Código de convite do servidor '" << comandos[1] << "' removido!" << endl;
                    }
                }
                else
                {
                    cout << "Você não pode alterar o código de convite do servidor que não foi criado por você" << endl;
                }
            }
            else
            {
                cout << "Servidor '" << comandos[1] << "' não existe" << endl;
            }
        }
        else if (comandos[0] == "list-servers")
        {
            // Lógica para listar os servidor

            sistema->listarServidores();
        }
        else if (comandos[0] == "remove-server")
        {

            // Lógica para remover um servidor

            if (sistema->servidorExiste(comandos[1]))
            {

                if (sistema->retornaServidor(comandos[1])->verificaUsuarioDono(sistema->usuarioAtual->id))
                {
                    sistema->removerServidor(comandos[1]);
                    cout << "Servidor '" << comandos[1] << "' removido" << endl;
                }
                else
                {
                    cout << "Você não é o dono do servidor '" << comandos[1] << "'" << endl;
                }
            }
            else
            {
                cout << "Servidor '" << comandos[1] << "'não encontrado" << endl;
            }
        }
        else
        {
            std::cout << "Comando inválido." << std::endl;
        }
    }

    delete novoUsuario;
    delete servidor;
    delete sistema;

    return 0;
}