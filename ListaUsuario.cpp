//---------------------------------------------------------------------
// Arquivo	: ListaUsuario.cpp
// Conteudo	: implementacao do TAD ListaUsuario  
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "ListaUsuario.h"

ListaUsuario::ListaUsuario()
// Descricao: Construtor do objeto ListaUsuario
// Entrada: Não tem
// Saida: head
{
  head = nullptr;
}


void ListaUsuario::cadastroUsuario(int id)
// Descricao: Cadastra o obejeto Usuario em ordem sequencial
// Entrada: id
// Saida: Ultimo elemento da lista
{
  Usuario* auxiliar = this->head;

  if(this->head==nullptr){
    this->head = new Usuario(id);
    cout << "OK: CONTA "<< id <<" CADASTRADA\n";
  }
  else{
    
    while (auxiliar->next != nullptr){
        
      if(auxiliar->Id == id){
        cout << "ERRO: CONTA " << auxiliar->Id << " JA EXISTENTE\n";
        return;
      }
      auxiliar = auxiliar->next;
    }

    if(auxiliar->Id == id){
      cout << "ERRO: CONTA " << id << " JA EXISTENTE\n";
      return;
    }

    auxiliar->next = new Usuario(id);
    cout << "OK: CONTA "<< id <<" CADASTRADA\n";
  }
}

void ListaUsuario::mostrarCaixaEntradada(int id)
// Descricao: Recebe o id de um usuario e procura na lista, caso exista, instancia o usuario e exibe o primerio elemento da caixa de entrada
// Entrada: id
// Saida: Depende se o usuario exista ou não
{
  Usuario* user = head;
    while(user){
      if(user->Id == id){
        cout << "CONSULTA " << user->Id << ": ";
        user->ExibeMensagens();
        return ;
      }
      user = user->next;
    }
    cout << "ERRO: CONTA " << id << " NAO EXISTE\n";
}

void ListaUsuario::enviaMensagem(int id_destinatario, Mensagem &msg)
// Descricao: Procrua na Lista de usuario se caso o usuario está cadastrado e caso esteja, envia mensagem para sua caixa de entrada
// Entrada: id, Mensagem
// Saida: Depende da existencia do usuario na lista
{
  Usuario* usuarios = head;

  while(usuarios){
    if(usuarios->Id == id_destinatario){
      usuarios->RecebeMensagem(msg);
      cout << "OK: MENSAGEM PARA " << id_destinatario << " ENTREGUE\n";
      return;
    }
    usuarios = usuarios->next;
  }

  cout << "ERRO: CONTA " << id_destinatario << " NAO EXSITE\n";
}

void ListaUsuario::removerUsuario(int id)
// Descricao: Recebe o id do usuario e apaga o usuario, caso o mesmo exista, desalocando da lista
// Entrada: id
// Saida: Depende da existencia do usuario
{
  Usuario* auxiliar = head;
  Usuario* auxiliar2;

  if(head == nullptr){
    cout << "ERRO: CONTA " << id << " NAO EXSITE\n";
  }
  else if(head->Id == id){
    auxiliar = auxiliar->next;
    cout << "OK: CONTA " << head->Id << " REMOVIDA\n";
    delete head;
    head = auxiliar;
  }else{
    while(auxiliar->next->Id != id){
      auxiliar = auxiliar->next;
      if(auxiliar == nullptr){
        cout << "ERRO: CONTA " << id << " NAO EXSITE\n";
        return ;
      }
    }
    auxiliar2 = auxiliar->next;
    auxiliar->next = auxiliar2->next;
    cout << "OK: CONTA " << auxiliar2->Id << " REMOVIDA\n";
    delete auxiliar2;
  }
}

void ListaUsuario::Limpa()
// Descricao: Responsável por desalocar usuario que não foram desalocado ao decorrer do programa
// Entrada: Não tem
// Saida: head
{
  Usuario *user;
  user = head->next;
  
  while(user != NULL){
    head->next = user->next;
    delete user;
    user = head->next;
  }
}

ListaUsuario::~ListaUsuario()
// Descricao: Destrutor do objeto ListaUsuario
// Entrada: Não tem
// Saida: head
{
  Limpa();
  delete head;
}