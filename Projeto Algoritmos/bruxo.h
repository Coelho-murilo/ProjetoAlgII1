#define TAM_STRING 20

typedef struct {
	int codigoBruxo;
	char nomeBruxo[TAM_STRING];
	char especialidadeBruxo[TAM_STRING];
} Bruxo;

int InicializarBruxos();
int EncerraBruxos();
int SalvarBruxo(Bruxo b);
int QuantidadeBruxos();
Bruxo* ObterBruxoPeloIndice(int indice);
Bruxo* ObterBruxoPeloCodigo(int codigo);
int AtualizarBruxo(Bruxo b);
int ApagarBruxoPeloCodigo(int codigo);
int ApagarBruxoPeloNome(char* nome);
