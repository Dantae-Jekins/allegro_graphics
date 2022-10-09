#ifndef _j_BASEFILE
#define _j_BASEFILE

#include <list>
#include "Vector.h";

/// <summary>
/// Base de duas dimensões de um vetor ou de um espaço vetorial
/// </summary>
namespace D3Struct
{
	class base3d
	{
	protected:
		vec3 v1;
		vec3 v2;
		std::list<vec3*> space; // vetores com esta base2d

	public:
		/// <summary>
		/// Cria uma base com dois vetores linearmente independentes, se forem dependentes os vetores da base retornam nulos [0, 0]
		/// </summary>
		base3d(vec3 vec1, vec3 vec2)
		{
			this->space.begin();

			// se são linearmente dependentes
			if (vec1.is_Parallel(vec2))
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


		/// <summary>
		/// Adiciona um vetor à lista desta base
		/// </summary>
		void assign_vec(vec3 *target)
		{ 
			// TODO
			// Se esta base for nula
			if (this->v1.is_Null() && this->v2.is_Null())
				return;

			if (target->base_Get() != this)
			{
				// o vetor não tem esta base, realiza a mudança
				target->base_Assign(this);
				this->space.push_front(target);
			}
			return;
		}

		/// <summary>
		/// Remove um vetor da lista desta base
		/// </summary>
		void remove_vec(vec3 *target)
		{ 
			if (target->base_Get() != this)
			{
				// o vetor não tem esta base
				return;
			}

			this->space.remove(target);
			return;
		}
	};
}
#endif // !_j_BASEFILE
