#include "vehicle.h"

vehicle::vehicle(){
	set_has_name(false);
}
vehicle::vehicle(int wheelNum,int maxSpeed){
        set_wheel_number(wheelNum);
	set_max_speed(maxSpeed);
}
vehicle::vehicle(int wheelNum,int maxSpeed,bool hasName){
		set_has_name(hasName);
                set_wheel_number(wheelNum);
                set_max_speed(maxSpeed);
}

        int vehicle::get_wheel_number(){
		return wheel_number;
	}
        int vehicle::get_max_speed(){
		return max_speed;
	}
        bool vehicle::get_has_name(){
		return has_name;
	}
        const char* vehicle::get_class_name(){
		return "vehicle";
	}
        void vehicle::set_wheel_number(int wheelNum){
		this->wheel_number = wheelNum;
	}
        void vehicle::set_max_speed(int maxSpeed){
		this->max_speed = maxSpeed;
	}
        void vehicle::set_has_name(bool hasName){
		this->has_name = hasName;
	}
