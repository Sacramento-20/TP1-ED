void exibeMain(string arquivo, ListaUsuario* Lista){
  ifstream texto;
  string frase;
  string consulta = "CONSULTA";
  string cadastra = "CADASTRA";
  string entrega = "ENTREGA";
  string remove = "REMOVE";
  int id_usuario = 0, tamanho_frase;
  int prioridade;

  texto.open(arquivo);

  while(!texto.eof()){
    getline(texto, frase); 
      size_t encontrou_entrega = frase.find(entrega);
      size_t encontrou_consulta = frase.find(consulta);
      size_t encontrou_cadastra = frase.find(cadastra);
      size_t encontrou_remove = frase.find(remove);
      
      if(encontrou_cadastra != string::npos){
        id_usuario = frase[9] - '0';
        Lista->cadastroUsuario(id_usuario);
      }
      
      else if(encontrou_consulta != string::npos){
        id_usuario = frase[9] - '0';
        Lista->mostrarCaixaEntradada(id_usuario);
      }
      
      else if(encontrou_entrega != string::npos){
        int pos, tam;

        // pos recebe a posição a frente a função que entrega
        pos = frase.find(" ", 0);

        // é recebida a posição do id do usuario
        tam = pos+1;
        pos = frase.find(" ", pos+1);
        id_usuario = stoi(frase.substr(tam, pos-tam)); 
        
        // é recebida a posição da prioridade.
        tam = pos+1;
        pos = frase.find(" ", pos+1);
        prioridade = stoi(frase.substr(tam, pos-tam)); 

        // todo o conteudo do email.
        tam = pos+1;
        pos = frase.find(" FIM", pos+1);

        string mensagem = frase.substr(tam, pos-tam);
        
        Mensagem msg;
        msg.Prioridade = prioridade;
        msg.Msg = mensagem;
        
        Lista->enviaMensagem(id_usuario, msg);
      }
    
      else if(encontrou_remove != string::npos){
        id_usuario = frase[7] - '0';
        Lista->removerUsuario(id_usuario);
      }
  }
  texto.close();
}