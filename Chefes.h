#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

#include "libUnicornio.h"

using namespace std;

class Chefes
{
public:
	Chefes();
	~Chefes();

	void Inicializar(float xi, float yi);
	void Atualizar();
	void Desenhar();
	void setVivo(bool Vivo);
	bool getVivo() { return Vivo; }
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x);
	void setY(float y);
	Sprite getSprite();
	int getVida() { return Vida; }
	void Combater(int Dano);
	
	

private:
	string NomeSpr;
	Sprite spr;
	int Vida = 150, Dano;
	float x, y;
	bool Vivo;
	Texto txt;
	ifstream ArquivoChefes;
};

