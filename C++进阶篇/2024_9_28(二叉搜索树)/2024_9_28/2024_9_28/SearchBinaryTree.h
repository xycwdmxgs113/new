#pragma once
#include<iostream>

using namespace std;

namespace key
{
	template<class K>
	struct SBTreeNode
	{

		SBTreeNode(const K& key)
			:_left(nullptr)
			, _key(key)
			, _right(nullptr)
		{}
		K _key;
		SBTreeNode<K>* _left;
		SBTreeNode<K>* _right;
	};

	template<class K>
	class SBTree
	{
		typedef SBTreeNode<K> Node;
	public:
		SBTree(const SBTree<K>& sb)
		{
			_root=Preamble(sb._root);
		}

		SBTree()
			:_root(nullptr)
		{}

		~SBTree()
		{
			Delete(_root);
		}
		
		SBTree<K>& operator=(SBTree<K> sb)
		{
			swap(_root, sb._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
			}
			else
			{
				Node* parent = _root;
				Node* cur = _root;
				while (cur)
				{

					if (cur->_key > key)
					{
						parent = cur;
						cur = cur->_left;
					}
					else if (cur->_key < key)
					{
						parent = cur;
						cur = cur->_right;
					}
					else
					{
						return false;
					}
				}
				cur = new Node(key);

				if (parent->_key > cur->_key)
				{
					parent->_left = cur;
				}
				else
				{
					parent->_right = cur;
				}
			}
			return true;
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = _root;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					break;
				}
			}

			if (cur == nullptr)
			{
				return false;
			}

			if (cur->_left != nullptr && cur->_right != nullptr)
			{

				parent = cur;
				Node* LeftMax = cur->_left;
				while (LeftMax->_right)
				{
					parent = LeftMax;
					LeftMax = LeftMax->_right;
				}

				swap(LeftMax->_key, cur->_key);
				if (LeftMax->_left)
				{
					if (parent->_left == LeftMax)
					{
						parent->_left = LeftMax->_left;
					}
					else
					{
						parent->_right = LeftMax->_left;
					}
				}
				else
				{
					if (parent->_right == LeftMax)
					{
						parent->_right = LeftMax->_right;
					}
					else
					{
						parent->_left = LeftMax->_right;
					}
				}
				cur = LeftMax;
			}
			else
			{
				if (cur->_left)
				{
					if (cur == _root)
					{
						parent = parent->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{
					if (cur == _root)
					{
						parent = parent->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
			}
			delete cur;
			return true;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:

		void Delete(Node* root)
		{
			if (root==nullptr)
			{
				return;
			}
			Delete(root->_left);
			Delete(root->_right);
			delete root;
			root = nullptr;
		}

		Node* Preamble(Node* root)
		{
			if (root==nullptr)
			{
				return nullptr;
			}
			Node* newnode = new Node(root->_key);
			newnode->_left = Preamble(root->_left);
			newnode->_right = Preamble(root->_right);
			return newnode;
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key == key)
			{
				return true;
			}

			return _FindR(root->_left, key) || _FindR(root->_right, key);
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				_InsertR(root->_left, key);
			}
			else if (root->_key < key)
			{
				_InsertR(root->_right, key);
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
				//有三种情况
				//1.左子树为空 2.右子树为空 3左右子树不为空
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
				else if (root->_left)
				{
					root = root->_left;
				}
				else
				{
					root = root->_right;
				}
				delete del;
				return true;
			}

		}

		void _InOrder(Node* root)
		{
			if (!root)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};
}


namespace key_val
{
	template<class K, class V >
	struct SBTreeNode
	{

		SBTreeNode(const K& key,const V&val)	
			:_left(nullptr)
			, _key(key)
			, _right(nullptr)
			, _val(val)
		{}
		K _key;
		V _val;
		SBTreeNode<K,V>* _left;
		SBTreeNode<K, V>* _right;
	};

	template<class K,class V>
	class SBTree
	{
		typedef	SBTreeNode<K, V> Node;
	public:
		SBTree(const SBTree<K,V>& sb)
		{
			_root = Preamble(sb._root);
		}

		SBTree()
			:_root(nullptr)
		{}

		~SBTree()
		{
			Delete(_root);
		}

		SBTree<K,V>& operator=(SBTree<K,V> sb)
		{
			swap(_root, sb._root);
			return *this;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}


		Node* FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key,const V&val)
		{
			return _InsertR(_root, key,val);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:

		void Delete(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			Delete(root->_left);
			Delete(root->_right);
			delete root;
			root = nullptr;
		}

		Node* Preamble(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newnode = new Node(root->_key);
			newnode->_left = Preamble(root->_left);
			newnode->_right = Preamble(root->_right);
			return newnode;
		}

		Node* _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;

			if (root->_key == key)
			{
				return root;
			}

			Node*ret= _FindR(root->_left, key);
			if(!ret)
			{
				ret = _FindR(root->_right, key);
			}
		}

		bool _InsertR(Node*& root, const K& key,const V&val)
		{
			if (root == nullptr)
			{
				root = new Node(key,val);
				return true;
			}

			if (root->_key > key)
			{
				_InsertR(root->_left, key, val);
			}
			else if (root->_key < key)
			{
				_InsertR(root->_right, key, val);
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
				//有三种情况
				//1.左子树为空 2.右子树为空 3左右子树不为空
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
				else if (root->_left)
				{
					root = root->_left;
				}
				else
				{
					root = root->_right;
				}
				delete del;
				return true;
			}

		}

		void _InOrder(Node* root)
		{
			if (!root)
				return;
			_InOrder(root->_left);
			cout << root->_key << "有" << root->_val << "个" << endl;
			_InOrder(root->_right);
		}

	private:
		Node* _root = nullptr;
	};

}

