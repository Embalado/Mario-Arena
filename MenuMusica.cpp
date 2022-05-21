#include "MenuMusica.h"



MenuMusica::MenuMusica()
{
}


MenuMusica::~MenuMusica()
{
}

void MenuMusica::Tocar()
{
	if (GetProxTela() == 1)
	{
		gMusica.tocar("m_menu", true);
	}
	if (GetProxTela() == 2)
	{
		gMusica.tocar("m_menu2", true);
	}
	if (GetProxTela() == 3)
	{
		gMusica.tocar("m_gameOver", false);
	}
	if (GetProxTela() == 4)
	{
		gMusica.tocar("m_vitoria", true);
	}
}
