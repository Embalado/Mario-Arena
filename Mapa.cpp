#include "Mapa.h"

Mapa::Mapa()
{
}

Mapa::~Mapa()
{
}

void Mapa::Carregar(string nomeArq)
{
	ifstream arqEntrada;

	arqEntrada.open(nomeArq);

	if (arqEntrada.is_open())
	{
		arqEntrada >> nTiles;
		tileset = new Sprite[nTiles];

		for (int i = 0; i < nTiles; i++)
		{
			string label, caminho;
			int nAnim, nFrames;

			arqEntrada >> label >> caminho >> nAnim >> nFrames;

			if (!gRecursos.carregouSpriteSheet(label))
			{
				gRecursos.carregarSpriteSheet(label, caminho, nAnim, nFrames);
				tileset[i].setSpriteSheet(label);
			}
		}

		//Processa a matriz

		arqEntrada >> nLinhas >> nColunas;
		map = new int*[nLinhas];

		for (int i = 0; i < nLinhas; i++)
		{
			map[i] = new int[nColunas];
		}

		for (int i = 0; i < nLinhas; i++)
		{
			for (int j = 0; j < nColunas; j++)
			{
				arqEntrada >> map[i][j];
			}
		}
	}
	else
	{
		// nao conseguiu
			
	}
	arqEntrada.close();

	//pode ser colocado no arquivo depois
	xi = 32; // tileset[iMap].getLargura() / 2;
	yi = 32; // tileset[iMap].getAltura() / 2;
}

void Mapa::Desenhar()
{
	for (int i = 0; i < nLinhas; i++)
	{
		for (int j = 0; j < nColunas; j++)
		{
			int iMap = map[i][j];

			float x = xi + j * tileset[iMap].getLargura();
			float y = yi + i * tileset[iMap].getAltura();

			tileset[iMap].desenhar(x, y);
		}
	}
}

int Mapa::getElemento(int i, int j)
{
 	return  map[i][j];
}

float Mapa::getPosX(int i, int j)
{
	int iMap = map[i][j];
	float x = xi + j * tileset[iMap].getLargura();
	return x;;
}

float Mapa::getPosY(int i, int j)
{
	int iMap = map[i][j];
	float y = yi + i * tileset[iMap].getAltura();
	return y;
}