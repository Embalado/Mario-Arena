#include "Peach.h"

Peach::Peach()
{
}
Peach::~Peach()
{
}

void Peach::Especial()
{
}

void Peach::Combater(int Dano)
{
	Vida = Vida + Dano /4 - rand() % 9;
	Vida += rand() % 6;
}


