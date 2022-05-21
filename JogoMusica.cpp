#include "JogoMusica.h"



JogoMusica::JogoMusica()
{
}


JogoMusica::~JogoMusica()
{
}

void JogoMusica::Tocar()
{
	gMusica.parar();
	if (GetProxTela() == 1)
	{
		gMusica.tocar("m_combate0", true);
	}
	if (GetProxTela() == 2)
	{
		gMusica.tocar("m_combate1", true);
	}
	if (GetProxTela() == 3)
	{
		gMusica.tocar("m_combate2", true);
	}
	if (GetProxTela() == 4)
	{
		gMusica.tocar("m_combate3", true);
	}
	if (GetProxTela() == 5)
	{
		gMusica.tocar("m_combateBoss", true);
	}
	if (GetProxTela() == 6)
	{
		gMusica.tocar("m_niveis", false);
	}
	if (GetProxTela() == 6)
	{
		gMusica.tocar("m_niveis", false);
	}
}
