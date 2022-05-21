#pragma once
#include "Telas.h"
class TelaJogo3 :
	public Telas
{
public:
	TelaJogo3();
	~TelaJogo3();
	void DesenharTela();
	void CarregarBowser(string nomearq);
	void CarregarMario(string nomearq);
	void CarregarPeach(string nomearq);
	void CarregarLuigi(string nomearq);
	void CarregarYoshi(string nomearq);
	void CarregarMapa();
	void ItensNascer();
	void ColisaoItens();
	
private:
	Mapa mapa3;
};

