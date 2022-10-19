//---------------------------------------------------------------------
// Arquivo	: CaixaEntrada.h
// Conteudo	: Definições do TAD CaixaEntrada 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#ifndef CAIXAENTRADA_H
#define CAIXAENTRADA_H
#include "Mensagem.h"

class CaixaEntrada{
  public:
    Mensagem* head = nullptr;
    Mensagem* temporario = nullptr;

    CaixaEntrada();
    CaixaEntrada(Mensagem& msg);
    
    void Insere_Prioridade(Mensagem &msg);
    void mostrarPrioridade();
    void DesalocaMensagens();
    virtual ~CaixaEntrada();
};

#endif
