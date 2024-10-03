#pragma once
#include<iostream>
using namespace std;

namespace key
{
	template<class K>
	class SBTNode
	{
	public:
		SBTNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}

		K _key;
		SBTNode* _left;
		SBTNode* _right;
	};

	template<class K>
	class SBT
	{
		typedef SBTNode<K> Node;
	public:

		SBT()
			:_root(nullptr)
		{}

		SBT(const SBT<K>& sb)
		{
			_root=Preamble(sb._root);
		}

		SBT<K>& operator =(SBT<K>& sb)
		{
			swap(_root, sb._root);
			return *this;
		}

		~SBT()
		{
			Del(_root);
		}

		bool insert(const K& key)
		{
			if (!_root)
				_root = new Node(key);
			else
			{
				Node* parent = _root, * child = _root;
				while (child)
				{
					if (child->_key > key)
					{
						parent = child;
						child = child->_left;
					}
					else if (child->_key < key)
					{
						parent = child;
						child = child->_right;
					}
					else
					{
						return false;
					}
				}

				child = new Node(key);
				if (parent->_key > key)
				{
					parent->_left = child;
				}
				else
				{
					parent->_right = child;
				}
			}
			return true;
		}

		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}

		bool Erase(const K& key)
		{
			Node* parent = _root, * child = _root;
			while (child)
			{
				if (child->_key > key)
				{
					parent = child;
					child = child->_left;
				}
				else if (child->_key < key)
				{
					parent = child;
					child = child->_right;
				}
				else
				{
					break;
				}
			}
			if (child == nullptr)
				return false;

			if (child->_left && child->_right)
			{
				Node* LeftMax = child;
				while (LeftMax->_right)
				{
					parent = LeftMax;
					LeftMax = LeftMax->_right;
				}

				swap(LeftMax->_key, child->_key);

				if (LeftMax->_left)
				{
					if (parent->_left == LeftMax)
						parent->_left = LeftMax->_left;

					else
						parent->_right = LeftMax->_left;
				}
				else
				{
					if (parent->_left == LeftMax)
						parent->_left = LeftMax->_right;

					else
						parent->_right = LeftMax->_right;
				}
				child = LeftMax;
			}
			else
			{
				if (child->_left)
				{
					if (child == _root)
					{
						_root = _root->_left;
					}
					else
					{
						if (parent->_left == child)
						{
							parent->_left = child->_left;
						}
						else
						{
							parent->_right = child->_left;
						}
					}
				}
				else
				{
					if (child == _root)
					{
						_root = _root->_right;
					}
					else
					{
						if (parent->_left == child)
						{
							parent->_left = child->_right;
						}
						else
						{
							parent->_right = child->_right;
						}
					}
				}
			}
			delete child;
			return true;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InserR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		void _Inorder(Node* root)
		{
			if (!root)
				return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			return root->_key == key || _FindR(root->_left, key) || _FindR(root->_right, key);

		}

		bool _InserR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				_InserR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_InserR(root->_right, key);
			}
			else
			{
				return false;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key > key)
			{
				_EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->_right, key);
			}
			else
			{
				Node* del = root;
				if (root->_left && root->_right)
				{
					Node* Max = root->_left;
					while (Max->_right)
					{
						Max = Max->_right;
					}
					swap(Max->_key, root->_key);
					return _EraseR(root->_left, key);
				}
				else
				{
					if (root->_left)
					{
						root = root->_left;
					}
					else
					{
						root = root->_right;
					}
				}
				delete  del;
				return true;
			}
		}

		Node* Preamble(Node*root)
		{
			if (root==nullptr)
			{
				return nullptr;
			}
			Node* myroot = new Node(root->_key);
			myroot->_left = Preamble(root->_left);
			myroot->_right = Preamble(root->_right);
			return myroot;
		}

		void Del(Node*root)
		{
			if (root==nullptr)
			{
				return;
			}
			Del(root->_left);
			Del(root->_right);
			delete root;
			return;
		}

	private:
		Node* _root = nullptr;
	};
}


namespace key_val
{
	template<class K,class V>
	class SBTNode
	{
	public:
		SBTNode(const K& key,const K&val)
			:_key(key)
			,_val(val)
			, _left(nullptr)
			, _right(nullptr)
		{}

		K _key;
		V _val;
		SBTNode* _left;
		SBTNode* _right;
	};

	template<class K,class V>
	class SBT
	{
		typedef SBTNode<K,V> Node;
	public:

		SBT()
			:_root(nullptr)
		{}

		SBT(const SBTNode<K, V>& sb)
		{
			_root = Preamble(sb._root);
		}

		SBTNode<K, V>& operator =(SBTNode<K, V>& sb)
		{
			swap(_root, sb._root);
			return *this;
		}

		~SBT()
		{
			Del(_root);
		}

		void Inorder()
		{
			_Inorder(_root);
			cout << endl;
		}


		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key,const V&val)
		{
			return _InserR(_root, key,val);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		void _Inorder(Node* root)
		{
			if (!root)
				return;

			_Inorder(root->_left);
			cout << root->_key << " ";
			_Inorder(root->_right);
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			if (root->_key==key)
			{
				return root;
			}
			else if(root->_key>key)
			{
				_FindR(root->_left, key);
			}
			else
			{
				_FindR(root->_right, key);
			}
		}

		bool _InserR(Node*& root, const K& key,const V&val)
		{
			if (root == nullptr)
			{
				root = new Node(key,val);
				return true;
			}

			if (root->_key > key)
			{
				_InserR(root->_left, key,val);
			}
			else if (root->_key < key)
			{
				_InserR(root->_right, key,val);
			}
			else
			{
				return false;
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key > key)
			{
				_EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_EraseR(root->_right, key);
			}
			else
			{
				Node* del = root;
				if (root->_left && root->_right)
				{
					Node* Max = root->_left;
					while (Max->_right)
					{
						Max = Max->_right;
					}
					swap(Max->_key, root->_key);
					return _EraseR(root->_left, key);
				}
				else
				{
					if (root->_left)
					{
						root = root->_left;
					}
					else
					{
						root = root->_right;
					}
				}
				delete  del;
				return true;
			}
		}

		Node* Preamble(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* myroot = new Node(root->_key);
			myroot->_left = Preamble(root->_left);
			myroot->_right = Preamble(root->_right);
			return myroot;
		}

		void Del(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Del(root->_left);
			Del(root->_right);
			delete root;
			return;
		}

	private:
		Node* _root = nullptr;
	};
}