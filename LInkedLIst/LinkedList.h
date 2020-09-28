#pragma once
#include "Node.h"
#include "Node.cpp"

template <typename T>
class LinkedList
{
private:
	typedef Node<T> node_type;
	typedef node_type* node_pointer;
public:
	typedef typename node_type::value_type value_type;
	typedef typename node_type::reference_type reference_type;
	typedef typename node_type::const_reference_type const_reference_type;
	typedef typename node_type::pointer_type pointer_type;
	typedef typename node_type::const_pointer_type const_pointer_type;
	class iterator;
	class reverse_iterator;
private:
	node_pointer head_;
	node_pointer tail_;
	unsigned size_{};
public:
	// constructor
	LinkedList();
	
	// iterators
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity
	bool empty() const noexcept;
	unsigned size() const noexcept;

	// element access
	value_type front();
	value_type back();
	value_type get(unsigned index);

	// modifiers
	void push_front(const_reference_type val);
	void pop_front();
	void push_back(const_reference_type val);
	void pop_back();
	void clear();
	iterator insert(iterator position, const_reference_type val);
	iterator erase(iterator position);
	
	// destructor
	~LinkedList();
};