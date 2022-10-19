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

class Email{
  public:
    int Prioridade;
    string Mensagem;
    Email* Next; 

    Email();
    Email(int prioridade, string mensagem);
    virtual ~Email();
};

#endif