#pragma once
#include "Telas.h"
class TelaJogo4 :
	public Telas
{
public:
	TelaJogo4();
	~TelaJogo4();
	void DesenharTela();
	void CarregarBowser(string nomearq);
	void CarregarMario(string nomearq);
	void CarregarPeach(string nomearq);
	void CarregarLuigi(string nomearq);
	void CarregarYoshi(string nomearq);
	void CarregarMapa();
	void CarregarChefes();
	void ItensNascer();
	void ColisaoItens();

private:
	Mapa mapa4;
};

