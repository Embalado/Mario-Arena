#pragma once
#include "Telas.h"
class TelaVitoria :
	public Telas
{
public:
	TelaVitoria();
	~TelaVitoria();
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);
};

