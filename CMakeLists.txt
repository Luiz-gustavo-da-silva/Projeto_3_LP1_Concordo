cmake_minimum_required(VERSION 3.0)
project(playList)

set(CMAKE_CXX_STANDARD 11)

add_executable(playList main.cpp 
src/Musica.cpp 
src/No.cpp 
src/EncadeadaLista.cpp 
src/PlayList.cpp 
src/NoPlayList.cpp 
src/EncadeadaListaPlayList.cpp 
src/gerenciaPlayList.cpp
src/GerenciaMusica.cpp
)