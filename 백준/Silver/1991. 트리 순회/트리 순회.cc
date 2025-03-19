#include <iostream>
#include <unordered_map>

using namespace std;

class Tree
{
public:
	struct Node
	{
		char node;
		Node* left;
		Node* right;

		Node(char _node) : node(_node), left(nullptr), right(nullptr) {}
	};

	void PreOrder(Node* root)
	{
		if (root == nullptr) return;
		cout << root->node;
		PreOrder(root->left);
		PreOrder(root->right);
	}

	void InOrder(Node* root)
	{
		if (root == nullptr) return;
		InOrder(root->left);
		cout << root->node;
		InOrder(root->right);
	}

	void PostOrder(Node* root)
	{
		if (root == nullptr) return;
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->node;
	}
};


int main()
{
	int n;
	unordered_map<char, Tree::Node*> m;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		char n, l, r;
		cin >> n >> l >> r;
		if (m[n] == NULL)
		{
			Tree::Node* node = new Tree::Node(n);
			m[n] = node;
		}
		if (m[l] == NULL)
		{
			Tree::Node* node = new Tree::Node(l);
			m[l] = node;
		}
		if (m[r] == NULL)
		{
			Tree::Node* node = new Tree::Node(r);
			m[r] = node;
		}

		if (l != '.')
		{
			m[n]->left = m[l];
		}
		if (r != '.')
		{
			m[n]->right = m[r];
		}
	}

	Tree t;
	Tree::Node* root = m['A'];
	t.PreOrder(root);
	cout << '\n';
	t.InOrder(root);
	cout << '\n';
	t.PostOrder(root);

	return 0;
}