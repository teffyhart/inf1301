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

typedef struct PLH_tagPilha * PLH_tppPilha;

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

  $FC Fun��o: PLH  &Criar pilha

  $ED Descri��o da fun��o
     Cria uma pilha gen�rica.
     Os poss�veis tipos s�o desconhecidos a priori.
     A tipagem � implicita.
     N�o existe identificador de tipo associado � lista.

  $EP Par�metros
     ExcluirValor  - ponteiro para a fun��o que processa a
                     exclus�o do valor referenciado pelo elemento
                     a ser exclu�do.
                     Ver descri��o do m�dulo.

  $FV Valor retornado
     Se executou corretamente retorna o ponteiro para o topo de uma pilha
     Este ponteiro ser� utilizado pelas fun��es que manipulem esta pilha.

     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
     a fun��o retornar� NULL.
     N�o ser� dada mais informa��o quanto ao problema ocorrido.

***********************************************************************/

PLH_tppPilha PLH_CriarTopo ();

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

PLH_tpCondRet PLH_Insere (PLH_tppPilha plh, char pValor);

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

char * PLH_Retira (PLH_tppPilha plh);

/***********************************************************************

  $FC Fun��o: PLH  &Libera Pilha

  $ED Descri��o da fun��o
     Libera uma dada pilha.

  $EP Par�metros
     PtoTopo   -	O topo da pilha que ser� liberada.

  $FV Valor retornado
     VOID
***********************************************************************/

PLH_tpCondRet PLH_Libera (PLH_tppPilha plh);

/******************************************************************

********************************************************************/

int PLH_ObterTam (PLH_tppPilha plh);

/********************************************************************

*******************************************************************/

char * PLH_Printar (PLH_tppPilha plh);

#undef PILHA_EXT

/********** Fim do m�dulo de defini��o: PLH  Pilha **********/

#else
#endif