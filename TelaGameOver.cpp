#include "TelaGameOver.h"



TelaGameOver::TelaGameOver()
{
}


TelaGameOver::~TelaGameOver()
{
}

void TelaGameOver::DesenharTela()
{
	fundo_GameOver.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}
}

int TelaGameOver::getBotaoClicado()
{
	return n;
}

void TelaGameOver::setBotaoClicado(int n)
{
	this->n = n;
}
