/**************************************************************
$MCI M�dulo de implementa��o: PIL	Pilha generica

Arquivo gerado:			PILHA.C

Projeto: INF1301
Autores: Stephanie, Marcos Rubio e Thiago

$HA Hist�rico de evolu��o:
	Vers�o	Data		Observa��o
	1		09/05/2013	Inicio da codifica��o do modulo
	2		27/05/2013	Corre��o/aprimoramento do codigo

*****************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include   <stdlib.h>

#define PILHA_OWN
#include "PILHA.h"
#undef PILHA_OWN

/********************************************

$Tipo de dados: Ponteiro para pilha generica

********************************************/

typedef struct tagElemPilha
{

		void * valor;
			/* Ponteiro para um valor generico*/
		
		struct tagElemPilha * prox;
			/* Ponteiro para o proximo da pilha */

} tpElemPilha;

/******************************************

Tipo de dados: Topo/Cabe�a da pilha

******************************************/

typedef struct PLH_tagPilha
{

	int tam;
		/* Tamanho da pilha */

	struct tagElemPilha * topo;
		/* Ponteiro para o topo da pilha */

} PLH_tpPilha;

/****************************************

Fun��o: Cria Topo da Pilha

******************************************/

PLH_tppPilha PLH_CriarTopo ()
{
	PLH_tppPilha pPilha = (PLH_tppPilha)malloc(sizeof(PLH_tpPilha));

		if ( pPilha == NULL)
			return NULL;

	pPilha->tam = 0;
	pPilha->topo = NULL;
		/*Limpando a cabe�a da pilha*/

	return pPilha;
}

/*****************************************

Fun��o: Push na pilha

******************************************/

PLH_tpCondRet PLH_Insere (PLH_tppPilha plh, char pValor)
{
	tpElemPilha * pElem = (tpElemPilha *)malloc(sizeof(tpElemPilha));
	
	if (pElem == NULL)
		return PLH_CondRetFaltouMemoria;
	
	pElem->valor = pValor;
	pElem->prox = plh->topo;
	plh->topo = pElem;
		/* Bota o elemento na pilha */

	plh->tam++;

	return PLH_CondRetOk;
}

/*****************************************

Fun��o: Pop na pilha

******************************************/

char * PLH_Retira (PLH_tppPilha plh)
{
	tpElemPilha * p;
	char * a=(char*)malloc(sizeof(char));

	if(plh->topo == NULL)
		return 0;

	p = plh->topo;
	*a = (char)p->valor;
	plh->topo = p->prox;
		/* Retira o elemento da pilha */

	free(p);
		/* Libera elemento */

	plh->tam--;

	return a;
}

/*****************************************

Fun��o: Obter tamanho da pilha

*******************************************/

int PLH_ObterTam (PLH_tppPilha plh)
{
	  #ifdef _DEBUG
         assert( plh != NULL ) ;
      #endif

	return plh->tam;
}

/*****************************************

Fun��o: Libera pilha

*******************************************/

PLH_tpCondRet PLH_Libera (PLH_tppPilha plh)
{
	tpElemPilha *p, *q;
	q = plh->topo;

	while (q!=NULL)
	{
		p=q->prox;
		free(q->valor);
		free(q);
		q=p;
	}

	plh->tam=0;

	return PLH_CondRetOk;
}

/***************************************

Fun��o: Printar o topo

*****************************************/

char * PLH_Printar (PLH_tppPilha plh)
{
	#ifdef _DEBUG
         assert( plh != NULL ) ;
      #endif

	if(plh->topo == NULL)
		return 0;

	return (char*)plh->topo->valor;
}

