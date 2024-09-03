#pragma once
namespace mabo
{
	template<class Iterator ,class Ref ,class Ptr>
	struct Reverse_iterator
	{
		Iterator _it;
		Reverse_iterator(const Iterator it)
			:_it(it)
		{}

		typedef Reverse_iterator<Iterator,Ref, Ptr> self;

		
		Ref operator*()
		{
			Iterator temp = _it;
			return *(--temp);
		}

		Ptr operator ->()
		{
			return &(_it.operator*());
		}

		self& operator++()
		{
			return --_it;
		}

		self& operator--()
		{
			return  ++_it;
		}

		bool operator!=(const self&it) const
		{
			return _it != it._it;
		}

	};

}
