//---------------------------------------------------------------------
// Arquivo	: Mensagem.cpp
// Conteudo	: implementacao do TAD Mensagem 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------
#include "Mensagem.h"

Mensagem::Mensagem()
// Descricao: Construtor do Objeto Mensagem
// Entrada: Não tem
// Saida: Não tem
{
  this -> next = NULL;
}

Mensagem::Mensagem(int prioridade, string mensagem)
// Descricao: Sobrecarga do construtor Mensagem que recebe dois parametros inicias
// Entrada: prioridade, mensagem
// Saida: Não tem
{
  this -> Prioridade = prioridade;
  this -> Msg = mensagem; 
  this -> next = NULL;
}

Mensagem::~Mensagem()
// Descricao: Destrutor do objeto Mensagem
// Entrada: Não tem
// Saida: Não tem
{}