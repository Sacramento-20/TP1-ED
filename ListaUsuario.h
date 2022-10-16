#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H
#include "Usuario.h"

class ListaUsuario
{
private:
  Usuario* head;
public:
  ListaUsuario();

  void cadastroUsuario(int id);
  void mostrarCaixaEntradada(int id);
  void enviaMensagem(int id_destinatario, Mensagem &msg);
  void removerUsuario(int id);
  virtual ~ListaUsuario();
};





#endif