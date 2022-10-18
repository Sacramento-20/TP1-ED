# TP1-ED
trabalho pratico 1 Estrutura de Dados

O Trabalho prático está dividido em quatro TADs, sendo eles: 
  Email, CaixaEntrada, Usuario, ListaUsuario, com as seguintes funcionalidades. 
## Contrato dos TADs
### Email
  O Tad Email conta com os atributos:
  Prioridade: variavel do tipo inteiro que será usada posteriormente para fazer a inserção na lista pela ordem de prioridade

  Msg: Variável do tipo string que será armazenado o conteúdo contido no email.

  next: Ponteiro do tipo mensagem que será utilizado no TAD CaixaEntrada como artificio pra percorrer a lista encadeada, sendo next uma variavel do tipo ponteiro que irá armazenar o endereço de memoria para um outro objeto do tipo mensagem.

  Construtor Mensagem: Função que não possui paramentro, nem saida, ele será utilizada como um construtor padrão inicialização em outras classes por meio de composição.

  Sobrecarga do construtor Mensagem: Construtor que é declarado com dois paramentros: prioridade e mensagem. Nele é atribuido os valores para os atributos, além de declarar o ponteiro next como nulo.

  Destrutor Mensagem: Declarado de forma virtual o destrutor para o objeto mensagem não possui nenhuma função em especifico.

### CaixaEntrada
  Atributos do TAD CaixaEntrada:

  head: ponteiro do tipo Mensagem que será utilizado como cabeça pra a lista encadeada de emails

  temporario:

  Construtor CaixaEntradada: O contrutor da classe CaixaEntrada apenas atribui o ponteiro de Mensagem head, como nulo.

  Sobrecarga do construtor CaixaEntrada: a primeira vez que o construtor da classe CaixaEntrada é chamada, ele receberá um objeto do tipo Mensagem e será atribuido como cabeça da lista encadeada. 

  Insere Prioridade: Método que recebe um objeto do tipo mensagem e que realiza a seguinte operação.
  Ao ser chamada, ela irá criar uma nova mensagem, a mesma que foi recebida como parametro da função, após isso, irá ser inicializado dois ponteiros, chamados auxiliar1 e auxiliar2 do tipo Mensagem que ambos são apontados para a cabeça da lista.
  O objeto Nova_mensagem que foi criado, tem seu ponteiro next inicializado como nulo.
  Após essas operações um while é iniciado, ele irá fazer duas comparações, checar se o auxiliar2 é um valor diferente de nulo e se o atributo prioridade do auxiliar é maior ou igual ao atributo prioridade da nova mensagem, se caso a afirmação for verdadeira:

  caso a afirmação for falsa:
  