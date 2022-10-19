//---------------------------------------------------------------------
// Arquivo	: ListaUsuario.h
// Conteudo	: Definições do TAD ListaUsuario 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H
#include "Usuario.h"

class ListaUsuario
{
public:
  Usuario* Head;
  ListaUsuario();

  void Cadastra_Usuario( int id );
  void Mostrar_Caixa_de_Entradada( int id );
  void Envia_Mensagem( int id, Email& mensagem );
  bool Procura_Usuario( int id );
  void Remove_Usuario( int id );
  void Limpa();
  virtual ~ListaUsuario();
};

#endif