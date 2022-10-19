//---------------------------------------------------------------------
// Arquivo	: ListaUsuario.cpp
// Conteudo	: implementacao do TAD ListaUsuario  
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "ListaUsuario.h"

ListaUsuario::ListaUsuario()
// Descricao: Construtor do objeto ListaUsuario
// Entrada: Não tem
// Saida: Head
{
  Head = nullptr;
}


void ListaUsuario::Cadastra_Usuario( int id )
// Descricao: Cadastra o obejeto Usuario em ordem sequencial
// Entrada: id
// Saida: Ultimo elemento da lista
{

  Usuario* auxiliar = this -> Head;

  if( this -> Head == nullptr ){

    this -> Head = new Usuario( id );
    cout << "OK: CONTA "<< id <<" CADASTRADA\n";
  
  }
  else{
    
    while ( auxiliar -> Next != nullptr ){
        
      if( auxiliar -> Id == id ){
        
        cout << "ERRO: CONTA " << auxiliar -> Id << " JA EXISTENTE\n";
        return;
      
      }
      
      auxiliar = auxiliar -> Next;
    
    }

    if( auxiliar -> Id == id ){
      
      cout << "ERRO: CONTA " << id << " JA EXISTENTE\n";
      return;

    }

    auxiliar -> Next = new Usuario( id );
    cout << "OK: CONTA "<< id <<" CADASTRADA\n";

  }

}

void ListaUsuario::Mostrar_Caixa_de_Entradada( int id )
// Descricao: Recebe o id de um usuario e procura na lista, caso exista, instancia o usuario e exibe o primerio elemento da caixa de entrada
// Entrada: id
// Saida: Depende se o usuario exista ou não
{

  Usuario* user = Head;
  
  while( user ){
    
    if( user -> Id == id ){
    
      cout << "CONSULTA " << user->Id << ": ";
      user->Exibe_Mensagens();
      return ;
    
    }

    user = user -> Next;
  }

  cout << "ERRO: CONTA " << id << " NAO EXISTE\n";
  return ;

}

void ListaUsuario::Envia_Mensagem( int id, Email& mensagem )
// Descricao: Procrua na Lista de usuario se caso o usuario está cadastrado e caso esteja, envia mensagem para sua caixa de entrada
// Entrada: id, Mensagem
// Saida: Depende da existencia do usuario na lista
{

  Usuario* usuarios = Head;

  while( usuarios ){

    if( usuarios->Id == id ){
    
      usuarios->Recebe_Mensagem( mensagem );
      cout << "OK: MENSAGEM PARA " << id << " ENTREGUE\n";
      return;
    
    }

    usuarios = usuarios -> Next;
  
  }

  cout << "ERRO: CONTA " << id << " NAO EXISTE\n";

}

bool ListaUsuario::Procura_Usuario( int id ){
  
  Usuario* auxiliar = Head;
  
  if( Head == nullptr ){
    
    return 0;
  
  }
  else{

    while( auxiliar ){
      
      if( auxiliar -> Id == id ){
        
        return 1;
      
      }
      
      auxiliar = auxiliar -> Next;
    
    }
  
  }
  return 0;
}

void ListaUsuario::Remove_Usuario( int id )
// Descricao: Recebe o id do usuario e apaga o usuario, caso o mesmo exista, desalocando da lista
// Entrada: id
// Saida: Depende da existencia do usuario
{
  
  Usuario* auxiliar = Head;
  Usuario* auxiliar2;

  if( !Procura_Usuario( id ) ){

    cout << "ERRO: CONTA " << id << " NAO EXISTE\n";
    return ;
  
  }
  else{

    while( auxiliar ){

      if( Head -> Id == id ){
      
        Head = Head -> Next;
      
      }

      else if( auxiliar -> Next == nullptr ){
      
        break;
      
      }
      
      else if( auxiliar -> Next -> Id == id ){

        auxiliar2 = auxiliar -> Next;
        auxiliar -> Next = auxiliar2 -> Next;
        delete auxiliar2;
        break;

      }

      auxiliar = auxiliar -> Next;
   
    }
  
    cout << "OK: CONTA " << id << " REMOVIDA\n";
  
  }

}

void ListaUsuario::Limpa()
// Descricao: Responsável por desalocar usuario que não foram desalocado ao decorrer do programa
// Entrada: Não tem
// Saida: Head
{

  Usuario *user;
  
  user = Head -> Next;
  
  while( user != NULL ){
    
    Head -> Next = user -> Next;
    delete user;
    user = Head -> Next;
  
  }

}  

ListaUsuario::~ListaUsuario()
// Descricao: Destrutor do objeto ListaUsuario
// Entrada: Não tem
// Saida: Head
{

  if(Head != NULL){
  
    Limpa();  
    delete Head;
  
  }
  
}