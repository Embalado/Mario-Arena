#pragma once
#include "Telas.h"
class TelaPersonagens :
	public Telas
{
public:
	TelaPersonagens();
	~TelaPersonagens();
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);
};

