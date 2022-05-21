#include "Personagem.h"

Personagem::Personagem()
{
}
Personagem::~Personagem()
{
}

void Personagem::Inicializar(string  NomeSpr, float  x, float  y)
{
	spr.setSpriteSheet(NomeSpr);
	this->x = x;
	this->y = y;
	this->vel = 0.8;
	Vida = 1000;
	Vivo = true;
}

void Personagem::Desenhar()
{
	if (getVivo() == true)
	{
		spr.desenhar(x, y);
	}
}

void Personagem::Atualizar()
{
	spr.setVelocidadeAnimacao(8.0);
	float nx, ny, nx1, ny1;
	nx = x + vel;
	ny = y + vel;
	nx1 = x - vel;
	ny1 = y - vel;

	int xTile = nx / mapa->getLarguraTile();
	int yTile = ny / mapa->getAlturaTile();
	int xTile1 = nx1 / mapa->getLarguraTile();
	int yTile1 = ny1 / mapa->getAlturaTile();

	if (gTeclado.segurando[TECLA_D])
	{
		if (mapa->getElemento(yTile, xTile) == 0 || mapa->getElemento(yTile, xTile) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
		{
			spr.setAnimacao(2);
			spr.avancarAnimacao();
			x = nx;
		}
		AnimPos = 1;
		
	}
	if (gTeclado.segurando[TECLA_A])
	{
		if (mapa->getElemento(yTile1, xTile1) == 0 || mapa->getElemento(yTile1, xTile1) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
		{
			spr.setAnimacao(1);
			spr.avancarAnimacao();
			x = nx1;
		}
		AnimPos = 2;
	}
	if (gTeclado.segurando[TECLA_W])
	{
		if (mapa->getElemento(yTile1, xTile1) == 0 || mapa->getElemento(yTile1, xTile1) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
		{
			spr.setAnimacao(3);
			spr.avancarAnimacao();
			y = ny1;
		}
		AnimPos = 3;
	}
	if (gTeclado.segurando[TECLA_S])
	{
		if (mapa->getElemento(yTile, xTile) == 0 || mapa->getElemento(yTile, xTile) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
		{
			spr.setAnimacao(0);
			spr.avancarAnimacao();
			y = ny;
		}
		AnimPos = 4;
	}
	
	if (mapa->getElemento(yTile, xTile) == 8)
	{
		Vida -= Armadilha(3);
	}

	if(AnimPos==1)
	{ 
		if (gTeclado.segurando[TECLA_ESPACO])
		{
			spr.setAnimacao(6);
			spr.avancarAnimacao();

		}

	}
	if (AnimPos == 2)
	{
		if (gTeclado.segurando[TECLA_ESPACO])
		{
			spr.setAnimacao(5);
			spr.avancarAnimacao();
		}
	}
	if (AnimPos == 3)
	{
		if (gTeclado.segurando[TECLA_ESPACO])
		{
			spr.setAnimacao(7);
			spr.avancarAnimacao();
		}
	}
	if (AnimPos == 4)
	{
		if (gTeclado.segurando[TECLA_ESPACO])
		{
			spr.setAnimacao(4);
			spr.avancarAnimacao();
		}
	}


}

Sprite Personagem::getSprite()
{
	return spr;
}

float Personagem::getX()
{
	return x;
}

float Personagem::getY()
{
	return y;
}

void Personagem::Combate()
{
	if (AnimPos == 1)
	{
		
			spr.setAnimacao(6);
			spr.avancarAnimacao();

		

	}
	if (AnimPos == 2)
	{
		
			spr.setAnimacao(5);
			spr.avancarAnimacao();
		
	}
	if (AnimPos == 3)
	{
		
			spr.setAnimacao(7);
		spr.avancarAnimacao();
		
	}
	if (AnimPos == 4)
	{
		
			spr.setAnimacao(4);
			spr.avancarAnimacao();
		
	}

}


void Personagem::setVivo(bool Vivo)
{
	this->Vivo = Vivo;
}



void Personagem::ResetarVida()
{
	Vida = 100;
}

void Personagem::Especial()
{
}

void Personagem::setMapa(Mapa * mapa)
{
	this->mapa = mapa;
}

void Personagem::IA(Personagem & PER)
{
	spr.setVelocidadeAnimacao(8.0);
	float nx, ny, nx1, ny1;
	nx = x + vel;
	ny = y + vel;
	nx1 = x - vel;
	ny1 = y - vel;

	int xTile = nx / mapa->getLarguraTile();
	int yTile = ny / mapa->getAlturaTile();
	int xTile1 = nx1 / mapa->getLarguraTile();
	int yTile1 = ny1 / mapa->getAlturaTile();
	
		if (getX() > PER.getX())
		{
			if (mapa->getElemento(yTile1, xTile1) == 0 || mapa->getElemento(yTile1, xTile1) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
			{
				spr.setAnimacao(1);
				spr.avancarAnimacao();
				x = nx1;
			}
			AnimPos = 2;
			


		}
		if (getX() < PER.getX())
		{
			if (mapa->getElemento(yTile, xTile) == 0 || mapa->getElemento(yTile, xTile) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
			{
				spr.setAnimacao(2);
				spr.avancarAnimacao();
				x = nx;
			}
			AnimPos = 1;
			
		
		}
		 if (getY() < PER.getY())
		{
			 if (mapa->getElemento(yTile, xTile) == 0 || mapa->getElemento(yTile, xTile) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
			 {
				 spr.setAnimacao(0);
				 spr.avancarAnimacao();
				 y = ny;
			 }
			 AnimPos = 4;
			
		}
		 if (getY() > PER.getY())
		{
			 if (mapa->getElemento(yTile1, xTile1) == 0 || mapa->getElemento(yTile1, xTile1) == 4 || mapa->getElemento(yTile, xTile) == 5 || mapa->getElemento(yTile, xTile) == 6 || mapa->getElemento(yTile, xTile) == 7 || mapa->getElemento(yTile, xTile) == 8 || mapa->getElemento(yTile, xTile) == 3)
			 {
				 spr.setAnimacao(3);
				 spr.avancarAnimacao();
				 y = ny1;
			 }
			 AnimPos = 3;
			
		}
		 if (mapa->getElemento(yTile1, xTile1) == 1 && AnimPos== 3 )
		 {
			 y = ny;
		 }
		 if(mapa->getElemento(yTile1, xTile1) == 1 && AnimPos == 4)
		 {
			 y = ny1;
		 }
		 if(mapa->getElemento(yTile1, xTile1) == 1 && AnimPos == 1)
		 {
			 x = nx1;
		 }
		 if (mapa->getElemento(yTile1, xTile1) == 1 && AnimPos == 2)
		 {
			 x = nx;
		 }
		 if (mapa->getElemento(yTile, xTile) == 8)
		 {
			 Vida -= Armadilha(3);
		 }
}

int Personagem::Armadilha(int a)
{
	if(a == 0)
	return 1;

	else
	{
		return a * Armadilha(a - 1);
	}
}

void Personagem::vidaManager(int vida)
{
  Vida += vida;
}

void Personagem::velManeger(float velo)
{
	vel += velo;
}
