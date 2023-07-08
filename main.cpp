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
    }
    else if (comando == "send-message")
    {

        string info1 = linhaComando.substr(pos1 + 1, linhaComando.length());
        comandos.push_back(info1);
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

void createUser(Sistema *sistema, vector<std::string> &comandos, int &id)
{
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
    }
}

void login(Sistema *sistema, vector<std::string> &comandos)
{
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
}

void quit()
{
    cout << "Saindo do Concordo" << endl;
    // Alguma lógica adicional pode ser necessária aqui
}

void disconnect(Sistema *sistema)
{
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

void createServer(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (!sistema->servidorExiste(comandos[1]))
        {
            auto servidor = new Servidor();
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

void setServerDescription(Sistema *sistema, vector<std::string> &comandos)
{
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

void setServerInviteCode(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->servidorExiste(comandos[1]))
    {
        if (sistema->retornaServidor(comandos[1])->verificaUsuarioDono(sistema->usuarioAtual->id))
        {
            if (!comandos[2].empty())
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

void listServers(Sistema *sistema)
{
    sistema->listarServidores();
}

void removeServer(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->verificaUsuarioLogado())
    {
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
            cout << "Servidor '" << comandos[1] << "' não encontrado" << endl;
        }
    }
    else
    {
        cout << "É necessário estar logado para remover um servidor" << endl;
    }
}

void enterServer(Sistema *sistema, vector<std::string> &comandos)
{
    int resultado = sistema->adicionarUsuarioNoServidor(comandos[1], comandos[2]);
    if (resultado == 1)
    {
        cout << "Entrou no servidor com sucesso." << endl;
    }
    else if (resultado == 2)
    {
        cout << "Código digitado está errado." << endl;
    }
    else
    {
        cout << "Não existe um servidor com esse nome." << endl;
    }
}

void leaveServer(Sistema *sistema)
{
    if (sistema->verificaUsuarioNoServidor())
    {
        cout << "Saindo do servidor '" << sistema->retornaServidorAtual()->nome << "'" << endl;
        sistema->sairServidor();
    }
    else
    {
        cout << "Você não está visualizando nenhum servidor" << endl;
    }
}

void listParticipants(Sistema *sistema)
{
    if (sistema->verificaUsuarioNoServidor())
    {
        sistema->listaUsuariosServidor();
    }
    else
    {
        cout << "O usuário não está em nenhum servidor, por favor entre em um servidor" << endl;
    }
}

void listarCanais(Sistema *sistema)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (sistema->verificaUsuarioNoServidor())
        {
            sistema->retornaServidorAtual()->listarCanais();
        }
    }
    else
    {
        cout << "É necessário estar logado realizar essa ação" << endl;
    }
}

void criarCanal(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (sistema->verificaUsuarioNoServidor())
        {
            sistema->retornaServidorAtual()->criarCanal(comandos[1], comandos[2]);
        }
    }
    else
    {
        cout << "É necessário estar logado realizar essa ação" << endl;
    }
}

void entrarCanal(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (sistema->verificaUsuarioNoServidor())
        {
            if (sistema->entrarCanal(comandos[1]))
            {
                cout << "Entrou no canal " << comandos[1] << "'" << endl;
            }
        }
    }
    else
    {
        cout << "É necessário estar logado realizar essa ação" << endl;
    }
}

void listarMensagem(Sistema *sistema)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (sistema->verificaUsuarioNoCanal())
        {
            sistema->printMensagens();
        }
        else
        {
            cout << "É necessário entrar em um canal" << endl;
        }
    }
    else
    {
        cout << "É necessário estar logado realizar essa ação" << endl;
    }
}

void sairCanal(Sistema *sistema)
{
    if (sistema->sairCanal())
    {
        cout << "Saindo do canal" << endl;
    }
    else
    {
        cout << "Falha ao sair do canal" << endl;
    }
}

void mardarMensagem(Sistema *sistema, vector<std::string> &comandos)
{
    if (sistema->verificaUsuarioLogado())
    {
        if (sistema->verificaUsuarioNoCanal())
        {
            sistema->enviarMensagem(comandos[1]);
        }
        else
        {
            cout << "É necessário entrar em um canal" << endl;
        }
    }
    else
    {
        cout << "É necessário estar logado realizar essa ação" << endl;
    }
}


int main()
{

    string linhaComando;
    Sistema *sistema = new Sistema();
    vector<string> comandos;

    sistema->carregar();
    
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
            createUser(sistema, comandos, id);
            sistema->salvar();
        }
        else if (comandos[0] == "login")
        {
            // Lógica para fazer login
            login(sistema, comandos);
        }
        else if (comandos[0] == "quit")
        {
            quit();
            sistema->salvar();
            return 0;
            break;
        }
        else if (comandos[0] == "disconnect")
        {
            // Lógica para fazer logout
            disconnect(sistema);
        }
        else if (comandos[0] == "create-server")
        {
            // Lógica para criar um servidor
            createServer(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "set-server-desc")
        {
            // Lógica para mudar a descrição de um servidor

            setServerDescription(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "set-server-invite-code")
        {
            // Lógica para Setar código de convite para o servidor

            setServerInviteCode(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "list-servers")
        {
            // Lógica para listar os servidor
            sistema->listarServidores();
        }
        else if (comandos[0] == "remove-server")
        {
            // Lógica para remover um servidor
            removeServer(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "enter-server")
        {
            // Lógica para entrar em um servidor
            enterServer(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "leave-server")
        {
            // Lógica para sair de uma servidor
            leaveServer(sistema);
        }
        else if (comandos[0] == "list-participants")
        {
            // Lógica para listar participantes de um servidor
            listParticipants(sistema);
        }
        else if (comandos[0] == "list-channels")
        {
            // Lógica para listar os canais de um servidor

            listarCanais(sistema);
        }
        else if (comandos[0] == "create-channel")
        {
            // Lógica para criar os canais de um servidor
            criarCanal(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "enter-channel")
        {   
            // Lógica para entrar em um canal de um servidor
            entrarCanal(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "send-message")
        {
            // Lógica para listar os canais de um servidor
            mardarMensagem(sistema, comandos);
            sistema->salvar();
        }
        else if (comandos[0] == "list-messages")
        {
            // Lógica para listar mensagens de um canal
            listarMensagem(sistema);
        }
        else if (comandos[0] == "leave-channel")
        {
            // Lógica para sair de um canal
            sairCanal(sistema);
        }else if(comandos[0] == "exit"){
            cout << "Programa encerrado!" << endl;
            sistema->salvar();
            return 0;
        }
        else
        {
            // Lógica para identificar comandos inválidos
            std::cout << "Comando inválido." << std::endl;
        }

        comandos.clear();
    }

    

    delete sistema;

    return 0;
}