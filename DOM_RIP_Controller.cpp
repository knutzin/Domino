//DOM-RIP - controller
//09/08/2023
//Grupo: RIP
//pedro yoshissaro / Isadora Piloto / Rafael Cabral

#include <stdio.h>
#include <stdlib.h>
#include "DOM_RIP_Controller.h"
#include "DOM_RIP_View.cpp"
#include <time.h>

void ChamarJogo() // chama o jogo
{
   	Iniciar();
    int esco;

    while (1) 
	{ // Loop principal para o menu
        esco = ChamarMenu();
        
        switch (esco) 
		{
            case 1: // Dentro do submenu
            	Iniciar(); 
                joguinho();
                break; // Volta para o menu principal quando a opção 5 for escolhida no submenu
            case 2:
            	Iniciar();
            	joguinho2();
            	break;
            case 3: //mostra as regras do jogo
                LimpaTela();
				Regras();
                break;
            case 4:
            	gravaCadastro();
                break;
            case 5: //recuperar o jogo salvo
                recuperaCadastro(); // recuperar jogo
                joguinho();
                break; // Volta para o menu principal quando a opção 5 for escolhida no submenu
            case 6:
                msgsaida();
                return; // Encerra a função e sai do programa
            default:
                apresentaMensagem("Opcao invalida, tente novamente");
                break;
        }
    }
}

void joguinho()
{
	while (acabarJogo()) 
	{
        apresentar();
        int escolhaSubMenu = subMenu(); // Obtenha a escolha do usuário apenas uma vez

        switch (escolhaSubMenu) 
		{
        	case 1:
                Jogar();
                break;
            case 2:
                comprar();
                break;
            case 3:
                passar();
                break;
            case 4:
                msgSair();
                LimpaTela();
                break;
            default:
                apresentaMensagem("Opcao invalida, tente novamente");
                break;
        }
                    
        if (escolhaSubMenu == 4) 
		{
            break; // Sai do loop interno quando a opção 5 for escolhida
        }
    }
}

void apresentar()
{
	apresentaMesa();
    Jogadorvez();
    Pecaj();
}

void Iniciar()
{
	Gmesa();
	GerarPecas(pecas);
	EmbaralharPecas(pecas);
	iniciarMao();
	primeiroLance();
	trocajvez();
}

void Jogar()
{
	int pecaEsc;
	char ladoEsc;

	printf("Qual peca vc deseja jogar? ");
	scanf("%d", &pecaEsc);
	
	//validar se eh compativel
	if((canto.ladoD == pecas[pecaEsc].lado1 || canto.ladoD == pecas[pecaEsc].lado2) || (canto.ladoE == pecas[pecaEsc].lado1 || canto.ladoE == pecas[pecaEsc].lado2)) 
	{
		//validar dois lados
		if((canto.ladoD == pecas[pecaEsc].lado1 || canto.ladoD == pecas[pecaEsc].lado2) && (canto.ladoE == pecas[pecaEsc].lado1 || canto.ladoE == pecas[pecaEsc].lado2))
		{
			printf("Vc deseja jogar na direita ou na esquerda? (d/e): ");
			scanf(" %c", &ladoEsc);
			
			if (ladoEsc == 'd')
			{
				if (canto.ladoD == pecas[pecaEsc].lado1)
				{
					addPecaD(pecaEsc);
					trocajvez();
				}
				else if (canto.ladoD == pecas[pecaEsc].lado2)
				{
					trocarLado(pecaEsc);
					addPecaD(pecaEsc);
					trocajvez();
				}
			}
			
			else
			{
				if (canto.ladoE == pecas[pecaEsc].lado1)
				{
					trocarLado(pecaEsc);
					addPecaE(pecaEsc);
					trocajvez();
				}
				else if (canto.ladoE == pecas[pecaEsc].lado2)
				{
					addPecaE(pecaEsc);
					trocajvez();
				}
			}
				
		} 
		
		//verificar lado Esquerdo
		else if((canto.ladoE == pecas[pecaEsc].lado1 || canto.ladoE == pecas[pecaEsc].lado2))
		{
			if (canto.ladoE == pecas[pecaEsc].lado1)
			{
				trocarLado(pecaEsc);
				addPecaE(pecaEsc);
				trocajvez();
			}
			
			else if (canto.ladoE == pecas[pecaEsc].lado2)
			{
				addPecaE(pecaEsc);
				trocajvez();
			}
		}
		
		//validar lado direito
		else if((canto.ladoD == pecas[pecaEsc].lado1 || canto.ladoD == pecas[pecaEsc].lado2))
		{
			if (canto.ladoD == pecas[pecaEsc].lado1)
			{
				addPecaD(pecaEsc);
				trocajvez();
			}
			
			else if (canto.ladoD == pecas[pecaEsc].lado2)
			{
				trocarLado(pecaEsc);
				addPecaD(pecaEsc);
				trocajvez();
			}
		} 
	} 
	else 
	{
		printf("\nEssa peca nao pode ser jogada na posicao desejada \n");
		trocajvez();
	}
}

void addPecaD(int peca)
{
	pecas[peca].status = MESA;
	mesa[++CMD] = pecas[peca];
	canto.ladoD = pecas[peca].lado2;
	if(jvez == '1')
		qtj1--;
	else
		qtj2--;
	
}

void addPecaE(int peca)
{
	pecas[peca].status = MESA;
	mesa[--CME] = pecas[peca];
	canto.ladoE = pecas[peca].lado1;
	if(jvez == '1')
		qtj1--;
	else
		qtj2--;
}

void trocarLado(int peca)
{
	int base = pecas[peca].lado1;
	pecas[peca].lado1 = pecas[peca].lado2;
	pecas[peca].lado2 = base;
}

void Gmesa()
{
	for (int i = 0; i < 100; i++)
	{
		mesa[i].lado1 = -1;
		mesa[i].lado2 = -1;
		mesa[i].status = NADA;
	}

}

void GerarPecas(tipoPeca peca[]) //cria todas as pecas do jogo 
{
    int a, b, i; // i = lado1 , j = lado2
    a = 0;
    b = 0;
    
	for (i = 0; i < 28; i++)
    {
        peca[i].lado1 = a;
        peca[i].lado2 = b;

        b++;

        if (b > 6)
        {
            a++;
            b = a;
        }
    }
}

void EmbaralharPecas(tipoPeca peca[]) //embaralhas pecas
{
    srand(time(NULL));
    
	for (int i = 27; i > 0; i--)
    {
        int randomIndex = rand() % (i + 1);
        tipoPeca temp = peca[i];
        peca[i] = peca[randomIndex];
        peca[randomIndex] = temp;
    }
}

void iniciarMao() //distribui as pecas entre os jogadores
{
		
    for(int x = 0; x < 7; x++)
    {
        pecas[x].status = '1';
        qtj1++;
    }
    for(int x = 7; x < 14; x++ )
    {
        pecas[x].status = '2';
        qtj2++;
    }
    for(int x = 14; x < 28; x++)
    {
        pecas[x].status = '0';
        qtlivre++;
    }
	
	
}

void primeiroLance() //Descobre e carrega a primeira peça na mesa
{
	int i, pj, dupla;
	pj = -1; // posicao da peca encontrada
	dupla = -1;
	// pesquisa primeiramente entre as pecas com lado1 = lado2
	for (i = 0; i < 14; i++)
	{
		if (pecas[i].lado1 == pecas[i].lado2)
		{
			if (pecas[i].lado1 > dupla)
			{
				dupla = pecas[i].lado1;
				pj = i;
			
			}
		}
	}

	// se nao encontrou, escolhe a peca com a maior soma
	if (pj == -1)
	{
		dupla = 0;
		for (i = 0; i < 14; i++)
		{
			if (pecas[i].lado1 + pecas[i].lado2 > dupla)
			{
				dupla = pecas[i].lado1 + pecas[i].lado2;
				pj = i;
				
			}
		}
	}

	jvez = pecas[pj].status; // descobre quem jogou a primeira peca
	if(jvez == '1')
		qtj1--;
	if(jvez == '2')
		qtj2--;
	
	pecas[pj].status = MESA;
	
	canto.ladoD = pecas[pj].lado1;
	canto.ladoE = pecas[pj].lado2;

	mesa[50] = pecas[pj];
		
}

void comprar()
{
	int i = 14; //as 14 primeiras peças já não estão mais livres
	while(i <= 28)
	{
		if (pecas[i].status == '0')
		{
			pecas[i].status = jvez;
		
			if(jvez == '1')
				qtj1++;
			if(jvez == '2')
				qtj2++;
			break;
	
		}
		i++;
		
	}
	
	if (i >= 28)
	{
		qtlivre = 0;
		LimpaTela();
		mensagemc();
	}
	
}

void trocajvez()
{
	if (jvez == '2')
		jvez = '1';
	else 
		jvez = '2';
}

void fclear()
{
 	int ch;
 	while( (ch = fgetc(stdin)) != EOF && ch != '\n');
}

void LimpaTela()
{
	system("@cls||clear");
}

void limparBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

bool acabarJogo()
{	
	if(qtj1 == 0)
	{
		LimpaTela();
		msgWin1();
		fimJogo = 0;
		return false;
	
	}
		
	if(qtj2 == 0 )
	{
		LimpaTela();
		msgWin2();
		fimJogo = 0;
		return false;
	}
	
	
	if(qtlivre == 0 && qtj1 >= 0 && qtj2 >= 0)
	{
		if(qtj1 > qtj2)
		{
			LimpaTela();
			msgWin2();
			fimJogo = 0;
			return false;
		}
			
		if(qtj2 > qtj1)
		{
			LimpaTela();
			msgWin1();
			fimJogo = 0;
			return false;
		}
		fimJogo = 1;
		return true;
	}
	
	
}

	
bool passar()
{
	if (depositoVazio() == false)
	{
		LimpaTela();
		msgCompra();
		return false;
	}
	else
	{
		trocajvez();
		return true ;
	}
	
}

bool depositoVazio()
{
	for(int i = 0; i < 28; i++)
	{
		if (pecas[i].status == '0') 
			return false;
	}
	return true;
}

void gravaCadastro()
{
	if (qtmesa == 0)
	{	
		apresentaMensagem("Sem jogo a ser gravado");
		return;
	}
	
	if (fimJogo > 0)
	{
		apresentaMensagem("Jogo terminado, não pode ser gravado");
		return;
	}
	
	int i;
	FILE *fp;
	FILE *fpm;
	FILE *fps;
	
	// Dados do Jogo a serem salvos
	for(int i = 0; i < 100; i++)
    {
        sitJogo.PecasMesa[i].status = mesa[i].status;
        sitJogo.PecasMesa[i].lado1 = mesa[i].lado1;
        sitJogo.PecasMesa[i].lado2 = mesa[i].lado2;
    }

	
	sitJogo.qtmesaJogo = qtmesa;
	sitJogo.jogadorJogo = jvez;
	sitJogo.jogadorComp = jogcomp;
	sitJogo.mesaDJogo = canto.ladoD;
	sitJogo.mesaEJogo = canto.ladoE;
	
	if ((fp = fopen("CAD_DOMINO", "w")) == NULL)
	{
		LimpaTela();
		apresentaMensagem("O arquivo CAD_DOMINO nao pode ser aberto para cadastrar");
		return;
	}
	 
	if ((fpm = fopen("CAD_MESA", "w")) == NULL)
	{
		LimpaTela();
		apresentaMensagem("O arquivo CAD_MESA nao pode ser aberto para cadastrar");
		return;
	}
	 	 
	if ((fps = fopen("CAD_JOGO", "w")) == NULL)
	{
		LimpaTela();
		apresentaMensagem("O arquivo CAD_JOGO nao pode ser aberto para cadastrar");
		return;
	}
	
	for (i = 0; i < 28; i++)
	{
		if (fwrite(&pecas[i], sizeof(struct stpeca), 1, fp) != 1)
		{
			LimpaTela();
			apresentaMensagem("Erro na gravacao do arquivo CAD_DOMINO");
			break;
		}
	}
	 
	for (i = 0; i < 100; i++)
	{
		if (fwrite(&mesa[i], sizeof(struct Mesa), 1, fpm) != 1)
		{
			LimpaTela();
			apresentaMensagem("Erro na gravacao do arquivo CAD_MESA");
			break;
		}
	}
	
	if (fwrite(&sitJogo, sizeof(struct Jogo), 1, fps) != 1)
	{
		LimpaTela();
		apresentaMensagem("Erro na gravacao do arquivo CAD_JOGO");
	}
	 	
	fclose(fps);
	fclose(fpm);
	fclose(fp);
	LimpaTela();
	apresentaMensagem("Gravados os arquivos CAD_DOMINO, CAD_MESA e CAD_JOGO");
}


void recuperaCadastro()
{
	int i;
	FILE *fp;
	FILE *fpm;
	FILE *fps;
	
	if ((fp = fopen("CAD_DOMINO", "r")) == NULL)
	{
		apresentaMensagem("O arquivo CAD_DOMINO nao pode ser aberto");
		apresentaMensagem("Novo jogo sendo criado....");
		return;
	}
	
	if ((fpm = fopen("CAD_MESA", "r")) == NULL)
	{
		apresentaMensagem("O arquivo CAD_MESA nao pode ser aberto");
		apresentaMensagem("Novo jogo sendo criado....");
		return;
	}
	
	if ((fps = fopen("CAD_JOGO", "r")) == NULL)
	{
		apresentaMensagem("O arquivo CAD_JOGO nao pode ser aberto");
		apresentaMensagem("Novo jogo sendo criado....");
		return;
	}
	 
	for (i = 0; i < 28; i++)
	{
		if (fread(&pecas[i], sizeof(struct stpeca), 1, fp) != 1)
		{
			apresentaMensagem("Erro na leitura do arquivo CAD_DOMINO");
			apresentaMensagem("Novo jogo sendo criado....");
			break;
		}
	}
	
	for (i = 0; i < 100; i++)
	{
		if (fread(&mesa[i], sizeof(struct Mesa), 1, fpm) != 1)
		{
			apresentaMensagem("Erro na leitura do arquivo CAD_MESA");
			apresentaMensagem("Novo jogo sendo criado....");
			break;
		}
	}
	
	if (fread(&sitJogo, sizeof(struct Jogo), 1, fps) != 1)
	{
		apresentaMensagem("Erro na leitura do arquivo CAD_JOGO");
		apresentaMensagem("Novo jogo sendo criado....");
	}
		
	fclose(fps);
	fclose(fpm);
	fclose(fp);
	
	// Recupera dados do Jogo salvo
	for(int i = 0; i < 100; i++)
    {
        mesa[i].status = sitJogo.PecasMesa[i].status;
        mesa[i].lado1 = sitJogo.PecasMesa[i].lado1;
        mesa[i].lado2 = sitJogo.PecasMesa[i].lado2;
    }
	
	qtmesa = sitJogo.qtmesaJogo;
	jvez = sitJogo.jogadorJogo;
	jogcomp = sitJogo.jogadorComp;
	canto.ladoD = sitJogo.mesaDJogo;
	canto.ladoE = sitJogo.mesaEJogo;
	LimpaTela();
	apresentaMensagem("Retornando ao jogo recuperado");
}

void contracomputador()
{
	int pecaEsc = -1; 
	jogcomp = jvez; 

	
		for (int i = 0; i < 28; i++)
		{
			if ((canto.ladoD == pecas[i].lado1 || canto.ladoD == pecas[i].lado2) || (canto.ladoE == pecas[i].lado1 || canto.ladoE == pecas[i].lado2))
			{
				pecaEsc = i;
				break;
			}
		}

		if (pecaEsc != -1) // Verifique se uma peça foi escolhida
		{
			if ((canto.ladoE == pecas[pecaEsc].lado1 || canto.ladoE == pecas[pecaEsc].lado2))
			{
				if (canto.ladoE == pecas[pecaEsc].lado1)
				{
					trocarLado(pecaEsc);
					addPecaE(pecaEsc);
					trocajvez();
				}
				else if (canto.ladoE == pecas[pecaEsc].lado2)
				{
					addPecaE(pecaEsc);
					trocajvez();
				}
			}
			// Validar lado direito
			else if ((canto.ladoD == pecas[pecaEsc].lado1 || canto.ladoD == pecas[pecaEsc].lado2))
			{
				if (canto.ladoD == pecas[pecaEsc].lado1)
				{
					addPecaD(pecaEsc);
					trocajvez();
				}
				else if (canto.ladoD == pecas[pecaEsc].lado2)
				{
					trocarLado(pecaEsc);
					addPecaD(pecaEsc);
					trocajvez();
				}
			}
		}
		else
		{
			if (depositoVazio() == false)
				comprar();
			else
				passar();
		}
	
	
}

void joguinho2()
{
    while (acabarJogo()) 
    {
        apresentar();
        
        if (jvez == '1') 
        {
            int escolhaSubMenu = subMenu(); // Obtenha a escolha do jogador humano

            switch (escolhaSubMenu) 
            {
                case 1:
                    Jogar();
                    break;
                case 2:
                    comprar();
                    break;
                case 3:
                    passar();
                    break;
                case 4:
                    msgSair();
                    LimpaTela();
                    break;
                default:
                    apresentaMensagem("Opcao invalida, tente novamente");
                    break;
            }

            if (escolhaSubMenu == 4) 
            {
                break; // Sai do loop interno quando a opção 4 for escolhida
            }
        } 
        else if (jvez == '2') 
        {
            // Chamada para o computador jogar automaticamente
            contracomputador();
        }
    }
}




	










