#pragma once
#include "libUnicornio.h"
#include <ctime>
#include <fstream>
#include <stack>
#include <queue>
#include "Musicas.h"
#include "MenuMusica.h"
#include "JogoMusica.h"
#include <list>
#include "Personagem.h"
#include "Mapa.h"
#include "Bowser.h"
#include "Mario.h"
#include "Luigi.h"
#include "Peach.h"
#include "Yoshi.h"
#include "Chefes.h"
#include "Telas.h"
#include "TelaControles.h"
#include "TelaCreditos.h"
#include "TelaMenu.h"
#include "TelaPersonagens.h"
#include "TelaSave.h"
#include "TelaGameOver.h"
#include "TelaVitoria.h"
#include "TelaJogo0.h"
#include "TelaJogo1.h"
#include "TelaJogo2.h"
#include "TelaJogo3.h"
#include "TelaJogo4.h"
#include "TelaNivel.h"

enum idTelas { TELA_MENU, TELA_NIVEL, TELA_NIVEL1, TELA_NIVEL2, TELA_NIVEL3, TELA_JOGO0, TELA_JOGO1, TELA_JOGO2, TELA_JOGO3, TELA_JOGO4, TELA_CREDITOS, TELA_PERSONAGEM, TELA_GAMEOVER, TELA_MAPAS, TELA_VITORIA, TELA_CONTROLES, TELA_SAVES,TELA_NMAPA };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	void DesenharTelas();
	void DesenharTelaJogo();
	void BotoesOeP();
	void SalvarJogo(int e);
	void CarregaSalvo(int e);
	
	void ResetarPilha();
	
	stack <Telas*> pilhaTelas;
	queue<Telas*> filaTelas;
	list<Musicas*> listaMusicas;
	list<Musicas>::iterator it;
    

private:
	int idTela;
	int aux, nMapa;
	int Save;
	bool pausou = false, salvar = false;
	
	TelaControles telaControles;
	TelaMenu telaMenu;
	TelaPersonagens telaPersonagens;
	TelaCreditos telaCreditos;
	TelaSave telaSave;
	TelaGameOver telaGameOver;
	TelaVitoria telaVitoria;
	TelaJogo0 telaJogo0;
	TelaJogo1 telaJogo1;
	TelaJogo2 telaJogo2;
	TelaJogo3 telaJogo3;
	TelaJogo4 telaJogo4;
	TelaNivel telaNivel;
	MenuMusica menuMusica;
	JogoMusica jogoMusica;
	BotaoSprite	bt_Salvar1, bt_Salvar2, bt_Salvar3;
	Sprite fundo_Pause;
};

