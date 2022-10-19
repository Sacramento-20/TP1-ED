//---------------------------------------------------------------------
// Arquivo	: CaixaEntrada.h
// Conteudo	: Definições do TAD CaixaEntrada 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#ifndef CAIXAENTRADA_H
#define CAIXAENTRADA_H
#include "Email.h"

class CaixaEntrada{
  public:
    Email* Head = nullptr;
    Email* Temporario = nullptr;

    CaixaEntrada();
    CaixaEntrada(Email& mensagem);
    
    void Insere_Prioridade(Email& mensagem);
    void Mostrar_Prioridade();
    void Desaloca_Mensagens();
    virtual ~CaixaEntrada();
};

#endif
