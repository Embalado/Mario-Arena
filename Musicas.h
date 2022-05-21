#pragma once
#include "libUnicornio.h"
class Musicas
{
public:
	Musicas();
	~Musicas();
	void InicializarMenu();
	void InicializarJogo();
	virtual void Tocar();
	int GetProxTela() { return n; }
	void SetProxTela(int n);
protected:
	int n;

};

