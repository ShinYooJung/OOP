#include "vehicle.h"

class bike: public vehicle{
	private:
	char* bike_name;
	int bike_number;

	public:
       	bike(int wheelNum, int maxSpeed, char* bikeName);
       	bike(int wheelNum, int maxSpeed, char* bikeName, int bikeNum);
       	bike(int wheelNum, int maxSpeed, char* bikeName, int bikeNum, bool hasName);

	int get_bike_number();
       	char* get_bike_name();
	const char* get_class_name();
	void set_bike_name(char* bikeName);
       	void set_bike_number(int bikeName);

};

