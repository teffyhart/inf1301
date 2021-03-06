#if ! defined( MATRIZ_ )
#define MATRIZ_
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

#if defined( MATRIZ_OWN )
   #define MATRIZ_EXT
#else
   #define MATRIZ_EXT extern
#endif

/**************************************************************

$TC Tipo de dados: MTZ Condi��es de retorno

$ED Descri��o do tipo
	Condi��es de retorno das fun��es da matriz

***************************************************************/

typedef enum {

	MTZ_CondRetOK ,
		/* Concluiu corretamente */

	MTZ_CondRetVazia ,
		/* A pilha n�o cont�m valor */

	MTZ_CondRetFaltouMemoria
		/* Faltou mem�ria ao tentar criar um elemento novo*/

} MTZ_tpCondRet;

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

LIS_tppLista MTZ_criarTab(int, int);

/***********************************************************************

  $FC Fun��o: MTZ  &Acha Coordenada

  $ED Descri��o da fun��o
     Essa fun��o ser� respons�vel por achar uma certa coordenada
	 que o usu�rio informar.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o percorrer�.
	X	   -	Um int que representa a posi��o lateral.
	Y	   -	Um int que representa a posi��o vertical.
	Coor   -    Um ponteiro que servir� para apontar para a coordenada encontrada.

  $FV Valor retornado
     Essa fun��o retorna um ponteiro para a coordenada passada.

***********************************************************************/

LIS_tppLista MTZ_achaCoor( LIS_tppLista , int , int );

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

MTZ_tpCondRet MTZ_pushCoor(LIS_tppLista, int, int, char);

/***********************************************************************

  $FC Fun��o: MTZ  &Retira da Coordenada

  $ED Descri��o da fun��o
     Essa fun��o ir� procurar a coordenada fornecida pelo usu�rio
	 e retirar um valor na pilha que existe nela.

  $EP Par�metros
	Tab    -	A tabela (matriz) qual a fun��o percorrer�.
	X	   -	Um int que representa a posi��o lateral.
	Y	   -	Um int que representa a posi��o vertical.
	Valor  -    Um ponteiro que receber� o valor retirado matriz.

  $FV Valor retornado
     VOID

***********************************************************************/

char MTZ_popCoor ( LIS_tppLista, int, int);

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

MTZ_tpCondRet MTZ_DestruirMatriz ( LIS_tppLista  );


#undef MATRIZ_EXT

/********** Fim do m�dulo de defini��o: MTZ Matriz **********/

#else
#endif