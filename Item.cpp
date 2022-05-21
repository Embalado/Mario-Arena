#include "Item.h"

Item::Item()
{
}
Item::~Item()
{
}

void Item::Inicializar(float xi, float yi)
{
	ArquivoItens.open("Itens.txt");

	string Linha;
	int nLinhas = 0, Random;

	if (!ArquivoItens.is_open())
	{
	}
	else
	{
		Random = rand() % 3;

		while (Random != nLinhas)
		{
			getline(ArquivoItens, Linha);
			++nLinhas;
		}

		ArquivoItens >> NomeSpr;

		spr.setSpriteSheet(NomeSpr);
		x = xi;
		y = yi;
		Vivo = true;
	}
	ArquivoItens.close();
}
void Item::Atualizar()
{
}

void Item::Desenhar()
{
	if (getVivo() == true)
	{
		spr.desenhar(x, y);
	}
}
void Item::setVivo(bool Vivo)
{
	this->Vivo = Vivo;
}

void Item::setX(float x)
{
	this->x = x;
}
void Item::setY(float y)
{
	this->y = y;
}
Sprite Item::getSprite()
{
	return spr;
}