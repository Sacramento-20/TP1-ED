//---------------------------------------------------------------------
// Arquivo	: Main.cpp
// Conteudo	: implementacao do TAD MAT
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "../include/ListaUsuario.h" /*apagar depois*/
#include <iostream>
#include <fstream>
#include <string>
#include "../include/fMain.h"

using namespace std;

int main(int argc, char *argv[])
{
  ListaUsuario *Lista = new ListaUsuario();

  exibeMain(argv[1], Lista);

  delete Lista;
}
