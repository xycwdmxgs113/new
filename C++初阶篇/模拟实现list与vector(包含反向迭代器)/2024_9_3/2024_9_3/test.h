#pragma once
#include<iostream>
#include<assert.h>
#include"reverse.h"

using namespace std;
namespace manbo
{
	template<class T>
	struct _list_node
	{
		typedef _list_node<T> Node;
		_list_node(const T&val=T())
			:_val(val)
		{}


		Node* _next=nullptr;
		Node* _prev=nullptr;
		T _val;
	};

	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;
		_list_iterator(Node * node)
			:_node(node)
		{}

		self&operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
		{
			self temp = _node;
			_node = _node->_next;
			return temp;
		}
		
		self &operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self& operator--(int)
		{
			self temp = _node;
			_node = _node->_prev;
			return temp;
		}

		Ref operator*()
		{
			return _node->_val;
		}

		const Ref operator*()const
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(_node->_val);
		}

		bool operator!=(const self&node)
		{
			return _node != node._node;
		}

		bool operator==(const self& node)
		{
			return _node == node._node;
		}

	};

	template<class T>
	class list
	{
		typedef _list_node<T> Node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*>const_iterator;

		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;


		void emptyInit()
		{
			_head = new Node;
			_head->_next = _head->_prev = _head;
		}

		list()
		{
			emptyInit();
		}

		list(const list&li)
		{
			emptyInit();
			for (const auto &e:li)
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

		void Swap(list<T>& li)
		{
			std::swap(_head, li._head);
			std::swap(_size, li._size);
		}

		list &operator =(list<T> li)
		{
			Swap(li);
			return *this;
		}

		void push_back(const T&val)
		{	
			insert(end(), val);
		}

		void push_front(const T&val)
		{
			insert(begin(), val);
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

		const iterator end()const
		{
			return _head;
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		void insert(iterator pos,const T&val)
		{
			Node* newnode = new Node(val);
			Node* Pos = pos._node;

			newnode->_next = Pos;
			newnode->_prev = Pos->_prev;
			Pos->_prev->_next = newnode;
			Pos->_prev = newnode;
			_size++;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());
			_size--;
			Node* Pos = pos._node;
			Node* next = Pos->_next;

			Pos->_prev->_next = Pos->_next;
			Pos->_next->_prev = Pos->_prev;
			delete Pos;
			Pos = nullptr;
			
			return next;
		}

		void clear()
		{
			iterator cur = begin();
			while (cur != end())
			{
				cur = erase(cur);
			}
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size = 0;
	};


	template<class T>
	class vector
	{
	public:
		vector()
		{}

		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (const auto e:v)
			{
				push_back(e);
			}
		}

		~vector()
		{
			delete[] _star;
			_star = _finish = _endof_storage = nullptr;
		}

		typedef T* iterator;
		typedef const T* const_iterator;

		typedef Reverse_iterator<iterator , T&, T*> reverse_iterator;
		typedef Reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;

		void reserve(size_t n)
		{
			if (n>capacity())
			{
				size_t oldsize = size();
				T* temp = new T[n];
				for(size_t i=0;i<oldsize;i++)
				{
					temp[i] = _star[i];
				}
				delete[]_star;
				_star = temp;
				_finish = temp + oldsize;
				_endof_storage = temp + n;
			}
		}

		void resize(size_t n,const T&val)
		{
			if (n<capacity())
			{
				_finish = _star + n;
			}else
			{
				reserve(n);
				for (size_t i = size(); i < n; i++)
				{
					_star[i] = val;
				}
			}
		}

		void Swap(vector<T>& v)
		{
			std::swap(_star, v._star);
			std::swap(_finish, v._finish);
			std::swap(_endof_storage, v._endof_storage);
		}

		vector<T>& operator=(vector<T> v)
		{
			Swap(v);
			return *this;
		}

		void push_back(const T&val)
		{
			if (_endof_storage==_finish)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = val;
			_finish++;
		}

		void pop_back()
		{
			assert(size() > 0);
			_finish--;
		}

		iterator insert(iterator pos,const T&val)
		{
			assert(pos >= begin() && pos <= end());
			if (_endof_storage == _finish)
			{
				size_t len = pos - _star;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _star + len;
			}
			
			iterator end = _finish;
			while (end>=pos)
			{
				*(end + 1) = *end;
				--end;
			}
			(*pos) = val;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= begin() && pos < end());
			iterator begin =pos+1;
			while (begin<_finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return pos;
		}

		iterator begin()
		{
			return _star;
		}

		iterator end()
		{
			return _finish;
		}
		
		const_iterator begin()const
		{
			return _star;
		}

		const_iterator end()const
		{
			return _finish;
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		const size_t size()const
		{
			return _finish - _star;
		}

		const size_t capacity() const
		{
			return _endof_storage - _star;
		}

		void clear()
		{
			 _finish = _star;
		}


	private:
		T* _star=nullptr;
		T* _finish=nullptr;
		T* _endof_storage=nullptr;
	};

}