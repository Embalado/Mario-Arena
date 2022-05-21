#include "Mario.h"

Mario::Mario()
{
}
Mario::~Mario()
{
}

void Mario::Especial()
{
}

void Mario::Combater(int Dano)
{
	Vida = Vida + Dano/5 - rand() % 7;
}

