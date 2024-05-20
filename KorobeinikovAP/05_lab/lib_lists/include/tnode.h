#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>


template <typename T>
class TNode {
public:
	T data;
	TNode<T>* pNext;
	TNode() : data(), pNext(nullptr) {};
	TNode(const T& data_, TNode* pNext_ = nullptr) : data(data_), pNext(pNext_) { return; };
};


#endif 

