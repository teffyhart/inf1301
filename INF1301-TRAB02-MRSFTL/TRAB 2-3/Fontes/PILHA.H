#if ! defined( PILHA_ )
#define PILHA_
/**************************************************************
Pilha generica

Arquivo gerado:			PILHA.H

Projeto: INF1301
Autores: Stephanie, Marcos Rubio e Thiago

Hist�rico de evolu��o:
	Vers�o	Data		Observa��o
	1		09/05/2013	Inicio da codifica��o do m�dulo
	2		10/05/2013	Termino da codifica��o

Descri��o do m�dulo
	Implementa pilhas gen�ricas e suas respectivas fun��es para
	um bom funcionamento.
	Por serem pilhas, seu conte�do s� pode ser alterado acessando
	o topo e, para isso, � feito o uso de duas structs.

	As pilhas s�o gen�rias, por�m o valor � homog�neo durante
	a fun��o.

	Utiliza ponteiros para a locomo��o de informa��es.

*****************************************************************/

#if defined( PILHA_OWN )
   #define PILHA_EXT
#else
   #define PILHA_EXT extern
#endif

/* Tipo refer�ncia para uma lista */

typedef struct pilha Pilha;
typedef struct ptoProTopo PtoTopo;

/**************************************************************

$TC Tipo de dados: PLH Condi��es de retorno

$ED Descri��o do tipo
	Condi��es de retorno das fun��es da pilha

***************************************************************/

typedef enum {

	PLH_CondRetOk ,
		/* Concluiu corretamente */

	PLH_CondRetPilhaVazia ,
		/* A pilha n�o cont�m valor */

	PLH_CondRetFaltouMemoria
		/* Faltou mem�ria ao tentar criar um elemento novo*/

} PLH_tpCondRet;

/***********************************************************************

  $FC Fun��o: PLH  &Criar Topo

  $ED Descri��o da fun��o
     Cria um topo para a referida pilha gen�rica.

  $EP Par�metros
     VOID

  $FV Valor retornado
     Se executou corretamente retorna o ponteiro para o topo de uma pilha
     Este ponteiro ser� utilizado pelas fun��es que manipulem esta pilha.

     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
     a fun��o retornar� NULL.
     N�o ser� dada mais informa��o quanto ao problema ocorrido.

***********************************************************************/

PtoTopo * criaTopo(void);

/***********************************************************************

  $FC Fun��o: PLH  &Insere Valor

  $ED Descri��o da fun��o
     Insere um valor na pilha, alterando seu topo para
	  o novo valor obtido e mant�m um ponteiro para o 
	  elemento anterior da pilha.

  $EP Par�metros
     PtoTopo   -	O topo da pilha em que a informa��o ser�
					inserida.
     Void      -	Ponteiro para Void, assim assegurando que a
					informa��o que ser� inserida ser� gen�rica.

  $FV Valor retornado
     VOID

**********************************************************************/

PLH_tpCondRet insere(PtoTopo *,void *);

/***********************************************************************

  $FC Fun��o: PLH  &� Vazio

  $ED Descri��o da fun��o
     Testa para saber se uma dada pilha est� vazia (booleana).

  $EP Par�metros
     PtoTopo   -	O topo da pilha que ser� testada.

  $FV Valor retornado
     0 se a pilha n�o est� vazia.
	  1 se a pilha est� vazia.

***********************************************************************/

int vazio(PtoTopo *);

/***********************************************************************

  $FC Fun��o: PLH  &Retira Valor

  $ED Descri��o da fun��o
     Retira um dado valor da pilha gen�rica apresentada.

  $EP Par�metros
     PtoTopo   -	O topo da pilha em que a informa��o ser�
					retirada.

  $FV Valor retornado
     Primeiro a fun��o testa se h� o que retirar da pilha, 
	  interrompendo a fun��o se n�o houver, e retira o valor
	  armazenado do topo da pilha, retornando-o para o usu�rio.
***********************************************************************/

PLH_tpCondRet retira(PtoTopo *);

/***********************************************************************

  $FC Fun��o: PLH  &Libera Pilha

  $ED Descri��o da fun��o
     Libera uma dada pilha.

  $EP Par�metros
     PtoTopo   -	O topo da pilha que ser� liberada.

  $FV Valor retornado
     VOID
***********************************************************************/

PLH_tpCondRet libera(PtoTopo *);

#undef LISTA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif