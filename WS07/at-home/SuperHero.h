/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 15, 2019 (Week 9, Workshop 7)
 **********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
		int jv_bonus;
		int jv_defend;

	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;

	};

	const SuperHero& operator*(const SuperHero&, const SuperHero&);

}

#endif
