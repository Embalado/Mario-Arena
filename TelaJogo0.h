#pragma once
#include "Telas.h"
class TelaJogo0 :
	public Telas
{
public:
	TelaJogo0();
	~TelaJogo0();
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
	Mapa mapa0;
};

