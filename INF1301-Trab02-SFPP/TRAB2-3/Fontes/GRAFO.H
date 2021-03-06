#if ! defined( GRAFO_ )
#define GRAFO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: GRA  Grafo
*
*  Arquivo gerado:              GRAFO.H
*  Letras identificadoras:      GRA
*
*  Projeto: INF 1301 Trabalho II
*  Gestor:  Grupo Stephanie Fay e Pedro Paulo
*  Autores: Stephanie, Pedro
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       SF     3/out/2013 Primeira vers�o
*     2       PP    10/out/2013 Corre��o de coment�rios e do prot�tipo
*                                da fun��o GRA_obterCorr
*
*  $ED Descri��o do m�dulo
*     Implementa grafo que possui arestas, vertices e uma cabe�a de grafo.
*     Podem existir N vertices criados.
*     Podem existir N arestas relacionando os vertices.
*     Os grafos possuem uma cabe�a encapsulando o seu estado.
*
*     Cada elemento do grafo pode armazenar uma string.
*
*     Cada v�rtice est� contido numa lista de v�rtices.
*        Esta lista utiliza o modulo LIS
*
*     H� uma lista de Origem, com origens do Grafo, de sucessores e antecessores.
*		 Estas listas utilizam o modulo LIS
***************************************************************************/
 

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um grafo */

typedef struct GRA_tagGrafo * GRA_tppGrafo ;
typedef struct GRA_ElemGrafo * GRA_tppElemento;

/***********************************************************************
*
*  $TC Tipo de dados: GRA Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do grafo
*
***********************************************************************/

typedef enum {

         GRA_CondRetOK = 0 ,
               /* Concluiu corretamente */

         GRA_CondRetNaoAchou = 1 ,
               /* N�o encontrou o valor procurado */

         GRA_CondRetFaltouMemoria = 2 ,
               /* Faltou mem�ria ao tentar criar um elemento de lista */
   
         GRA_CondRetGrafoNaoExiste = 3 ,
               /* Grafo passado por parametro nao existe */

         GRA_CondRetVerticeCorrNaoExiste = 4 ,
               /* Vertice corrente nao existe */

         GRA_CondRetArestaNaoExiste = 5 ,
               /* Nao existe aresta entre o vertice corrente e o passado por parametro */

         GRA_CondRetArestaJaExiste = 6 ,
               /* Ja existe aresta entre o vertice corrente e o passado por parametro */

         GRA_CondRetParamInvalido = 7 ,
               /* Um ou mais parametros passados para funcao sao invalidos */

   } GRA_tpCondRet ;
   

/***********************************************************************
*
*  $FC Fun��o: GRA  &Criar Grafo
*
*  $ED Descri��o da fun��o
*     Cria um grafo de char.
*     Ao criar o grafo a funcao cria uma cabeca da lista de vertices e inicializa
*     o ponteiro do vertice corrente com NULL, indicando que ele ainda nao foi definido.
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo que ser� inicializado.

*  $FV Valor retornado
*     GRA_CondRetParamInvalido - falha do parametro de entrada
*                                
*     GRA_CondRetFaltouMemoria - faltou memoria ao alocar a cabeca do grafo ou
*                                a cabeca da lista de vertices
*     GRA_CondRetOK            - foi alocada a cabeca do grafo e a cabeca da lista
*                                de vertices corretamente. Assim como o encapsulamento
*                                das funcoes passadas por parametro.
*
***********************************************************************/

GRA_tpCondRet GRA_criarGrafo ( GRA_tppGrafo parmGrafo );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Ir V�rtice
*
*  $ED Descri��o da fun��o
*		
*       Modifica o ponteiro de vertice corrente para o vertice cujo identificador
*       foi passado por parametro.
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo.
*
*     id   - Identificador de vertice
*
*  $FV Valor retornado
*     GRA_CondRetParamInvalido        - identificador do vertice passado por parametro nao eh valido
*     GRA_CondRetVerticeCorrNaoExiste - vertice corrente nao existe
*     GRA_CondRetArestaNaoExiste      - aresta para vertice solicitado nao existe
*     GRA_CondRetOK                   - ponteiro corrente agora aponta para vertice
*                                       cujo identificador foi passado por parametro
*
***********************************************************************/

GRA_tpCondRet GRA_irVertice ( GRA_tppGrafo parmGrafo , int id );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Cria V�rtice
*
*  $ED Descri��o da fun��o
*		
*     Cria um vertice com o dado valor e ID no final da lista vertices.
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo.
*
*
*     id   - Identificador de vertice
*
*  $FV Valor retornado
*     GRA_CondRetFaltouMemoria        - nao foi possivel alocar memoria para as estruturas
*     GRA_CondRetOK                   - vertice foi criado com sucesso
*
***********************************************************************/

GRA_tpCondRet GRA_criaVertice ( GRA_tppGrafo parmGrafo , char * parmValor, int id );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Destruir V�rtice Corrente
*
*  $ED Descri��o da fun��o
*		
*       Destroi o vertice que est� sendo apontado pela cabe�a de grafo.
*		Faz as devidas liga��es na lista v�rtices para manter a consist�ncia da mesma.
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo.

*
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetNaoAchou             - vertice buscado nao foi encontrado
*     GRA_CondRetOK                   - vertice destruido com sucesso
*
*
*
***********************************************************************/

GRA_tpCondRet GRA_destruirVertice ( GRA_tppGrafo parmGrafo );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Destruir Aresta
*
*  $ED Descri��o da fun��o
*		
*       Destroi a aresta que aponta para os devidos IDs desponibilizados.
*
*  $EP Par�metros
*
*     Grafo     - Ponteiro do tipo cabe�a de grafo.
*
*     antecessor   - Identificador de vertice
*
*     sucessor   - Identificador de vertice
*
**  $FV Valor retornado
*     GRA_CondRetParamInvalido        - identificador do vertice passado por parametro nao eh valido
*
*     GRA_CondRetNaoAchou             - vertice buscado nao foi encontrado
*     GRA_CondRetOK                   - aresta foi criado com sucesso
*
***********************************************************************/


GRA_tpCondRet GRA_destruirAresta ( GRA_tppGrafo Grafo, int antecessor, int sucessor );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Criar Aresta
*
*  $ED Descri��o da fun��o
*		
*       Cria a aresta que aponta o v�rtice corrente ao v�rtice dado.
*
*  $EP Par�metros
*
*     Grafo     - Ponteiro do tipo cabe�a de grafo.
*
*     id   - Identificador de vertice
*
*     tipo   
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetParamInvalido        - identificador do vertice passado por parametro nao eh valido
*     GRA_CondRetVerticeCorrNaoExiste - vertice corrente nao existe
*     GRA_CondRetFaltouMemoria        - nao foi possivel alocar memoria para as estruturas
*     GRA_CondRetNaoAchou             - vertice buscado nao foi encontrado
*     GRA_CondRetOK                   - aresta foi criado com sucesso
*
***********************************************************************/

GRA_tpCondRet GRA_criarAresta ( GRA_tppGrafo Grafo, int id, char*  tipo );

/***********************************************************************
*
*  $FC Fun��o: GRA  &Destruir Grafo
*
*  $ED Descri��o da fun��o
*		
*       Destroi o grafo dado e libera a memoria ocupada por todas
*       as suas estruturas.
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo
*
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetOK                   - grafo destruido com sucesso
*
*
*
*
***********************************************************************/

GRA_tpCondRet GRA_destruirGrafo ( GRA_tppGrafo parmGrafo ) ;

/***********************************************************************
*
*  $FC Fun��o: GRA  &Obter Vertice Corrente
*
*  $ED Descri��o da fun��o
*		
*       Retorna a informa��o guardada no vertice corrente
*
*  $EP Par�metros
*
*     parmGrafo     - Ponteiro do tipo cabe�a de grafo.
*
*     ppValor       - Ponteiro para variavel do tipo ponteiro generica
*
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetParamInvalido        - ponteiro para variavel que armazenara a informacao
*                                       retornada eh invalido
*     GRA_CondRetVerticeCorrNaoExiste - vertice corrente nao existe
*     GRA_CondRetOK                   - valor obtido com sucesso
*
***********************************************************************/

GRA_tpCondRet GRA_obterCorr ( GRA_tppGrafo parmGrafo , char * valor ) ;

/***********************************************************************
*
*  $FC Fun��o: GRA  &Ir Origem
*
*  $ED Descri��o da fun��o
*		
*       Vai para uma dada origem do Grafo
*
*  $EP Par�metros
*
*     Grafo               - Ponteiro do tipo cabe�a de grafo.
*
*     identificador       - Identificador para a escolha da origem
*
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetParamInvalido        - ponteiro para variavel que armazenara a informacao
*                                       retornada eh invalido
*     GRA_CondRetOK                   - valor obtido com sucesso
*
***********************************************************************/

GRA_tpCondRet GRA_IrOrigem ( GRA_tppGrafo Grafo, int verificador ) ;

/***********************************************************************
*
*  $FC Fun��o: GRA  &Avan�ar Elemento Corrente
*
*  $ED Descri��o da fun��o
*		
*       Avan�a uma dada quantidade de vezes o ponteiro corrente do Grafo
*
*  $EP Par�metros
*
*     Grafo         - Ponteiro do tipo cabe�a de grafo.
*
*     id            - Contador para avan�o no grafo.
*
*  $FV Valor retornado
*     GRA_CondRetGrafoNaoExiste       - grafo passado por parametro nao eh valido
*     GRA_CondRetParamInvalido        - ponteiro para variavel que armazenara a informacao
*                                       retornada eh invalido
*     GRA_CondRetOK                   - valor obtido com sucesso
*
***********************************************************************/

GRA_tpCondRet GRA_AvancaElemCorrente (GRA_tppGrafo Grafo, int id ) ;




#undef GRAFO_EXT

/********** Fim do m�dulo de defini��o: GRA  Grafo **********/

#else
#endif