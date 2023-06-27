cmake_minimum_required(VERSION 3.0)
project(concordo)

set(CMAKE_CXX_STANDARD 11)

add_executable(concordo main.cpp src/sistema.cpp src/servidor.cpp src/usuario.cpp
)