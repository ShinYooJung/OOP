#include "vehicle.h"

class car: public vehicle{
	private:
	char* car_name;

	public:
        car(int wheelNum, int maxSpeed, char* carName);
        car(int wheelNum, int maxSpeed, char* carName, bool hasName);
        char* get_car_name(); 
        const char* get_class_name();
        void set_car_name(char* carName);

};
