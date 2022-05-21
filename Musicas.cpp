#include "Musicas.h"



Musicas::Musicas()
{
}


Musicas::~Musicas()
{
}

void Musicas::InicializarMenu()
{
	//Carregar Musicas
	gRecursos.carregarMusica("m_menu", "Assets/Music/MTelaAbertura.mp3");
	gRecursos.carregarMusica("m_menu2", "Assets/Music/MCreditos&Controles&Save.mp3");
	gRecursos.carregarMusica("m_vitoria", "Assets/Music/MVitoria.mp3");
	gRecursos.carregarMusica("m_gameOver", "Assets/Music/GameOver.mp3");
}

void Musicas::InicializarJogo()
{
	//Carregar musicas de combate
	gRecursos.carregarMusica("m_combate0", "Assets/Music/MMapa0.mp3");
	gRecursos.carregarMusica("m_combate1", "Assets/Music/MMapa1.mp3");
	gRecursos.carregarMusica("m_combate2", "Assets/Music/MMapa2.mp3");
	gRecursos.carregarMusica("m_combate3", "Assets/Music/MMapa3.mp3");
	gRecursos.carregarMusica("m_niveis", "Assets/Music/MTelaMapas.mp3");
	gRecursos.carregarMusica("m_combateBoss", "Assets/Music/MMapaBoss.mp3");
}

void Musicas::Tocar()
{
}

void Musicas::SetProxTela(int n)
{
	this->n = n;
}
