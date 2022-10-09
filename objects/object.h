#ifndef _j_OBJECTFILE
#define _j_OBJECTFILE

#include"../3D/Point.h";
#include"../3D/Vector.h";
using namespace D3Struct;

namespace Objects
{
	/// <summary>
	/// Template de um objeto físico
	/// </summary>
	class Shape
	{
	// ponteiros são protegidos para prevenir vazamentos
	protected:
		point3* pos;	//posição ou âncora
		vec3* vel;		//velocidade
		vec3* acel;		//aceleração


	public:
		bool frozen;	//congelado
		vec3 offset;    //offset da posição

		/// <summary>
		/// Gera um template de um objeto geométrico
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
		/// Gera um vetor, aplica ele e retorna seu endereço
		/// </summary>
		vec3 *assign_Speed(double x, double y, double z)
		{
			this->vel = new vec3(x, y, z);
			return this->vel;
		}

		/// <summary>
		/// Retorna o endereço da velocidade
		/// </summary>
		vec3* get_Speed(double x, double y, double z)
		{
			return this->vel;
		}


		/// ACELERAÇÃO
		
		/// <summary>
		/// Aplica uma aceleração ao objeto
		/// </summary>
		void assign_Accel(vec3 *target)
		{
			this->acel = target;
		}

		/// <summary>
		/// Gera um vetor, aplica ele e retorna seu endereço
		/// </summary>
		vec3 *assign_Accel(double x, double y, double z)
		{
			this->acel = new vec3();
			return this->acel;
		}

		/// <summary>
		/// Retorna o endereço da aceleração
		/// </summary>
		vec3 *get_Accel()
		{
			return this->acel;
		}
	};
}

#endif // !_j_OBJECTFILE
