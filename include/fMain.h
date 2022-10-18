#include "msgassert.h" 

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void exibeMain(string arquivo, ListaUsuario* Lista){
  ifstream texto;
  string frase;
  string consulta = "CONSULTA";
  string cadastra = "CADASTRA";
  string entrega = "ENTREGA";
  string remove = "REMOVE";
  int id_usuario = 0;
  int prioridade;

  texto.open(arquivo);

  while(!texto.eof()){
    getline(texto, frase); 
      size_t encontrou_entrega = frase.find(entrega);
      size_t encontrou_consulta = frase.find(consulta);
      size_t encontrou_cadastra = frase.find(cadastra);
      size_t encontrou_remove = frase.find(remove);
      
      if(encontrou_cadastra != string::npos){
        int pos, tam;

        // pos recebe a posição a frente a função que entrega
        pos = frase.find(" ", 0);

        // é recebida a posição do id do usuario
        tam = pos + 1;
        pos = frase.find(" ", pos + 1);

        string digito =  frase.substr(tam, pos - tam);
        
        if(isNumber(digito)){
          id_usuario = stoi(frase.substr(tam, pos - tam));
          // cout << "Cadastra " << id_usuario << "\n";
          Lista->cadastroUsuario(id_usuario);
        }
        else{
          // assert
          erroAssert(digito.empty(), "Valor encontrado não é numerico");
        }
          // id_usuario = frase[9] - '0';
      }
      
      else if(encontrou_consulta != string::npos){
        int pos, tam;

        // pos recebe a posição a frente a função que entrega
        pos = frase.find(" ", 0);

        // é recebida a posição do id do usuario
        tam = pos + 1;
        pos = frase.find(" ", pos + 1);

        string digito =  frase.substr(tam, pos - tam);

        if(isNumber(digito)){
          id_usuario = stoi(frase.substr(tam, pos - tam));
          Lista->mostrarCaixaEntradada(id_usuario);
        }
        else{
          // assert
          erroAssert(digito.empty(), "Valor encontrado não é numerico");
          
        }
        // id_usuario = frase[9] - '0';
      }
      
      else if(encontrou_entrega != string::npos){
        int pos, tam;

        // pos recebe a posição a frente a função que entrega
        pos = frase.find(" ", 0);

        // é recebida a posição do id do usuario
        tam = pos+1;
        pos = frase.find(" ", pos+1);
        string digitoid =  frase.substr(tam, pos - tam);
        // id_usuario = stoi(frase.substr(tam, pos-tam)); 
        if(isNumber(digitoid)){
          id_usuario = stoi(frase.substr(tam, pos - tam));
          // cout << "ID:  " << id_usuario << "\n";
        }
        else{
          // assert
          erroAssert(digitoid.empty(), "Valor encontrado para ID não é numerico");
          return;
        }
        
        // é recebida a posição da prioridade.
        tam = pos+1;
        pos = frase.find(" ", pos+1);
        string digitoprio =  frase.substr(tam, pos - tam);

        if(isNumber(digitoprio)){
          prioridade = stoi(frase.substr(tam, pos - tam));
          // cout << "Prioridade: " << prioridade << "\n";
        }
        else{
          // assert
          erroAssert(digitoprio.empty(),"Valor encontrado para prioridade não é numerico");
          return;
        }

        // todo o conteudo do email.
        tam = pos+1;
        pos = frase.find(" FIM", pos+1);

        string mensagem = frase.substr(tam, pos-tam);
        
        Mensagem msg;
        msg.Prioridade = prioridade;
        msg.Msg = mensagem;
        
        Lista->enviaMensagem(id_usuario, msg);

        // free(msg);
      }
    
      else if(encontrou_remove != string::npos){
        int pos, tam;

        // pos recebe a posição a frente a função que entrega
        pos = frase.find(" ", 0);

        // é recebida a posição do id do usuario
        tam = pos + 1;
        pos = frase.find(" ", pos + 1);

        string digitoremove =  frase.substr(tam, pos - tam);
        
        if(isNumber(digitoremove)){
          id_usuario = stoi(frase.substr(tam, pos - tam));
          Lista->removerUsuario(id_usuario);
        }
        else{
          // assert
          erroAssert(digitoremove.empty(), "Valor encontrado não é numerico");
        }
        
      }
  }
  texto.close();
}