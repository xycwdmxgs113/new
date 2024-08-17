#include"2024_8_16.h"
namespace manbo
{
	string::string(const char* s)
		:_size(strlen(s))
		, _capaticy(_size)
		, _str(new char[_size + 1])
	{
		memcpy(_str, s,_size+1);
	}

	string::string()
		:_size(0)
		, _capaticy(0)
		, _str(new char[1])
	{
		_str[0] = '\0';
	}

	string::string(const string& s)
	{
		_str = new char[s._size + 1];
		_size = s._size;
		_capaticy = s._capaticy;
		memcpy(_str,s._str,s._size+1);
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capaticy = 0;
	}

	const char* string::c_str()const 
	{
		return _str;
	}

	char& string::operator[](size_t pos)
	{
		assert(pos >= 0 && pos < _size);
		return _str[pos];
	}

	const char& string::operator[](size_t pos)const
	{
		assert(pos >= 0 && pos < _size);
		return _str[pos];
	}

	const size_t string ::size()const
	{
		return _size;
	}


	void string::reserve(size_t n)
	{
		if (n>_capaticy)
		{
			char* temp = new char[n + 1];
			memcpy(temp, _str,_size+1);
			_capaticy = n;
			delete[] _str;
			_str = temp;
		}
	}

	void string::push_back(char ch)
	{
		if (_size==_capaticy)
		{
			reserve(_capaticy == 0 ? 4 : 2 * _capaticy);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	string& string:: append(const char*s)
	{
		size_t len = strlen(s);
		if (_size+len>_capaticy)
		{
			reserve(2 * (_size + len));
		}
		memcpy(_str + _size,s,len+1);
		_size += len;
		return *this;
	}

	string& string::operator+=(const char* s)
	{
		append(s);
		return *this;
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	string& string::insert(size_t pos, const char* s)
	{
		assert(pos >= 0 && pos <= _size);
		size_t n = strlen(s);
		size_t len = _size + n;
		_size += n;
		if (len>_capaticy)
		{
			reserve(2 *len);
		}
		size_t end = _size;
		
		while (end>=pos&&end!=npos)
		{
			_str[end + n] = _str[end];
			end--;
		}
		
		for (int i = 0; i <n ; i++)
		{
			_str[pos + i] = s[i];

		}
			
		return *this;

	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos >= 0 && pos <_size);
		if (len==npos||pos+len>=_size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			int sum = 0;
			size_t begin = pos + len;
			while (begin<=_size)
			{
				sum++;
				_str[pos] = _str[begin];
				pos++, begin++;
			}
			_size = pos + sum;
		}
		return *this;
	}

	size_t string::find(char c, size_t pos) const
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}
	size_t string:: find(const char* s, size_t pos) const
	{
		char* temp = strstr(_str, s);
		if (!temp)
		{
			return npos;
		}
		else
		{
			return temp-_str ;
		}
	}

	string string::substr(size_t pos, size_t len) const
	{
		assert(pos >= 0 && pos < _size);
		string temp;
		if (len == npos || pos + len >= _size)
		{
			temp.reserve(_capaticy);
			for (size_t i = pos; i < _size; i++)
			{
				temp += _str[i];
			}
		}
		else
		{
			temp.reserve(len + 1);
			for (size_t i = pos; i < len+pos; i++)
			{
				temp += _str[i];
			}
		}
		return temp;
	}
	
	size_t string::npos = -1;

	void string::resize(size_t n, char ch)
	{
		if (n<_size)
		{
			_str[n] = '\0';
			_size = n;
		}
		else
		{
			reserve(n);
			for (int i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_str[n] = '\0';
			_size = n;
		}
	}

	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	// hello hello		false
	// hello*** hello	false
	// hello hello**	true
	bool string:: operator<(const string& s) const
	{
		size_t s1, s2;
		s1 = s2 = 0;
		while (s1<_size&&s2<s._size)
		{
			if (_str[s1] < s._str[s2])
				return true;
			else if (_str[s1] > s._str[s2])
				return false;
			else
			{
				s1++, s2++;
			}
		}
		if (_size>s.size())
		{
			return false;
		}else if(_size == s.size())
		{
			return false;
		}
		return true;
	}

	bool string::operator==(const string& s) const
	{
		return _size == s._size && 0 == (memcmp(s._str, _str, _size));
	}

	bool string:: operator<=(const string& s) const
	{
		return *this < s || *this == s;
	}

	bool string::operator>(const string& s) const
	{
		return !(*this <= s);
	}

	bool string::operator>=(const string& s) const
	{
		return *this == s || *this > s;
	}

	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	void string:: swap( string& s)
	{
		std::swap(_str, s._str);
		std::swap(_capaticy, s._capaticy);
		std::swap(_size, s._size);
	}
	// µœ÷…ÓøΩ±¥
	string& string::operator=(string temp)
	{
		swap(temp);
		return *this;
	}
}

ostream& manbo:: operator<<(ostream& out, const string& s)
{
	for (auto ch:s)
	{
		out << ch;
	}
	cout << endl;
	return out;
}
istream&manbo:: operator>>(istream& in, string& s)
{
	s.clear();

	char ch;
	ch = in.get();
	while (ch == '\0' || ch == '\n')
	{
		ch = in.get();
	}
	char buff[128];
	int i = 0;

	while (ch!='\0'&&ch!='\n')
	{
		buff[i++] = ch;
		if (i==127)
		{
			buff[i] = '\0';
			s += buff;
			i = 0;
		}
		ch = in.get();
	}

	if (i>0)
	{
		buff[i] = '\0';
		s += buff;
	}
	return in;
}