#pragma once
#include "Telas.h"
class TelaGameOver :
	public Telas
{
public:
	TelaGameOver();
	~TelaGameOver();
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);
};

