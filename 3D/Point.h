#ifndef _j_point3FILE
#define _j_point3FILE

namespace D3Struct
{

	/// <summary>
	/// Estrutura de um ponto no espaço
	/// </summary>
	class point3
	{
	public:
		double x;
		double y;
		double z;

		/// <summary>
		/// Gera um ponto
		/// </summary>
		point3()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		/// <summary>
		/// Gera um ponto com coordenadas
		/// </summary>
		point3(double x, double y, double z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		/// <summary>
		/// Copia um ponto
		/// </summary>
		point3 Clone()
		{
			point3 ret{
				x = this->x,
				y = this->y,
				z = this->z
			};

			return ret;
		}
	};
}
#endif