cmake_minimum_required(VERSION 3.20)
project(Proyecto_1_Arqui)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wno-deprecated -Werror -pedantic -pedantic-errors -O3 -DNDEBUG -DCMAKE_BUILD_TYPE=Release)

add_executable(Proyecto_1_Arqui main.cpp)
