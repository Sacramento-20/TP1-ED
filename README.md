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
  O TAD ListaUsuario possui a responsabilidade de coordenar todos os outros 3 TAD criados.
  Como uma lista de Usuario que consequentemente cada um deles possui uma caixa de entrada, esse será o contrato com o maior numero de instancias em suas aplicações

  Atributos do TAD ListaUsuario:

  head: Ponteiro do tipo usuario que será responsável por inicializar a lista encadeada de ususarios.

  Construtor de ListaUsuario: construtor padrão que não recebe parametros e que possui como função declarar head como um ponteiro nulo.

  CadastraUsuario: Método do tipo void que possui como parametro um valor do tipo int que chamaremos de id. Após a chamada desse metodo será inicializado um ponteiro do tipo Usuario chamado auxiliar que receberá o endereço de head, após essa declaração head será submetido a uma estrutura condicional. Se caso head for nula, assume-se que a lista está vazia e dessa forma é cadastrado um usuário, dessa forma, head irá receber o endereço de um objeto do tipo Usuario que terá como parametro o valor inteiro id, retornando assim uma string informando que a conta foi devidamente cadastrada. Caso head não for nula, irá ser inicializada uma estrutura de repetição que vai comparar o id que foi passado com o id de todos os usuario que ja foram devidamente cadastrados e se caso houver algum usuário com mesmo id do que foi passado, é retornado um erro e a função é encerrada, O while percorre até a penultima posição, mas não valida para a ultima, dessa forma ele encerra a execução e checa se a ultima posição possui o mesmo id do que foi passado por parametro, caso não tenha sido o auxiliar next que agora se encontra na ultima posição recebe o endereço de um novo usuario com o id passado posteriormente.

   MostrarCaixaEntrada: Método do tipo void que recebe como parametro um inteiro de nome id.
   Nessa função head é passada para uma variavel do tipo ponteiro Usuario que será iterada em um while com uma condição que se o id passado por parametro for o mesmo do usuario que está sendo iterado, esse mesmo usuário irá instanciar uma função do objeto usuario que ExibeMensagens que por consequencia instancia uma função do objeto caixa de entrada para exibir a mensagem com maior prioridade. Caso o id que foi passado não estiver presente na lista, é exibido um erro informando que o usuario não existe e assim finalizando a execução da função.

   EnviaMensagem: Metodo do tipo void que recebe como parametro um atributo do tipo inteiro id e um objeto do tipo Mensagem.
   Nessa função será feita uma implementação analoga ao que foi feito na função que mostra a caixa de entrada, inicializando um ponteiro para head, iterando sobre ele, procurando um id semelhando ao que foi passado por parametro e se caso for encontrado, instanciar o metodo RecebeMensagem passando como parametro o objeto mensagem e exibindo uma string informando que a mensagem foi entregue, caso contrario não será enviada a mensagem e será impressa a mensagem de que o usuario não existe.

    ProcuraUsuario: Metodo do tipo booleano que será importante para encontrar se um usuario está presente na lista ou não.
    Ela recebe como paramentro um id e itera a lista encadeada procurando o usuario de mesmo id, caso não encontre, ela retornará 0, caso encontre, retornará 1. Essa função será bem importante para a função que será descrita logo em seguida, o metodo removeUsuario.

    RemoveUsuario: Metodo do tipo void que recebe como parametro o id do usuario que é desejado a remoção.
    Nesta funçao são inicializados dois ponteiro do tipo Usuario, um recebendo a cabeça da lista e outro vazio que será utilizado como temporario para a realização da remoção do usuario na lista. Após isso a função será submetida a uma estutura de condição que irá usar a função procura usuario para validar a existencia ou não do usuario na lista, caso não existir, será impressa uma mensagem da não existencia e encerrara o programa, caso contrário será inicializado um while que percorerá toda a lista, dentro do while ha 3 condições, se caso o id passado estiver em um usuario que se encontra na cabeça, a cabeça irá receber a o elemento seguinte e itera novamente o while. Se o auxiliar next for nulo, é encerrado o while e a mensagem de que usuario é inexistente é exibida. E por ultimo, se caso for encontrado o usuario, um segundo auxiliar recebe o usuario, o primeiro auxiliar que está iteradno a lista recebe o usuario seguinte para a ligação da lista e não deletar um usuario no meio da lista e por ultimo deleta o usuario do segundo auxiliar, finalizando o ciclo, removendo o usuario com base no seu id.

    Limpa: Metodo do tipo void que não recebe nenhum parametro tem por objetivo desalocar todos os usuarios restantes na lista encadeada.
    Através de um ponteiro auxiliar que é recebido o segundo elemento da lista, é passado por um for desaloca todos os usuario restantes, sobrendo apenas o elemento head.

    Destrutor de ListaUsuario: Esse destrutor ira checar sempre se a cabeça da lista possui conteudo, caso exista, chama a função limpa, exemplificada a cima e por ultimo deleta o elemento da cabeça que foi deixado em aberto quando chamada a função Limpa, e assim é finalizada a execução do programa.
 