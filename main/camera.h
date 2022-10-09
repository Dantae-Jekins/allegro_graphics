#ifndef _j_CAMERAFILE
#define _j_CAMERAFILE

#include"../3D/Point.h";
#include"../objects/object.h";
#include<list>;

//ALLEGRO LIBS
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>


using D3Struct::point3;

/// <summary>
/// Arquivo que controla o render da aplicação
/// </summary>
class Camera
{
	private:
		// posição da câmera
		point3 *pos;
		// direção da câmera
		point3 orientation;

		int width;
		int height;

	public:
		/// <summary>
		/// Gera uma câmera default
		/// </summary>
		Camera()
		{
			width = 720;
			height = 480;
			pos = nullptr;
		}

		/// <summary>
		/// Aclopa a câmera à um ponto
		/// </summary>
		void assign_Position(point3 *point)
		{
			this->pos = point;
		}

		/// <summary>
		/// Altera as dimensões da câmera
		/// </summary>
		void assign_Size(int width, int height)
		{
			this->width = width;
			this->height = height;
		}
};

class Render
{
	private:
		// lista dos objetos que queremos renderizar
		static std::list<Objects::Shape> Shapes;
		static Camera camera;
};

#endif // !__CAMERAFILE
