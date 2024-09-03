#pragma once
namespace manbo
{
	//·´Ïòµü´úÆ÷
	template<class Iterator,class Ref,class Ptr>
	struct Reverse_iterator
	{
		Iterator _it;
		typedef Reverse_iterator<Iterator, Ref, Ptr> self;
		Reverse_iterator( Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator temp = _it;
			return *(--temp);
		}

		Ptr operator ->()
		{
			return &(operator*());
		}

		self&operator++()
		{
			--_it;
			return *this;
		}

		self& operator++(int)
		{
			Iterator temp = _it;
			--_it;
			return *temp;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		self& operator--(int)
		{
			Iterator temp = _it;
			++_it;
			return *temp;
		}

		bool operator !=(const self& it) 
		{
			return _it != it._it;
		}

		bool operator ==(const self& it)
		{
			_it == it._it;
		}
		
	};

}
