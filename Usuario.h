//---------------------------------------------------------------------
// Arquivo	: Usuario.h
// Conteudo	: Definições do TAD Usuario
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#ifndef USUARIO_H
#define USUARIO_H
#include "CaixaEntrada.h"

class Usuario{
  public:
    int Id;
    CaixaEntrada Emails;  
    Usuario* next = nullptr;

    Usuario();
    Usuario(int id);
    void RecebeMensagem(Mensagem& msg);
    void ExibeMensagens();
    void setProx(Usuario* u);
    Usuario* obterProx();
    void DesalocaMensagens();
    
    ~Usuario();
};

#endif