//201702032 ShinYooJung

#include "shared_ref.h"

namespace ptr {
shared_ref::shared_ref() {
    // _mgr의 default 값을 빈 mgr으로 설정
    this->_mgr = new mgr();
}

shared_ref::shared_ref(student* student) {
    // ptr_map에 student의 주소가 있으면 _mgr을 빈 mgr으로 설정
    if(ptr_map.count(student)){
	    this->_mgr = new mgr();
    }
    // ptr_map에 student의 주소가 없으면 _mgr을 student의 메모리를 관리하는 mgr으로 설정하고
    else{
	_mgr = new mgr(student);	
    }
    // ptr_map에 key를 student의 주소로 하고 value를 mgr로 등록 ==> student의 주소가 shared_ref의 mgr로 관리되는지 확인 가능
}

shared_ref::shared_ref(const shared_ref& shared) {
    // shared_ref 의 _mgr을 자신의 _mgr로 설정
    this->_mgr = shared._mgr;
    // reference가 증가하였으므로 increase 호출
    increase();
}

shared_ref::~shared_ref() {
    // mgr을 반환하는 release를 호출하게 만듦
	release();
}

void shared_ref::release() {
    // _mgr이 nullptr일 경우 아무 작업도 하지 않음
    if(_mgr == nullptr){}
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 감소시키고
    else{
	_mgr->count--;
    // count가 0인 경우 ptr_map에서 _mgr의 ptr가 key인 value를 nullptr로 설정하고 _mgr을 delete함
    	if(_mgr->count == 0){
		ptr_map.find(_mgr->ptr)->second = nullptr;
		delete _mgr;
    	}
    // ==> student 포인터에 대해 mgr 관리가 끝났음을 알려줌

    }
}

student *shared_ref::get() const {
    // _mgr이 nullptr일 경우 nullptr 반환하고
    if(this->_mgr == nullptr){
	    return nullptr;
    }
    // _mgr이 nullptr가 아닐 경우 _mgr의 ptr을 return 하도록 구현
    else{
	return _mgr->ptr;
    }
}

void shared_ref::increase() {
    // _mgr이 nullptr일 경우 아무런 작업도 하지 않음
    if(this->_mgr == nullptr){
    }
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 증가시킴
    else{
    	this->_mgr->count++;
    }
}

shared_ref &shared_ref::operator=(const shared_ref &r) {
    // r의 주소가 this와 같은 경우 아무런 작업도 하지 않고 *this를 리턴
    // ex: a = a;
    // r의 주소가 this와 다른 경우 현재 _mgr을 release하고 r의 _mgr을 this의 _mgr로 설정. 그 후 increase
    // ex: b = a; -> a의 값을 가리키는 것이 a와 b 두 값이 됨
    if(this != &r){
    	release();
	this->_mgr = r._mgr;
	increase();
    }
    return *this;
}

student *shared_ref::operator->() {
    // _mgr이 nullptr일 경우 nullptr 반환
    if(this->_mgr == nullptr){
	    return nullptr;
    }
    // _mgr이 nullptr가 아닐 경우 _mgr의 ptr을 반환
    else{
	    return this->_mgr->ptr;
    }
}

int shared_ref::count() {
    // _mgr이 nullptr일 경우 0을 반환
    if(this->_mgr == nullptr){
	    return 0;
    }
    // _mgr이 nullptr가 아닐 경우 _mgr의 count를 반환
    else{
    	return this->_mgr->count;
    }
}

}
