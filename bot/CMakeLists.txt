cmake_minimum_required(VERSION 3.15)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src main.c logica.c logica.h camadadedados.c camadadedados.h interface.c interface.h listas.c listas.h bot.c bot.h)