#include "TelaJogo4.h"



TelaJogo4::TelaJogo4()
{
}


TelaJogo4::~TelaJogo4()
{
}

void TelaJogo4::DesenharTela()
{
		fundo_MapaChefe.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		mapa4.Desenhar();
		ItensNascer();
		ColisaoItens();
		chefes.Desenhar();
		chefes.Atualizar();
		

		if (GetEscolha() == 1)

		{
			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, chefes.getSprite(), chefes.getX(), chefes.getY(), 0.0))
			{
				if (gTeclado.segurando[TECLA_ESPACO] && chefes.getVivo() == true)
				{
					chefes.Combater(-6);
					bowser.Combater(-8);
					if (chefes.getVida() <=0)
					{
						chefes.setVivo(false);
					}
				}
			}
			bowser.Atualizar();
			bowser.Desenhar();
			
			txtVida.setString(to_string(bowser.getVida()));

			if (bowser.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (GetEscolha() == 2)

		{
			if (uniTestarColisao(peach.getSprite(), peach.getX(), peach.getY(), 0.0, chefes.getSprite(), chefes.getX(), chefes.getY(), 0.0))
			{
				if (gTeclado.segurando[TECLA_ESPACO] && peach.getVivo() == true)
				{
					chefes.Combater(-6);
					peach.Combater(-8);
				}
			}
			peach.Atualizar();
			peach.Desenhar();
			
			txtVida.setString(to_string(peach.getVida()));

			if (peach.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (GetEscolha() == 3)

		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, chefes.getSprite(), chefes.getX(), chefes.getY(), 0.0))
			{
				if (gTeclado.segurando[TECLA_ESPACO] && yoshi.getVivo() == true)
				{
					chefes.Combater(-6);
					yoshi.Combater(-8);
				}
			}
			yoshi.Atualizar();
			yoshi.Desenhar();
		
			txtVida.setString(to_string(yoshi.getVida()));

			if (yoshi.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (GetEscolha() == 4)

		{
			if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, chefes.getSprite(), chefes.getX(), chefes.getY(), 0.0))
			{
				if (gTeclado.segurando[TECLA_ESPACO] && luigi.getVivo() == true)
				{
					chefes.Combater(-6);
					luigi.Combater(-8);
				}
			}
			luigi.Atualizar();
			luigi.Desenhar();
			
			txtVida.setString(to_string(luigi.getVida()));

			if (luigi.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (GetEscolha() == 5)

		{
			if (uniTestarColisao(mario.getSprite(), mario.getX(), mario.getY(), 0.0, chefes.getSprite(), chefes.getX(), chefes.getY(), 0.0))
			{
				if (gTeclado.segurando[TECLA_ESPACO] && mario.getVivo() == true)
				{
					chefes.Combater(-6);
					mario.Combater(-8);
				}
			}
			mario.Atualizar();
			mario.Desenhar();
			
			txtVida.setString(to_string(mario.getVida()));


			if (mario.getVida() <= 0)
			{
				SetProxMapa(2);
			}
		}

		if (chefes.getVivo() == false)
		{
			SetProxMapa(1);
		}

		txtVida1.setString(to_string(chefes.getVida()));
		txtVida.desenhar(300, 732);
		txtVida1.desenhar(600, 732);
		Vida.desenhar(450, 732);
}

void TelaJogo4::CarregarBowser(string nomearq)
{
	{
		ifstream arqEntrada;
		arqEntrada.open(nomearq);
		if (arqEntrada)
		{
			string nomeSpr, nomeArq;
			int nAnim, nFrames, iLin, iCol;
			arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
			gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
			float xPersonagem = iCol * mapa4.getLarguraTile() + mapa4.getLarguraTile() / 2;
			float yPersonagem = iLin * mapa4.getAlturaTile() + mapa4.getAlturaTile() / 2;
			int x, y;
			do {
				x = rand() % mapa4.getNColunas();
				y = rand() % mapa4.getNLinhas();

			} while (mapa4.getElemento(y, x) != 4);
			bowser.Inicializar(nomeSpr, (float)mapa4.getPosX(y, x), (float)mapa4.getPosY(y, x));
		}
		arqEntrada.close();
	}
}

void TelaJogo4::CarregarMario(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{
		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa4.getLarguraTile() + mapa4.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa4.getAlturaTile() + mapa4.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa4.getNColunas();
			y = rand() % mapa4.getNLinhas();

		} while (mapa4.getElemento(y, x) != 5);
		mario.Inicializar(nomeSpr, (float)mapa4.getPosX(y, x), (float)mapa4.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo4::CarregarPeach(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa4.getLarguraTile() + mapa4.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa4.getAlturaTile() + mapa4.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa4.getNColunas();
			y = rand() % mapa4.getNLinhas();

		} while (mapa4.getElemento(y, x) != 6);
		peach.Inicializar(nomeSpr, (float)mapa4.getPosX(y, x), (float)mapa4.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo4::CarregarLuigi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa4.getLarguraTile() + mapa4.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa4.getAlturaTile() + mapa4.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa4.getNColunas();
			y = rand() % mapa4.getNLinhas();

		} while (mapa4.getElemento(y, x) != 7);
		luigi.Inicializar(nomeSpr, (float)mapa4.getPosX(y, x), (float)mapa4.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo4::CarregarYoshi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa4.getLarguraTile() + mapa4.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa4.getAlturaTile() + mapa4.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa4.getNColunas();
			y = rand() % mapa4.getNLinhas();

		} while (mapa4.getElemento(y, x) != 3);
		yoshi.Inicializar(nomeSpr, (float)mapa4.getPosX(y, x), (float)mapa4.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo4::CarregarMapa()
{
	mapa4.Carregar("mapa4.txt");
	bowser.setMapa(&mapa4);
	luigi.setMapa(&mapa4);
	peach.setMapa(&mapa4);
	yoshi.setMapa(&mapa4);
	mario.setMapa(&mapa4);
}

void TelaJogo4::CarregarChefes()
{
	int x, y;
	do {
		x = rand() % mapa4.getNColunas();
		y = rand() % mapa4.getNLinhas();

	} while (mapa4.getElemento(y, x) != 9);

	chefes.Inicializar(mapa4.getPosX(y, x), mapa4.getPosY(y, x));
}

void TelaJogo4::ItensNascer()
{
	if (nItens < MAX_ITENS)
	{
		int x, y;
		do {
			x = rand() % mapa4.getNColunas();
			y = rand() % mapa4.getNLinhas();

		} while (mapa4.getElemento(y, x) != 0);
		itens[nItens].Inicializar(mapa4.getPosX(y, x), mapa4.getPosY(y, x));
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

void TelaJogo4::ColisaoItens()
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

