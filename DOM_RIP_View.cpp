//DOM-RIP - View
//09/08/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral 


#include "DOM_RIP_View.h"

void MostrarPecas(tipoPeca peca[]) //mostra as pecas do tabuleiro
{
    for (int x = 0; x < 28; x++)
    {
        printf("[%d|%d]", peca[x].lado1, peca[x].lado2);
    }
}
		
int ChamarMenu() //menu de uso 
{
	int op;
    printf("+--------------------------------------+\n");
    printf("|             Menu Geral:             |\n");
    printf("+--------------------------------------+\n");
    printf("| 1 - iniciar jogo (2 jogadores)      |\n");
    printf("| 2 - iniciar jogo (1 jogador)        |\n");
    printf("| 3 - Regras do jogo                  |\n");
    printf("| 4 - Salvar Jogo                     |\n");
    printf("| 5 - Continuar Jogo salvo            |\n");
    printf("| 6 - Sair                            |\n");
    printf("+--------------------------------------+\n");
    printf("Escolha uma opcao: ");
	scanf("%d", &op);
	LimpaTela();
	printf("\n");
	return op;
}

void Pecaj()
{
    int x;
		
		for(x = 0; x < 27; x++)
		{
			if (pecas[x].status == jvez)
        	{
            	printf(" %d-[%d|%d]", x, pecas[x].lado1, pecas[x].lado2);
        	}
		}
        
    
}

void apresentaMesa()
{
	printf("\n\n");
	printf("==============================\n");
	for (int i = 0; i < 100; i++)
	{
		if (mesa[i].status == MESA)
		{
			printf("[%d|%d]", mesa[i].lado1, mesa[i].lado2);
			qtmesa++;
		}
	}
	printf("\n==============================\n");
} 
	
void Jogadorvez()
{
	printf("\n\n");
	
	if(jvez == '1')
		printf("Mao do jogador 1: ");
	else
		printf("Mao do jogador 2: ");
	
}

char subMenu()
{
	int escolha;
	
	printf("\n1 - Jogar\n");
	printf("2 - Comprar\n");
	printf("3 - Passar\n");
	printf("4 - sair (interrompe o jogo)\n");
	printf("Opcao: ");
	scanf("%d", &escolha);
	fclear();
		
	return escolha;	
}

void apresentaMensagem(char mens[100])
{
	printf("%s\n",mens);
}
	
void mensagemc()
{
	printf("Nada para comprar!");
}

void Regras()
{
	printf("Regras do jogo domino!");
	printf(" cada jogador inicia com sete pecas obtidas aleatoriamente e pode 'comprar' quantas vezes for necessario ");
	printf("jogo inicia-se com o jogador que tiver a peca 'seis-seis'");
	printf("os jogadores devem colocar pecas que tenham os mesmos numeros das pecas que se encontram nas 2 pontas do jogo.");
	printf("Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas na mesa,");
	printf("de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde esta sendo colocada");
	printf("\n");
	
}

void msgsaida()
{
	printf("obrigado por jogar!");
}

void msgNpode()
{
	printf("Nao eh possivel passar a jogada\n\n");
}

void msgWin1()
{
	printf("Jogardor 1 venceu o jogo\n\n");
}

void msgWin2()
{
	printf("Jogador 2 venceu o jogo\n\n");
}

void msgCompra()
{
	printf("\nPassagem bloqueada. O depositivo nao esta vazio. Voce deve jogar e/ou comprar\n\n");
}

void msgEmpate()
{
	printf("Empate Tecnico\n\n");
}

void msgSair()
{
	printf("Voltando ao submenu....");
}

void msgCompras()
{
	printf("ainda ha pecas para serem compradas\n\n");
}

void msgEx()
{
	printf("Peca invalida");
}

void msgEscolha()
{
	printf("Qual peca vc deseja jogar? ");
}

void falarJvez()
{
	printf("O primeiro jogador foi %c", jvez);
}

void msgEscolhaL()
{
	printf("Vc deseja jogar na direita ou na esquerda? (d/e): ");
}

void msgNpodeJ()
{
	printf("\nEssa peca nao pode ser jogada na posicao desejada \n");
}