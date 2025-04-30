#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

#define MOD 1000000000
#define int long long
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define tiii tuple<int,int,int>

class Node
{
public:
	Node* left=nullptr;
	Node* right=nullptr;
	int value=0;

	Node() {}
	Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& node, int val)
{
	if (node == nullptr)
	{
		node = new Node(val);
		return;
	}
	if (val < node->value) insert(node->left, val);
	else insert(node->right, val);
}

void printPostorder(Node* node)
{
	if (node == nullptr) return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->value << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	Node* root = nullptr;
	while (cin >> num)
	{
		insert(root, num);
	}

	printPostorder(root);
	
	return 0;
}

