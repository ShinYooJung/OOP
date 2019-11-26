#include "json_object.h"

int json_object::index = 0;
json_object* json_object::parse(const char *aChar, int length){
	for(index = 0; index < length; index++){
		if( aChar == "'" || aChar == '"'){
			String::parse(aChar);
		}	
		else if(aChar == '['){
			json_dict::parse(aChar);
		}
	}
}
json_object* json_object::parse(const std::string& str){
	string::parse(str);
}

