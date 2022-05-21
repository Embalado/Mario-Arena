#include "TelaJogo0.h"

TelaJogo0::TelaJogo0()
{
}
TelaJogo0::~TelaJogo0()
{
}

void TelaJogo0::DesenharTela()
{
	fundo_Mapa0.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);;
	mapa0.Desenhar();
	

	if (GetEscolha() == 1)
	{
		if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
		{
			mario.Combate();
			bowser.Combater(-8);
			if (gTeclado.segurando[TECLA_ESPACO] && mario.getVivo() == true)
			{
				mario.Combater(-5);
				

				if (mario.getVida() <= 0)
				{
					mario.setVivo(false);
				}
			}
		}
	bowser.setMapa(&mapa0);
	bowser.Atualizar();
	bowser.Desenhar();
	mario.Desenhar();
	mario.IA(bowser);

	
	txtVida.setString(to_string(bowser.getVida()));
	txtVida1.setString(to_string(mario.getVida()));

	if (bowser.getVida() <= 0)
	{
		SetProxMapa(2);
	}
      }
	if (GetEscolha() == 2)
	{
		if (uniTestarColisao(peach.getSprite(), peach.getX(), peach.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
		{
			mario.Combate();
			peach.Combater(-8);
			
			if (gTeclado.segurando[TECLA_ESPACO] && mario.getVivo() == true)
			{
				mario.Combater(-7);
				

				if (mario.getVida() <= 0)
				{
					mario.setVivo(false);
				}
			}
		}
		peach.setMapa(&mapa0);
		peach.Atualizar();
		peach.Desenhar();
		mario.Desenhar();
		mario.IA(peach);
		txtVida.setString(to_string(peach.getVida()));
		txtVida1.setString(to_string(mario.getVida()));

		if (peach.getVida() <= 0)
		{
			SetProxMapa(2);
		}
	}
	if (GetEscolha() == 3)
	{
		if (uniTestarColisao(yoshi.getSprite(), yoshi.getX(), yoshi.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
		{
			mario.Combate();
			yoshi.Combater(-8);
			
			if (gTeclado.segurando[TECLA_ESPACO] && mario.getVivo() == true)
			{
				mario.Combater(-10);
				

				if (mario.getVida() <= 0)
				{
					mario.setVivo(false);
				}
			}
		}
	    yoshi.setMapa(&mapa0);
		yoshi.Atualizar();
		yoshi.Desenhar();
		mario.Desenhar();
		mario.IA(yoshi);
		txtVida.setString(to_string(yoshi.getVida()));
		txtVida1.setString(to_string(mario.getVida()));

		if (yoshi.getVida() <= 0)
		{
			SetProxMapa(2);
		}
	}
		if (GetEscolha() == 4)
		{

			if (uniTestarColisao(luigi.getSprite(), luigi.getX(), luigi.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
			{
				mario.Combate();
				luigi.Combater(-8);
				if (gTeclado.segurando[TECLA_ESPACO] && mario.getVivo() == true)
				{
					mario.Combater(-6);
					

					if (mario.getVida() <= 0)
					{
						mario.setVivo(false);
					}
				}
			}
			luigi.setMapa(&mapa0);
			luigi.Atualizar();
			luigi.Desenhar();
			mario.Desenhar();
			mario.IA(luigi);
			txtVida.setString(to_string(luigi.getVida()));
			txtVida1.setString(to_string(mario.getVida()));

			if (luigi.getVida() <= 0)
			{
				SetProxMapa(2);
			}
		}

				if (GetEscolha() == 5)
				{
					if (uniTestarColisao(bowser.getSprite(), bowser.getX(), bowser.getY(), 0.0, mario.getSprite(), mario.getX(), mario.getY(), 0.0))
					{
						bowser.Combate();
						mario.Combater(-5);
						if (gTeclado.segurando[TECLA_ESPACO] && bowser.getVivo() == true)
						{
							
							bowser.Combater(-8);

							if (bowser.getVida() <= 0)
							{
								bowser.setVivo(false);
							}
						}
					}
					mario.setMapa(&mapa0);
					mario.Atualizar();
					mario.Desenhar();
					bowser.Desenhar();
					bowser.IA(mario);
					txtVida.setString(to_string(mario.getVida()));
					txtVida1.setString(to_string(bowser.getVida()));

					if (mario.getVida() <= 0)
					{
						SetProxMapa(2);
					}

					
				
				}
				if (mario.getVivo() == false || bowser.getVivo() == false)
				{
					SetProxMapa(1);
				}
				ItensNascer();
				ColisaoItens();
				txtVida.desenhar(300, 732);
				txtVida1.desenhar(600, 732);
				Vida.desenhar(450, 732);
		}

		void TelaJogo0::CarregarBowser(string nomearq)
		{
			ifstream arqEntrada;
			arqEntrada.open(nomearq);
			if (arqEntrada)
			{

				string nomeSpr, nomeArq;
				int nAnim, nFrames, iLin, iCol;
				arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
				gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
				float xPersonagem = iCol * mapa0.getLarguraTile() + mapa0.getLarguraTile() / 2;
				float yPersonagem = iLin * mapa0.getAlturaTile() + mapa0.getAlturaTile() / 2;
				int x, y;
				do {
					x = rand() % mapa0.getNColunas();
					y = rand() % mapa0.getNLinhas();

				} while (mapa0.getElemento(y, x) != 4);
				bowser.Inicializar(nomeSpr, (float)mapa0.getPosX(y, x), (float)mapa0.getPosY(y, x));
			}
			arqEntrada.close();
		}

		void TelaJogo0::CarregarMario(string nomearq)
		{
			ifstream arqEntrada;
			arqEntrada.open(nomearq);
			if (arqEntrada)
			{
				
					string nomeSpr, nomeArq;
					int nAnim, nFrames, iLin, iCol;
					arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
					gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
					float xPersonagem = iCol * mapa0.getLarguraTile() + mapa0.getLarguraTile() / 2;
					float yPersonagem = iLin * mapa0.getAlturaTile() + mapa0.getAlturaTile() / 2;
					int x, y;
					do {
						x = rand() % mapa0.getNColunas();
						y = rand() % mapa0.getNLinhas();

					} while (mapa0.getElemento(y, x) != 5);
					mario.Inicializar(nomeSpr, (float)mapa0.getPosX(y, x), (float)mapa0.getPosY(y, x));
			}
			arqEntrada.close();
		}

		void TelaJogo0::CarregarPeach(string nomearq)
		{
			ifstream arqEntrada;
			arqEntrada.open(nomearq);
			if (arqEntrada)
			{

				string nomeSpr, nomeArq;
				int nAnim, nFrames, iLin, iCol;
				arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
				gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
				float xPersonagem = iCol * mapa0.getLarguraTile() + mapa0.getLarguraTile() / 2;
				float yPersonagem = iLin * mapa0.getAlturaTile() + mapa0.getAlturaTile() / 2;
				int x, y;
				do {
					x = rand() % mapa0.getNColunas();
					y = rand() % mapa0.getNLinhas();

				} while (mapa0.getElemento(y, x) != 6);
				peach.Inicializar(nomeSpr, (float)mapa0.getPosX(y, x), (float)mapa0.getPosY(y, x));
			}
			arqEntrada.close();
		}

		void TelaJogo0::CarregarLuigi(string nomearq)
		{
			ifstream arqEntrada;
			arqEntrada.open(nomearq);
			if (arqEntrada)
			{
				
					string nomeSpr, nomeArq;
					int nAnim, nFrames, iLin, iCol;
					arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
					gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
					float xPersonagem = iCol * mapa0.getLarguraTile() + mapa0.getLarguraTile() / 2;
					float yPersonagem = iLin * mapa0.getAlturaTile() + mapa0.getAlturaTile() / 2;
					int x, y;
					do {
						x = rand() % mapa0.getNColunas();
						y = rand() % mapa0.getNLinhas();

					} while (mapa0.getElemento(y, x) != 7);
					luigi.Inicializar(nomeSpr, (float)mapa0.getPosX(y, x), (float)mapa0.getPosY(y, x));
			}
			arqEntrada.close();
		}

		void TelaJogo0::CarregarYoshi(string nomearq)
		{
			ifstream arqEntrada;
			arqEntrada.open(nomearq);
			if (arqEntrada)
			{

				
					string nomeSpr, nomeArq;
					int nAnim, nFrames, iLin, iCol;
					arqEntrada >> nomeSpr >> nomeArq >> nAnim >> nFrames >> iLin >> iCol;
					gRecursos.carregarSpriteSheet(nomeSpr, nomeArq, nAnim, nFrames);
					float xPersonagem = iCol * mapa0.getLarguraTile() + mapa0.getLarguraTile() / 2;
					float yPersonagem = iLin * mapa0.getAlturaTile() + mapa0.getAlturaTile() / 2;
					int x, y;
					do {
						x = rand() % mapa0.getNColunas();
						y = rand() % mapa0.getNLinhas();

					} while (mapa0.getElemento(y, x) != 3);
					yoshi.Inicializar(nomeSpr, (float)mapa0.getPosX(y, x), (float)mapa0.getPosY(y, x));
			}
			arqEntrada.close();
		}

		void TelaJogo0::CarregarMapa()
		{
			mapa0.Carregar("mapa0.txt");
			bowser.setMapa(&mapa0);
			luigi.setMapa(&mapa0);
			peach.setMapa(&mapa0);
			yoshi.setMapa(&mapa0);
			mario.setMapa(&mapa0);
		}

		void TelaJogo0::ItensNascer()
		{
			if (nItens < MAX_ITENS)
			{
				int x, y;
				do {
					x = rand() % mapa0.getNColunas();
					y = rand() % mapa0.getNLinhas();

				} while (mapa0.getElemento(y, x) != 0);
				itens[nItens].Inicializar(mapa0.getPosX(y, x), mapa0.getPosY(y, x));
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

		void TelaJogo0::ColisaoItens()
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
