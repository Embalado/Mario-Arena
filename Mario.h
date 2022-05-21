#pragma once
#include "Personagem.h"

class Mario : public Personagem
{
public:
	Mario();
	~Mario();

	void Especial();
	void Combater(int Dano);
	
};

