#include <String.h>

String::String(const std::string& str){
	this->_val = 0;
}

std::string String::val(){
	return _val;
}
  
void String::set_val(const std::string& str){
	_val = str;
}

json_object* String::parse(const char *string, int length, char base){
	char *c = string;
	for(int i = 0; i < length; i++, c++){
		switch(string){
		case "{": 

		case '"':
		case '\0':
		case "'":

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		'6':
		'7':
		'8':
		'9':
		
		case '[':
		}
	}
}

_type String::type(){
	return STRING;
}
    
std::string String::to_string(){
	return _val;
}

