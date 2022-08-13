#ifndef PLAYER_DATA
#define PLAYER_DATA
/*
	Arquivo de agrupamento para funções do jogador
*/

//consts
#define PLAYER_HEIGHT 30
#define PLAYER_WIDTH 20

// blibiotecas
#include "2D/Vector.h"
#include "2D/Point.h"

using namespace D2Struct;

/// <summary>
/// Classe da câmera
/// </summary>
class Camera
{
public:
		Point Position;

		/// <summary>
		/// Gera uma câmera
		/// </summary>
		Camera() {
			this->Position;
		}

};

/// <summary>
/// Classe do jogador
/// </summary>
class Player {
	public:
		Point Pos;
		Camera Cam;

		/// <summary>
		/// Gera um jogador
		/// </summary>
		Player(void) {
			this->Cam;
			this->Pos;
			return;
		};
};

#endif // !PLAYER_DATA

