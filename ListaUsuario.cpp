#include "ListaUsuario.h"


ListaUsuario::ListaUsuario(){
  head = nullptr;
}

ListaUsuario::~ListaUsuario(){
  delete head;
}

// Cadastrando mais de uma vez o mesmo usuario.
void ListaUsuario::cadastroUsuario(int id){
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

void ListaUsuario::mostrarCaixaEntradada(int id){
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
  // }
}

void ListaUsuario::enviaMensagem(int id_destinatario, Mensagem &msg){
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

void ListaUsuario::removerUsuario(int id){
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