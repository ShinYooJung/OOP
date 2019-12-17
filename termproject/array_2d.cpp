#include "array_2d.h"

array_2d::array_2d() {
	FALLING =  false;
}

//make new block randomly
bool array_2d::make() {
	int x = (rand() % 3)+1;
	int block_type = rand() % 3;
	if(block_type == 0){ //fold
		if(block_array[x-1][H-2] == nullptr 
				&& block_array[x][H-2] == nullptr 
				&& block_array[x][H-1] == nullptr)
		{
			insert(x-1, H-2,new block(rand()%4));
			insert(x, H-2,new block(rand()%4));
			insert(x, H-1,new block(rand()%4));
			block_type = 0;
			this->FALLING = true;
			
			return true;
		}
	}	
	else if(block_type == 1){ //tree
		 if(block_array[x][H-1] == nullptr 
				 && block_array[x][H-2] == nullptr 
				 && block_array[x][H-3] == nullptr)
		 {
                        insert(x, H-3,new block(rand()%4));
						insert(x, H-2,new block(rand()%4));
						insert(x, H-1,new block(rand()%4));
                	block_type = 1;
					this->FALLING = true;
			return true;
		 }

	}
	else { //cross
		 if(block_array[x-1][H-2] == nullptr 
				 && block_array[x][H-2] == nullptr 
				 && block_array[x][H-1] == nullptr
				 && block_array[x][H-3] == nullptr
				 && block_array[x+1][H-2] == nullptr)
		 {
            insert(x-1, H-2,new block(rand()%4));
            insert(x, H-3,new block(rand()%4));
			insert(x, H-2,new block(rand()%4));
			insert(x, H-1,new block(rand()%4));
			insert(x+1, H-2,new block(rand()%4));
			block_type = 2;
			this->FALLING = true;
			return true;
                }	
	}
	return false;
}

//update board
void array_2d::update(char input){
	if(input == 'a'){
		left();
	}
	else if(input == 'd'){
		right();
	}
	else if(input == 's'){
		gravity();
	}
	else if(input == 'x'){
		down_all();
	}
	else if(input == 'e'){
		turn();
	}
	else{
		gravity();
	}
}

void array_2d::left(){
	if(block_type == 0){
		
	}

	/*
	bool canLeft = true;
	for(block* i = falling_blocks.begin(); i != falling_blocks.end();i++){
		if(block_array[i.get_x-1][i.get_y] != nullptr){
			for(block* j = falling_blocks.begin(); j!= falling_blocks.end(); j++){
				if(block_array[i.get_x-1][i.get_y] != j){
					canLeft = false;
				}
			}
		}
	}
	if(canLeft){
		for(block* i = falling_blocks.begin(); i!= falling_blocks.end();i++){
			delete_block(i.get_x, i.get_y);
			insert(x-1,y,i);
		}
	}*/	
}

void array_2d::right(){

}

void array_2d::down_all(){
	while(FALLING){
		gravity();
	}
}

void array_2d::turn()
{
}

bool array_2d::isFalling(){
	return FALLING;
}

void array_2d::delete_block(int x, int y) {
	block *deleted = this->block_array[x][y];
	this->block_array[x][y] = nullptr;
	deleted->~block();
}

void array_2d::insert(int x, int y, block* b) {
	this->block_array[x][y] = b;
	b->set_location(x, y);
}

block *array_2d::get_block(int x, int y) {
	return this->block_array[x][y];
}

void array_2d::gravity(){
	bool isFalling = false;

        for (int i = 0; i < W; i++) {
                for (int j = 1; j < H; j++) {
                        if (block_array[i][j] != nullptr) {
                                if (block_array[i][j-1] == nullptr) {
									block_array[i][j - 1] = block_array[i][j];
									block_array[i][j] = nullptr;
									isFalling = true;
									
                                }
                        }
                }
        }
	if(!isFalling){
		FALLING = false;
	}
}

//print block_array
void array_2d::print() {
	printf("score: %d\n", get_score());
	for (int row = H-1; row >= 0; row--){
		for (int col = 0; col < W; col++){
			if(block_array[col][row]  == nullptr){
				printf(".");
			}
			else
			switch(block_array[col][row]->get_color()){
				case 0: //RED
					printf("R");
					break;
				case 1: //GREEN
					printf("G");
					break;
				case 2: //BLUE
					printf("B");
					break;
				case 3: //GREY
					printf("X");
			}
		}
		printf("\n");
	}	
	printf("\n");
}

/*
void array_2d::insert_explosion(color_block *group) {
	this->explosion_s.insert(group);
}

void array_2d::remove_explosion(color_block *group) {
	for (auto i : group->get_set()) {
		this->delete_block(*i->get_x,*i->get_y);
	}
	this->explosion_s.erase(group);

}
*/

//search for 4 of more block group
bool array_2d::can_explosion() {
	
	//if you find
	//insert_explosion();
	return false;
}

void array_2d::explosion() {
	if (can_explosion()) {
		
		this->score++;
	}
}

//getter of score
int array_2d::get_score() {
	return this->score;
}
