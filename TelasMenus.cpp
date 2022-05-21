#include "Telas.h"

Telas::Telas()
{
}

Telas::~Telas()
{
}

void Telas::MenusInicializar()
{
	
	
	//Carregar Sprites de Fundos
	gRecursos.carregarSpriteSheet("fundo_Menu", "Assets/Sprites/Fundos/Menu.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Pause", "Assets/Sprites/Fundos/WindowSair.png", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Saves", "Assets/Sprites/Fundos/Saves.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Personagens", "Assets/Sprites/Fundos/Personagens.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Creditos", "Assets/Sprites/Fundos/Creditos.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Controles", "Assets/Sprites/Fundos/ControlsScreen.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_GameOver", "Assets/Sprites/Fundos/GameOver.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa0", "Assets/Sprites/Fundos/BG1.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa1", "Assets/Sprites/Fundos/BG2.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa2", "Assets/Sprites/Fundos/BG4.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa3", "Assets/Sprites/Fundos/BG5.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_MapaChefe", "Assets/Sprites/Fundos/BGBOSS.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Vitoria", "Assets/Sprites/Fundos/VictoryScreen.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Nivel1", "Assets/Sprites/Fundos/Mapa1.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Nivel2", "Assets/Sprites/Fundos/Mapa2.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Nivel3", "Assets/Sprites/Fundos/Mapa3.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Nivel4", "Assets/Sprites/Fundos/Mapa4.jpg", 1, 1);

	//Carregar Sprites de Botões
	gRecursos.carregarSpriteSheet("bt_Jogar", "Assets/Sprites/Botoes/ButtonPlay.png");
	gRecursos.carregarSpriteSheet("bt_Continuar", "Assets/Sprites/Botoes/ButtonContinue.png");
	gRecursos.carregarSpriteSheet("bt_Creditos", "Assets/Sprites/Botoes/ButtonCredits.png");
	gRecursos.carregarSpriteSheet("bt_Sair", "Assets/Sprites/Botoes/ButtonExit.png");
	gRecursos.carregarSpriteSheet("bt_Controles", "Assets/Sprites/Botoes/ButtonControls.png");
	gRecursos.carregarSpriteSheet("bt_Carregar1", "Assets/Sprites/Botoes/ButtonSave1.png");
	gRecursos.carregarSpriteSheet("bt_Carregar2", "Assets/Sprites/Botoes/ButtonSave2.png");
	gRecursos.carregarSpriteSheet("bt_Carregar3", "Assets/Sprites/Botoes/ButtonSave3.png");
	gRecursos.carregarSpriteSheet("bt_Salvar1", "Assets/Sprites/Botoes/ButtonSave1.png");
	gRecursos.carregarSpriteSheet("bt_Salvar2", "Assets/Sprites/Botoes/ButtonSave2.png");
	gRecursos.carregarSpriteSheet("bt_Salvar3", "Assets/Sprites/Botoes/ButtonSave3.png");
	gRecursos.carregarSpriteSheet("bt_Voltar", "Assets/Sprites/Botoes/ButtonBack.png");
	gRecursos.carregarSpriteSheet("bt_per1", "Assets/Sprites/Botoes/ButtonBowser.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per2", "Assets/Sprites/Botoes/ButtonPeach.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per3", "Assets/Sprites/Botoes/ButtonYoshi.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per4", "Assets/Sprites/Botoes/ButtonLuigi.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per5", "Assets/Sprites/Botoes/ButtonMario.png", 1, 1);
	gRecursos.carregarSpriteSheet("chefes01", "Assets/Sprites/PiranhaIdle.png", 1, 4);
	gRecursos.carregarSpriteSheet("chefes02", "Assets/Sprites/MidBusIdle.png", 1, 13);
	gRecursos.carregarSpriteSheet("Vida", "Assets/Sprites/Vida.png", 1, 1);
	gRecursos.carregarSpriteSheet("TeclasJogo", "Assets/Sprites/Fundos/TeclasJogo.png", 1, 1);

	//Carregar fontes
	gRecursos.carregarFonte("fonte", "Assets/Fontes/fonte_padrao.ttf", 32);

	//Setar sprites de botões
	bt_Jogar.setSpriteSheet("bt_Jogar");
	bt_Sair.setSpriteSheet("bt_Sair");
	bt_Continuar.setSpriteSheet("bt_Continuar");
	bt_Creditos.setSpriteSheet("bt_Creditos");
	bt_Controles.setSpriteSheet("bt_Controles");

	//Setar textos
	txtVida.setFonte("fonte");
	txtVida.setAlinhamento(TEXTO_CENTRALIZADO);
	txtVida.setCor(255, 0, 0);

	//Setar Sprites de Fundos
	fundo_Menu.setSpriteSheet("fundo_Menu");
	fundo_Personagens.setSpriteSheet("fundo_Personagens");
	fundo_Creditos.setSpriteSheet("fundo_Creditos");
	fundo_Saves.setSpriteSheet("fundo_Saves");
	fundo_GameOver.setSpriteSheet("fundo_GameOver");
	fundo_Controles.setSpriteSheet("fundo_Controles");
	fundo_Mapa0.setSpriteSheet("fundo_Mapa0");
	fundo_Mapa1.setSpriteSheet("fundo_Mapa1");
	fundo_Mapa2.setSpriteSheet("fundo_Mapa2");
	fundo_Mapa3.setSpriteSheet("fundo_Mapa3");
	fundo_MapaChefe.setSpriteSheet("fundo_MapaChefe");
	fundo_Pause.setSpriteSheet("fundo_Pause");
	fundo_Vitoria.setSpriteSheet("fundo_Vitoria");
	fundo_Nivel1.setSpriteSheet("fundo_Nivel1");
	fundo_Nivel2.setSpriteSheet("fundo_Nivel2");
	fundo_Nivel3.setSpriteSheet("fundo_Nivel3");
	fundo_Nivel4.setSpriteSheet("fundo_Nivel4");

	Vida.setSpriteSheet("Vida");

	//Setar Sprites de Botões

	bt_Salvar1.setSpriteSheet("bt_Salvar1");
	bt_Salvar2.setSpriteSheet("bt_Salvar2");
	bt_Salvar3.setSpriteSheet("bt_Salvar3");
	bt_Carregar1.setSpriteSheet("bt_Carregar1");
	bt_Carregar2.setSpriteSheet("bt_Carregar2");
	bt_Carregar3.setSpriteSheet("bt_Carregar3");
	bt_Voltar.setSpriteSheet("bt_Voltar");
	bt_per1.setSpriteSheet("bt_per1");
	bt_per2.setSpriteSheet("bt_per2");
	bt_per3.setSpriteSheet("bt_per3");
	bt_per4.setSpriteSheet("bt_per4");
	bt_per5.setSpriteSheet("bt_per5");

	teclasJogo.setSpriteSheet("TeclasJogo");
}

void Telas::DesenharPrincipal()
{
		fundo_Menu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		//Botões do menu
		bt_Jogar.setPos(795, 400);
		bt_Jogar.desenhar();
		bt_Jogar.atualizar();

		bt_Continuar.setPos(795, 500);
		bt_Continuar.desenhar();
		bt_Continuar.atualizar();

		bt_Creditos.setPos(795, 600);
		bt_Creditos.desenhar();
		bt_Creditos.atualizar();

		bt_Sair.setPos(150, 650);
		bt_Sair.desenhar();
		bt_Sair.atualizar();

		bt_Controles.setPos(795, 700);
		bt_Controles.desenhar();
		bt_Controles.atualizar();

		if (bt_Jogar.estaClicado())
		{
			nMapa = 0;
			idTela = TELA_PERSONAGEM;
		}

		if (bt_Creditos.estaClicado())
		{
			idTela = TELA_CREDITOS;
		}

		if (bt_Controles.estaClicado())
		{
			idTela = TELA_CONTROLES;
		}

		if (bt_Continuar.estaClicado())
		{

			idTela = TELA_SAVES;
		}
}

void Telas::DesenharControles()
{
	fundo_Controles.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(130, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
		idTela = TELA_MENU;
	}
}

void Telas::DesenharCreditos()
{
	fundo_Creditos.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
	bt_Voltar.setPos(130, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

		if (bt_Voltar.estaClicado())
		{
	    }
}

void Telas::DesenharContinuar()
{
}

void Telas::DesenharPersonagens()
{
	fundo_Personagens.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Voltar.setPos(120, 750);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	bt_per1.setPos(865, 450);
	bt_per1.desenhar();
	bt_per1.atualizar();

	bt_per2.setPos(175, 450);
	bt_per2.desenhar();
	bt_per2.atualizar();

	bt_per3.setPos(720, 750);
	bt_per3.desenhar();
	bt_per3.atualizar();

	bt_per4.setPos(355, 750);
	bt_per4.desenhar();
	bt_per4.atualizar();

	bt_per5.setPos(520, 300);
	bt_per5.desenhar();
	bt_per5.atualizar();

	//Selecionar o personagem
	if (bt_per1.estaClicado())
	{
		escolha = 1;
		idTela = TELA_JOGO;
		CarregarBowser("Bowser.txt");
		CarregarLuigi("Luigi.txt");
		CarregarPeach("Peach.txt");
		CarregarYoshi("Yoshi.txt");
		CarregarMario("Mario.txt");
	}

	if (bt_per2.estaClicado())
	{
		escolha = 2;
		idTela = TELA_JOGO;
		CarregarPeach("Peach.txt");
		CarregarBowser("Bowser.txt");
		CarregarLuigi("Luigi.txt");
		CarregarYoshi("Yoshi.txt");
		CarregarMario("Mario.txt");
	}

	if (bt_per3.estaClicado())
	{
		escolha = 3;
		idTela = TELA_JOGO;
		CarregarLuigi("Luigi.txt");
		CarregarBowser("Bowser.txt");
		CarregarPeach("Peach.txt");
		CarregarYoshi("Yoshi.txt");
		CarregarMario("Mario.txt");
	}

	if (bt_per4.estaClicado())
	{
		escolha = 4;
		idTela = TELA_JOGO;
		CarregarYoshi("Yoshi.txt");
		CarregarBowser("Bowser.txt");
		CarregarLuigi("Luigi.txt");
		CarregarPeach("Peach.txt");
		CarregarMario("Mario.txt");
	}

	if (bt_per5.estaClicado())
	{
		escolha = 5;
		idTela = TELA_JOGO;
		CarregarMario("Mario.txt");
		CarregarBowser("Bowser.txt");
		CarregarLuigi("Luigi.txt");
		CarregarPeach("Peach.txt");
		CarregarYoshi("Yoshi.txt");

	}

	if (bt_Voltar.estaClicado())
	{
	}
}

void Telas::DesenharSaves()
{
	fundo_Saves.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bt_Carregar1.setPos(512, 150);
	bt_Carregar1.desenhar();
	bt_Carregar1.atualizar();

	bt_Carregar2.setPos(512, 300);
	bt_Carregar2.desenhar();
	bt_Carregar2.atualizar();

	bt_Carregar3.setPos(512, 450);
	bt_Carregar3.desenhar();
	bt_Carregar3.atualizar();

	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();
	CarregarBowser("Bowser.txt");
	CarregarLuigi("Luigi.txt");
	CarregarPeach("Peach.txt");
	CarregarYoshi("Yoshi.txt");
	CarregarMario("Mario.txt");

	if (bt_Voltar.estaClicado())
	{
		idTela = TELA_MENU;
	}
	if (bt_Carregar1.estaClicado())
	{

		CarregaSalvo(0);
		CarregarPer(0);
		chefes.CarregarPersonagem(0);
		idTela = TELA_MAPAS;
	}
	if (bt_Carregar2.estaClicado())
	{

		CarregaSalvo(1);
		CarregarPer(1);
		chefes.CarregarPersonagem(1);
		idTela = TELA_MAPAS;
	}
	if (bt_Carregar3.estaClicado())
	{

		CarregaSalvo(2);
		CarregarPer(2);
		chefes.CarregarPersonagem(2);
		idTela = TELA_MAPAS;
	}
}

void Telas::DesenharGameOver()
{
	fundo_GameOver.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
	}
}

void Telas::DesenharVitoria()
{
	fundo_Vitoria.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bt_Voltar.setPos(512, 700);
	bt_Voltar.desenhar();
	bt_Voltar.atualizar();

	if (bt_Voltar.estaClicado())
	{
	}
}
