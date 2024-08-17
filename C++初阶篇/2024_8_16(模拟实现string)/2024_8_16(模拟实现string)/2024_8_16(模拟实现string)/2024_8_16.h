#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace manbo
{
	class string
	{
		public:
			typedef char* iterator;
			static size_t npos;

			string(const char* s);
			string();
			string(const string& s);

			~string();

			const char* c_str()const ;

			char& operator[](size_t pos);
			const char& operator[](size_t pos)const ;

			const size_t size()const;

			iterator begin()
			{
				return _str;
			}

			iterator end()
			{
				return _str + _size;
			}

			const iterator begin()const 
			{
				return _str;
			}

			const iterator end()const 
			{
				return _str + _size;
			}

			void reserve(size_t n = 0);
			void push_back(char ch);
			string& append(const char*s);
			string& operator+=(const char* s);
			string& operator+=(char ch);
			string& insert(size_t pos, const char* s);
			string& erase(size_t pos, size_t len = npos);

			size_t find(const char* s, size_t pos = 0) const;
			size_t find(char c, size_t pos = 0) const;

			string substr(size_t pos, size_t len =npos) const;

			void resize(size_t n, char ch = '\0');
			void clear();

			bool operator<(const string& s) const;
			bool operator<=(const string& s) const;

			bool operator>(const string& s) const;
			bool operator>=(const string& s) const;

			bool operator==(const string& s) const;
			bool operator!=(const string& s) const;

			void swap(string& s2);
			string& operator=(string temp);
			
		private:
			size_t _size;
			size_t _capaticy;
			char* _str;
	};

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}



