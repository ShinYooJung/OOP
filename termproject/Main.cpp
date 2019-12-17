#include <stdio.h>
#include <iostream>
#include <ctime>
#include "array_2d.h"

int main() {
	printf("START\n\n");	
	srand((unsigned int)time(0));

	array_2d *board = new array_2d();
		while (board->make()) {
			board->print();
			while (board->isFalling()) {
				char input = getchar();
				board->update(input);
				board->print();
			}
		}

		printf("\nscore: %d\n", board->get_score());
		printf("END");
	
	
	
	return 0;
}
