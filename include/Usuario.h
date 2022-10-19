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
    Usuario* Next = nullptr;

    Usuario();
    Usuario(int id);
    void Recebe_Mensagem( Email& mensagem );
    void Exibe_Mensagens();
    void Desaloca_Mensagens();
    
    virtual ~Usuario();
};

#endif