#include "Bruxo.h"
#include <string.h>

Bruxo* bruxos = NULL;
int MAX_BRUXOS = 1;
int qtdBruxos = 0;
int codBruxo = 0;


int InicializarBruxos()
{
	bruxos = (Bruxo*) calloc (MAX_BRUXOS, sizeof(Bruxo));
	if(bruxos == NULL)
		return 0;
		
	return 1;	
}

int EncerraBruxos()
{
	free(bruxos);
	bruxos = NULL;
	
	return 1;
}

int SalvarBruxo(Bruxo b)
{
	Bruxo* bruxosRealoc = (Bruxo*)realloc(bruxos, (MAX_BRUXOS+1)*sizeof(Bruxo)); 
	if(bruxosRealoc == NULL) 
		return 0;
	
	MAX_BRUXOS++;
	
	bruxos = bruxosRealoc;
	
	codBruxo++;
	b.codigoBruxo = codBruxo;

	
	bruxos[qtdBruxos] = b;
	qtdBruxos++;
	
	return 1;
}
int QuantidadeBruxos()
{
	return qtdBruxos;
}

Bruxo* ObterBruxoPeloIndice(int indice)
{
	if(indice < 0 || indice > QuantidadeBruxos()) 
		return NULL;
	Bruxo *b = (Bruxo*) malloc (sizeof(Bruxo));	
	if(b == NULL)
		return NULL;
	*b = bruxos[indice];
	//fazer malloc 
	return b;
}

Bruxo* ObterBruxoPeloCodigo(int codigo)
{
	if(codigo < 0) return 0;
	
	for(int i = 0; i < qtdBruxos; i++){
		if (bruxos[i].codigoBruxo == codigo) 
		return &bruxos[i];
	}
	
	return 0;
}

int AtualizarBruxo(Bruxo b)
{
	for(int i = 0; i < qtdBruxos; i++){
		if (bruxos[i].codigoBruxo == b.codigoBruxo) {
			bruxos[i] = b;
			return 1;
		}
	}
	
	return 0;
}

int ApagarBruxoPeloCodigo(int codigo)
{
	if(codigo < 0) 
		return 0;
	
	for(int i = 0; i < QuantidadeBruxos(); i++){
		if(bruxos[i].codigoBruxo == codigo){
			bruxos[i] = bruxos[QuantidadeBruxos()-1];
			qtdBruxos--;
			Bruxo* bruxosRealoc = (Bruxo*)realloc(bruxos, (MAX_BRUXOS-1)*sizeof(Bruxo)); 
			if(bruxosRealoc == NULL) 
				return 0;
			bruxos = bruxosRealoc;
			MAX_BRUXOS--;		
			break;
		}
	}
		 
	return 1;
}
