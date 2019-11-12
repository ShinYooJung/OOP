#include "car.h"
	
car::car(int wheelNum, int maxSpeed, char* carName){
//      super(wheelNum,maxSpeed,true);
	set_wheel_number(wheelNum);
	set_max_speed(maxSpeed);
	set_has_name(true);

	set_car_name(carName);
}
car::car(int wheelNum, int maxSpeed, char* carName, bool hasName){
//	super(wheelNum,maxSpeed,hasName);
	set_wheel_number(wheelNum);
        set_max_speed(maxSpeed);
        set_has_name(hasName);

	set_car_name(carName);
}

char* car::get_car_name(){
	return car_name;
}
const char* car::get_class_name(){
	return "car";
}
void car::set_car_name(char* carName){
	this->car_name = carName;
}
