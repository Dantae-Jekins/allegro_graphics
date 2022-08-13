#ifndef _j_BASEFILE
#define _j_BASEFILE

#include <list>
#include "Vector.h";

/// <summary>
/// Base de um vetor ou de um espaço vetorial
/// </summary>
namespace D2Struct
{
	class Base
	{
	protected:
		Vector v1;
		Vector v2;
		std::list<Vector*> space; // vetores com esta base

	public:
		/// <summary>
		/// Cria uma base com dois vetores linearmente independentes, se forem dependentes os vetores da base retornam nulos [0, 0]
		/// </summary>
		Base(Vector vec1, Vector vec2)
		{
			this->space.begin();

			// se são linearmente dependentes
			if (vec1.vec_Parallel(vec2))
			{
				this->v1;
				this->v2;
				return;
			}

			this->v1 = vec1.Clone();
			this->v2 = vec2.Clone();

			// remove a base dos vetores gerados
			// pela glória da simplicidade (sem cascata de bases)
			this->v1.base_Remove();
			this->v2.base_Remove();
			return;
		}

		void assign_Vector(Vector target)
		{ // TODO!!!
			this->space.push_front(&target);
		}

		void remove_Vector(Vector target)
		{ // TODO!!!
			this->space.remove(&target);
		}
	};
}
#endif // !_j_BASEFILE
