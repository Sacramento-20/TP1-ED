#include "Usuario.h"

Usuario::Usuario(int id){
  this -> Id = id;
}

Usuario::Usuario(){}

Usuario::~Usuario(){
}

void Usuario::ExibeMensagens(){
  this->Emails.mostrarPrioridade();
}

void Usuario::RecebeMensagem(Mensagem& msg){
  this->Emails.Insere_Prioridade(msg);
}

void Usuario::setProx(Usuario* u){
  next = u;
}

Usuario* Usuario::obterProx(){
  return next;
}


