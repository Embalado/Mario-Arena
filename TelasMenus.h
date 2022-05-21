#pragma once
#include "libUnicornio.h"

class Telas
{
public:

	Telas();
	~Telas();

	void MenusInicializar();
	void DesenharPrincipal();
	void DesenharControles();
	void DesenharCreditos();
	void DesenharContinuar();
	void DesenharPersonagens();
	void DesenharSaves();
	void DesenharGameOver();
	void DesenharVitoria();

private:
	BotaoSprite bt_Jogar, bt_Continuar, bt_Creditos, bt_Sair, bt_Controles, bt_Voltar, bt_per1, bt_per2, bt_per3, bt_per4, bt_per5, bt_Salvar1, bt_Salvar2, bt_Salvar3, bt_Carregar1, bt_Carregar2, bt_Carregar3;
	Sprite fundo_Menu, fundo_Personagens, fundo_Creditos, fundo_GameOver, fundo_Controles, fundo_Mapa0, fundo_Mapa1, fundo_Mapa2, fundo_Mapa3, fundo_MapaChefe, fundo_Pause, fundo_Vitoria, fundo_Nivel1, fundo_Nivel2, fundo_Nivel3, fundo_Nivel4, fundo_Saves, Vida, teclasJogo;
	Texto txtVida;
};

