#pragma once
#include "libUnicornio.h"
#include "Mapa.h"
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Personagem
{
public:
	Personagem();
	~Personagem();
	void Inicializar(string NomeSpr, float x, float y);
	void Desenhar();
	void Atualizar();
	Sprite getSprite();
	float getX();
	float getY();
	void Combate();
	void setVivo(bool Vivo);
	bool getVivo() { return Vivo; }
    int getVida() { return Vida; }
	void ResetarVida();
	virtual void Especial() ;
	void setMapa(Mapa *mapa);
	Mapa getMapa() { return *mapa; }
	void IA(Personagem &PER);
	int Armadilha(int a);
	void vidaManager(int vida);
	void velManeger(float velo);

protected:
	Sprite spr;
	float x, y, vel;
	Mapa *mapa;
	int Dano, Vida;
	bool Vivo;
	int AnimPos;
};

