#include "CaixaEntrada.h"

CaixaEntrada::CaixaEntrada(){
  head = NULL;
  tail = NULL;
}

CaixaEntrada::CaixaEntrada(Mensagem& msg){
  head = new Mensagem(msg);
  tail = head;  
}

CaixaEntrada::~CaixaEntrada(){
  delete head;
}


bool CaixaEntrada::vazia(){
  return(head == NULL);
}


void CaixaEntrada::Insere_Prioridade(Mensagem &msg){
  Mensagem *Nova_mensagem = new Mensagem(msg);

  Mensagem *auxiliar1 = head;
  Mensagem *auxiliar2 = head;

  Nova_mensagem->next = NULL;

  while((auxiliar2 != NULL) && (auxiliar2->Prioridade >= Nova_mensagem->Prioridade)){
    auxiliar1 = auxiliar2;
    auxiliar2 = auxiliar2->next;
  }
  if(auxiliar1 == auxiliar2){
    Nova_mensagem->next = auxiliar1;
    head = Nova_mensagem;
  }
  else{
    Nova_mensagem->next = auxiliar1->next;
    auxiliar1->next = Nova_mensagem;
  }
}



void CaixaEntrada::mostrarPrioridade(){
  Mensagem* mensagens = head;
  Mensagem* temp = head;

  if(head == NULL){
    cout << "CAIXA DE ENTRADA VAZIA\n";
  }
  else{
    cout << mensagens->Msg << "\n";
    temp = temp->next;
    delete head;
    head = temp;
  }
}



