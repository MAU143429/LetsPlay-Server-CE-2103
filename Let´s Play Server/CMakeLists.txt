# CMakeList.txt: proyecto de CMake para Let´s Play Server, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

project ("Let´s Play Server")

# Agregue un origen al ejecutable de este proyecto.
add_executable (CMakeTarget "Let´s Play Server.cpp" "Let´s Play Server.h")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
