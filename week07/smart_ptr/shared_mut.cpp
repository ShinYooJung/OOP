//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();

}

void shared_mut::increase(){
	_mgr->count++;
}

Object* shared_mut::get() const {
	return _mgr->ptr;
}

void shared_mut::release() {
	_mgr->count--;
	if(_mgr->count <= 0){
		_mgr->~mgr();
		delete _mgr;
	}
}

int shared_mut::count() {
	return _mgr->count;
}

    shared_mut shared_mut::operator+(const shared_mut &shared){
	    
	    Object* newObj = new Object(get()->get() + shared.get()->get());
	    shared_mut newShared = shared_mut(newObj);
	    return newShared;
    }

    shared_mut shared_mut::operator-(const shared_mut &shared){
	    Object* newObj = new Object(get()->get() - shared.get()->get());
            shared_mut newShared = shared_mut(newObj);
            return newShared;
    }

    shared_mut shared_mut::operator*(const shared_mut &shared){
Object* newObj = new Object(get()->get() * shared.get()->get());
            shared_mut newShared = shared_mut(newObj);
            return newShared;
    }

    shared_mut shared_mut::operator/(const shared_mut &shared){
	    Object* newObj = new Object(get()->get() / shared.get()->get());
            shared_mut newShared = shared_mut(newObj);
            return newShared;    }

    Object* shared_mut::operator->(){
	    return _mgr->ptr;
    }

//    shared_mut operator+(unique_immut &unique);
//    shared_mut operator-(unique_immut &unique);
//    shared_mut operator*(unique_immut &unique);
//    shared_mut operator/(unique_immut &unique);
//    shared_mut&operator=(unique_immut &r);
    shared_mut& shared_mut::operator=(const shared_mut &r){
	    release();
	    _mgr = r._mgr;
	    increase();
	    return *this;
    }

} // end of namespace ptr
