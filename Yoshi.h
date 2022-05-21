#pragma once
#include "Personagem.h"

class Yoshi : public Personagem
{
public:
	Yoshi();
	~Yoshi();

	void Especial();
	void Combater(int Dano);
	
};

