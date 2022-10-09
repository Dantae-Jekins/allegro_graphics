#ifndef _j_OBJECTFILE
#define _j_OBJECTFILE

#include"../3D/Point.h";
#include"../3D/Vector.h";
using namespace D3Struct;

namespace Objects
{
	/// <summary>
	/// Template de um objeto f�sico
	/// </summary>
	class Shape
	{
	// ponteiros s�o protegidos para prevenir vazamentos
	protected:
		point3* pos;	//posi��o ou �ncora
		vec3* vel;		//velocidade
		vec3* acel;		//acelera��o


	public:
		bool frozen;	//congelado
		vec3 offset;    //offset da posi��o

		/// <summary>
		/// Gera um template de um objeto geom�trico
		/// </summary>
		Shape()
		{
			pos = nullptr;
			vel = nullptr;
			acel = nullptr;
			frozen = false;
			offset = vec3();
		}


		/// VELOCIDADE
		
		/// <summary>
		/// Aplica uma velocidade ao objeto
		/// </summary>
		void assign_Speed(vec3 *target)
		{
			this->vel = target;
		}

		/// <summary>
		/// Gera um vetor, aplica ele e retorna seu endere�o
		/// </summary>
		vec3 *assign_Speed(double x, double y, double z)
		{
			this->vel = new vec3(x, y, z);
			return this->vel;
		}

		/// <summary>
		/// Retorna o endere�o da velocidade
		/// </summary>
		vec3* get_Speed(double x, double y, double z)
		{
			return this->vel;
		}


		/// ACELERA��O
		
		/// <summary>
		/// Aplica uma acelera��o ao objeto
		/// </summary>
		void assign_Accel(vec3 *target)
		{
			this->acel = target;
		}

		/// <summary>
		/// Gera um vetor, aplica ele e retorna seu endere�o
		/// </summary>
		vec3 *assign_Accel(double x, double y, double z)
		{
			this->acel = new vec3();
			return this->acel;
		}

		/// <summary>
		/// Retorna o endere�o da acelera��o
		/// </summary>
		vec3 *get_Accel()
		{
			return this->acel;
		}
	};
}

#endif // !_j_OBJECTFILE
