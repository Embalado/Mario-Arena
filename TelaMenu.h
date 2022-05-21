#pragma once
#include "Telas.h"
class TelaMenu :
	public Telas
{
public:
	TelaMenu();
	~TelaMenu();
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);

};

