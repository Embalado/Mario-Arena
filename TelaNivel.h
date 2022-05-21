#pragma once
#include "Telas.h"

class TelaNivel : public Telas
{
public:
	TelaNivel();
	~TelaNivel();
	void DesenharTela();
	void SetProxTela(int n);
	int GetProxTela() { return n; }
private:
	int n;
};

