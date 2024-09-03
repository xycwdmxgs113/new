#pragma once
#include<iostream>
#include<stdbool.h>
#include<assert.h>
#include"reverse_iterator.h"

namespace mabo
{
	template<class T>
	struct list_node
	{
		list_node(T val=T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}

		T _val;
		list_node* _next;
		list_node* _prev;
	};


	template<class T, class Ref,class Por>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T,Ref,Por> self;


		_list_iterator(Node*node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_val;
		}

		self&operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self temp(*this);
			_node = _node->_next;
			return temp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self& operator--(int)
		{
			self temp(*this);
			_node = _node->_prev;
			return *this;
		}

		Por operator->()
		{
			return  &_node->_val;
		}

		bool operator!=(const  self& it)const
		{
			return _node != it._node;
		}

		bool operator ==(const  self& it)const
		{
			return _node == it._node;
		}

		Node* _node;
	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;

		typedef Reverse_iterator<iterator,T&, T*> reverse_iterator;

		void emptyInit()
		{
			_head = new Node(T());
			_head->_next = _head->_prev = _head;
			_size = 0;
		}

		list()
		{
			emptyInit();
		}

		list(const list<T>&lt)
		{
			emptyInit();
			for (auto& e:lt)
			{
				push_back(e);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>&operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T&val)
		{
			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const iterator begin() const
		{
			return _head->_next;
		}

		const iterator end() const
		{
			return _head;
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			newnode->_next = pos._node;
			newnode->_prev = pos._node->_prev;
			pos._node->_prev->_next = newnode;
			pos._node->_prev = newnode;
			_size++;
			return newnode; 
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;
			return next;
		}

		size_t size()
		{
			return _size;
		}

		void clear()
		{
			iterator it = begin();
			while (it!=end())
			{
				it=erase(it);
			}
			_size = 0;
		}


	private:
		Node* _head;
		size_t _size;
	};


	struct A
	{
		A(int a1 = 1, int a2 = 2)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};


}