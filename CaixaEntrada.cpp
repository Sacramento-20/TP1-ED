//---------------------------------------------------------------------
// Arquivo	: CaixaEntrada.cpp
// Conteudo	: implementacao do TAD CaixaEntrada 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "CaixaEntrada.h"

CaixaEntrada::CaixaEntrada()
// Descricao: Construtor padrão para o objeto CaixaEntrada. Head é inicializada como null
// Entrada: Não tem
// Saida: head
{
  head = NULL;
}

CaixaEntrada::CaixaEntrada(Mensagem& msg)
// Descricao: Sobrecarga do Construtor CaixaEntrada que recebe o objeto mensagem no atributo head
// Entrada: Mensagem
// Saida: head
{
  head = new Mensagem(msg);
}


void CaixaEntrada::Insere_Prioridade(Mensagem &msg)
// Descricao: Insere um email no objeto Caixa de Entrada com base na prioridade que neste caso é crescente 
// Entrada: Mensagem
// Saida: head
{
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

void CaixaEntrada::mostrarPrioridade()
// Descricao: Exibe um email com base em sua prioridade e logo em seguida desaloca ele 
// Entrada: Não tem
// Saida: head
{
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

void CaixaEntrada::DesalocaMensagens()
// Descricao: Desaloca todas os objetos do tipo Mensagem restante na Caixa de entrada, caso houver
// Entrada: Não tem
// Saida: head
{
  Mensagem *msg;

  if(head == nullptr){
    delete head;
    return ;
  }
  else{
    msg = head->next;
    while(msg){
      head->next = msg->next;
      delete msg;
      msg = head->next;
    }
  }
}


CaixaEntrada::~CaixaEntrada()
// Descricao: Destrutor para a função CaixaEntrada
// Entrada: Não tem
// Saida: head
{
  // Mensagem *msg;
  // msg = head->next;
  // if(head == nullptr){
  //   delete head;
  //   return ;
  // }
  // else{
  //   while(msg){
  //     head->next = msg->next;
  //     delete msg;
  //     msg = head->next;
  //   }
  // }
  // DesalocaMensagens();
  delete head;
}


