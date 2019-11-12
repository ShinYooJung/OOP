#include "bike.h"

bike::bike(int wheelNum, int maxSpeed, char* bikeName){
//	super(wheelNum,maxSpeed);
	set_wheel_number(wheelNum);
	set_max_speed(maxSpeed);

	set_bike_name(bikeName);
}
bike::bike(int wheelNum, int maxSpeed, char* bikeName, int bikeNum){
//	super(wheelNum,maxSpeed);
	set_wheel_number(wheelNum);
        set_max_speed(maxSpeed);

	set_bike_name(bikeName);
	set_bike_number(bikeNum);
}
bike::bike(int wheelNum, int maxSpeed, char* bikeName, int bikeNum, bool hasName){
//	super(wheelNum,maxSpeed,hasName);
	set_wheel_number(wheelNum);
        set_max_speed(maxSpeed);
	set_has_name(hasName);

	set_bike_name(bikeName);
	set_bike_number(bikeNum);
}
        
int bike::get_bike_number(){
	return bike_number;
}        
char* bike::get_bike_name(){
	return bike_name;
}
const char* bike::get_class_name(){
	return "bike";
}        
void bike::set_bike_name(char* bikeName){
	this->bike_name = bikeName;
}       
void bike::set_bike_number(int bikeNum){
	this->bike_number = bikeNum;
}
