#include "TelaVitoria.h"



TelaVitoria::TelaVitoria()
{
}


TelaVitoria::~TelaVitoria()
{
}

void TelaVitoria::DesenharTela()
{
	fundo_Vitoria.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}
}

int TelaVitoria::getBotaoClicado()
{
	return n;
}

void TelaVitoria::setBotaoClicado(int n)
{
	this->n = n;
}
