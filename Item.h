#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include "libUnicornio.h"
#include "Personagem.h"

using namespace std;

class Item
{
public:
	Item();
	~Item();
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
	




private:
	string NomeSpr;
	Sprite spr;
	float x, y;
	bool Vivo;
	Texto txt;
	ifstream ArquivoItens;


};

