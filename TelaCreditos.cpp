#include "TelaCreditos.h"



TelaCreditos::TelaCreditos()
{
}


TelaCreditos::~TelaCreditos()
{
}



void TelaCreditos::DesenharTela()
{
	fundo_Creditos.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(130, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
		setBotaoClicado(4);
	}
}

int TelaCreditos::getBotaoClicado() 
{
	return n;
}

void TelaCreditos::setBotaoClicado(int n)
{
	this->n = n;
}
