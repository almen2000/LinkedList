#include "Node.h"

template <typename T>
Node<T>::Node()
{
	next_ = nullptr;
	previous_ = nullptr;
};

template <typename T>
Node<T>::Node(const_reference_type value) : value_(value)
{
	next_ = nullptr;
	previous_ = nullptr;
}

template <typename T>
Node<T>::Node(const_reference_type value, Node<T>* previous, Node<T>* next):
	value_(value),
	previous_(previous),
	next_(next)
{
}

template <typename T>
typename Node<T>::value_type Node<T>::value() const
{
	return value_;
}

template <typename T>
void Node<T>::set_value(reference_type value)
{
	value_ = value;
}

template <typename T>
Node<T>* Node<T>::next() const
{
	return next_;
}

template <typename T>
void Node<T>::set_next(Node<T>* next)
{
	next_ = next;
}

template <typename T>
Node<T>* Node<T>::previous() const
{
	return previous_;
}

template <typename T>
void Node<T>::set_previous(Node<T>* previous)
{
	previous_ = previous;
}
