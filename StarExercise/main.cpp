#include<iostream>
#include "Star.h"
using namespace std;

int main() {
	int i, j;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

}