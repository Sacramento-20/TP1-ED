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

void Usuario::Exibe_Mensagens()
// Descricao: Chama função que exibe por prioridade da sua lista de emails cadastrados
// Entrada: Não tem
// Saida: CaixaEntrada
{

  this->Emails.Mostrar_Prioridade();

}

void Usuario::Recebe_Mensagem( Email& mensagem )
// Descricao: Cadastra um novo Email na caixa de entrada do proprio usuario, instanciando o objeto CaixaEntrada
// Entrada: Mensagem
// Saida: CaixaEntrada
{

  this -> Emails.Insere_Prioridade( mensagem );

}

void Usuario::Desaloca_Mensagens(){
  
  this -> Emails.Desaloca_Mensagens();

}

Usuario::~Usuario()
// Descricao: Destrutor do objeto Usuario
// Entrada: Não tem
// Saida: Não tem
{}

