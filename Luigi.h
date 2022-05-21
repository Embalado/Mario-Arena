#pragma once
#include "Personagem.h"

class Luigi : public Personagem
{
public:
	Luigi();
	~Luigi();

	void Especial();
	void Combater(int Dano);
	
};

