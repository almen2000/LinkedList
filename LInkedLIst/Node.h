#pragma once
template <typename T>
class Node
{
public:
	typedef T value_type;
	typedef T& reference_type;
	typedef T const& const_reference_type;
	typedef T* pointer_type;
	typedef T const* const_pointer_type;
private:
	value_type value_;
	Node* previous_;
	Node* next_;
public:
	// constructors
	Node();
	Node(const_reference_type value);
	Node(const_reference_type value, Node<T>* previous, Node<T>* next);

	// getters and setters
	value_type value() const;
	void set_value(reference_type value);
	Node<T>* next() const;
	void set_next(Node<T>* next);
	Node<T>* previous() const;
	void set_previous(Node<T>* previous);
};

