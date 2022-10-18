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
  Após essas operações um while é iniciado, ele irá fazer duas comparações, checar se o auxiliar2 é um valor diferente de nulo e se o atributo prioridade do auxiliar é maior ou igual ao atributo prioridade da nova mensagem.
  caso a afirmação for verdadeira:
    O auxiliar1 irá receber o endereço de auxiliar2 que está iterando a lista e o auxiliar2 recebe um ponteiro para o proximo email.
  caso a afirmação for falsa:
    para os dois casos ele será testado na estrutura de condição abaixo do while, porem é checado para caso a nova mensagem for maior que o primeiro elemento da lista. Neste caso, o auxiliar 1 que possui um ponteiro pra a cabeça aponta para a nova mensagem transformando ela na cabeça da lista. Analogo a isso, o else da estrutura condicional insere a mensagem sequencialmente.
  
  MostrarPrioridade: Metodo do tipo void que não possui nenhum parametro para ser inicializado. O metodo iniciará duas variaveis do tipo ponteiro Mensagem, mensagens e temporario, ambas sendo apontadas para a cabeça da lista de emails.
  através de uma estrutura de condição, primeiro é checado se a cabeça da lista é nula, caso seja verdadeiro, é retornado o erro de que a caixa de entrada está vazia, caso contrário, será exibida a mensagem atraves do ponteiro mensagens que foi declarado no escopo da função, a variavel temporaria que tambem está apontando para head, aponta para o segundo elemento da lista, o elemento que está na cabeça da lista (mensagem com maior prioridade e com ordem de chegada) é desalocado. Dessa forma o elemento cabeça recebe a variavel temporada que no momento está apontando para o elemento seguinte da lista.

  DesalocaMensagens: Metodo do tipo vazio que não possui nenhum parametro. Ele é responsável por desalocar todos os objetos do tipo Mensagens ao final da execução do programa, para isso, inicialmente é alocado uma variavel ponteiro do tipo Mensagem que será usada para iterar a caixa de entrada e desalocar as mensagens.
  apos a inicialização do ponteiro mensagem e passado uma estrutura condicional que checa, caso a caixa de entrada do usuario já está vazia ou não com a expressão: se cabeça for nula. Caso seja, apenas é deletada a cabeça da lista, caso contrario, o ponteiro declarada no inicio do metodo, recebe o elemento posterior a head e inicializa um while até a variavel mensagem ser totalmente percorrida, dentro do while ó objeto alocado no head  é passado para o ponteiro mensagem que em seguida é deletado da memoria, apos isso, a variavel mensagem recebe novamente o proximo elemento e assim é iterado até a todas as mensagens serem totalmente desalocadas.

  Destrutor CaixaEntrada: Destrutor virtual que recebe o metodo DesalocaMensagens como descrita a cima e após isso, desaloca o elemento que se encontra na cabeça da lista.

### Usuario
  O TAD Usuario além de possuir um atributo do tipo id e um ponteiro do mesmo tipo para a implementação da lista de usuario, também, atraves de composição recebe o TAD CaixaEntrada. Dessa forma, cada Usuario irá possuir uma caixa de entrada separadamente com o atributo Id para diferencia-los entre si.

  Atributos do TAD Usuario

  Id: atributo do tipo inteiro que será utilizada para identificar o usuario no momento do cadastro em uma fila encadeada do tipo Usuario.

  Emails: Atributo do tipo CaixaEntrada, uma lista encadeada de emails.

  next: ponteiro do tipo Usuario que será o nó da lista encadeada de usuarios.

  Usuario: Construtor padrão do objeto usuario

  Sobrecarga Usuario: Construtor sobrecarregado de usuario que recebe como parametro o id do usuario e atribui o valor do parametro ao atributo id.

  RecebeMensagens: Metodo do tipo void que recebe como parametro um objeto do tipo mensagem que instancia um metodo do TAD Caixa de entrada, chamadando a função Insere_Prioridade

  ExibeMensagens: Metodo do tipo void que possui uma instancia caixa de entrada que exibe uma mensagem instanciando um metodo da composição da caixa de entrada.

  DesalocaMensagens: Metodo do tipo void que não recebe parametro e que instancia um metodo do TAD caixa de entrada DesalocaMensagens.

  Destrutor Usuario: Destrutor virtual que não possui nenhuma implementação.

### ListaUsuario
