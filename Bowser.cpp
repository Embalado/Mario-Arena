#include "Bowser.h"

Bowser::Bowser()
{
}
Bowser::~Bowser()
{
}

void Bowser::Especial()
{
}

void Bowser::Combater(int Dano)
{
	Vida = Vida + Dano / 10 - rand() % 6;
}


