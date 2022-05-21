#include "TelaNivel.h"

TelaNivel::TelaNivel()
{
}
TelaNivel::~TelaNivel()
{
}

void TelaNivel::DesenharTela()
{
	if (GetEscolha() == 1)
		fundo_Nivel1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (GetEscolha() == 2)
		fundo_Nivel2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (GetEscolha() == 3)
		fundo_Nivel3.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (GetEscolha() == 4)
		fundo_Nivel4.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Continuar.setPos(795, 720);
	bt_Continuar.desenhar();
	bt_Continuar.atualizar();

	bt_Sair.setPos(150, 720);
	bt_Sair.desenhar();
	bt_Sair.atualizar();

	if (bt_Continuar.estaClicado())
	{
		SetProxTela(1);
	}
	if (bt_Sair.estaClicado())
	{

		SetProxTela(2);
	}
}

void TelaNivel::SetProxTela(int n)
{
	this->n = n;
}
