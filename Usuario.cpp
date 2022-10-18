//---------------------------------------------------------------------
// Arquivo	: Usuario.cpp
// Conteudo	: implementacao do TAD Usuario 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "Usuario.h"

Usuario::Usuario()
// Descricao: Construtor padrão do objeto Usuario
// Entrada: Não tem
// Saida: Não tem
{}

Usuario::Usuario(int id)
// Descricao: Sobrecarga do contrutor Usuario
// Entrada: id
// Saida: id
{
  this -> Id = id;
}

Usuario::~Usuario()
// Descricao: Destrutor do objeto Usuario
// Entrada: Não tem
// Saida: Não tem
{
}

void Usuario::ExibeMensagens()
// Descricao: Chama função que exibe por prioridade da sua lista de emails cadastrados
// Entrada: Não tem
// Saida: CaixaEntrada
{
  this->Emails.mostrarPrioridade();
}

void Usuario::RecebeMensagem(Mensagem& msg)
// Descricao: Cadastra um novo Email na caixa de entrada do proprio usuario, instanciando o objeto CaixaEntrada
// Entrada: Mensagem
// Saida: CaixaEntrada
{
  this->Emails.Insere_Prioridade(msg);
}

void Usuario::DesalocaMensagens(){
  
  this->Emails.DesalocaMensagens();
}


