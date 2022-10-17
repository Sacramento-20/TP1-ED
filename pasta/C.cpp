#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctype.h>

using namespace std;


bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
  ifstream texto;
  string frase;
  string consulta = "CONSULTA";
  string cadastra = "CADASTRA";
  string entrega = "ENTREGA";
  string remove = "REMOVE";
  int id_usuario = 0, tamanho_frase;
  int prioridade;

  texto.open(argv[1]);

  while (!texto.eof())
  {
    getline(texto, frase);
    size_t encontrou_entrega = frase.find(entrega);
    size_t encontrou_consulta = frase.find(consulta);
    size_t encontrou_cadastra = frase.find(cadastra);
    size_t encontrou_remove = frase.find(remove);

    if (encontrou_cadastra != string::npos)
    {
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find(" ", 0);

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find(" ", pos + 1);

      string digito =  frase.substr(tam, pos - tam);
      
      if(isNumber(digito)){
        id_usuario = stoi(frase.substr(tam, pos - tam));
        cout << "Cadastra " << id_usuario << "\n";
      }
      else{
        // assert
        cout << "Valor encontrado não é numerico\n";
      }
    }

    else if (encontrou_consulta != string::npos)
    {
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find(" ", 0);

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find(" ", pos + 1);

      string digito =  frase.substr(tam, pos - tam);

      if(isNumber(digito)){
        id_usuario = stoi(frase.substr(tam, pos - tam));
        cout << "Consulta " << id_usuario << "\n";
      }
      else{
        // assert
        cout << "Valor encontrado não é numerico\n";
      }
      
    }

    else if (encontrou_entrega != string::npos)
    {
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find(" ", 0);

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find(" ", pos + 1);
      string digitoid =  frase.substr(tam, pos - tam);
      // id_usuario = stoi(frase.substr(tam, pos - tam));
      if(isNumber(digitoid)){
        id_usuario = stoi(frase.substr(tam, pos - tam));
        cout << "ID:  " << id_usuario << "\n";
      }
      else{
        // assert
        cout << "Valor encontrado para id não é numerico\n";
        return 0;
      }


      // é recebida a posição da prioridade.
      tam = pos + 1;
      pos = frase.find(" ", pos + 1);
      string digitoprio =  frase.substr(tam, pos - tam);
  

      if(isNumber(digitoprio)){
        prioridade = stoi(frase.substr(tam, pos - tam));
        cout << "Prioridade: " << prioridade << "\n";
      }
      else{
        // assert
        cout << "Valor encontrado para prioridade não é numerico\n";
        return 0;
      }

      // todo o conteudo do email.
      tam = pos + 1;
      pos = frase.find(" FIM", pos + 1);

      string mensagem = frase.substr(tam, pos - tam);

      cout << "Entrega: " << mensagem << "\n";
    }

    else if (encontrou_remove != string::npos)
    {
      int pos, tam;

      // pos recebe a posição a frente a função que entrega
      pos = frase.find(" ", 0);

      // é recebida a posição do id do usuario
      tam = pos + 1;
      pos = frase.find(" ", pos + 1);

      string digitoremove =  frase.substr(tam, pos - tam);
      
      if(isNumber(digitoremove)){
        id_usuario = stoi(frase.substr(tam, pos - tam));
        cout << "Remove " << id_usuario << "\n";
      }
      else{
        // assert
        cout << "Valor encontrado não é numerico\n";
      }
    }
  }
  texto.close();

  
}

