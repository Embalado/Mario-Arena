#pragma once
#include "libUnicornio.h"
#include "Mapa.h"
#include "Yoshi.h"
#include "Bowser.h"
#include "Peach.h"
#include "Luigi.h"
#include "Mario.h"
#include "Personagem.h"
#include "Chefes.h"
#include "Item.h"
#include <list>

class Telas
{
public:

	Telas();
	~Telas();

	void TelasInicializarMenus();
	void TelasInicializarCombate();

	void SetEscolha(int escolha);
	void SetProxMapa(int Prox);

	virtual void DesenharTela();
	virtual void ItensNascer();
	virtual void CarregarBowser(string nomearq);
    virtual void CarregarMario(string nomearq);
	virtual void CarregarPeach(string nomearq);
	virtual void CarregarLuigi(string nomearq);
	virtual void CarregarYoshi(string nomearq);
	virtual void CarregarMapa();
	void ItensInicializar();
	int GetEscolha() { return escolha; }
	int GetProxMapa() { return Prox; }

	

protected:
	BotaoSprite bt_Jogar, bt_Continuar, bt_Creditos, bt_Sair, bt_Controles, bt_Voltar, bt_per1, bt_per2, bt_per3, bt_per4, bt_per5, bt_Carregar1, bt_Carregar2, bt_Carregar3;
	Sprite fundo_Menu, fundo_Personagens, fundo_Creditos, fundo_GameOver, fundo_Controles, fundo_Mapa0, fundo_Mapa1, fundo_Mapa2, fundo_Mapa3, fundo_MapaChefe, fundo_Vitoria, fundo_Nivel1, fundo_Nivel2, fundo_Nivel3, fundo_Nivel4, fundo_Saves, Vida, teclasJogo;
	Texto txtVida, txtVida1;
	Item *itens;
	int Rand;
	int n = 6;
	int nItens, MAX_ITENS;
	int escolha, nMapa;
	Bowser bowser;
	Mario mario;
	Peach peach;
	Yoshi yoshi;
	Luigi luigi;
	Chefes chefes;
	int Prox;
};

