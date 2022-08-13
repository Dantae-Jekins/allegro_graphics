#ifndef _j_VECTORFILE
#define _j_VECTORFILE

namespace D2Struct 
{

	#define _j_doubleModule(a, b) ( (a > b)? a-b : b-a )
	#define _j_doubleEqual(a, b) ( ((a > b)? a-b : b-a) <0.0065?true:false)

	class Base;
	/// <summary>
	/// Estrutura de um vetor
	/// </summary>
	class Vector
	{
	protected:
		// uma base NULL é a base canônica
		Base* _base;

	public:
		double x;
		double y;

		/// <summary>
		/// Gera um vetor vazio
		/// </summary>s
		Vector()
		{
			this->x = 0;
			this->y = 0;
			this->_base = NULL;
		}

		/// <summary>
		/// Gera um vetor com coordenadas
		/// </summary>
		Vector(double x, double y)
		{
			this->x = x;
			this->y = y;
			this->_base = NULL;
			return;
		}

		/// <summary>
		/// Cria um vetor com coordeanadas em uma base
		/// </summary>
		Vector(double x, double y, Base* base)
		{
			this->x = x;
			this->y = y;
			this->_base = base;
		}

		/// <summary>
		/// Clona o vetor atual com os mesmos valores
		/// </summary>
		Vector Clone()
		{
			Vector ret{
				x = this->x,
				y = this->y
			};
			return ret;
		}

		/// <summary>
		/// Soma um vetor ao vetor que chamou a função
		/// </summary>
		void vec_Sum(Vector target)
		{
			this->x += target.x;
			this->y += target.y;
			return;
		}

		/// <summary>
		/// Checa se
		/// </summary>
		bool vec_Parallel(Vector target)
		{
			double factor_x = 0;
			double factor_y = 0;
			if (this->x == 0 && this->y == 0 || target.x == 0 && target.y == 0)
			{
				return false; // Um ou mais vetores nulos
			}
			if (this->x >= target.x) factor_x = this->x / target.x;
			else factor_x = target.x / this->x;

			if (this->y >= target.y) factor_y = this->y / target.y;
			else factor_y = target.y / this->y;

			// problema da igualdade de pontos flutuantes
			bool ret = _j_doubleEqual(factor_x, factor_y);
			return ret;
		}

		/// <summary>
		/// Retorna a base do vetor atual
		/// </summary>
		Base* base_Get()
		{
			// uma base NULL é a base canônica
			return this->_base;
		}

		/// <summary>
		/// Aplica uma base ao vetor atual, realizando as mudanças necessárias
		/// </summary>
		/// <returns>Se foi realizada ou não</returns>
		bool base_Assign(Base *target)
		{
			// TODO! mudança de base
			return false;
		}

		bool base_Remove()
		{
			// TODO! remoção de base
			return false;
		}
	};

}
#endif