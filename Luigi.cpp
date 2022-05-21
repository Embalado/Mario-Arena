#include "Luigi.h"

Luigi::Luigi()
{
}
Luigi::~Luigi()
{
}

void Luigi::Especial()
{
}

void Luigi::Combater(int Dano)
{
	Vida = Vida + Dano/5 - rand() % 8;
}

