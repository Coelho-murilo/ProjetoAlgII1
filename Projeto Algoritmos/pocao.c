#include "Pocao.h"
#include <string.h>

Pocao* pocoes = NULL;
int MAX_POCOES = 1;
int qtdPocoes = 0;
int codPocoes = 0;


int InicializarPocoes()
{
	pocoes = (Pocao*) calloc (MAX_POCOES, sizeof(Pocao));
	if(pocoes == NULL)
		return 0;
		
	return 1;
	
}

int EncerraPocoes()
{
	free(pocoes);
	pocoes = NULL;
	
	return 1;
}

int SalvarPocao(Pocao Pc)
{
	Pocao* pocoesRealoc = (Pocao*)realloc(pocoes, (MAX_POCOES+1)*sizeof(Pocao)); 
	if(pocoesRealoc == NULL)
		return 0;
	
	MAX_POCOES++;
	
	pocoes = pocoesRealoc;
	
	codPocoes++;
	Pc.codigoPocao = codPocoes;

	
	pocoes[qtdPocoes] = Pc;
	qtdPocoes++;
	
	return 1;
}
int QuantidadePocoes()
{
	return qtdPocoes;
}

Pocao* ObterPocaoPeloIndice(int indice)
{
	if(indice < 0 || indice > QuantidadePocoes())
		return NULL;
	
	return &pocoes[indice];
}

Pocao* ObterPocaoPeloCodigo(int codigo)
{
	if(codigo < 0) return 0;
	
	for(int i = 0; i < qtdPocoes; i++){
		if (pocoes[i].codigoPocao == codigo)
			return &pocoes[i];
	}
	
	return 0;
}

int AtualizarPocao(Pocao Pc)
{
	for(int i = 0; i < qtdPocoes; i++){
		if (pocoes[i].codigoPocao == Pc.codigoPocao){
			pocoes[i] = Pc;
			return 1;
		}
	}
	
	return 0;
}

int ApagarPocaoPeloCodigo(int codigo)
{
	if(codigo < 0)
		return 0;
	
	int k = 0;
	
	for(int i = 0; i < QuantidadePocoes(); i++){
		if(pocoes[i].codigoPocao == codigo || k == 1){
			if(i+1 > QuantidadePocoes()){
				pocoes[i].codigoPocao = NULL;
				pocoes[i].nomePocao[0] = '\0';
				pocoes[i].tipoPocao[0] = '0';
			}
			else{
				pocoes[i] = pocoes[i+1];
				k = 1;
			}
		}
	}
	
	Pocao* pocoesRealoc = (Pocao*)realloc(pocoes, (MAX_POCOES-1)*sizeof(Pocao)); 
	if(pocoesRealoc == NULL)
		return 0;
	pocoes = pocoesRealoc;
	
	MAX_POCOES--;
	qtdPocoes--;
	 
	return 1;
}
