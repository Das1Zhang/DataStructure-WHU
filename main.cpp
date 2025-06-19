#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char key;
	Node *left, *right;
	int height;
	Node(char k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *n)
{
	return n ? n->height : 0;
}

void updateHeight(Node *n)
{
	n->height = 1 + max(height(n->left), height(n->right));
}

int balanceFactor(Node *n)
{
	return height(n->left) - height(n->right);
}

Node *rotateRight(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;
	x->right = y;
	y->left = T2;
	updateHeight(y);
	updateHeight(x);
	return x;
}

Node *rotateLeft(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	updateHeight(x);
	updateHeight(y);
	return y;
}

Node *rebalance(Node *n)
{
	updateHeight(n);
	int bf = balanceFactor(n);
	if (bf > 1)
	{
		if (balanceFactor(n->left) < 0)
			n->left = rotateLeft(n->left);
		return rotateRight(n);
	}
	if (bf < -1)
	{
		if (balanceFactor(n->right) > 0)
			n->right = rotateRight(n->right);
		return rotateLeft(n);
	}
	return n;
}

Node *insertAVL(Node *root, char key)
{
	if (!root)
		return new Node(key);
	if (key < root->key)
		root->left = insertAVL(root->left, key);
	else if (key > root->key)
		root->right = insertAVL(root->right, key);
	// duplicates ignored
	return rebalance(root);
}

Node *findMin(Node *root)
{
	while (root->left)
		root = root->left;
	return root;
}

Node *deleteAVL(Node *root, char key)
{
	if (!root)
		return nullptr;
	if (key < root->key)
		root->left = deleteAVL(root->left, key);
	else if (key > root->key)
		root->right = deleteAVL(root->right, key);
	else
	{
		if (!root->left || !root->right)
		{
			Node *t = root->left ? root->left : root->right;
			delete root;
			return t;
		}
		else
		{
			Node *succ = findMin(root->right);
			root->key = succ->key;
			root->right = deleteAVL(root->right, succ->key);
		}
	}
	return rebalance(root);
}

void postOrder(Node *root, string &out)
{
	if (!root)
		return;
	postOrder(root->left, out);
	postOrder(root->right, out);
	out.push_back(root->key);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N1;
	if (!(cin >> N1))
		return 0;
	Node *root = nullptr;
	for (int i = 0; i < N1; i++)
	{
		char c;
		cin >> c;
		root = insertAVL(root, c);
	}
	int N2;
	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		char c;
		cin >> c;
		root = deleteAVL(root, c);
	}
	string result;
	postOrder(root, result);
	cout << result << "\n";
	return 0;
}
