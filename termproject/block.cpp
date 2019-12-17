#include "block.h"
//#include "color_block.h"

block::block(int color) {
	this->color = color;
}
block::~block(){

}

int block::get_color() {
	return this->color;
}
int block::get_x() {
	return this->x;
}
int block::get_y() {
	return this->y;
}
/*
void block::set_group(color_block *group) {
	this->group = group;
}
color_block *block::get_group() {
	return this->group;
}
*/
void block::set_location(int x, int y) {
	this->x = x;
	this->y = y;
}

bool block::can_left()
{
	return false;
}

bool block::can_right()
{
	return false;
}

bool block::can_down()
{
	return false;
}

void block::right()
{
	if (can_right()) {
		this->x++;
	}
}

void block::left()
{
	if (can_left()) {
		this->x--;
	}
}

void block::down()
{
	if (can_down()) {
		this->y--;
	}
}

void block::down_all()
{
	if (can_down()) {
		this->y = 0;
	}
}

bool block::can_merge(block * b)
{
	return false;
}

bool block::can_explosion(block * b)
{
	return false;
}

void block::merge(block * b)
{
	if (can_merge(b)) {
		find_merge();
	}
}

void block::find_merge()
{
}
