//---------------------------------------------------------------------
// Arquivo	: Mensagem.h
// Conteudo	: Definições do TAD Mensagem 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Mensagem{
  public:
    int Prioridade;
    string Msg;
    Mensagem* next; 

    Mensagem();
    Mensagem(int prioridade, string mensagem);
    void setProx(Mensagem* m);
    Mensagem* obterProx();
    ~Mensagem();
};

#endif