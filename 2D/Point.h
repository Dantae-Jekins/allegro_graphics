#ifndef _j_POINTFILE
#define _j_POINTFILE

namespace D2Struct
{

	/// <summary>
	/// Estrutura de um ponto no espaço
	/// </summary>
	class Point
	{
	public:
		double x;
		double y;

		/// <summary>
		/// Gera um ponto
		/// </summary>
		Point()
		{
			this->x = 0;
			this->y = 0;
		}

		/// <summary>
		/// Gera um ponto com coordenadas
		/// </summary>
		Point(double x, double y)
		{
			this->x = x;
			this->y = y;
		}

		/// <summary>
		/// Copia um ponto
		/// </summary>
		Point Clone()
		{
			Point ret{
				x = this->x,
				y = this->y
			};

			return ret;
		}
	};
}
#endif