#pragma once
#include<vector>
#include<iostream>
using namespace std;
namespace manbo
{
	//·Âº¯Êý
	template<class T>
	struct Less
	{
		bool operator()(const T&x,const T y)
		{
			return x<y;
		}
	};

	template<class T>
	struct Greate
	{
		bool operator()(const T& x, const T y)
		{
			return x > y;
		}
	};

	template<class T,class Container=vector<T>,class Compare= Greate<T>>
	class priority_queue
	{
	private:
		void AdjustDown(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}

		}
		void AdjustUp(int child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child>=0)
			{
				if(com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent=( child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		

	public:
		priority_queue()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first,InputIterator last)
		{
			while (first!=last)
			{
				_con.push_back(*first);
				first++;
			}
			for (int i = (_con.size()-2)/2; i >=  0; --i)
			{
				AdjustDown(i);
			}
		}

		void push(const T &val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
			
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& top() const
		{
			return  _con[0];
		}

		const size_t size()const
		{
			return _con. size();
		}
	
	private:
		Container _con;
	};

}