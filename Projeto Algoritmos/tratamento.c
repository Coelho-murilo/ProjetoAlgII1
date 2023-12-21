#include "Tratamento.h"
#include <string.h>

Tratamento* tramentos = NULL;
int MAX_TRATAMENTO = 1;
int qtdTratamento = 0;
int codTratamento = 0;


int InicializarTratamento()
{
	
	tramentos = (Tratamento *)calloc(MAX_TRATAMENTO, sizeof(Tratamento));
	if(tramentos == NULL)
		return 0;
	
	return 1;
	
}

int EncerraTratamento()
{	
	free(tramentos);
	tramentos = NULL;
	
	return 1;
}

int SalvarTratamento(Tratamento t)
{
	
	Tratamento* tratamentosRealoc = (Tratamento*)realloc(tramentos, (MAX_TRATAMENTO+1) * sizeof(Tratamento));
	if(tratamentosRealoc == NULL)
		return 0;
	
	MAX_TRATAMENTO++;
	tramentos = tratamentosRealoc;
 
 	codTratamento++;
	t.codigo = codTratamento;
	
	tramentos[qtdTratamento] = t;
	qtdTratamento++;
	
	return 1;
	
}

int QuantidadeTratamento()
{
	return qtdTratamento;
}

Tratamento* ObterTratamentoPeloCodigo(int codigo)
{
		
	if(codigo < 0)
		return 0;
		
	for(int i = 0; i < QuantidadeTratamento(); i++){
		if(tramentos[i].codigo == codigo) {
			
			Tratamento *t = (Tratamento *)malloc(sizeof(Tratamento));
			if(t == NULL)
				return 0;
			
			*t = tramentos[i];
				
			return t;
			
		}
	}
	
	return 0;
	
}

Tratamento* ObterTratamentoPeloCodigodoBruxo(int codigo, int indice){
	
	if(codigo < 0 || indice < 0 || indice > QuantidadeTratamento() || tramentos[indice].codigoBruxo != codigo) 
		return 0;
		
	Tratamento *t = (Tratamento *)malloc(sizeof(Tratamento));
	if(t == NULL)
		return 0;
	
	*t = tramentos[indice];
		
	return t;
			
}

Tratamento* ObterTratamentoPeloCodigodoPaciente(int codigo, int indice){
	
	if(codigo < 0 || indice < 0 || indice > QuantidadeTratamento() || tramentos[indice].codigoPaciente != codigo) 
		return 0;
		
	Tratamento *t = (Tratamento *)malloc(sizeof(Tratamento));
	if(t == NULL) 
		return 0;
	
	*t = tramentos[indice];
		
	return t;
	
}

Tratamento* ObterTratamentoPeloCodigodaPocao(int codigo, int indice){
	
	if(codigo < 0 || indice < 0 || indice > QuantidadeTratamento() || tramentos[indice].codigoPocao != codigo) 
		return 0;
		
	Tratamento *t = (Tratamento *) malloc (sizeof(Tratamento));
	if(t == NULL) 
		return 0;
	
	*t = tramentos[indice];
		
	return t;
	
}


int AtualizarTratamento(Tratamento t)
{
	
	for(int i = 0; i < qtdTratamento; i++){
		if(tramentos[i].codigo == t.codigo) {
			tramentos[i] = t;
			return 1;										
		}
	}
						
	return 0;
	
}

int ApagarTratamentoPeloCodigo(int codigo){
	
	if(codigo < 0)
		return 0;

		
	for(int i = 0; i < QuantidadeTratamento(); i++){
		if(tramentos[i].codigo == codigo) {
			
			tramentos[i] = tramentos[QuantidadeTratamento()-1];

			Tratamento* tratamentosRealoc = (Tratamento*)realloc(tramentos, (MAX_TRATAMENTO-1) * sizeof(Tratamento));
			if(tratamentosRealoc == NULL) 
				return 0;
			tramentos = tratamentosRealoc;
			
			MAX_TRATAMENTO--;
			qtdTratamento--;
									
			return 1;

		}
	}
	
	return 0;
	
}



