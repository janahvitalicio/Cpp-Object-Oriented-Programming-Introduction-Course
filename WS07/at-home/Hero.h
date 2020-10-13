/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 15, 2019 (Week 9, Workshop 7)
 **********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <ostream>

namespace sict {

	const int max_rounds = 100;
	const int max_name_size = 40;

	class Hero {
		/* Instance Variables Convention:
		 * jv == Janah Vitalicio
		 * jv_variableName
		 */
		char jv_name[max_name_size + 1];
		int jv_health;
		int jv_attack;

	public:
		Hero();
		Hero(const char*, int, int);

		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;

		const char* getName() const;

		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);

}

#endif
