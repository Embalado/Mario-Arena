#include "TelaSave.h"



TelaSave::TelaSave()
{
}


TelaSave::~TelaSave()
{
}



void TelaSave::DesenharTela()
{


	fundo_Saves.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Carregar1.setPos(512, 150);
	bt_Carregar1.desenhar();
	bt_Carregar1.atualizar();

	bt_Carregar2.setPos(512, 300);
	bt_Carregar2.desenhar();
	bt_Carregar2.atualizar();

	bt_Carregar3.setPos(512, 450);
	bt_Carregar3.desenhar();
	bt_Carregar3.atualizar();

	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	/*CarregarBowser("Bowser.txt");
	CarregarLuigi("Luigi.txt");
	CarregarPeach("Peach.txt");
	CarregarYoshi("Yoshi.txt");
	CarregarMario("Mario.txt");*/

	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}

	if (bt_Carregar1.estaClicado())
	{
		setBotaoClicado(1);
	}
	if (bt_Carregar2.estaClicado())
	{
		setBotaoClicado(2);
	}
	if (bt_Carregar3.estaClicado())
	{
		setBotaoClicado(3);
	}
}

int TelaSave::getBotaoClicado() 
{
	return n;
}

void TelaSave::setBotaoClicado(int n)
{
	this->n = n;
}
