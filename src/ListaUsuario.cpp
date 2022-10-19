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
    return ;
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

  cout << "ERRO: CONTA " << id_destinatario << " NAO EXISTE\n";
}

bool ListaUsuario::procuraUsuario(int id){
  Usuario* auxiliar = head;
  if(head == nullptr){
    return 0;
  }
  else{
    while(auxiliar){
      if(auxiliar->Id == id){
        return 1;
      }
      auxiliar = auxiliar->next;
    }
  }
  return 0;
}

void ListaUsuario::removerUsuario(int id)
// Descricao: Recebe o id do usuario e apaga o usuario, caso o mesmo exista, desalocando da lista
// Entrada: id
// Saida: Depende da existencia do usuario
{
  Usuario* auxiliar = head;
  Usuario* auxiliar2;

  if(!procuraUsuario(id)){
    cout << "ERRO: CONTA " << id << " NAO EXISTE\n";
    return ;
  }
  else{
    while(auxiliar){
      if(head->Id == id){
        head = head->next;
      }
      else if(auxiliar->next == nullptr){
        break;
      }
      else if(auxiliar->next->Id == id){
        auxiliar2 = auxiliar->next;
        auxiliar->next = auxiliar2->next;
        delete auxiliar2;
        break;
      }
      auxiliar = auxiliar->next;
    }
    cout << "OK: CONTA " << id << " REMOVIDA\n";
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
    // user->DesalocaMensagens();
    head->next = user->next;
    delete user;
    user = head->next;
  }
  // user->DesalocaMensagens();
}    // auxiliar = auxiliar->next;
    // cout << "OK: CONTA " << id << " REMOVIDA\n";
    // delete head;
    // head = auxiliar;

ListaUsuario::~ListaUsuario()
// Descricao: Destrutor do objeto ListaUsuario
// Entrada: Não tem
// Saida: head
{
  if(head != NULL){
    Limpa();  
    delete head;
  }
  // delete head;
}