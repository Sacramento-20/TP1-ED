#ifndef CAIXAENTRADA_H
#define CAIXAENTRADA_H
#include "Mensagem.h"

class CaixaEntrada{
  public:
    Mensagem* head;
    Mensagem* tail;
    Mensagem* temporario;

    CaixaEntrada();
    CaixaEntrada(Mensagem& msg);
    
    bool vazia();
    void Insere_Prioridade(Mensagem &msg);
    void mostrar(int prioridade);
    void mostrarPrioridade();
    virtual ~CaixaEntrada();
};

#endif
