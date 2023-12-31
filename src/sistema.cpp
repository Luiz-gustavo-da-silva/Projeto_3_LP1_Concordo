/**
 * @file sistema.cpp
 * @brief Implementação da classe Sistema.
 */

#include "../include/sistema.h"

using namespace std;

/**
 * @brief Destrutor da classe Sistema.
 * Libera a memória alocada para os objetos do vetor de usuários e servidores.
 */
Sistema::~Sistema()
{
    for (auto objeto : usuarios)
    {
        delete objeto;
    }

    for (auto objeto : servidores)
    {
        delete objeto;
    }
}

/**
 * @brief Cadastra um novo usuário no sistema.
 * @param usuario Ponteiro para o objeto do tipo Usuario a ser cadastrado.
 */
void Sistema::cadastrarUsuario(Usuario *usuario)
{
    usuarios.push_back(usuario);
}

/**
 * @brief Verifica se um usuário com o email fornecido já existe no sistema.
 * @param email Email a ser verificado.
 * @return True se o usuário existe, False caso contrário.
 */
bool Sistema::usuarioExiste(string email)
{
    for (const Usuario *usuario : usuarios)
    {
        if (usuario->email == email)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Realiza o login de um usuário no sistema.
 * @param email Email do usuário.
 * @param senha Senha do usuário.
 * @return True se o login for bem-sucedido, False caso contrário.
 */
bool Sistema::login(string email, string senha)
{
    for (Usuario *usuario : usuarios)
    {
        if (usuario->email == email && usuario->senha == senha)
        {
            usuarioAtual = usuario;
            return true;
        }
    }
    return false;
}

/**
 * @brief Realiza o logout do usuário atual.
 */
void Sistema::logout()
{
    usuarioAtual = nullptr;
    servidorAtual = nullptr;
}

/**
 * @brief Verifica se há um usuário logado no sistema.
 * @return True se houver um usuário logado, False caso contrário.
 */
bool Sistema::verificaUsuarioLogado()
{
    if (usuarioAtual == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief Cria um novo servidor no sistema.
 * @param servidor Ponteiro para o objeto do tipo Servidor a ser criado.
 */
void Sistema::criarServidor(Servidor *servidor)
{
    servidores.push_back(servidor);
}

/**
 * @brief Verifica se um servidor com o nome fornecido já existe no sistema.
 * @param nome Nome do servidor.
 * @return True se o servidor existe, False caso contrário.
 */
bool Sistema::servidorExiste(string nome)
{
    for (const Servidor *server : servidores)
    {
        if (server->nome == nome)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Retorna um ponteiro para o objeto Servidor com o nome fornecido.
 * @param nome Nome do servidor.
 * @return Ponteiro para o objeto Servidor, ou nullptr se o servidor não for encontrado.
 */
Servidor *Sistema::retornaServidor(string nome)
{
    for (Servidor *server : servidores)
    {
        if (server->nome == nome)
        {
            return server;
        }
    }
    return nullptr;
}

/**
 * @brief Lista os nomes de todos os servidores do sistema.
 */
void Sistema::listarServidores()
{
    for (Servidor *server : servidores)
    {
        cout << server->nome << endl;
    }
}

/**
 * @brief Remove um servidor do sistema com o nome fornecido.
 * @param nome Nome do servidor a ser removido.
 */
void Sistema::removerServidor(string nome)
{
    for (auto it = servidores.begin(); it != servidores.end(); ++it)
    {
        if ((*it)->nome == nome)
        {
            delete *it;
            servidores.erase(it);
            break;
        }
    }
}

/**
 * @brief Retorna um ponteiro para o objeto Usuario com o email fornecido.
 * @param email Email do usuário.
 * @return Ponteiro para o objeto Usuario, ou nullptr se o usuário não for encontrado.
 */
Usuario *Sistema::retornaUsuario(string email)
{
    for (Usuario *usuario : usuarios)
    {
        if (usuario->email == email)
        {
            return usuario;
        }
    }
    return nullptr;
}

/**
 * @brief Adiciona um usuário ao servidor com o nome e código de convite fornecidos.
 * @param nome Nome do servidor.
 * @param codigoConvite Código de convite do servidor.
 * @return 1 se o usuário foi adicionado com sucesso, 2 se o código de convite estiver incorreto, 3 se o servidor não for encontrado.
 */
void Sistema::adicionarUsuarioNoServidor(string nome, string codigoConvite)
{

    for (Servidor *servidor : servidores)
    {

        if (nome == servidor->nome)
        {
            if (servidor->verificaCodigoConvite(codigoConvite))
            {

                servidor->adicionarUsuario(usuarioAtual->id);
                servidorAtual = servidor;
                cout << "Entrou no servidor com sucesso." << endl;
                return;
                break;
                
            }
            else
            {
                cout << "Código digitado está errado." << endl;
                return;
                break;
            }
        }
    }

    cout << "Não existe um servidor com esse nome." << endl;
}

/**
 * @brief Verifica se há um usuário logado em um servidor.
 * @return True se houver um usuário logado em um servidor, False caso contrário.
 */
bool Sistema::verificaUsuarioNoServidor()
{
    if (servidorAtual == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief Remove o usuário logado do servidor atual.
 */
void Sistema::sairServidor()
{
    servidorAtual = nullptr;
}

/**
 * @brief Retorna um ponteiro para o objeto Servidor atual.
 * @return Ponteiro para o objeto Servidor atual.
 */
Servidor *Sistema::retornaServidorAtual()
{
    return this->servidorAtual;
}

/**
 * @brief Lista os nomes dos usuários do servidor atual.
 */
void Sistema::listaUsuariosServidor()
{
    vector<int> ids = servidorAtual->listaUsuariosServidor();

    for (int i = 0; i < ids.size(); i++)
    {
        for (const Usuario *usuario : usuarios)
        {
            if (usuario->id == ids[i])
            {
                cout << usuario->nome << endl;
            }
        }
    }
}

/**
 * @brief Lista os nomes de todos os usuários do sistema.
 */
void Sistema::listarUsuarios()
{
    for (const Usuario *usuario : usuarios)
    {
        cout << usuario->nome << endl;
    }
}

/**
 * @brief Entra em um canal com o nome fornecido no Servidor atualmente selecionado.
 * @param nome Nome do canal a ser acessado.
 * @return True se a entrada no canal foi bem-sucedida, False caso contrário.
 */
bool Sistema::entrarCanal(string nome)
{
    vector<Canal *> canais = servidorAtual->canais;

    for (Canal *canal : canais)
    {
        if (canal->nome == nome)
        {
            canalAtual = canal;
            return true;
        }
    }
    return false;
}

/**
 * @brief Sai do canal atualmente selecionado.
 * @return True se a saída do canal foi bem-sucedida, False caso contrário.
 */
bool Sistema::sairCanal()
{
    canalAtual = nullptr;
    return true;
}

/**
 * @brief Verifica se o usuário está associado a um canal.
 * @return True se o usuário está associado a um canal, False caso contrário.
 */
bool Sistema::verificaUsuarioNoCanal()
{
    if (canalAtual == nullptr)
    {
        return false;
    }
    return true;
}

/**
 * @brief Envia uma mensagem para o canal atualmente selecionado.
 * @param mensagem Conteúdo da mensagem a ser enviada.
 */
void Sistema::enviarMensagem(string mensagem)
{
    chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));

    Mensagem mensagemOBJ;
    mensagemOBJ.dataHora = buffer;
    mensagemOBJ.enviadaPor = usuarioAtual->id;
    mensagemOBJ.conteudo = mensagem;

    if (canalAtual == nullptr)
    {
        cout << "Nenhum canal selecionado." << endl;
        return;
    }

    if (CanalTexto *canalTexto = dynamic_cast<CanalTexto *>(canalAtual))
    {
        canalTexto->mensagens.push_back(mensagemOBJ);
    }
    else if (CanalVoz *canalVoz = dynamic_cast<CanalVoz *>(canalAtual))
    {
        canalVoz->ultimaMensagem = mensagemOBJ;
    }
    else
    {
        cout << "Canal inválido." << endl;
        return;
    }
}

/**
 * @brief Exibe as mensagens do canal atualmente selecionado.
 * Se não houver nenhuma mensagem para exibir, exibe uma mensagem de aviso.
 */
void Sistema::printMensagens()
{
    if (CanalTexto *canalTexto = dynamic_cast<CanalTexto *>(canalAtual))
    {
        vector<Mensagem> mensagens = canalTexto->mensagens;

        if (mensagens.empty())
        {
            cout << "Sem mensagens para exibir" << endl;
            return;
        }

        for (const Mensagem &mensagem : mensagens)
        {
            cout << usuarioAtual->nome << "<" << mensagem.dataHora << ">: " << mensagem.conteudo << endl;
        }
    }
    else if (CanalVoz *canalVoz = dynamic_cast<CanalVoz *>(canalAtual))
    {
        Mensagem mensagem = canalVoz->ultimaMensagem;

        if (mensagem.conteudo.empty())
        {
            cout << "Sem mensagens para exibir" << endl;
            return;
        }

        cout << usuarioAtual->nome << "<" << mensagem.dataHora << ">: " << mensagem.conteudo << endl;
    }
    else
    {
        cout << "Canal inválido." << endl;
    }
}

/**
 * @brief Chama os métodos salvarUsuarios e salvarServidores para salvar as informações
 * dos usuários e servidores nos arquivos externos.
 */
void Sistema::salvar()
{
    salvarUsuarios();
    salvarServidores();
}

/**
 * @brief Salva no arquivo externo usuarios.txt as informações referentes aos usuários do sistema.
 */
void Sistema::salvarUsuarios()
{
    ofstream arquivo("../arquivos/usuarios.txt");

    if (!arquivo.is_open())
    {
        // O arquivo não existe, então vamos criá-lo
        arquivo.open("../arquivos/usuarios.txt", ios::app);

        if (!arquivo.is_open())
        {
            cout << "Error: não foi possiível abrir o arquivo!" << endl;

            return;
        }
    }

    arquivo << usuarios.size() << "\n";

    for (Usuario *usuario : usuarios)
    {
        arquivo << usuario->id << "\n";
        arquivo << usuario->nome << "\n";
        arquivo << usuario->email << "\n";
        arquivo << usuario->senha << "\n";
    }

    arquivo.close();
}

/**
 * @brief Salva no arquivo externo servidores.txt as informações referentes aos servidores do sistema.
 */
void Sistema::salvarServidores()
{
    ofstream arquivo("../arquivos/servidores.txt");

    if (!arquivo.is_open())
    {
        arquivo.open("../arquivos/servidores.txt", ios::app);

        if (!arquivo.is_open())
        {
            cout << "Error: não foi possiível abrir o arquivo!" << endl;

            return;
        }
    }

    arquivo << servidores.size() << "\n";

    for (Servidor *servidor : servidores)
    {
        arquivo << servidor->usuarioDonoId << "\n";
        arquivo << servidor->nome << "\n";
        arquivo << servidor->descricao << "\n";
        arquivo << servidor->codigoConvite << "\n";
        arquivo << servidor->participantesIDs.size() << "\n";

        for (int i = 0; i < servidor->participantesIDs.size(); i++)
        {
            arquivo << servidor->participantesIDs[i] << "\n";
        }

        arquivo << servidor->canais.size() << "\n";

        for (int a = 0; a < servidor->canais.size(); a++)
        {

            arquivo << servidor->canais[a]->nome << "\n";
            if (CanalVoz *canalVoz = dynamic_cast<CanalVoz *>(servidor->canais[a]))
            {
                arquivo << "VOZ \n";
                if (canalVoz->ultimaMensagem.conteudo != "")
                {
                    arquivo << "1"
                            << "\n";
                }
                arquivo << canalVoz->ultimaMensagem.enviadaPor << "\n";
                arquivo << canalVoz->ultimaMensagem.dataHora << "\n";
                arquivo << canalVoz->ultimaMensagem.conteudo << "\n";
            }
            else if (CanalTexto *canalTexto = dynamic_cast<CanalTexto *>(servidor->canais[a]))
            {
                arquivo << "TEXTO \n";
                arquivo << canalTexto->mensagens.size() << "\n";

                for (Mensagem mensagem : canalTexto->mensagens)
                {
                    arquivo << mensagem.enviadaPor << "\n";
                    arquivo << mensagem.dataHora << "\n";
                    arquivo << mensagem.conteudo << "\n";
                }
            }
        }
    }

    arquivo.close();
}

/**
 * @brief Chama os métodos carregarUsuarios e carregarServidores para resgatar as informações
 * dos usuários e servidores nos arquivos externos.
 */
void Sistema::carregar()
{
    carregarUsuarios();
    carregarServidores();
}

/**
 * @brief Recupera os dados referentes aos usuários no arquivo externo e adiciona na aplicação.
 */
void Sistema::carregarUsuarios()
{
    cout << "Carregando dados ... " << endl;

    int qUsuarios = 0;
    string linha;

    ifstream arquivo("../arquivos/usuarios.txt");

    if (arquivo.is_open())
    {
        getline(arquivo, linha);
        if (linha == "")
        {
            cout << "O arquivo não possui dados." << endl;
            return;
        }
        qUsuarios = stoi(linha);

        for (int i = 0; i < qUsuarios; i++)
        {
            auto usuario = new Usuario();
            getline(arquivo, linha);
            usuario->id = stoi(linha);
            // Adiciona o id do último usuário
            this->id = stoi(linha);
            getline(arquivo, linha);
            usuario->nome = linha;
            getline(arquivo, linha);
            usuario->email = linha;
            getline(arquivo, linha);
            usuario->senha = linha;

            usuarios.push_back(usuario);
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Falha ao abrir o arquivo de entrada. Pode ser que ele não exista." << std::endl;
    }
}

/**
 * @brief Recupera os dados referentes aos servidores no arquivo externo e adiciona na aplicação.
 */
void Sistema::carregarServidores()
{
    cout << "Carregando dados ... " << endl;

    int qServidores = 0;
    int qUsuarios = 0;
    int qCanais = 0;
    int qMensagem = 0;
    string nomeCanal;
    string linha;

    ifstream arquivo("../arquivos/servidores.txt");

    if (arquivo.is_open())
    {
        // n servidores
        getline(arquivo, linha);
        // cout << linha << endl;
        if (linha == "")
        {
            cout << "O arquivo não possui dados." << endl;
            return;
        }
        qServidores = stoi(linha);

        for (int i = 0; i < qServidores; i++)
        {
            auto servidor = new Servidor();

            // id usuário dono
            getline(arquivo, linha);
            // cout << linha << endl;
            servidor->usuarioDonoId = stoi(linha);

            // nome do server
            getline(arquivo, linha);
            // cout << linha << endl;
            servidor->nome = linha;

            // descrição server
            getline(arquivo, linha);
            // cout << linha << endl;
            servidor->setDescricao(linha);

            // código de convite
            getline(arquivo, linha);
            // cout << linha << endl;
            servidor->setCodigoConvite(linha);

            // n usuários
            getline(arquivo, linha);
            // cout << linha << endl;
            qUsuarios = stoi(linha);

            for (int i = 0; i < qUsuarios; i++)
            {
                // id usuário participante
                getline(arquivo, linha);
                // cout << linha << endl;
                servidor->participantesIDs.push_back(stoi(linha));
            }

            // n canais
            getline(arquivo, linha);
            // cout << linha << endl;
            qCanais = stoi(linha);

            for (int i = 0; i < qCanais; i++)
            {
                // nome canal
                getline(arquivo, linha);
                // cout << linha << endl;
                nomeCanal = linha;

                // tipo canal
                getline(arquivo, linha);
                // cout << linha << endl;

                if ("TEXTO" == linha)
                {
                    auto canalTexto = new CanalTexto();
                    canalTexto->nome = nomeCanal;

                    // n mensagens
                    getline(arquivo, linha);
                    qMensagem = stoi(linha);
                    // cout << linha << endl;
                    for (int i = 0; i < qMensagem; i++)
                    {
                        auto mensagem = new Mensagem();

                        // ID do usuário que a escreveu
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        mensagem->enviadaPor = stoi(linha);

                        // Data e hora
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        mensagem->dataHora = linha;

                        // conteúdo
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        mensagem->conteudo = linha;

                        // adição da mensagem no canal
                        canalTexto->mensagens.push_back(*mensagem);
                    }

                    // adição do canal no servidor
                    servidor->canais.push_back(canalTexto);
                }
                else
                {
                    auto canalVoz = new CanalVoz();
                    canalVoz->nome = nomeCanal;

                    // n mensagens
                    getline(arquivo, linha);
                    // cout << linha << endl;
                    qMensagem = stoi(linha);
                    if (qMensagem != 0)
                    {

                        // ID do usuário que a escreveu
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        canalVoz->ultimaMensagem.enviadaPor = stoi(linha);

                        // Data e hora
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        canalVoz->ultimaMensagem.dataHora = linha;

                        // conteúdo
                        getline(arquivo, linha);
                        // cout << linha << endl;
                        canalVoz->ultimaMensagem.conteudo = linha;
                    }

                    // adição do canal no servidor
                    servidor->canais.push_back(canalVoz);
                }
            }

            // adição do servidor no vetor de servidores em sistema
            servidores.push_back(servidor);
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Falha ao abrir o arquivo de entrada. Pode ser que ele não exista." << std::endl;
    }
}
