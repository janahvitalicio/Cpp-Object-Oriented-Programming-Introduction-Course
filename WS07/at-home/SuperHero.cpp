/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 15, 2019 (Week 9, Workshop 7)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero() : Hero() {
		jv_bonus = 0;
		jv_defend = 0;
	}

	SuperHero::SuperHero(const char *name, int health, int attack, int bonus, int defend)
	: Hero(name, health, attack) {
		jv_bonus = bonus;
		jv_defend = defend;
	}

	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() > 0) {
			int attack = Hero::attackStrength() + jv_bonus;
			return attack;
		}
		else {
			return 0;
		}
	}

	int SuperHero::defend() const {
		if (jv_defend > 0) {
			return jv_defend;
		}
		else {
			return 0;
		}
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero first_ = first;
		SuperHero second_ = second;
		SuperHero winner;
		int round = 0;
		int oneDied = 0;


		for (int i = 0; i < max_rounds && oneDied == 0; i++) {
			if (first_.isAlive() && second_.isAlive()) {
				first_ -= second_.attackStrength() - first_.defend();
				second_ -= first_.attackStrength() - second_.defend();
				round++;
			}

			if (!first_.isAlive() || !second_.isAlive()) {
				oneDied = 1; // Stop the for loop if one Hero dies
			}
		}

		// Draw
		if (!first_.isAlive() && !second_.isAlive()) {
			winner = first_;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}

		// First superhero wins
		else if (!second_.isAlive()) {
			winner = first_;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}

		// Second superhero wins
		else if (!first_.isAlive()) {
			winner = second_;
			cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return second;
		}
		else {
			return first;
		}
	}
}