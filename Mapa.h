#pragma once
#include "libUnicornio.h"

class Mapa
{
public:
	Mapa();
	~Mapa();
	void Carregar(string nomeArq);
	void Desenhar();
	int getElemento(int i, int j);
	inline int getNLinhas() { return nLinhas; }
	inline int getNColunas() { return nColunas; }
	inline int getLarguraTile() { return tileset[0].getLargura(); }
	inline int getAlturaTile() { return tileset[0].getAltura(); }
	float getPosX(int i, int j);
	float getPosY(int i, int j);

protected:
	Sprite * tileset;
	int nTiles;
	int n;
	int **map;
	int nLinhas, nColunas;
	float xi, yi;

};

