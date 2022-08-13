#ifndef __RENDER_FILE
#define __RENDER_FILE
/*
	Arquivo feito para agrupar funções que renderizam os objetos de Object_Data e Player_Data
	serve como comunicação entre o allegro e estes outros 2 arquivos
*/
#include "Player_Data.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>


/// <summary>
/// Handle para renderizar
/// </summary>
class Handle_Render
{
private:
	Camera Camera;

public:
	//TODO
};


#endif // !__RENDER_FILE
