//201702032 ShinYooJung

#include "weak_pointer.h"

namespace ptr {
ptr::weak_pointer::weak_pointer() {
    // ptr을 default값으로 nullptr로 설정
    this->ptr = nullptr;
}

weak_pointer::weak_pointer(shared_ref &shared) {
    // shared의 get으로 student* 값을 ptr의 값으로 설정
    this->ptr = shared.get();
}

weak_pointer::weak_pointer(const weak_pointer &weak) {
    // weak의 ptr을 ptr값으로 설정
    this->ptr = weak.ptr;
}

int weak_pointer::is_expired() {
    // ptr_map에 자신의 ptr 값이 있는지 확인하고
    // ptr_map의 value인 mgr이 해제되었는지 확인
    // ptr_map에서 ptr을 관리하는 mgr이 있으면(nullptr이 아니면) 1 리턴
    if(ptr_map.count(this->ptr)){
    	if(ptr_map.find(this->ptr)->second != nullptr){
		return 0;
	}
    }
    return 1;
}

student *weak_pointer::get() {
    // ptr_map에서 ptr을 관리하는 mgr이 있으면(nullptr이 아니면) ptr을 리턴
    if(ptr_map.count(this->ptr)){
    	return this->ptr;
    }
    // 아닌 경우 nullptr 리턴
    else{
    	return nullptr;
    }
}

}
