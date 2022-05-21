#pragma once
#include "Telas.h"
class TelaCreditos :
	public Telas
{
public:
	TelaCreditos();
	~TelaCreditos();
	
	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);
};

