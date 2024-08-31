#pragma once
#include<iostream>
#include<list>
using namespace std;

namespace manbo
{
	template<class T, class container = list<int>>
	class queue
	{
	public:
		void push(T val)
		{
			_con.push_back(val);
		}

		T& front()
		{
			return _con.front();
		}

		void pop()
		{
			_con.erase(_con.begin());
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		container  _con;
	};
}

