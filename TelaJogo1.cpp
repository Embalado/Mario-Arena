 #include "TelaJogo1.h"

TelaJogo1::TelaJogo1()
{
}

TelaJogo1::~TelaJogo1()
{
}

void TelaJogo1::DesenharTela()
{
	fundo_Mapa1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	mapa1.Desenhar();
	ItensNascer();
	ColisaoItens();
	if (GetEscolha() == 1)
			{
				if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
				{
					peach.Combate();
					bowser.Combater(-7);
					if (gTeclado.segurando[TECLA_ESPACO] && peach.getVivo() == true)
					{
						peach.Combater(-10);
						
						
						if (peach.getVida() <= 0)
						{
							peach.setVivo(false);
						}
					}
				}
				bowser.setMapa(&mapa1);
				bowser.Atualizar();
				bowser.Desenhar();
				peach.Desenhar();
				peach.IA(bowser);
				txtVida.setString(to_string(bowser.getVida()));
				txtVida1.setString(to_string(peach.getVida()));
		
				if (bowser.getVida() <= 0)
				{
					SetProxMapa(2);
				}
		
			}
			if (GetEscolha() == 2)
			{
				if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
				{
					bowser.Combate();
					peach.Combater(-5);
					if (gTeclado.segurando[TECLA_ESPACO] && bowser.getVivo() == true)
					{
						
						bowser.Combater(-7);
						
						if (bowser.getVida() <= 0)
						{
							bowser.setVivo(false);
						}
					}
				}
				peach.setMapa(&mapa1);
				peach.Atualizar();
				peach.Desenhar();
				bowser.Desenhar();
				bowser.IA(peach);
				txtVida.setString(to_string(peach.getVida()));
				txtVida1.setString(to_string(bowser.getVida()));
		
				if (peach.getVida() <= 0)
				{
					SetProxMapa(2);
				}
		
			}
			if (GetEscolha() == 3)
			{
				if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
				{
					peach.Combate();
					yoshi.Combater(-7);
					if (gTeclado.segurando[TECLA_ESPACO] && peach.getVivo() == true)
					{
						peach.Combater(-10);
						
						
						if (peach.getVida() <= 0)
						{
							peach.setVivo(false);
						}
					}
				}
				yoshi.setMapa(&mapa1);
				yoshi.Atualizar();
				yoshi.Desenhar();
				peach.Desenhar();
				peach.IA(yoshi);
				txtVida.setString(to_string(yoshi.getVida()));
				txtVida1.setString(to_string(peach.getVida()));
		
				if (yoshi.getVida() <= 0)
				{
					SetProxMapa(2);
				}
		
			}
			if (GetEscolha() == 4)
			{
				if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, peach.getSprite(), peach.getX(), peach.getY(), 0.0))
				{
					peach.Combate();
					luigi.Combater(-7);
					if (gTeclado.segurando[TECLA_ESPACO] && peach.getVivo() == true)
					{
						peach.Combater(-6);
						
						if (luigi.getVida() <= 0)
						{
							/*idTela = TELA_GAMEOVER;*/
						}
						if (peach.getVida() <= 0)
						{
							peach.setVivo(false);
						}
					}
				}
				luigi.setMapa(&mapa1);
				luigi.Atualizar();
				luigi.Desenhar();
				peach.Desenhar();
				peach.IA(luigi);
				txtVida.setString(to_string(luigi.getVida()));
				txtVida1.setString(to_string(peach.getVida()));
		
				if (luigi.getVida() <= 0)
				{
					SetProxMapa(2);
				}
		
			}
			if (GetEscolha() == 5)
			{
				if (uniTestarColisao(peach.getSprite(), peach.getX(), peach.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
				{
					peach.Combate();
					mario.Combater(-7);
				
					if (gTeclado.segurando[TECLA_ESPACO] && peach.getVivo() == true)
					{
						
						peach.Combater(-8);
						
						if (peach.getVida() <= 0)
						{
							peach.setVivo(false);
						}
					}
				}
				mario.setMapa(&mapa1);
				mario.Atualizar();
				mario.Desenhar();
				peach.Desenhar();
				peach.IA(mario);
				txtVida.setString(to_string(mario.getVida()));
				txtVida1.setString(to_string(peach.getVida()));
		
				if (mario.getVida() <= 0)
				{
					SetProxMapa(2);
				}

			}
			
			if ((peach.getVivo() == false || bowser.getVivo() == false))
			{
				
					SetProxMapa(1);
			}
		
			txtVida.desenhar(300, 732);
			txtVida1.desenhar(600, 732);
			Vida.desenhar(450, 732);
			
}

void TelaJogo1::CarregarBowser(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa1.getLarguraTile() + mapa1.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa1.getAlturaTile() + mapa1.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 4);
		bowser.Inicializar(nomeSpr, (float)mapa1.getPosX(y, x), (float)mapa1.getPosY(y, x));
	}
		arqEntrada.close();
	
}

void TelaJogo1::CarregarMario(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa1.getLarguraTile() + mapa1.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa1.getAlturaTile() + mapa1.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 5);
		mario.Inicializar(nomeSpr, (float)mapa1.getPosX(y, x), (float)mapa1.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo1::CarregarPeach(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa1.getLarguraTile() + mapa1.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa1.getAlturaTile() + mapa1.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 6);
		peach.Inicializar(nomeSpr, (float)mapa1.getPosX(y, x), (float)mapa1.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo1::CarregarLuigi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa1.getLarguraTile() + mapa1.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa1.getAlturaTile() + mapa1.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 7);
		luigi.Inicializar(nomeSpr, (float)mapa1.getPosX(y, x), (float)mapa1.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo1::CarregarYoshi(string nomearq)
{
	ifstream arqEntrada;
	arqEntrada.open(nomearq);
	if (arqEntrada)
	{

		string nomeSpr, nomeArq;
		int nAnim, nFrames, iLin, iCol;
		arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
		gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
		float xPersonagem = iCol * mapa1.getLarguraTile() + mapa1.getLarguraTile() / 2;
		float yPersonagem = iLin * mapa1.getAlturaTile() + mapa1.getAlturaTile() / 2;
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 3);
		yoshi.Inicializar(nomeSpr, (float)mapa1.getPosX(y, x), (float)mapa1.getPosY(y, x));
	}
	arqEntrada.close();
}

void TelaJogo1::CarregarMapa()
{
	mapa1.Carregar("mapa1.txt");
	bowser.setMapa(&mapa1);
	luigi.setMapa(&mapa1);
	peach.setMapa(&mapa1);
	yoshi.setMapa(&mapa1);
	mario.setMapa(&mapa1);
}

void TelaJogo1::ItensNascer()
{
	if (nItens < MAX_ITENS)
	{
		int x, y;
		do {
			x = rand() % mapa1.getNColunas();
			y = rand() % mapa1.getNLinhas();

		} while (mapa1.getElemento(y, x) != 0);
		itens[nItens].Inicializar(mapa1.getPosX(y, x), mapa1.getPosY(y, x));
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

void TelaJogo1::ColisaoItens()
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


