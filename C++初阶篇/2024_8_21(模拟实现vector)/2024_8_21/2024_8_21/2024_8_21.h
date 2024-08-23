#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace cat
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
		{}

		vector(const vector<T>& v)
		{
			_star=new T[v.Capacity()];
			_finish=_star + v.Size();
			_endof_storage=_star + v.Capacity();
			//这里要用深拷贝,如果是自定义类型的对象如string,会调用它的拷贝构造
			for (size_t i = 0; i <v.Size(); i++)
			{
				_star[i] = v._star[i];
			}
		}

		vector(size_t n,const T&val=T())
		{
			resize(n, val);
		}

		//左闭右开
		template<class InputIterator>
			vector(InputIterator first,InputIterator last)
			{
				while (first!=last)
				{
					push_back(*first);
					first++;
				}
			}

		~vector()
		{
			delete[] _star;
			_star = _finish = _endof_storage = nullptr;
		}

		iterator begin()
		{
			return _star;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _star;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n>Capacity())
			{
				size_t old_size = Size();
				iterator temp = new T[n];
				if (_star)
				{
					//深拷贝
					for (size_t i = 0; i < Size(); i++)
					{
						temp[i] = _star[i];
					}
					delete [] _star;
				}
				_star = temp;
				_finish = temp + old_size;
				_endof_storage = temp + n;
			}
		}

		void push_back(const T&x)
		{
			if (_finish==_endof_storage)
			{
				size_t capacity = Capacity() == 0 ? 4 : 2 * Capacity();
				reserve(capacity);
			}
			*_finish = x;
			++_finish;
		}

		T&operator[](size_t n)
		{
			assert(n >= 0 && n < Size());
			return *(_star + n);
		}

		size_t Capacity() const
		{
			return _endof_storage - _star;
		}

		size_t Size() const
		{
			return _finish - _star;
		}

		void insert(iterator pos,const T&val)
		{
			assert(pos >= _star && pos <= _finish);
			if (_finish == _endof_storage)
			{
				//涉及迭代器失效问题
				size_t len = pos - _star;
				size_t capacity = Capacity() == 0 ? 4 : 2 * Capacity();
				reserve(capacity);
				pos = _star + len;
			}
			iterator end = _finish-1;
			while (end>=pos) 
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			_finish++;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _star && pos < _finish);
			iterator begin = pos;
			while (begin+1 <_finish)
			{
				*(begin) = *(begin + 1);
				begin++;
			}
			_finish--;
			return pos;
		}

		void resize(size_t n,T val=T())
		{
			if (n<Size())
			{
				_finish =_star+ n;
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

		void Swap(vector<T> &v)
		{
			swap(_star,  v._star);
			swap(_finish, v._finish);
			swap(_endof_storage,v._endof_storage);
		}

		vector<T> &operator=( vector<T> v)
		{
			Swap(v);
			return *this;
		}

	private:
		iterator _star=nullptr;
		iterator _finish = nullptr;
		iterator _endof_storage = nullptr;
	};



};
