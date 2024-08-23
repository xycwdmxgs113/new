#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace fj
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const  T* const_iterator;
		vector()
		{}
		
		vector(size_t n,const T&val=T())
		{
			resize(n, val);
		}

		template<class InputIterator>
			vector(InputIterator first, InputIterator last)
			{
				while (first!=last)
				{
					push_back(*first);
					first++;
				}
			}


		vector(const vector<T>& v)
		{
			reserve(v.Capacity());
			for (size_t i = 0; i <v.Size(); i++)
			{
				_star[i] =v. _star[i];	
			}
			_finish = _star + v.Size();
		}

		~vector()
		{
			delete[] _star;
			_star = _finish = _end_of_storage;
		}

		iterator begin()
		{
			return _star;
		}

		iterator end()
		{
			return _finish;
		}

		const iterator begin() const 
		{
			return _star;
		}

		const iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n>Capacity())
			{
				size_t old_size = Size();
;				iterator temp = new T[n];
				if (_star)
				{
					//深拷贝中的深拷贝,为了防止自定义类型的vector中内容的浅拷贝如string
					for(size_t i=0;i<Size();i++)
					{
						temp[i] = _star[i];
					}
					delete[] _star;
				}
				_star = temp;
				_finish = temp + old_size;
				_end_of_storage = _star + n;
			}
		}

		void resize(size_t n,T val=T())
		{
			if (n<Size())
			{
				_finish = _star + n;
			}
			else
			{
				reserve(n);
				while (_finish!=_star+n)
				{
					(*_finish) = val;
					++_finish;
				}
			}
		}

		void push_back(const T& val)
		{
			if (_finish==_end_of_storage)
			{
				size_t capacity = Capacity() == 0 ? 4 : 2 * Capacity();
				reserve(capacity);
			}
			*_finish = val;
			_finish++;
		}

		size_t Capacity() const 
		{
			return _end_of_storage - _star;
		}

		size_t	Size() const 
		{
			return _finish - _star;
		}

		void Swap(vector<T>&v)
		{
			swap(_star, v._star);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>&operator=(vector<T> v)
		{
			Swap(v);
			return *this;
		}

		T&operator[](size_t n)
		{
			return *(_star + n);
		}
		
		void insert(iterator pos,const T&val)
		{
			assert(pos >= _star && pos <= _finish);
			if (_finish==_end_of_storage)
			{
				//防止迭代器失效
				size_t len = pos - _star;
				reserve(Capacity()*2);
				pos = _star + len;
			}
			iterator end = _finish-1;
			while (end>=pos)
			{
				*(end + 1) = *(end);
				end--;
			}
			*(pos) = val;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _star && pos < _finish);
			iterator begin = pos;
			while (begin+1!=_finish)
			{
				*(begin) = *(begin + 1);
				++begin;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _star=nullptr;
		iterator _finish=nullptr;
		iterator _end_of_storage=nullptr;
	};



}


