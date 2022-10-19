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
  Usuario* head;
  ListaUsuario();

  void cadastroUsuario(int id);
  void mostrarCaixaEntradada(int id);
  void enviaMensagem(int id_destinatario, Mensagem &msg);
  bool procuraUsuario(int id);
  void removerUsuario(int id);
  void Limpa();
  virtual ~ListaUsuario();
};

#endif