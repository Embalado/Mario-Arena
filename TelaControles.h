#pragma once
#include "Telas.h"
class TelaControles :
	public Telas
{
public:
	TelaControles();
	~TelaControles();
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);
};

