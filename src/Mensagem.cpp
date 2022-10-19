//---------------------------------------------------------------------
// Arquivo	: Mensagem.cpp
// Conteudo	: implementacao do TAD Mensagem 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------
#include "Email.h"

Email::Email()
// Descricao: Construtor do Objeto Mensagem
// Entrada: Não tem
// Saida: Não tem
{
  this -> Next = NULL;
}

Email::Email(int prioridade, string mensagem)
// Descricao: Sobrecarga do construtor Mensagem que recebe dois parametros inicias
// Entrada: prioridade, mensagem
// Saida: Não tem
{
  this -> Prioridade = prioridade;
  this -> Mensagem = mensagem; 
  this -> Next = NULL;
}

Email::~Email()
// Descricao: Destrutor do objeto Mensagem
// Entrada: Não tem
// Saida: Não tem
{}