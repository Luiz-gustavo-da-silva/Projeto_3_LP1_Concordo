# Projeto 3 LP1 Concordo parte 1 e 2

## Grupo:

Luiz Gustavo da Silva

### Link do GitHub

https://github.com/Luiz-gustavo-da-silva/Projeto_3_LP1_Concordo

### Objetivo

Esse projeto tem o objetivo de compor a nota da 3° unidade da disciplina de LP1, trabalhando com conceitos de
Herança, Classes abstratas, Manipulação de Arquivos, Standard Template Library (STL) e vector. O projeto consiste em
um sistema chamado "Concordo" com recursos similares ao Discord, porém vai funcionar somente em modo texto e sem recursos de rede.

https://docs.google.com/document/d/1cWiRVAXkkgIILL5snvoVAJLwmTi6YP-UmX4l7JNrLBE/edit?usp=sharing

### Compilação:

- Clone o repositório "git clone https://github.com/Luiz-gustavo-da-silva/Projeto_3_LP1_Concordo.git"
- Navegue até ele "cd Projeto_3_LP1_Concordo"
- Crie uma pasta build na raiz do projeto
- Navegue até ela "cd build"
- Execute o camando "cmake ..""
- Execute o comando "make"
- Por fim, rode o executável gerado "./concordo"

### Comandos do código

- quit: programa é fechado

- create-user: criação de usuário

- login: conectar usuário no sistema

- disconnect: disconectar usuário do sistema

- create-server: criação de servidores (o dono é o usuário logado)

- set-server-desc: atualização da descrição de um servidor (só funciona para donos) 

- set-server-invite-code: setar código de convite para o servidor (só funciona para donos) 

- list-servers: listar os servidores do sistema

- remove-server: remover servidor do sistema (só funciona para donos logado no sistema) 

- enter-server: entrar em um servidor (é necessário informar a senha caso o servidor tiver)

- leave-server: remoção de um servidor do sistema (só funciona para donos)    

- list-participants: listar usuários participantes de um servidor pelo nome 

- list-channels: listar canais de um servidor

- create-channel: criar canal em um servdor

- enter-channel: entrar em um canal de um servidor

- send-message: mandar mensagem em um canal

- list-messages: listar mensagens de um chat 

- leave-channel: sair de um canal 

- exit: terminar a execução do programa

### Dificuldades

Alocação dinâmica.

### Tecnologias utilizadas

C++, Makefile e doxywizard.