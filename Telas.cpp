#include "Telas.h"

Telas::Telas()
{
}

Telas::~Telas()
{
}

void Telas::TelasInicializarMenus()
{

	//Carregar Sprites de Fundos
	gRecursos.carregarSpriteSheet("fundo_Menu", "Assets/Sprites/Fundos/Menu.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Saves", "Assets/Sprites/Fundos/Saves.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Personagens", "Assets/Sprites/Fundos/Personagens.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Creditos", "Assets/Sprites/Fundos/Creditos.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Controles", "Assets/Sprites/Fundos/ControlsScreen.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_GameOver", "Assets/Sprites/Fundos/GameOver.jpg", 1, 1);
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
	gRecursos.carregarSpriteSheet("bt_Voltar", "Assets/Sprites/Botoes/ButtonBack.png");
	gRecursos.carregarSpriteSheet("bt_per1", "Assets/Sprites/Botoes/ButtonBowser.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per2", "Assets/Sprites/Botoes/ButtonPeach.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per3", "Assets/Sprites/Botoes/ButtonYoshi.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per4", "Assets/Sprites/Botoes/ButtonLuigi.png", 1, 1);
	gRecursos.carregarSpriteSheet("bt_per5", "Assets/Sprites/Botoes/ButtonMario.png", 1, 1);
	
	gRecursos.carregarSpriteSheet("TeclasJogo", "Assets/Sprites/Fundos/TeclasJogo.png", 1, 1);

	
	//Setar sprites de botões
	bt_Jogar.setSpriteSheet("bt_Jogar");
	bt_Sair.setSpriteSheet("bt_Sair");
	bt_Continuar.setSpriteSheet("bt_Continuar");
	bt_Creditos.setSpriteSheet("bt_Creditos");
	bt_Controles.setSpriteSheet("bt_Controles");

	//Setar Sprites de Fundos
	fundo_Menu.setSpriteSheet("fundo_Menu");
	fundo_Personagens.setSpriteSheet("fundo_Personagens");
	fundo_Creditos.setSpriteSheet("fundo_Creditos");
	fundo_Saves.setSpriteSheet("fundo_Saves");
	fundo_GameOver.setSpriteSheet("fundo_GameOver");
	fundo_Controles.setSpriteSheet("fundo_Controles");
	fundo_Vitoria.setSpriteSheet("fundo_Vitoria");
	fundo_Nivel1.setSpriteSheet("fundo_Nivel1");
	fundo_Nivel2.setSpriteSheet("fundo_Nivel2");
	fundo_Nivel3.setSpriteSheet("fundo_Nivel3");
	fundo_Nivel4.setSpriteSheet("fundo_Nivel4");

	//Setar Sprites de Botões
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

void Telas::TelasInicializarCombate()
{
	gRecursos.carregarSpriteSheet("bt_Continuar", "Assets/Sprites/Botoes/ButtonContinue.png");
	gRecursos.carregarSpriteSheet("fundo_Mapa0", "Assets/Sprites/Fundos/BG1.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa1", "Assets/Sprites/Fundos/BG2.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa2", "Assets/Sprites/Fundos/BG4.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_Mapa3", "Assets/Sprites/Fundos/BG5.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("fundo_MapaChefe", "Assets/Sprites/Fundos/BGBOSS.jpg", 1, 1);
	gRecursos.carregarSpriteSheet("chefes01", "Assets/Sprites/PiranhaIdle.png", 1, 4);
	gRecursos.carregarSpriteSheet("chefes02", "Assets/Sprites/MidBusIdle.png", 1, 13);
	gRecursos.carregarSpriteSheet("Vida", "Assets/Sprites/Vida.png", 1, 1);
	gRecursos.carregarSpriteSheet("item1", "Assets/Sprites/item1.png");
	gRecursos.carregarSpriteSheet("item2", "Assets/Sprites/item2.png");
	gRecursos.carregarSpriteSheet("item3", "Assets/Sprites/item3.png");

	//Carregar fontes
	gRecursos.carregarFonte("fonte", "Assets/Fontes/fonte_padrao.ttf", 32);
	bt_Continuar.setSpriteSheet("bt_Continuar");
	Vida.setSpriteSheet("Vida");

	//Setar textos
	txtVida.setFonte("fonte");
	txtVida.setAlinhamento(TEXTO_CENTRALIZADO);
	txtVida.setCor(255, 0, 0);

	txtVida1.setFonte("fonte");
	txtVida1.setAlinhamento(TEXTO_CENTRALIZADO);
	txtVida1.setCor(0, 255, 0);

	fundo_Mapa0.setSpriteSheet("fundo_Mapa0");
	fundo_Mapa1.setSpriteSheet("fundo_Mapa1");
	fundo_Mapa2.setSpriteSheet("fundo_Mapa2");
	fundo_Mapa3.setSpriteSheet("fundo_Mapa3");
	fundo_MapaChefe.setSpriteSheet("fundo_MapaChefe");
	
	
	


}

void Telas::DesenharTela()
{
}

void Telas::ItensNascer()
{
}

void Telas::CarregarBowser(string nomearq)
{
}

void Telas::CarregarMario(string nomearq)
{
}

void Telas::CarregarPeach(string nomearq)
{
}

void Telas::CarregarLuigi(string nomearq)
{
	
}

void Telas::CarregarYoshi(string nomearq)
{
}

void Telas::CarregarMapa()
{
}

void Telas::ItensInicializar()
{
	MAX_ITENS = rand() % 6;
	nItens = 0;
	itens = new Item[MAX_ITENS];
}

void Telas::SetEscolha(int escolha)
{
	this->escolha = escolha;
}

void Telas::SetProxMapa(int Prox)
{
	this->Prox = Prox;
}









