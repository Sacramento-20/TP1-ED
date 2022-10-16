#include "Mensagem.h"

Mensagem::Mensagem(){}

Mensagem::Mensagem(int prioridade, string mensagem){
  this -> Prioridade = prioridade;
  this -> Msg = mensagem; 
  this -> next = NULL;
}

void Mensagem::setProx(Mensagem* m){
  next = m;
}

Mensagem* Mensagem::obterProx(){
  return next;
}


Mensagem::~Mensagem(){}