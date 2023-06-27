#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "./include/usuario.h"
#include "./include/sistema.h"
#include "./include/servidor.h"

// função para separar as informações do string de entrada
vector<string> quebrarString(const string &linhaComando)
{
    vector<string> comandos;

    size_t pos1 = linhaComando.find(' ');
    string comando = linhaComando.substr(0, pos1);
    comandos.push_back(comando);

    if (comando == "set-server-desc")
    {
        // linha com 3 comandos sendo o último com espaços

        size_t pos2 = linhaComando.find(' ', pos1 + 1);

        string info1 = linhaComando.substr(pos1 + 1, pos2 - pos1 - 1);
        string info2 = linhaComando.substr(pos2 + 1, linhaComando.length() - 1);

        comandos.push_back(info1);
        comandos.push_back(info2);
    }
    else if (comando == "set-server-invite-code" || comando == "enter-server")
    {
        // linha com 2 ou 3 comandos

        istringstream iss(linhaComando);
        string comando, servidor, senha;
        iss >> comando >> servidor >> senha;

        if (senha.empty())
        {
            senha = ""; // Define senha como string vazia quando não for digitada
        }

        comandos.push_back(servidor);
        comandos.push_back(senha);

        //cout << comandos[0] << comandos[1] << comandos[2] << endl;
    }
    else
    {
        // linha com 4 ou 1 comandos

        size_t pos2 = linhaComando.find(' ', pos1 + 1);
        size_t pos3 = linhaComando.find(' ', pos2 + 1);

        string info1 = linhaComando.substr(pos1 + 1, pos2 - pos1 - 1);
        string info2 = linhaComando.substr(pos2 + 1, pos3 - pos2 - 1);
        string info3 = linhaComando.substr(pos3 + 1);

        comandos.push_back(info1);
        comandos.push_back(info2);
        comandos.push_back(info3);
    }

    return comandos;
}

int main()
{

    string linhaComando;

    Sistema *sistema = new Sistema();
    vector<string> comandos;
    int id = 1;

    while (true)
    {
        getline(cin, linhaComando);

        comandos = quebrarString(linhaComando);

        // cout << "comando: " << comandos[0] << "email: " << comandos[1] << "senha: " << comandos[2] << "nome: "<< comandos[3] << endl;

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
                auto novoUsuario = new Usuario();

                novoUsuario->id = id;
                novoUsuario->email = comandos[1];
                novoUsuario->senha = comandos[2];
                novoUsuario->nome = comandos[3];

                sistema->cadastrarUsuario(novoUsuario);

                id++;

                cout << "Usuário criado" << endl;

                // sistema->listarUsuarios();
            }
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

            // cout << sistema->usuarioAtual->nome << endl;
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

                    auto servidor = new Servidor();
                    servidor->nome = comandos[1];
                    servidor->usuarioDonoId = sistema->usuarioAtual->id;
                    sistema->criarServidor(servidor);

                    cout << "Servidor criado" << endl;

                    // sistema->listarServidores();
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
            // Lógica para mudar a descrição de um servidor

            if (sistema->servidorExiste(comandos[1]))
            {

                if (sistema->retornaServidor(comandos[1])->verificaUsuarioDono(sistema->usuarioAtual->id))
                {
                    sistema->retornaServidor(comandos[1])->setDescricao(comandos[2]);
                    cout << "Descrição do servidor '" << comandos[1] << "' modificada!" << endl;
                    //cout << sistema->retornaServidor(comandos[1])->descricao << endl;
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
                        //cout << sistema->retornaServidor(comandos[1])->codigoConvite << endl;
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
                    sistema->sairServidor();
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
        else if (comandos[0] == "enter-server")
        {

            // Lógica para entrar em um servidor

            if (sistema->adicionarUsuarioNoServidor(comandos[1], comandos[2]) == 1)
            {
                cout << "Entrou no servidor com sucesso." << endl;
                //cout << sistema->servidorAtual->nome << endl;
                //cout << sistema->servidorAtual->participantesIDs[0] << endl;
                
            }
            else if (sistema->adicionarUsuarioNoServidor(comandos[1], comandos[2]) == 2)
            {
                cout << "Código digitado está errado." << endl;
            }
            else
            {
                cout << "Não existe um servidor com esse nome." << endl;
            }

        }
        else if (comandos[0] == "leave-server")
        {

            // Lógica para sair de uma servidor

            if (sistema->verificaUsuarioNoServidor())
            {
                cout << "Saindo do servidor '" << sistema->retornaServidorAtual()->nome << "'" << endl;
                sistema->sairServidor();
                //cout << sistema->retornaServidorAtual() << endl;
            }
            else
            {
                cout << "Você não está visualizando nenhum servidor" << endl;
            }
        }
        else if (comandos[0] == "list-participants")
        {

            // Lógica para listar participantes de um servidor

            if (sistema->verificaUsuarioNoServidor())
            {

                sistema->listaUsuariosServidor();
            }
            else
            {
                cout << "O usuario não está em nenhum servidor, por favor entre em um servidor" << endl;
            }
        }
        else
        {
            std::cout << "Comando inválido." << std::endl;
        }

        comandos.clear();
    }

    delete sistema;

    return 0;
}