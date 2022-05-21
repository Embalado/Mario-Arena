#include "Yoshi.h"

Yoshi::Yoshi()
{
}

Yoshi::~Yoshi()
{
}

void Yoshi::Especial()
{
}

void Yoshi::Combater(int Dano)
{
	Vida = Vida + Dano/4  - rand() % 10;
}

