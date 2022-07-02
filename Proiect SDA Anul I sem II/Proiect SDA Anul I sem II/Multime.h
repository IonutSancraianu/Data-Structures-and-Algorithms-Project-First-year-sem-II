#pragma once
#include <iostream>

template <class T>
class Multime
{
private:

	template <class T>
	class Node
	{
	public:
		T info;
		Node* next; 
		Node(T& info) 
		{
			this->info = info;
			this->next = nullptr;
		}
	};
	Node<T>* first;
	int size;
public:
	Multime()
	{
		this->first = nullptr;
		this->size = 0;
	}

	void add(T elem)
	{
		if (is_empy())
		{
			this->first = new Node<T>(elem);
			size++;
		}
		else
		{
			Node<T>* it = this->first;
			while (it->next != nullptr)
				it = it->next;
			it->next = new Node<T>(elem);
			size++;
		}
	}

	void remove(T elem)
	{
		if (this->find(elem))
		{
			Node<T>* it = this->first;
			if (it->info == elem)
			{
				Node<T>* poz = this->first->next;
				delete this->first;
				this->first = poz;
				delete poz;
			}
			else
				while (it != nullptr)
				{
					if (it->next->info == elem)
					{
						Node<T>* poz = it->next->next;
						delete it->next;
						it->next = poz;
						delete poz;
						size--;
					}
					it = it->next;
				}
		}
	}

	void update(T elem, T elem_new)
	{
		Node<T>* it = this->first;
		while (it != nullptr)
		{
			if (it->info == elem)
				it->info = elem_new;
			it = it->next;
		}
	}

	bool find(T elem)
	{
		Node<T>* it = this->first;
		if (it == nullptr)
			return false;
		while (it != nullptr)
		{
			if (it->info == elem)
				return true;
			it = it->next;
		}
		return false;
	}

	int get_size()
	{
		return this->size;
	}

	Node<T>* get_first()
	{
		return this->first;
	}

	bool is_empy()
	{
		if (this->first == nullptr)
			return true;
		return false;
	}

};
