#include "json_dict.h"

void json_dict::put(json_object* key, json_object* val){

}

int json_dict::find(json_object* key){
	auto it = std::find(v.begin(), v.end(), key);
	int index = std::distance(v.begin(), it);
	return index;
}

json_dict::json_dict(){
}

json_object* json_dict::parse(const char *str, int length){
	int i = 0;
	if(str == '['){
		while(str[i] != ']'){
			i++;		
		}
		
	}else 
		return nullptr;
}

json_object* json_dict::operator[](json_object* key) const{

}

json_object* json_dict::operator[](const std::string& key) const{

}

json_object* json_dict::operator[](int key) const{

}

_type json_dict::type(){
	return DICT;
}

std::string json_dict::to_string(){
	for(iter i = v.begin(); i != v.end(); i++){

	}
}
