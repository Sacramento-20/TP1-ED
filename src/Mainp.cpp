//---------------------------------------------------------------------
// Arquivo	: Main.cpp
// Conteudo	: implementacao do TAD MAT
// Autor	: Lucas Santana do Carmo Sacramento (sacramento-15@.ufmg.br)
//---------------------------------------------------------------------

#include "ListaUsuario.h"
#include <iostream>
#include <fstream>
#include <string>
#include "msgassert.h" 

using namespace std;

bool isNumber( const string& str ){

    for ( char const &c : str ) {

      if ( std::isdigit(c) == 0 ){
        
        return false;
      
      } 
    
    }

    return true;

}

int main( int argc, char *argv[] ){

  ListaUsuario *Lista = new ListaUsuario();
  ifstream texto;
  string frase, consulta = "CONSULTA", cadastra = "CADASTRA", entrega = "ENTREGA", remove = "REMOVE";
  int id_usuario = 0, prioridade;

  texto.open( argv[1] );

  while( !texto.eof() ){
    
    getline(texto, frase); 
    
    size_t encontrou_cadastra = frase.find(cadastra);
    size_t encontrou_consulta = frase.find(consulta);
    size_t encontrou_entrega = frase.find(entrega);
    size_t encontrou_remove = frase.find(remove);
    
    if( encontrou_cadastra != string::npos ){
      
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find( " ", 0 );

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find( " ", pos + 1 );

      string digito = frase.substr( tam, pos - tam );
      
      if( isNumber(digito) ){

        id_usuario = stoi(frase.substr(tam, pos - tam));
        Lista->Cadastra_Usuario(id_usuario);
      
      }
      else{

        erroAssert( digito.empty(), "Valor encontrado não é numerico" );
      
      }

    }
    
    else if( encontrou_consulta != string::npos ){
      
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find( " ", 0 );

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find( " ", pos + 1 );

      string digito =  frase.substr( tam, pos - tam );

      if( isNumber(digito) ){
        
        id_usuario = stoi(frase.substr(tam, pos - tam));
        Lista->Mostrar_Caixa_de_Entradada(id_usuario);
      
      }

      else{
        // assert
        erroAssert( digito.empty(), "Valor encontrado não é numerico" );
        
      }
      // id_usuario = frase[9] - '0';
    }
    
    else if( encontrou_entrega != string::npos ){
      
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find( " ", 0 );

      // é recebida a posição do id do usuario
      tam = pos+1;
      pos = frase.find( " ", pos+1 );

      string digito_id =  frase.substr( tam, pos - tam );
        
      if( isNumber( digito_id ) ){

        id_usuario = stoi(frase.substr( tam, pos - tam ));
        
      }
      else{
        
        erroAssert( digito_id.empty(), "Valor encontrado para ID não é numerico" );
      
      }
      
      // é recebida a posição da prioridade.
      
      tam = pos+1;
      pos = frase.find( " ", pos+1 );
      string digito_prioridade =  frase.substr( tam, pos - tam );

      if( isNumber( digito_prioridade ) ){
        
        prioridade = stoi( frase.substr(tam, pos - tam ));

      }
      else{
        
        erroAssert( digito_prioridade.empty(),"Valor encontrado para prioridade não é numerico" );
      
      }

      // todo o conteudo do email.
      tam = pos+1;
      pos = frase.find( " FIM", pos+1 );

      string mensagem = frase.substr( tam, pos-tam );
      
      Email email;
      email.Prioridade = prioridade;
      email.Mensagem = mensagem;
      
      Lista -> Envia_Mensagem( id_usuario, email );

    }
  
    else if( encontrou_remove != string::npos ){
      
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find( " ", 0 );

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find( " ", pos + 1 );

      string digito_remove =  frase.substr( tam, pos - tam );
      
      if( isNumber( digito_remove ) ){
      
        id_usuario = stoi( frase.substr( tam, pos - tam ) );
        Lista -> Remove_Usuario( id_usuario );
      
      }
      else{

        erroAssert( digito_remove.empty(), "Valor encontrado não é numerico" );

      }
      
    }

  }

  texto.close();

  delete Lista;

}
