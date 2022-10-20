//---------------------------------------------------------------------
// Arquivo	: CaixaEntrada.cpp
// Conteudo	: implementacao do TAD CaixaEntrada 
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "CaixaEntrada.h"

CaixaEntrada::CaixaEntrada()
// Descricao: Construtor padrão para o objeto CaixaEntrada. Head é inicializada como null
// Entrada: Não tem
// Saida: Head
{

  Head = NULL;

}

CaixaEntrada::CaixaEntrada( Email& mensagem )
// Descricao: Sobrecarga do Construtor CaixaEntrada que recebe o objeto mensagem no atributo Head
// Entrada: Mensagem
// Saida: Head
{

  Head = new Email( mensagem );

}


void CaixaEntrada::Insere_Prioridade( Email& mensagem )
// Descricao: Insere um email no objeto Caixa de Entrada com base na prioridade que neste caso é crescente 
// Entrada: Mensagem
// Saida: Head
{

  Email *novo_email = new Email( mensagem );
  Email *auxiliar1 = Head;
  Email *auxiliar2 = Head;

  novo_email ->  Next = NULL;

  while(( auxiliar2 != NULL ) && ( auxiliar2->Prioridade >= novo_email -> Prioridade )){
  
    auxiliar1 = auxiliar2;
    auxiliar2 = auxiliar2 -> Next;
  
  }
  if( auxiliar1 == auxiliar2 ){

    novo_email ->  Next = auxiliar1;
    Head = novo_email;
  
  }
  else{

    novo_email ->  Next = auxiliar1 ->  Next;
    auxiliar1 ->  Next = novo_email;
  
  }

}

void CaixaEntrada::Mostrar_Prioridade()
// Descricao: Exibe um email com base em sua prioridade e logo em seguida desaloca ele 
// Entrada: Não tem
// Saida: Head
{
  Email* emails = Head;
  Email* temporario = Head;

  if(Head == NULL){
  
    cout << "CAIXA DE ENTRADA VAZIA\n";
  
  }
  else{

    cout << emails -> Mensagem << "\n";
    temporario = temporario-> Next;
    delete Head;
    Head = temporario;
  
  }

}

void CaixaEntrada::Desaloca_Mensagens()
// Descricao: Desaloca todas os objetos do tipo Mensagem restante na Caixa de entrada, caso houver
// Entrada: Não tem
// Saida: Head
{
  
  Email *emails;
  if( Head == nullptr ){
    
    delete Head;
    return ;
  
  }
  else{
  
    emails = Head-> Next;
    while(emails){
  
      Head-> Next = emails-> Next;
      delete emails;
      emails = Head-> Next;
  
    }
  
  }

}


CaixaEntrada::~CaixaEntrada()
// Descricao: Destrutor para a função CaixaEntrada
// Entrada: Não tem
// Saida: Head
{

  Desaloca_Mensagens();
  delete Head;

}


