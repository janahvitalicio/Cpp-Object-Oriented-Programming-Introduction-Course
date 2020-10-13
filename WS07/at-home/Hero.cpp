/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 15, 2019 (Week 9, Workshop 7)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ostream>
#include <cstring>
#include <string.h>

#include "Hero.h"

using namespace std;

namespace sict {

	Hero::Hero() {
		jv_name[0] = '\0';
		jv_health = 0;
		jv_attack = 0;
	}

	Hero::Hero(const char *name, int health, int attack) {
		bool validName = name[0] != '\0' && name != nullptr;
		bool validHealth = health > 0;
		bool validAttack = attack > 0;

		if (validName && validHealth && validAttack) {
			strncpy(jv_name, name, max_name_size);
			jv_health = health;
			jv_attack = attack;
		}
		else {
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack) {
		if ((attack > 0) && (jv_health > 0)) {
			jv_health -= attack;

			if (jv_health < 0) {
				jv_health = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		bool alive = jv_health > 0;

		return alive;
	}

	int Hero::attackStrength() const {
		if (jv_attack > 0) {
			return this->jv_attack;
		}
		else {
			return 0;
		}
	}

	const char* Hero::getName() const {
		return this->jv_name;
	}

	// Friend function
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.jv_name[0] != '\0' || hero.jv_health > 0 || hero.jv_attack > 0) {
			os << hero.jv_name;
		}
		else {
			os << "No hero";
		}
		return os;
	}

	// Helper function
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero first_ = first;
		Hero second_ = second;
		Hero winner;
		int round = 0;
		int oneDied = 0;


		for (int i = 0; i < max_rounds && oneDied == 0; i++) {
			if (first_.isAlive() && second_.isAlive()) {
				first_ -= second_.attackStrength();
				second_ -= first_.attackStrength();
				round++;
			}

			if (!first_.isAlive() || !second_.isAlive()) {
				oneDied = 1; // Stop the for loop if one Hero dies
			}
		}

		// Draw
		if (!first_.isAlive() && !second_.isAlive()) {
			winner = first_;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}

		// First hero wins
		else if (!second_.isAlive()) {
			winner = first_;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return first;
		}

		// Second hero wins
		else if (!first_.isAlive()) {
			winner = second_;
			cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : Winner is "
				<< winner.getName() << " in " << round << " rounds." << endl;
			return second;
		}
		else {
			return first;
		}



	}



}