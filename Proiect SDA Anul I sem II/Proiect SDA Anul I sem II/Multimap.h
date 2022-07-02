#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class Key, class Value>
class Multimap
{
private:

	template <class K, class V>
	class MapNode
	{
	public:
		K key;
		V value;
		MapNode<K, V>* next;
		MapNode(K key, V value): key(key), value(value) {this->next = nullptr; }
	};

	template<class V>
	class ListNode
	{
	public:
		V info;
		ListNode<V> *next;
		ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
		ListNode(V info) : info(info) { next = nullptr; }
	};

	int size;
	MapNode<Key,ListNode<Value>*>* first;

	MapNode<Key, ListNode<Value>*>* searchAdress(Key k)
	{
		if (this->size == 0) 
			return nullptr;
		MapNode<Key, ListNode<Value>*>* p = first;
		while (p->next != nullptr)
		{
			if (p->key == k)
				return p;
			p = p->next;
		}
		return p;
	}
public:
	Multimap()
	{
		this->first = nullptr;
		this->size = 0;
	}

	void put(Key key, Value value)
	{
		MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
		if (poz == nullptr)
		{
			/*this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
			this->size++;*/
			MapNode<Key, ListNode<Value>*>* node = new MapNode<Key, ListNode<Value>*>(key, nullptr);
			 ListNode<Value>* listnode = new ListNode<Value>(value);
			this->first = node;
			this->first->value = listnode;
			this->size++;
		}
		else
		{
			if (poz->key == key)
			{
				ListNode<Value>* node = new ListNode<Value>(value, poz->value);
				poz->value = node;
			}else
			{
				poz->next = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
				this->size++;
			}
		}
	}

	vector<Value> remove(Key key)
	{
		MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
		vector<Value> result;
		if (poz != nullptr && poz->key == key)
		{
			MapNode<Key, ListNode<Value>*>* p = first;
			if (poz == this->first)
				this->first = poz->next;
			else
			{
				while (p->next != poz)
					p = p->next;
				p->next = poz->next;
			}
			while (poz->value != nullptr)
			{
				ListNode<Value>* node = poz->value;
				result.push_back(node->info);
				poz->value = node->next;
				delete node;
			}
			this->size--;
			delete poz;
		}
		return result;
	}

	bool find(Key key)
	{
		if (searchAdress(key) == nullptr)
			return false;
		else if (searchAdress(key)->key == key)
			return true;
		return false;
	}

	int get_size()
	{
		return this->size;
	}
	

	MapNode<Key, ListNode<Value>*>* get_first()
	{
		return this->first;
	}

	Value get_value()
	{
		return this->value;
	}
	

	MapNode<Key, ListNode<Value>*>* operator=(const MapNode<Key, ListNode<Value>*>*& p)
	{
		this->key = p.key;
		this->value = p.value;
		this->next = p.next;
		return *this;
	}

};
