#include "Jogo.h"

Jogo::Jogo()
{
	idTela = TELA_MENU;
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false);
	srand(time(0));

	//Carregar Mapas
	gRecursos.carregarSpriteSheet("fundo_Pause", "Assets/Sprites/Fundos/WindowSair.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_Salvar1", "Assets/Sprites/Botoes/ButtonSave1.png");
	gRecursos.carregarSpriteSheet("bt_Salvar2", "Assets/Sprites/Botoes/ButtonSave2.png");
	gRecursos.carregarSpriteSheet("bt_Salvar3", "Assets/Sprites/Botoes/ButtonSave3.png");
	fundo_Pause.setSpriteSheet("fundo_Pause");
	bt_Salvar1.setSpriteSheet("bt_Salvar1");
	bt_Salvar2.setSpriteSheet("bt_Salvar2");
	bt_Salvar3.setSpriteSheet("bt_Salvar3");

	//Tela Menu
	telaMenu.TelasInicializarMenus();
	telaControles.TelasInicializarMenus();
	telaCreditos.TelasInicializarMenus();
	telaSave.TelasInicializarMenus();
	telaPersonagens.TelasInicializarMenus();
	telaNivel.TelasInicializarMenus();
	telaGameOver.TelasInicializarMenus();
	telaVitoria.TelasInicializarMenus();
	//Tela Combate
	telaJogo0.TelasInicializarCombate();
	telaJogo1.TelasInicializarCombate();
	telaJogo2.TelasInicializarCombate();
	telaJogo3.TelasInicializarCombate();
	telaJogo4.TelasInicializarCombate();
	telaJogo0.CarregarMapa();
	telaJogo1.CarregarMapa();
	telaJogo2.CarregarMapa();
	telaJogo3.CarregarMapa();
	telaJogo4.CarregarMapa();
	//Musicas 
	menuMusica.InicializarMenu();
	jogoMusica.InicializarJogo();
	
//PilhaTelas
	pilhaTelas.push(&telaVitoria);
	pilhaTelas.push(&telaGameOver);
	pilhaTelas.push(&telaControles);
	pilhaTelas.push(&telaCreditos);
	pilhaTelas.push(&telaSave);
	pilhaTelas.push(&telaPersonagens);
	pilhaTelas.push(&telaMenu);

	//FilaTelas
	filaTelas.push(&telaJogo0);
	filaTelas.push(&telaNivel);
	filaTelas.push(&telaJogo1);
	filaTelas.push(&telaNivel);
	filaTelas.push(&telaJogo2);
	filaTelas.push(&telaNivel);
	filaTelas.push(&telaJogo3);
	filaTelas.push(&telaNivel);
	filaTelas.push(&telaJogo4);

	//ListaMusica
	menuMusica.SetProxTela(1);
	listaMusicas.push_front(&jogoMusica);
	listaMusicas.push_front(&menuMusica);
	listaMusicas.begin();
	listaMusicas.front()->Tocar();
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaMenu.getBotaoClicado()!= 8)
	{
		uniIniciarFrame();
	
		DesenharTelas();
		DesenharTelaJogo();
		uniTerminarFrame();
	}
}

//Funções de desenhar telas
void Jogo::DesenharTelas()
{
    switch (idTela)
	{
	case TELA_MENU:
		
		pilhaTelas.top()->DesenharTela();
		
	
	
		if (telaMenu.getBotaoClicado() == 1)
		{
			pilhaTelas.pop();
			telaMenu.setBotaoClicado(6);
			telaJogo0.SetProxMapa(6);
			menuMusica.SetProxTela(2);
			listaMusicas.front()->Tocar();
			idTela = TELA_PERSONAGEM;
		}
		if (telaMenu.getBotaoClicado() == 2)
		{
			telaMenu.setBotaoClicado(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			menuMusica.SetProxTela(2);
			listaMusicas.front()->Tocar();
			idTela = TELA_SAVES;	
		}
		if (telaMenu.getBotaoClicado() == 3)
		{
			telaMenu.setBotaoClicado(6);
			
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			menuMusica.SetProxTela(2);
			listaMusicas.front()->Tocar();
			idTela = TELA_CREDITOS;
		}
		if (telaMenu.getBotaoClicado() == 4)
		{
			telaMenu.setBotaoClicado(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			menuMusica.SetProxTela(2);
			listaMusicas.front()->Tocar();
			idTela = TELA_CONTROLES;
		}
		break;
	case TELA_CREDITOS:
		
		pilhaTelas.top()->DesenharTela();
		if (telaCreditos.getBotaoClicado() == 4)
		{
			
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);

			telaCreditos.setBotaoClicado(6);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;
		}

		break;
	case TELA_PERSONAGEM:
		
		pilhaTelas.top()->DesenharTela();
		
		if (telaPersonagens.getBotaoClicado() == 4)
		{
			pilhaTelas.push(&telaMenu);
			telaPersonagens.setBotaoClicado(6);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;
		}
		if (telaPersonagens.getBotaoClicado() == 10)
		{
			pilhaTelas.pop();
			telaPersonagens.setBotaoClicado(6);
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			nMapa = 0;
			aux = 1;
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
		}
		if (telaPersonagens.getBotaoClicado() == 11)
		{
			pilhaTelas.pop();
			telaPersonagens.setBotaoClicado(6);
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			nMapa = 0;
			aux = 2;
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
		}
		if (telaPersonagens.getBotaoClicado() == 12)
		{
			pilhaTelas.pop();
			telaPersonagens.setBotaoClicado(6);
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			nMapa = 0;
			aux = 3;
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
		}
		if (telaPersonagens.getBotaoClicado() == 13)
		{
			pilhaTelas.pop();
			telaPersonagens.setBotaoClicado(6);
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			nMapa = 0;
			aux = 4;
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
		}
		if (telaPersonagens.getBotaoClicado() == 14)
		{
			pilhaTelas.pop();
			telaPersonagens.setBotaoClicado(6);
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			nMapa = 0;
			aux = 5;
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
		}
			break;
	case TELA_CONTROLES:
	
		pilhaTelas.top()->DesenharTela();
		if (telaControles.getBotaoClicado() == 4)
		{
		pilhaTelas.push(&telaCreditos);
	     pilhaTelas.push(&telaSave);
	     pilhaTelas.push(&telaPersonagens);
		 pilhaTelas.push(&telaMenu);

		 telaControles.setBotaoClicado(6);
		 menuMusica.SetProxTela(1);
		 listaMusicas.front()->Tocar();
		 idTela = TELA_MENU;
		}
		break;
	case TELA_SAVES:
		
		pilhaTelas.top()->DesenharTela();
		if ((telaSave.getBotaoClicado() == 1))
		{
			telaSave.setBotaoClicado(6);
			
			Save = 0;
			CarregaSalvo(0);
			idTela = TELA_NMAPA;
		}
		if ((telaSave.getBotaoClicado() == 2))
		{
			
			telaSave.setBotaoClicado(6);
		
			Save = 1;
			CarregaSalvo(1);
			idTela = TELA_NMAPA;
		
		}
		if ((telaSave.getBotaoClicado() == 3))
		{
			telaSave.setBotaoClicado(6); 
			
			Save = 2;
			CarregaSalvo(2);
			idTela = TELA_NMAPA;
		}
		
		if (telaSave.getBotaoClicado() == 4)
		{
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			telaSave.setBotaoClicado(6);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;
		}
		break;
	case TELA_GAMEOVER:
		
		pilhaTelas.top()->DesenharTela();
		if (telaGameOver.getBotaoClicado() == 4)
		{
			pilhaTelas.pop();
			pilhaTelas.push(&telaVitoria);
			pilhaTelas.push(&telaGameOver);
			pilhaTelas.push(&telaControles);
			pilhaTelas.push(&telaCreditos);
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			telaGameOver.setBotaoClicado(6);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;
		}
		break;
	case TELA_VITORIA:
	
		pilhaTelas.top()->DesenharTela();
		if (telaVitoria.getBotaoClicado() == 4)
		{
			pilhaTelas.pop();
			pilhaTelas.push(&telaVitoria);
			pilhaTelas.push(&telaGameOver);
			pilhaTelas.push(&telaControles);
			pilhaTelas.push(&telaCreditos);
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			telaVitoria.setBotaoClicado(6);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;
		}
		break;
	}
}

void Jogo::DesenharTelaJogo()
{
	switch (idTela)
	{
	case TELA_JOGO0:

		filaTelas.front()->DesenharTela();
		BotoesOeP();


		if (telaJogo0.GetProxMapa() == 1)
		{
			filaTelas.pop();
			telaJogo1.SetProxMapa(6);
			telaNivel.SetProxTela(10);
			telaNivel.SetEscolha(1);
			aux = telaJogo0.GetEscolha();
			telaJogo1.SetEscolha(aux);

			telaJogo1.CarregarLuigi("Luigi.txt");
			telaJogo1.CarregarBowser("Bowser.txt");
			telaJogo1.CarregarPeach("Peach.txt");
			telaJogo1.CarregarYoshi("Yoshi.txt");
			telaJogo1.CarregarMario("Mario.txt");
			telaJogo1.ItensInicializar();
			telaJogo1.TelasInicializarCombate();
			jogoMusica.SetProxTela(6);
			listaMusicas.back()->Tocar();
			idTela = TELA_NIVEL;
		}
		if (telaJogo0.GetProxMapa() == 2)
		{
			telaJogo0.SetProxMapa(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			menuMusica.SetProxTela(3);
			listaMusicas.front()->Tocar();
			idTela = TELA_GAMEOVER;
		}
		break;

	case TELA_JOGO1:

		filaTelas.front()->DesenharTela();
		BotoesOeP();
		
			if (telaJogo1.GetProxMapa() == 1)
			{

				aux = telaJogo1.GetEscolha();
				telaJogo2.SetEscolha(aux);

				filaTelas.pop();
				telaNivel.SetProxTela(10);
				telaJogo2.SetProxMapa(6);
				telaNivel.SetEscolha(2);
				telaJogo2.CarregarLuigi("Luigi.txt");
				telaJogo2.CarregarBowser("Bowser.txt");
				telaJogo2.CarregarPeach("Peach.txt");
				telaJogo2.CarregarYoshi("Yoshi.txt");
				telaJogo2.CarregarMario("Mario.txt");
				telaJogo2.ItensInicializar();
				telaJogo2.TelasInicializarCombate();
				jogoMusica.SetProxTela(6);
				listaMusicas.back()->Tocar();
				idTela = TELA_NIVEL1;
			}
			if (telaJogo1.GetProxMapa() == 2)
			{
				telaJogo1.SetProxMapa(6);
				pilhaTelas.pop();
				pilhaTelas.pop();
				pilhaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.pop();
				filaTelas.push(&telaJogo0);
				filaTelas.push(&telaNivel);
				filaTelas.push(&telaJogo1);
				filaTelas.push(&telaNivel);
				filaTelas.push(&telaJogo2);
				filaTelas.push(&telaNivel);
				filaTelas.push(&telaJogo3);
				filaTelas.push(&telaNivel);
				filaTelas.push(&telaJogo4);
				menuMusica.SetProxTela(3);
				listaMusicas.front()->Tocar();
				idTela = TELA_GAMEOVER;
			}

			break;

	case TELA_JOGO2:

		filaTelas.front()->DesenharTela();
		BotoesOeP();

		if (telaJogo2.GetProxMapa() == 1)
		{
			aux = telaJogo2.GetEscolha();
			telaJogo3.SetEscolha(aux);

			filaTelas.pop();
			telaNivel.SetProxTela(10);
			telaJogo3.SetProxMapa(6);
			telaNivel.SetEscolha(3);
			telaJogo3.CarregarLuigi("Luigi.txt");
			telaJogo3.CarregarBowser("Bowser.txt");
			telaJogo3.CarregarPeach("Peach.txt");
			telaJogo3.CarregarYoshi("Yoshi.txt");
			telaJogo3.CarregarMario("Mario.txt");
			telaJogo3.ItensInicializar();
			telaJogo3.TelasInicializarCombate();
			jogoMusica.SetProxTela(6);
			listaMusicas.back()->Tocar();
			idTela = TELA_NIVEL2;
		}
		if (telaJogo2.GetProxMapa() == 2)
		{
			telaJogo2.SetProxMapa(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
		
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			menuMusica.SetProxTela(3);
			listaMusicas.front()->Tocar();
			idTela = TELA_GAMEOVER;
		}
		break;

	case TELA_JOGO3:

		filaTelas.front()->DesenharTela();
		BotoesOeP();

		if (telaJogo3.GetProxMapa() == 1)
		{

			telaJogo4.CarregarChefes();
			aux = telaJogo3.GetEscolha();
			telaJogo4.SetEscolha(aux);

			filaTelas.pop();
			telaNivel.SetProxTela(10);
			telaJogo4.SetProxMapa(6);
			telaNivel.SetEscolha(4);
			telaJogo4.CarregarLuigi("Luigi.txt");
			telaJogo4.CarregarBowser("Bowser.txt");
			telaJogo4.CarregarPeach("Peach.txt");
			telaJogo4.CarregarYoshi("Yoshi.txt");
			telaJogo4.CarregarMario("Mario.txt");
			telaJogo4.ItensInicializar();
			telaJogo4.TelasInicializarCombate();
			jogoMusica.SetProxTela(6);
			listaMusicas.back()->Tocar();
			idTela = TELA_NIVEL3;
		}
		if (telaJogo3.GetProxMapa() == 2)
		{
			telaJogo3.SetProxMapa(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			menuMusica.SetProxTela(3);
			listaMusicas.front()->Tocar();
			idTela = TELA_GAMEOVER;
		}
		break;

	case TELA_JOGO4:

		filaTelas.front()->DesenharTela();
		BotoesOeP();

		if (telaJogo4.GetProxMapa() == 1)
		{
			telaJogo4.SetProxMapa(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			menuMusica.SetProxTela(4);
			listaMusicas.front()->Tocar();
			idTela = TELA_VITORIA;
		}
		if (telaJogo4.GetProxMapa() == 2)
		{
			telaJogo4.SetProxMapa(6);
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
		
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			menuMusica.SetProxTela(3);
			listaMusicas.front()->Tocar();
			idTela = TELA_GAMEOVER;
		}
		break;

	case TELA_NIVEL:

		filaTelas.front()->DesenharTela();
		if (telaNivel.GetProxTela() == 1)
		{
			filaTelas.pop();
			jogoMusica.SetProxTela(2);
			listaMusicas.back()->Tocar();
			nMapa = 1;
			idTela = TELA_JOGO1;
		}

		if (telaNivel.GetProxTela() == 2)
		{
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.push(&telaVitoria);
			pilhaTelas.push(&telaGameOver);
			pilhaTelas.push(&telaControles);
			pilhaTelas.push(&telaCreditos);
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);

			telaNivel.SetProxTela(10);
			menuMusica.SetProxTela(1);
			listaMusicas.front()->Tocar();
			idTela = TELA_MENU;

		}
		break;
	case TELA_NIVEL1:

		filaTelas.front()->DesenharTela();
		if (telaNivel.GetProxTela() == 1)
		{
			filaTelas.pop();
			nMapa = 2;
			jogoMusica.SetProxTela(3);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO2;
		}

		if (telaNivel.GetProxTela() == 2)
		{
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.push(&telaVitoria);
			pilhaTelas.push(&telaGameOver);
			pilhaTelas.push(&telaControles);
			pilhaTelas.push(&telaCreditos);
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			telaNivel.SetProxTela(10);
			idTela = TELA_MENU;

		}
		break;
	case TELA_NIVEL2:

		filaTelas.front()->DesenharTela();
		if (telaNivel.GetProxTela() == 1)
		{
			nMapa = 3;
			filaTelas.pop();
			jogoMusica.SetProxTela(4);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO3;
		}


		if (telaNivel.GetProxTela() == 2)
		{
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.pop();
			pilhaTelas.push(&telaVitoria);
			pilhaTelas.push(&telaGameOver);
			pilhaTelas.push(&telaControles);
			pilhaTelas.push(&telaCreditos);
			pilhaTelas.push(&telaSave);
			pilhaTelas.push(&telaPersonagens);
			pilhaTelas.push(&telaMenu);
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			telaNivel.SetProxTela(10);
			idTela = TELA_MENU;
		}

		break;
	case TELA_NIVEL3:

		filaTelas.front()->DesenharTela();
		if (telaNivel.GetProxTela() == 1)
		{
			nMapa = 4;
			filaTelas.pop();
			jogoMusica.SetProxTela(5);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO4;
		}
		if (telaNivel.GetProxTela() == 2)
		{

			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
			telaNivel.SetProxTela(10);
			idTela = TELA_MENU;

		}

		break;
	case TELA_NMAPA:

		switch (nMapa)
		{
		case 0:
			telaJogo0.CarregarLuigi("Luigi.txt");
			telaJogo0.CarregarBowser("Bowser.txt");
			telaJogo0.CarregarPeach("Peach.txt");
			telaJogo0.CarregarYoshi("Yoshi.txt");
			telaJogo0.CarregarMario("Mario.txt");
			telaJogo0.ItensInicializar();
			telaJogo0.SetEscolha(aux);
			jogoMusica.SetProxTela(1);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO0;
			break;
		case 1:
			filaTelas.pop();
			filaTelas.pop();

			telaJogo1.CarregarLuigi("Luigi.txt");
			telaJogo1.CarregarBowser("Bowser.txt");
			telaJogo1.CarregarPeach("Peach.txt");
			telaJogo1.CarregarYoshi("Yoshi.txt");
			telaJogo1.CarregarMario("Mario.txt");
			telaJogo1.ItensInicializar();
			
			telaJogo1.SetEscolha(aux);
			jogoMusica.SetProxTela(2);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO1;
			break;
		case 2:
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();

			telaJogo2.CarregarLuigi("Luigi.txt");
			telaJogo2.CarregarBowser("Bowser.txt");
			telaJogo2.CarregarPeach("Peach.txt");
			telaJogo2.CarregarYoshi("Yoshi.txt");
			telaJogo2.CarregarMario("Mario.txt");
			telaJogo2.ItensInicializar();
			
			

			jogoMusica.SetProxTela(3);
			listaMusicas.back()->Tocar();
			telaJogo2.SetEscolha(aux);
			idTela = TELA_JOGO2;
			break;
		case 3:
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();

			telaJogo3.CarregarLuigi("Luigi.txt");
			telaJogo3.CarregarBowser("Bowser.txt");
			telaJogo3.CarregarPeach("Peach.txt");
			telaJogo3.CarregarYoshi("Yoshi.txt");
			telaJogo3.CarregarMario("Mario.txt");
			telaJogo3.ItensInicializar();

			
		
			telaJogo3.SetEscolha(aux);
			jogoMusica.SetProxTela(4);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO3;
			break;
		case 4:
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			
			telaJogo4.CarregarLuigi("Luigi.txt");
			telaJogo4.CarregarBowser("Bowser.txt");
			telaJogo4.CarregarPeach("Peach.txt");
			telaJogo4.CarregarYoshi("Yoshi.txt");
			telaJogo4.CarregarMario("Mario.txt");
			telaJogo4.CarregarChefes();
			telaJogo4.ItensInicializar();
			

			telaJogo4.SetEscolha(aux);
			jogoMusica.SetProxTela(5);
			listaMusicas.back()->Tocar();
			idTela = TELA_JOGO4;
			break;
		}

		break;
		}
	}




void Jogo::BotoesOeP()
{
	if (gTeclado.pressionou[TECLA_P])
	{
		pausou = !pausou;
	}
	if (pausou)
	{
		fundo_Pause.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	if (gTeclado.pressionou[TECLA_S] && pausou)
	{
		if (filaTelas.size() == 9)
		{
			ResetarPilha();

		}

		if (filaTelas.size() == 7)
		{
			ResetarPilha();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
		}

		if (filaTelas.size() == 5)
		{
			ResetarPilha();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
		}

		if (filaTelas.size() == 3)
		{
			ResetarPilha();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
		}

		if (filaTelas.size() == 1)
		{
			ResetarPilha();
			filaTelas.pop();
			filaTelas.push(&telaJogo0);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo1);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo2);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo3);
			filaTelas.push(&telaNivel);
			filaTelas.push(&telaJogo4);
		}
		menuMusica.SetProxTela(1);
		listaMusicas.front()->Tocar();
		idTela = TELA_MENU;
		pausou = false;
	}
	if (gTeclado.pressionou[TECLA_N] && pausou)
	{
		pausou = false;
	}
	if (gTeclado.pressionou[TECLA_O])
	{
		salvar = !salvar;
	}
	if (salvar)
	{
		bt_Salvar1.setPos(130, 100);
		bt_Salvar1.desenhar();
		bt_Salvar1.atualizar();

		bt_Salvar2.setPos(130, 200);
		bt_Salvar2.desenhar();
		bt_Salvar2.atualizar();

		bt_Salvar3.setPos(130, 300);
		bt_Salvar3.desenhar();
		bt_Salvar3.atualizar();

		if (bt_Salvar1.estaClicado())
		{
			

			SalvarJogo(0);
			salvar = !salvar;
		}
		if (bt_Salvar2.estaClicado())
		{

		;

			SalvarJogo(1);
			salvar = !salvar;
		}
		if (bt_Salvar3.estaClicado())
		{

		

			SalvarJogo(2);
			salvar = !salvar;
		}
	}
	
}

void Jogo::SalvarJogo(int e)
{
	ofstream ArqJogo;
	if (e == 0)
	{
		ArqJogo.open("Salvar.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.write(reinterpret_cast<const char*>(&nMapa), sizeof(int));
			ArqJogo.write(reinterpret_cast<const char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
	if (e == 1)
	{
		ArqJogo.open("Salvar1.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.write(reinterpret_cast<const char*>(&nMapa), sizeof(int));
			ArqJogo.write(reinterpret_cast<const char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
	if (e == 2)
	{
		ArqJogo.open("Salvar2.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.write(reinterpret_cast<const char*>(&nMapa), sizeof(int));
			ArqJogo.write(reinterpret_cast<const char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
}

void Jogo::CarregaSalvo(int e)
{
	ifstream ArqJogo;
	if (e == 0)
	{
		ArqJogo.open("Salvar.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.read(reinterpret_cast<char*>(&nMapa), sizeof(int));
			ArqJogo.read(reinterpret_cast<char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
	if (e == 1)
	{
		ArqJogo.open("Salvar1.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.read(reinterpret_cast<char*>(&nMapa), sizeof(int));
			ArqJogo.read(reinterpret_cast<char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
	if (e == 2)
	{
		ArqJogo.open("Salvar2.txt", ios::binary);
		if (ArqJogo)
		{
			ArqJogo.read(reinterpret_cast<char*>(&nMapa), sizeof(int));
			ArqJogo.read(reinterpret_cast<char*>(&aux), sizeof(int));
		}
		ArqJogo.close();
	}
}

void Jogo::ResetarPilha()
{
	pilhaTelas.pop();
	pilhaTelas.pop();
	pilhaTelas.pop();
	pilhaTelas.pop();
	pilhaTelas.push(&telaVitoria);
	pilhaTelas.push(&telaGameOver);
	pilhaTelas.push(&telaControles);
	pilhaTelas.push(&telaCreditos);
	pilhaTelas.push(&telaSave);
	pilhaTelas.push(&telaPersonagens);
	pilhaTelas.push(&telaMenu);
}



