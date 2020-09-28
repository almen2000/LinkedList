#pragma once
#include "LinkedList.h"
#include "IteratorException.h"

template <typename T>
class LinkedList<T>::iterator
{
private:
	node_pointer node_ptr_;
public:

	explicit iterator(node_pointer node_ptr) : node_ptr_(node_ptr)
	{
	}

	iterator& operator=(node_pointer node_ptr)
	{
		this->node_ptr_ = node_ptr;
		return *this;
	}

	iterator& operator=(const iterator& it)
	{
		this->node_ptr_ = it.node_ptr();
		return *this;
	}

	iterator& operator+(int index)
	{
		for (int i = 0; i < index; ++i, ++*this);
		return *this;
	}

	iterator& operator-(int index)
	{
		for (int i = 0; i < index; ++i, --*this);
		return *this;
	}

	iterator& operator++()
	{
		node_ptr_ = node_ptr_->next();
		return *this;
	}

	iterator operator++(int)
	{
		iterator it = *this;
		++*this;
		return it;
	}

	iterator& operator--()
	{
		node_ptr_ = node_ptr_->previous();
		return *this;
	}

	iterator operator--(int)
	{
		iterator it = *this;
		--*this;
		return it;
	}

	value_type operator*()
	{
		if (node_ptr_ == nullptr) throw IteratorException("trying dereference iterator with nullptr value");
		return node_ptr_->value();
	}

	node_pointer node_ptr() const
	{
		if (node_ptr_ == nullptr) throw IteratorException("trying to return node_ptr with nullptr value");
		return node_ptr_;
	}


	friend bool operator==(const iterator& lhs, const iterator& rhs)
	{
		return lhs.node_ptr_ == rhs.node_ptr_;
	}

	friend bool operator!=(const iterator& lhs, const iterator& rhs)
	{
		return !(lhs == rhs);
	}
};

template <typename T>
class LinkedList<T>::reverse_iterator
{
private:
	node_pointer node_ptr_;
public:

	explicit reverse_iterator(node_pointer node_ptr)
		: node_ptr_(node_ptr)
	{
	}

	reverse_iterator& operator=(node_pointer node_ptr)
	{
		this->node_ptr_ = node_ptr;
		return *this;
	}

	reverse_iterator& operator++()
	{
		node_ptr_ = node_ptr_->previous();
		return *this;
	}

	reverse_iterator operator++(int)
	{
		reverse_iterator it = *this;
		++*this;
		return it;
	}

	reverse_iterator& operator--()
	{
		node_ptr_ = node_ptr_->next();
		return *this;
	}

	reverse_iterator operator--(int)
	{
		reverse_iterator it = *this;
		--*this;
		return it;
	}

	value_type operator*()
	{
		if (node_ptr_ == nullptr) throw IteratorException("trying dereference iterator with nullptr value");
		return node_ptr_->value();
	}

	friend bool operator==(const reverse_iterator& lhs, const reverse_iterator& rhs)
	{
		return lhs.node_ptr_ == rhs.node_ptr_;
	}

	friend bool operator!=(const reverse_iterator& lhs, const reverse_iterator& rhs)
	{
		return !(lhs == rhs);
	}
};
