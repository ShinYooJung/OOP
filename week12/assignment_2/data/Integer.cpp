#include "Integer.h"

Integer::Integer(int value){
	this->_val = value;
}

int Integer::val(){
	return _val;
}

void Integer::set_val(const int& value){
	_val = value;
}

json_object* Integer::parse(const char *str, int length){
	_val = atoi(str.c_str());
	json_object::parse(str,length);
}
    
_type Integer::type(){
	return INTEGER;
}
    
std::string String::to_string(){
	return std::to_string(_val);
}

