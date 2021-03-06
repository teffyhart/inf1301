/**************************************************************
Matriz generica

Arquivo gerado:			MATRIZ.H

Projeto: INF1301
Autores: Stephanie, Marcos Rubio e Thiago

Hist�rico de evolu��o:
	Vers�o	Data		Observa��o
	1		13/05/2013	Inicio e termino da codifica��o do modulo

Descri��o do m�dulo
	Implementa uma matriz de listas gen�ricas duplamente
	encadeadas que o conte�do s�o pilhas gen�ricas.

	A matriz funcionar� com uma lista principal que ter� ponteiros
	para a origem, o �ltimo elemente dela, al�m dos ponteiros
	de locomo��o normais (pr�ximo e anterior). Seu conte�do ter� 
	um ponteiro para outra lista com cabe�a que funcionar� da
	mesma maneira que a principal, sendo assim as colunas de
	nossa matriz. O conte�do dessas, no entantanto, s�o ponteiros
	para pilhas gen�ricas.

	Lida-se o tempo todo com os ponteiros das listas, usando
	de fun��es implementadas em outros m�dulos para complemento
	das dispostas neste.


*****************************************************************/

/***********************************************************************

  $FC Fun��o: MTZ  &Cria Matriz (Tabela)

  $ED Descri��o da fun��o
     Essa fun��o ser� respons�vel pela cria��o de uma
	 matriz de listas de tamanho fornecido pelo usu�rio.

  $EP Par�metros
     X	   -	Um int que � respons�vel pela largura da matriz.
	 Y	   -	Um int que � respons�vel pela altura da matriz.

  $FV Valor retornado
     A fun��o retornar� NULL caso a lista n�o consiga ser criada,
	 por�m se houver a cria��o da lista, a fun��o retornar� um
	 ponteiro para a cabe�a da lista.

***********************************************************************/

LIS_tppLista criarTab(int, int);

/***********************************************************************

  $FC Fun��o: MTZ  &Acha Coordenada

  $ED Descri��o da fun��o
     Essa fun��o ser� respons�vel por achar uma certa coordenada
	 que o usu�rio informar.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o percorrer�.
	X	   -	Um int que representa a posi��o lateral.
	Y	   -	Um int que representa a posi��o vertical.

  $FV Valor retornado
     Essa fun��o retorna um ponteiro para a coordenada passada.

***********************************************************************/

LIS_tppLista achaCoor( LIS_tppLista, int, int);

/***********************************************************************

  $FC Fun��o: MTZ  &Insere na Coordenada

  $ED Descri��o da fun��o
     Essa fun��o ir� procurar a coordenada fornecida pelo usu�rio
	 e inserir um valor na pilha que existe nela.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o percorrer�.
	X	   -	Um int que representa a posi��o lateral.
	Y	   -	Um int que representa a posi��o vertical.
	valor  -	O valor a ser inserido na pilha.

  $FV Valor retornado
     VOID

***********************************************************************/

void pushCoor(LIS_tppLista, int, int, void *);

/***********************************************************************

  $FC Fun��o: MTZ  &Retira da Coordenada

  $ED Descri��o da fun��o
     Essa fun��o ir� procurar a coordenada fornecida pelo usu�rio
	 e retirar um valor na pilha que existe nela.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o percorrer�.
	X	   -	Um int que representa a posi��o lateral.
	Y	   -	Um int que representa a posi��o vertical.

  $FV Valor retornado
     VOID
	 OBS: A fun��o n�o retornar� o valor retirado da pilha,
	 ela simplesmente o destr�i.

***********************************************************************/

void popCoor(LIS_tppLista, int, int);

/***********************************************************************

  $FC Fun��o: MTZ  &Destr�i Matriz

  $ED Descri��o da fun��o
     A fun��o ir� destruir e liberar os valores que tem na 
	 matriz passada.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o destruir�.

  $FV Valor retornado
     VOID

***********************************************************************/

void DestruirMatriz ( LIS_tppLista Tab );