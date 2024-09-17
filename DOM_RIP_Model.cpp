//DOM-RIP - Model
//09/08/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 

#include "DOM_RIP_Model.h"


typedef struct stpeca //struct das pecas
{
	int lado1;
	int lado2;
	char status;
	
} tipoPeca;
tipoPeca pecas [28];
tipoPeca mesa[100];

typedef struct Mesa
{
	int ladoD;
	int ladoE;
	
};

Mesa canto;

int CMD = 50; 
int CME = 50;

struct Jogo
{
	int qtmesaJogo;
	char jogadorJogo;
	int jogadorComp;
	int mesaDJogo;
	int mesaEJogo;
	tipoPeca PecasMesa[100];
}sitJogo;



