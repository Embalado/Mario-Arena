#include "TelaControles.h"



TelaControles::TelaControles()
{
}


TelaControles::~TelaControles()
{
}


void TelaControles::DesenharTela()
{
	fundo_Controles.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(130, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}
}

int TelaControles::getBotaoClicado() 
{
	return n;
}

void TelaControles::setBotaoClicado(int n)
{
	this->n = n;
}
