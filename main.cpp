#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "./include/usuario.h"
#include "./include/sistema.h"

vector<string> quebrarString(const string &linhaComando)
{
    vector<string> comandos;

    size_t pos1 = linhaComando.find(' ');
    size_t pos2 = linhaComando.find(' ', pos1 + 1);
    size_t pos3 = linhaComando.find(' ', pos2 + 1);

    string comando = linhaComando.substr(0, pos1);
    string email = linhaComando.substr(pos1 + 1, pos2 - pos1 - 1);
    string senha = linhaComando.substr(pos2 + 1, pos3 - pos2 - 1);
    string nome = linhaComando.substr(pos3 + 1);

    comandos.push_back(comando);
    comandos.push_back(email);
    comandos.push_back(senha);
    comandos.push_back(nome);

    return comandos;
}

int main()
{

    string linhaComando;
    Usuario * novoUsuario;
    Sistema * sistema = new Sistema();
    int id = 1;

    getline(cin, linhaComando);

    vector<string> comandos = quebrarString(linhaComando);

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
            if(sistema->login(comandos[1], comandos[2])){
                cout << "Logado como "<< comandos[1] << endl;
            }else{
                cout << "Senha ou usuário inválidos!"<< endl;
            }
        }
        else
        {
            cout << "Usuário não existente por favor crie um login na nossa aplicação!"<< endl;
        }


        //cout << comandos[0] << comandos[1] << comandos[2] << endl;
    }
    else if (comandos[0] == "quit")
    {
        cout << "Saindo do Concordo" << endl;
        return 0;
    }
    else
    {
        std::cout << "Comando inválido." << std::endl;
    }

    delete novoUsuario;
    delete sistema;

    return 0;
}