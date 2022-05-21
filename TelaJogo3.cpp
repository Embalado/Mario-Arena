#include "TelaJogo3.h"



TelaJogo3::TelaJogo3()
{
}


TelaJogo3::~TelaJogo3()
{
}

void TelaJogo3::DesenharTela()
{
	fundo_Mapa3.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	mapa3.Desenhar();
	ItensNascer();
	ColisaoItens();

	if (GetEscolha() == 1)
		{
			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0))
			{
				luigi.Combate();
				bowser.Combater(-6);
				if (gTeclado.segurando[TECLA_ESPACO] && luigi.getVivo() == true)
				{
					luigi.Combater(-5);
					

					if (luigi.getVida() <= 0)
					{
						luigi.setVivo(false);
					}
				}
			}
			bowser.Atualizar();
			bowser.Desenhar();
			luigi.Desenhar();
			luigi.IA(bowser);
			txtVida.setString(to_string(bowser.getVida()));
			txtVida1.setString(to_string(luigi.getVida()));

			if (bowser.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
	if (GetEscolha() == 2)
		{
			if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
			{
				luigi.Combate();
				peach.Combater(-6);
				if (gTeclado.segurando[TECLA_ESPACO] && luigi.getVivo() == true)
				{
					
					luigi.Combater(-7);

					if (luigi.getVida() <= 0)
					{
						luigi.setVivo(false);
					}
				}
			}
			peach.Atualizar();
			peach.Desenhar();
			luigi.Desenhar();
			luigi.IA(peach);
			txtVida.setString(to_string(peach.getVida()));
			txtVida1.setString(to_string(luigi.getVida()));

			if (peach.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
	if (GetEscolha() == 3)
		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0))
			{
				luigi.Combate();
				yoshi.Combater(-6);
				if (gTeclado.segurando[TECLA_ESPACO] && luigi.getVivo() == true)
				{
					luigi.Combater(-10);
			

					if (luigi.getVida() <= 0)
					{
						luigi.setVivo(false);
					}
				}
			}
			yoshi.Atualizar();
			yoshi.Desenhar();
			luigi.Desenhar();
			luigi.IA(yoshi);
			txtVida.setString(to_string(yoshi.getVida()));
			txtVida1.setString(to_string(luigi.getVida()));

			if (yoshi.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
	if (GetEscolha() == 4)
		{

			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0))
			{
				bowser.Combate();
				luigi.Combater(-5);
				if (gTeclado.segurando[TECLA_ESPACO] && bowser.getVivo() == true)
				{
					
					bowser.Combater(-6);

					if (bowser.getVida() <= 0)
					{
						bowser.setVivo(false);
					}
				}
			}
			luigi.Atualizar();
			luigi.Desenhar();
			bowser.Desenhar();
			bowser.IA(luigi);
			txtVida.setString(to_string(luigi.getVida()));
			txtVida1.setString(to_string(bowser.getVida()));

			if (luigi.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
	if (GetEscolha() == 5)
		{
			if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
			{
				luigi.Combate();
				mario.Combater(-6);
				if (gTeclado.segurando[TECLA_ESPACO] && luigi.getVivo() == true)
				{
					
					luigi.Combater(-8);

					if (luigi.getVida() <= 0)
					{
						luigi.setVivo(false);
					}
				}
			}
			mario.Atualizar();
			mario.Desenhar();
			luigi.Desenhar();
			luigi.IA(mario);
			txtVida.setString(to_string(mario.getVida()));
			txtVida1.setString(to_string(luigi.getVida()));

			if (mario.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if ((luigi.getVivo() == false || bowser.getVivo() == false))
		{
			
				SetProxMapa(1);
			
		}
		txtVida.desenhar(300, 732);
		txtVida1.desenhar(600, 732);
		Vida.desenhar(450, 732);

		
	}

void TelaJogo3::CarregarBowser(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa3.getLarguraTile() + mapa3.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa3.getAlturaTile() + mapa3.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 4);
		bowser.Inicializar(nomeSpr, (float)mapa3.getPosX(y, x), (float)mapa3.getPosY(y, x));
	}
	arqEntrada.close();

}

void TelaJogo3::CarregarMario(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa3.getLarguraTile() + mapa3.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa3.getAlturaTile() + mapa3.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 5);
		mario.Inicializar(nomeSpr, (float)mapa3.getPosX(y, x), (float)mapa3.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo3::CarregarPeach(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa3.getLarguraTile() + mapa3.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa3.getAlturaTile() + mapa3.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 6);
		peach.Inicializar(nomeSpr, (float)mapa3.getPosX(y, x), (float)mapa3.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo3::CarregarLuigi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa3.getLarguraTile() + mapa3.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa3.getAlturaTile() + mapa3.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 7);
		luigi.Inicializar(nomeSpr, (float)mapa3.getPosX(y, x), (float)mapa3.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo3::CarregarYoshi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa3.getLarguraTile() + mapa3.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa3.getAlturaTile() + mapa3.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 3);
		yoshi.Inicializar(nomeSpr, (float)mapa3.getPosX(y, x), (float)mapa3.getPosY(y, x));
	}
	arqEntrada.close();
}


void TelaJogo3::CarregarMapa()
{
	mapa3.Carregar("mapa3.txt");
	bowser.setMapa(&mapa3);
	luigi.setMapa(&mapa3);
	peach.setMapa(&mapa3);
	yoshi.setMapa(&mapa3);
	mario.setMapa(&mapa3);
}

void TelaJogo3::ItensNascer()
{
	if (nItens < MAX_ITENS)
	{
		int x, y;
		do {
			x = rand() % mapa3.getNColunas();
			y = rand() % mapa3.getNLinhas();

		} while (mapa3.getElemento(y, x) != 0);
		itens[nItens].Inicializar(mapa3.getPosX(y, x), mapa3.getPosY(y, x));
		nItens++;
	}

	//Atualizar todos
	for (int i = 0; i < nItens; i++)
	{
		itens[i].Atualizar();
	}
	//Desenha todos
	for (int i = 0; i < nItens; i++)
	{
		if (itens[i].getVivo() == true)
		{
			itens[i].Desenhar();
		}
	}
}

void TelaJogo3::ColisaoItens()
{
	if (GetEscolha() == 1)
	{
		for (int i = 0; i < nItens; i++)
		{
			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, itens[i].getSprite(), itens[i].getX(), itens[i].getY(), 0.0))
			{
				if (itens[i].getVivo() == true)
				{
					Rand = rand() % 3;
					if (Rand == 0)
					{
						bowser.vidaManager(200);
					}
					if (Rand == 1)
					{
						bowser.vidaManager(-200);
					}
					if (Rand == 2)
					{
						bowser.velManeger(0.1);
					}
					itens[i].setVivo(false);
				}
			}
		}
	}
	if (GetEscolha() == 2)
	{
		for (int i = 0; i < nItens; i++)
		{
			if (uniTestarColisao(peach.getSprite(), peach.getX(), peach.getY(), 0.0, itens[i].getSprite(), itens[i].getX(), itens[i].getY(), 0.0))
			{
				if (itens[i].getVivo() == true)
				{
					Rand = rand() % 3;
					if (Rand == 0)
					{
						peach.vidaManager(200);
					}
					if (Rand == 1)
					{
						peach.vidaManager(-200);
					}
					if (Rand == 2)
					{
						peach.velManeger(0.1);
					}
					itens[i].setVivo(false);
				}
			}
		}
	}
	if (GetEscolha() == 3)
	{
		for (int i = 0; i < nItens; i++)
		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, itens[i].getSprite(), itens[i].getX(), itens[i].getY(), 0.0))
			{
				if (itens[i].getVivo() == true)
				{
					Rand = rand() % 3;
					if (Rand == 0)
					{
						yoshi.vidaManager(200);
					}
					if (Rand == 1)
					{
						yoshi.vidaManager(-200);
					}
					if (Rand == 2)
					{
						yoshi.velManeger(0.1);
					}
					itens[i].setVivo(false);
				}
			}
		}
	}
	if (GetEscolha() == 4)
	{
		for (int i = 0; i < nItens; i++)
		{
			if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, itens[i].getSprite(), itens[i].getX(), itens[i].getY(), 0.0))
			{
				if (itens[i].getVivo() == true)
				{
					Rand = rand() % 3;
					if (Rand == 0)
					{
						luigi.vidaManager(200);
					}
					if (Rand == 1)
					{
						luigi.vidaManager(-200);
					}
					if (Rand == 2)
					{
						luigi.velManeger(0.1);
					}
					itens[i].setVivo(false);
				}
			}
		}
	}
	if (GetEscolha() == 5)
	{
		for (int i = 0; i < nItens; i++)
		{
			if (uniTestarColisao(mario.getSprite(), mario.getX(), mario.getY(), 0.0, itens[i].getSprite(), itens[i].getX(), itens[i].getY(), 0.0))
			{
				if (itens[i].getVivo() == true)
				{
					Rand = rand() % 3;
					if (Rand == 0)
					{
						mario.vidaManager(200);
					}
					if (Rand == 1)
					{
						mario.vidaManager(-200);
					}
					if (Rand == 2)
					{
						mario.velManeger(0.1);
					}
					itens[i].setVivo(false);
				}
			}
		}
	}
}


