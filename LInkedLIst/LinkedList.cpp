#include "LinkedList.h"
#include "Iterator.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	this->head_ = this->tail_ = nullptr;
	this->size_ = 0;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
	return iterator(head_);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
	return iterator(nullptr);
}

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin()
{
	return reverse_iterator(tail_);
}

template <typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend()
{
	return reverse_iterator(nullptr);
}

template <typename T>
bool LinkedList<T>::empty() const noexcept
{
	return !size_;
}

template <typename T>
unsigned LinkedList<T>::size() const noexcept
{
	return size_;
}

template <typename T>
typename LinkedList<T>::value_type LinkedList<T>::front()
{
	return head_->value();
}

template <typename T>
typename LinkedList<T>::value_type LinkedList<T>::back()
{
	return tail_->value();
}

template <typename T>
typename LinkedList<T>::value_type LinkedList<T>::get(const unsigned index)
{
	if (index > size_ || index < 0)
	{
		throw std::out_of_range("Index is out of range");
	}
	auto it = this->begin();
	it = it + index;
	return *it;
}

template <typename T>
void LinkedList<T>::push_front(const_reference_type val)
{
	if (tail_ == nullptr)
	{
		tail_ = new node_type(val);
		head_ = tail_;
	}
	else
	{
		node_pointer temp = new node_type(val);
		temp->set_next(head_);
		head_->set_previous(temp);
		head_ = head_->previous();
	}
	size_++;
}

template <typename T>
void LinkedList<T>::pop_front()
{
	if (!empty())
	{
		const node_pointer temp = head_;
		head_ = head_->next();
		if (head_ != nullptr) head_->set_previous(nullptr);
		delete temp;
		size_--;
	}
}

template <typename T>
void LinkedList<T>::push_back(const_reference_type val)
{
	if (head_ == nullptr)
	{
		head_ = new node_type(val);
		tail_ = head_;
	}
	else
	{
		node_pointer temp = new node_type(val);
		temp->set_previous(tail_);
		tail_->set_next(temp);
		tail_ = tail_->next();
	}
	size_++;
}

template <typename T>
void LinkedList<T>::pop_back()
{
	if (!empty())
	{
		const node_pointer temp = tail_;
		tail_ = tail_->previous();
		if (tail_ != nullptr) tail_->set_next(nullptr);
		delete temp;
		size_--;
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	node_pointer ptr = head_;
	while (ptr != nullptr)
	{
		node_pointer temp_ptr = ptr->next();
		delete ptr;
		ptr = temp_ptr;
	}
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator position, const_reference_type val)
{
	node_pointer current_ptr = position.node_ptr();
	node_pointer previous = current_ptr->previous();
	if (current_ptr == nullptr)
	{
		throw IteratorException("iterator in this position points to null pointer");
	}
	node_pointer new_ptr = new node_type(val, previous, current_ptr);
	previous->set_next(new_ptr);
	current_ptr->set_previous(new_ptr);
	++size_;
	--position;
	return position;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator position)
{
	node_pointer current_ptr = position.node_ptr();
	node_pointer previous = current_ptr->previous();
	node_pointer next = current_ptr->next();
	if (current_ptr == nullptr)
	{
		throw IteratorException("iterator in this position points to null pointer");
	}
	if (previous != nullptr)
	{
		previous->set_next(next);
	}
	if (next != nullptr)
	{
		next->set_previous(previous);
	}
	if (current_ptr == tail_)
	{
		tail_ = previous;
	}
	if (current_ptr == head_)
	{
		head_ = next;
	}
	delete current_ptr;
	position = next;
	--size_;
	return position;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}
