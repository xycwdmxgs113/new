#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace manbo
{
	template<class T,class container=vector<int>>
	class stack
	{
	public:
		void push( T val)
		{
			_con.push_back(val);
		}

		T& top()
		{
			return _con.back();
		}

		void pop()
		{
			_con.pop_back();
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


