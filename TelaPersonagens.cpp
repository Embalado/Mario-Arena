#include "TelaPersonagens.h"



TelaPersonagens::TelaPersonagens()
{
}


TelaPersonagens::~TelaPersonagens()
{
}

void TelaPersonagens::DesenharTela()
{
	fundo_Personagens.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(120, 750);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	bt_per1.setPos(865, 450);
	bt_per1.desenhar();
	bt_per1.atualizar();

	bt_per2.setPos(175, 450);
	bt_per2.desenhar();
	bt_per2.atualizar();

	bt_per3.setPos(720, 750);
	bt_per3.desenhar();
	bt_per3.atualizar();

	bt_per4.setPos(355, 750);
	bt_per4.desenhar();
	bt_per4.atualizar();

	bt_per5.setPos(520, 300);
	bt_per5.desenhar();
	bt_per5.atualizar();

	//Selecionar o personagem
	if (bt_per1.estaClicado())
	{
		setBotaoClicado(10);
		SetEscolha(1);

	}

	if (bt_per2.estaClicado())
	{
		setBotaoClicado(11);
		SetEscolha(2);

	}

	if (bt_per3.estaClicado())
	{
		setBotaoClicado(12);
		SetEscolha(3);
	}

	if (bt_per4.estaClicado())
	{
		setBotaoClicado(13);
		SetEscolha(4);

	}

	if (bt_per5.estaClicado())
	{
		setBotaoClicado(14);
		SetEscolha(5);
	
	}
	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}
}

int TelaPersonagens::getBotaoClicado() 
{
	return n;
}

void TelaPersonagens::setBotaoClicado(int n)
{
	this-> n = n;
}

