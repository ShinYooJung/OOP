#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "block.h"

#define W 5
#define H 12

class array_2d {

private:
	bool FALLING;
	int block_type;
	block* falling_blocks;	
	//std::set<color_block*> explosion_s;
	int score;

	//void insert_explosion(color_block *group);
    //void remove_explosion(color_block *group);
	
	void delete_block(int x, int y);
    void insert(int x, int y, block* b);

	void left();
	void right();
	void gravity();
	void down_all();
	void turn();

public:
	void update(char input);
	bool isFalling();

	block *block_array[W][H];

	array_2d();
	bool make();

	block *get_block(int x, int y);
	
	void print();
	bool can_explosion();
	void explosion();
	int get_score();
};
