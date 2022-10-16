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
    
    ~Usuario();
};

#endif