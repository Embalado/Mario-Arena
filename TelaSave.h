#pragma once
#include "Telas.h"
class TelaSave :
	public Telas
{
public:
	TelaSave();
	~TelaSave();

	void DesenharTela();
	int getBotaoClicado();
	void setBotaoClicado(int n);

};

