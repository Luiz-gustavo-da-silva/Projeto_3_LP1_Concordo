# Projeto 3 LP1 Concordo parte 1

## Grupo:

Luiz Gustavo da Silva

### Link do GitHub

https://github.com/Luiz-gustavo-da-silva/Projeto_3_LP1_Concordo

### Objetivo

Esse projeto tem o objetivo de compor a nota da 3° unidade da disciplina de LP1, trabalhando com conceitos de
Herança, Classes abstratas, Manipulação de Arquivos, Standard Template Library (STL) e vector. O projeto consiste em
um sistema chamado "Concordo" com recursos similares ao Discord, porém vai funcionar somente em modo texto e sem recursos de rede.

https://drive.google.com/file/d/1WWUY1W99fN9bv5E-Csypsgcs-ogpLlNZ/view?usp=sharing

### Compilação:

- Clone o repositório "git clone https://github.com/Luiz-gustavo-da-silva/Projeto_3_LP1_Concordo.git"
- Navegue até ele "cd Projeto_3_LP1_Concordo"
- Crie uma pasta build na raiz do projeto
- Navegue até ela
- Execute o camando cmake ..
- Execute o comando make
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

### Dificuldades

Alocação dinâmica.

### Tecnologias utilizadas

C++, Makefile e doxywizard.
