#ifndef _j_VECTORFILE
#define _j_VECTORFILE

#include "Point.h"
#include <math.h>

namespace D3Struct 
{

	#define _j_doubleModule(a, b) ( (a > b)? a-b : b-a )
	#define _j_doubleEqual(a, b) ( ((a > b)? a-b : b-a) <0.0065?true:false)
	struct _minmaxvals { double vmin; double vmax;};
	_minmaxvals _getminmax(double val1, double val2, double val3) {
		double n[3];

		// sort simples
		if (val1 < val2) {
			n[0] = val1;
			n[1] = val2;
		}
		else {
			n[0] = val2;
			n[1] = val1;
		}

		if (val3 < n[1]) {
			if (val3 < n[0]) {
				n[2] = n[1];
				n[1] = n[0];
				n[0] = val3;
			}
			else {
				n[2] = n[1];
				n[1] = val3;
			}
		}
		else {
			n[2] = val3;
		}

		_minmaxvals ret;
		ret.vmin = n[0];
		ret.vmax = n[2];
		return ret;
	}



	class base3d;

	/// <summary>
	/// Estrutura de um vetor
	/// </summary>
	class vec3
	{
	protected:
		// uma base3d NULL é a base3d canônica
		base3d* _base3d;

	public:
		double x;
		double y;
		double z;

		/// <summary>
		/// Gera um vetor vazio
		/// </summary>s
		vec3()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
			this->_base3d = NULL;
		}


		/// <summary>
		/// Gera um vetor com coordenadas
		/// </summary>
		vec3(double x, double y, double z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->_base3d = NULL;
			return;
		}

		/// <summary>
		/// Cria um vetor com coordeanadas em uma base3d
		/// </summary>
		vec3(double x, double y, double z, base3d* base3d)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->_base3d = base3d;
		}

		/// <summary>
		/// Clona o vetor atual com os mesmos valores
		/// </summary>
		vec3 Clone()
		{
			vec3 ret{
				x = this->x,
				y = this->y,
				z = this->z
			};
			return ret;
		}

		/// <summary>
		/// Checa se este vetor é paralelo a target
		/// </summary>
		bool is_Parallel(vec3 target)
		{
			double factor_x = 0;
			double factor_y = 0;
			double factor_z = 0;
			if (this->x == 0 && this->y == 0 && this->z == 0 || target.x == 0 && target.y == 0 && target.z == 0)
			{
				return false; // Um ou mais vetores nulos
			}
			if (this->x >= target.x) factor_x = this->x / target.x;
			else factor_x = target.x / this->x;

			if (this->y >= target.y) factor_y = this->y / target.y;
			else factor_y = target.y / this->y;

			if (this->z >= target.z) factor_z = this->z / target.z;
			else factor_z = target.z / this->z;

			// problema da igualdade de pontos flutuantes
			_minmaxvals val = _getminmax(factor_x, factor_y, factor_z);
			bool ret = _j_doubleEqual(val.vmax, val.vmin);
			return ret;
		}

		/// <summary>
		/// Retorna se o vetor é um vetor nulo [0, 0]
		/// </summary>
		bool is_Null()
		{
			if (!this->x && !this->y && !this->z)
				return true;

			return false;
		}


		/// <summary>
		/// Soma um vetor ao vetor que chamou a função
		/// </summary>
		void sum_Vec(vec3 target)
		{
			this->x += target.x;
			this->y += target.y;
			this->z += target.z;
			return;
		}


		/// <summary>
		/// Soma um ponto ao vetor, virtualmente mesmo funcionamento de sum_Vec
		/// </summary>
		void sum_Point(point3 target)
		{
			//TODO
		}


		/// <summary>
		/// Retorna a base3d do vetor atual
		/// </summary>
		base3d* base_Get()
		{
			// uma base2d NULL é a base2d canônica
			return this->_base3d;
		}


		/// <summary>
		/// Aplica uma base3d ao vetor atual, realizando as mudanças necessárias
		/// </summary>
		/// <returns>Se foi realizada ou não</returns>
		bool base_Assign(base3d *target)
		{
			// TODO mudança de base3d
			return false;
		}


		/// <summary>
		/// Remove a base3d deste vetor, restaurando os valores ordinários
		/// </summary>
		/// <returns>Se foi realizada ou não</returns>
		bool base_Remove()
		{
			// TODO remoção de base
			return false;
		}
	};

}
#endif