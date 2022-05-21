#pragma once
#include "Personagem.h"

class Bowser : public Personagem
{
public:
	Bowser();
	~Bowser();

	void Especial();
	void Combater(int Dano);
	
};

