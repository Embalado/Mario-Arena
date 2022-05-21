#include "TelaMenu.h"

TelaMenu::TelaMenu()
{
}
TelaMenu::~TelaMenu()
{
}

void TelaMenu::DesenharTela()
{
	fundo_Menu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	//Botões do menu
	bt_Jogar.setPos(795, 400);
	bt_Jogar.desenhar();
	bt_Jogar.atualizar();

	bt_Continuar.setPos(795, 500);
	bt_Continuar.desenhar();
	bt_Continuar.atualizar();

	bt_Creditos.setPos(795, 600);
	bt_Creditos.desenhar();
	bt_Creditos.atualizar();

	bt_Sair.setPos(150, 650);
	bt_Sair.desenhar();
	bt_Sair.atualizar();

	bt_Controles.setPos(795, 700);
	bt_Controles.desenhar();
	bt_Controles.atualizar();

	if (bt_Jogar.estaClicado())
	{
		setBotaoClicado(1);
		
	}

	if (bt_Creditos.estaClicado())
	{
		setBotaoClicado(3);
	
	}

	if (bt_Controles.estaClicado())
	{
		setBotaoClicado(4);
	}

	if (bt_Continuar.estaClicado())
	{
		setBotaoClicado(2);
		
	}
	if (bt_Sair.estaClicado())
	{
		
		setBotaoClicado(8);
	}
}

int TelaMenu::getBotaoClicado() 
{
	return n;
}

void TelaMenu::setBotaoClicado(int n) 
{
   this-> n = n;
}


