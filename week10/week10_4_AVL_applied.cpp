#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct {
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

void expandExternal(TreeNode* w) {
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = NULL;
	l->right = NULL;
	l->parent = w;
	r->left = NULL;
	r->right = NULL;
	r->parent = w;
	w->left = l;
	w->right = r;
}

TreeNode* treeSearch(TreeNode* v, int k) {
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else
		return treeSearch(v->right, k);
}

int findElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (isExternal(w))
		return 0;
	else
		return w->key;
}

void insertItem(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w))//isInternal 대신해서 사용
		return;
	else {
		w->key = k;
		expandExternal(w);
	}
}

TreeNode* sibling(TreeNode* z) {
	if (z->parent->left == z)
		return z->parent->right;
	else
		return z->parent->left;
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z) {
	TreeNode* w = z->parent;
	TreeNode* g = w->parent;
	TreeNode* zs = sibling(z);
	zs->parent = g;

	if (g == NULL) {
		T->root = zs;
	}
	else {
		if (w == g->left)
			g->left = zs;
		else //if w==g->right
			g->right = zs;
	}

	return z;
}

TreeNode* inOrderSucc(TreeNode* w) {
	w = w->right;
	while (w->left != NULL)
		w = w->left;
	return w;
}

int removeElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);

	if (isExternal(w))
		return 0;
	TreeNode* z, * y;
	z = w->left;
	if (!isExternal(z))
		z = w->right;
	if (isExternal(z))
		reduceExternal(T, z);
	else {//case2
		z = inOrderSucc(w);
		y = z->parent; //실제 삭제될 것
		w->key = y->key;
		reduceExternal(T, z);
	}

	return k;
}

//전위순회
void preOrder(TreeNode* root) {
	if (isExternal(root))
		return;
	printf("[%d] ", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

void rFindAllInRange(TreeNode* v, int k1, int k2) {
	if (isExternal(v))
		return;
	if (k1 <= v->key && v->key < k2)
		printf("[%d] ", v->key);
	if (v->key <= k1)
		rFindAllInRange(v->right, k1, k2);
	else if (k2 <= v->key)
		rFindAllInRange(v->left, k1, k2);
	else {
		rFindAllInRange(v->left, k1, k2);
		rFindAllInRange(v->right, k1, k2);
	}
}

int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 44);
	insertItem(T, 17);
	insertItem(T, 32);
	insertItem(T, 78);
	insertItem(T, 50);
	insertItem(T, 88);
	insertItem(T, 48);
	insertItem(T, 62);
	insertItem(T, 54);

	// 결과가 다르넹..
	preOrder(T->root); printf("\n");

	rFindAllInRange(T->root, 50, 80);
	return 0;
}