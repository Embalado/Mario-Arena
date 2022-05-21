#include "TelaJogo2.h"



TelaJogo2::TelaJogo2()
{
}


TelaJogo2::~TelaJogo2()
{
}

void TelaJogo2::DesenharTela()
{
	fundo_Mapa2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	mapa2.Desenhar();
	ItensNascer();
	ColisaoItens();

		if (escolha == 1)
		{
			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0))
			{
				yoshi.Combate();
				bowser.Combater(-10);
				if (gTeclado.segurando[TECLA_ESPACO] && yoshi.getVivo() == true)
				{
					yoshi.Combater(-5);
				

					if (yoshi.getVida() <= 0)
					{
						yoshi.setVivo(false);
					}
				}
			}
			bowser.Atualizar();
			bowser.Desenhar();
			yoshi.Desenhar();
			yoshi.IA(bowser);
			txtVida.setString(to_string(bowser.getVida()));
			txtVida1.setString(to_string(yoshi.getVida()));

			if (bowser.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (escolha == 2)
		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
			{
				yoshi.Combate();
				peach.Combater(-10);
				if (gTeclado.segurando[TECLA_ESPACO] && yoshi.getVivo() == true)
				{
					peach.Combater(-10);
					yoshi.Combater(-7);

					if (yoshi.getVida() <= 0)
					{
						yoshi.setVivo(false);
					}
				}
			}
			peach.Atualizar();
			peach.Desenhar();
			yoshi.Desenhar();
			yoshi.IA(peach);
			txtVida.setString(to_string(peach.getVida()));
			txtVida1.setString(to_string(yoshi.getVida()));

			if (peach.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (escolha == 3)
		{
			if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0))
			{
				bowser.Combate();
				yoshi.Combater(-5);
				if (gTeclado.segurando[TECLA_ESPACO] && bowser.getVivo() == true)
				{
					
					bowser.Combater(-10);

					if (bowser.getVida() <= 0)
					{
						bowser.setVivo(false);
					}
				}
			}
			yoshi.Atualizar();
			yoshi.Desenhar();
			bowser.Desenhar();
			bowser.IA(yoshi);
			txtVida.setString(to_string(yoshi.getVida()));
			txtVida1.setString(to_string(bowser.getVida()));

		if (yoshi.getVida() <= 0)
		{
			SetProxMapa(2);
		}

		}
		if (escolha == 4)
		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0))
			{
				yoshi.Combate();
				luigi.Combater(-10);
				if (gTeclado.segurando[TECLA_ESPACO] && yoshi.getVivo() == true)
				{
					
					yoshi.Combater(-6);

					if (yoshi.getVida() <= 0)
					{
						yoshi.setVivo(false);
					}
				}
			}
			luigi.Atualizar();
			luigi.Desenhar();
			yoshi.Desenhar();
			yoshi.IA(luigi);
			txtVida.setString(to_string(luigi.getVida()));
			txtVida1.setString(to_string(yoshi.getVida()));

			if (luigi.getVida() <= 0)
			{
				SetProxMapa(2);
			}

		}
		if (escolha == 5)
		{
			if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
			{
				yoshi.Combate();
				mario.Combater(-10);
				if (gTeclado.segurando[TECLA_ESPACO] && yoshi.getVivo() == true)
				{
					
					yoshi.Combater(-8);

					if (yoshi.getVida() <= 0)
					{
						yoshi.setVivo(false);
					}
				}
			}
			mario.Atualizar();
			mario.Desenhar();
			yoshi.Desenhar();
			yoshi.IA(mario);
			txtVida.setString(to_string(mario.getVida()));
			txtVida1.setString(to_string(yoshi.getVida()));

			if (mario.getVida() <= 0)
			{
				SetProxMapa(2);
			}
		}

		if ((yoshi.getVivo() == false || bowser.getVivo() == false))
		{
			
				SetProxMapa(1);
			
		}

		txtVida.desenhar(300, 732);
		txtVida1.desenhar(600, 732);
		Vida.desenhar(450, 732);


	
	}


void TelaJogo2::CarregarBowser(string nomearq)
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
			float xPersonagem = iCol * mapa2.getLarguraTile() + mapa2.getLarguraTile() / 2;
			float yPersonagem = iLin * mapa2.getAlturaTile() + mapa2.getAlturaTile() / 2;
			int x, y;
			do {
				x = rand() % mapa2.getNColunas();
				y = rand() % mapa2.getNLinhas();

			} while (mapa2.getElemento(y, x) != 4);
			bowser.Inicializar(nomeSpr, (float)mapa2.getPosX(y, x), (float)mapa2.getPosY(y, x));
		}
		arqEntrada.close();
	}
}

void TelaJogo2::CarregarMario(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa2.getLarguraTile() + mapa2.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa2.getAlturaTile() + mapa2.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa2.getNColunas();
			y = rand() % mapa2.getNLinhas();

		} while (mapa2.getElemento(y, x) != 5);
		mario.Inicializar(nomeSpr, (float)mapa2.getPosX(y, x), (float)mapa2.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo2::CarregarPeach(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa2.getLarguraTile() + mapa2.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa2.getAlturaTile() + mapa2.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa2.getNColunas();
			y = rand() % mapa2.getNLinhas();

		} while (mapa2.getElemento(y, x) != 6);
		peach.Inicializar(nomeSpr, (float)mapa2.getPosX(y, x), (float)mapa2.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo2::CarregarLuigi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa2.getLarguraTile() + mapa2.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa2.getAlturaTile() + mapa2.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa2.getNColunas();
			y = rand() % mapa2.getNLinhas();

		} while (mapa2.getElemento(y, x) != 7);
		luigi.Inicializar(nomeSpr, (float)mapa2.getPosX(y, x), (float)mapa2.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo2::CarregarYoshi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa2.getLarguraTile() + mapa2.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa2.getAlturaTile() + mapa2.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa2.getNColunas();
			y = rand() % mapa2.getNLinhas();

		} while (mapa2.getElemento(y, x) != 3);
		yoshi.Inicializar(nomeSpr, (float)mapa2.getPosX(y, x), (float)mapa2.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo2::CarregarMapa()
{
	mapa2.Carregar("mapa2.txt");
	bowser.setMapa(&mapa2);
	luigi.setMapa(&mapa2);
	peach.setMapa(&mapa2);
	yoshi.setMapa(&mapa2);
	mario.setMapa(&mapa2);
}

void TelaJogo2::ItensNascer()
{
	if (nItens < MAX_ITENS)
	{
		int x, y;
		do {
			x = rand() % mapa2.getNColunas();
			y = rand() % mapa2.getNLinhas();

		} while (mapa2.getElemento(y, x) != 0);
		itens[nItens].Inicializar(mapa2.getPosX(y, x), mapa2.getPosY(y, x));
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

void TelaJogo2::ColisaoItens()
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

