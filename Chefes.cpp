#include "Chefes.h"

Chefes::Chefes()
{
}


Chefes::~Chefes()
{
}

void Chefes::Inicializar(float xi, float yi)
{
	ArquivoChefes.open("Chefes.txt");

	string Linha;
	int nLinhas = 0, Random;

	if (!ArquivoChefes.is_open())
	{
	}
	else
	{
		Random = rand() % 2;

		while (Random != nLinhas)
		{
			getline(ArquivoChefes, Linha);
			++nLinhas;
		}

		ArquivoChefes >> NomeSpr >> Vida;

		spr.setSpriteSheet(NomeSpr);
		x = xi;
		y = yi;
		Vivo = true;
	}
	ArquivoChefes.close();
}

void Chefes::Atualizar()
{
	if (getVivo() == true)
	{
		spr.setAnimacao(0);
		spr.avancarAnimacao();
	}
}

void Chefes::Desenhar()
{
	if (getVivo() == true)
	{
		spr.desenhar(x, y);
	
		
	}
}

void Chefes::setVivo(bool Vivo)
{
	this->Vivo = Vivo;
}

void Chefes::setX(float x)
{
	this->x = x;
}

void Chefes::setY(float y)
{
	this->y = y;
}

Sprite Chefes::getSprite()
{
	return spr;
}

void Chefes::Combater(int Dano)
{
	Vida = Vida + Dano/2 - rand() % 5;
}





