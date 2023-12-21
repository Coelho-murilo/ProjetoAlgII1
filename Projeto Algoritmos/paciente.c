#include "Paciente.h"
#include <string.h>

Paciente* Pacientes = NULL;
int MAX_PACIENTES = 1;
int qtdPacientes = 0;
int codPacientes = 0;


int InicializarPacientes()
{
	Pacientes = (Paciente*) calloc (MAX_PACIENTES, sizeof(Paciente));
	if(Pacientes == NULL)
		return 0;
		
	return 1;
}

int EncerraPacientes()
{
	free(Pacientes);
	Pacientes = NULL;
	
	return 1;
}

int SalvarPaciente(Paciente p)
{
	Paciente* PacientesRealoc = (Paciente*)realloc(Pacientes, (MAX_PACIENTES+1)*sizeof(Paciente)); 
	if(PacientesRealoc == NULL) 
		return 0;
	
	MAX_PACIENTES++;
	
	Pacientes = PacientesRealoc;
	
	codPacientes++;
	p.codigoPaciente = codPacientes;

	
	Pacientes[qtdPacientes] = p;
	qtdPacientes++;
	
	return 1;
}
int QuantidadePacientes()
{
		return qtdPacientes;
}

Paciente* ObterPacientePeloIndice(int indice)
{
	if(indice < 0 || indice > QuantidadePacientes()) 
		return NULL;
	
	return &Pacientes[indice];
}

Paciente* ObterPacientePeloCodigo(int codigo)
{
	
	if(codigo < 0) 	
		return 0;
	
	for(int i = 0; i < qtdPacientes; i++){
		if (Pacientes[i].codigoPaciente == codigo) 
			return &Pacientes[i];
	}
	
	return 0;
}

int AtualizarPaciente(Paciente p)
{
	for(int i = 0; i < qtdPacientes; i++){
		if (Pacientes[i].codigoPaciente == p.codigoPaciente) {
			Pacientes[i] = p;
			return 1;
		}
	}
	
	return 0;
}

int ApagarPacientePeloCodigo(int codigo)
{
	if(codigo < 0) 
		return 0;
	
	int k = 0;
	
	for(int i = 0; i < QuantidadePacientes(); i++){
		if(Pacientes[i].codigoPaciente == codigo || k == 1){
			if(i+1 > QuantidadePacientes()){
				Pacientes[i].codigoPaciente = NULL;
				Pacientes[i].nomePaciente[0] = '\0';
				Pacientes[i].idadePaciente = NULL;
				Pacientes[i].alturaPaciente = 0;
			}
			else{
				Pacientes[i] = Pacientes[i+1];
				k = 1;
			}
		}
	}
	
	Paciente* PacientesRealoc = (Paciente*)realloc(Pacientes, (MAX_PACIENTES-1)*sizeof(Paciente)); 
	if(PacientesRealoc == NULL) 
		return 0;
	Pacientes = PacientesRealoc;
	
	MAX_PACIENTES--;
	qtdPacientes--;
	 
	return 1;	
}

