#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle{
	protected:	
		bool has_name;
		int wheel_number;
		int max_speed;

	public:
		vehicle();
		vehicle(int wheelNum,int maxSpeed);
		vehicle(int wheelNum,int maxSpeed,bool hasName);

		int get_wheel_number();
		int get_max_speed();
		bool get_has_name();
		const char* get_class_name();
		void set_wheel_number(int wheelNum);
      	 	void set_max_speed(int maxSpeed);
       		void set_has_name(bool hasName);
};

#endif
