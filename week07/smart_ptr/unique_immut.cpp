//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const{
	return _mgr->ptr;
}

void unique_immut::release(){
	if(_mgr->ptr != nullptr){
		delete _mgr;
	}
}

unique_immut unique_immut::operator+(unique_immut &unique){
	Object* newObj = new Object(get()->get() + unique.get()->get());
	unique_immut newUnique = unique_immut(newObj);
	release();
	unique.release();
	return newUnique;
}

unique_immut unique_immut::operator-(unique_immut &unique){
	Object* newObj = new Object(get()->get() - unique.get()->get());
        unique_immut newUnique = unique_immut(newObj);
        release();
        unique.release();
        return newUnique;
}

unique_immut unique_immut::operator*(unique_immut &unique){
	Object* newObj = new Object(get()->get() * unique.get()->get());
        unique_immut newUnique = unique_immut(newObj);
        release();
        unique.release();
        return newUnique;

}

unique_immut unique_immut::operator/(unique_immut &unique){
	Object* newObj = new Object(get()->get() / unique.get()->get());
        unique_immut newUnique = unique_immut(newObj);
        release();
        unique.release();
        return newUnique;

}

Object* unique_immut::operator->(){
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r){
	if(this == &r) 
		return *this;
	release();
	*this = r;
	return *this;
}

} // end of namespace ptr
