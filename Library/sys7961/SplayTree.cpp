#include<bits/stdc++.h>

template <typename Data_Ty>
struct SplayTree {
	struct node {
		node *L, *R, *P;
		int cnt;
		int key;
		Data_Ty num;
		Data_Ty sum;
		Data_Ty lazy;
		node(int key,Data_Ty num) :L(NULL), R(NULL), P(NULL),num(num),key(key) {
			cnt = 1;
			sum = 0;
			lazy = 0;
		}
	};

	node* root=NULL;
	void insert(int key,Data_Ty num) {
		if (root == NULL) {
			root = new node(key,num);
			return;
		}
		node* p = root;
		while (true) {
			Propagation(p);
			if (p->key == key)return;
			if (key < p->key) {
				if (p->L == NULL) {
					node* x = new node(key,num);
					addNodeLeft(p, x);
					splay(x);
					return;
				}
				p = p->L;
			}
			else {
				if (p->R == NULL) {

					node* x = new node(key,num);
					addNodeRight(p,x);
					splay(x);
					return;
				}
				p = p->R;
			}
		}
	}
	bool find(int key) {
		node* p = root;
		while (p != NULL) {
			Propagation(p);
			if (key == p->key) {
				splay(p);
				return true;
			}
			if (key < p->key) {
				if (p->L == NULL) {
					splay(p);
					return false;
				}
				p = p->L;
			}
			else {
				if (p->R == NULL) {
					splay(p);
					return false;
				}
				p = p->R;
			}
		}
		return false;
	}
	void update(node* x) {
		x->cnt = 1;
		x->sum = x->num;
		if (x->L) {
			x->cnt += x->L->cnt;
			x->sum += x->L->sum;
		}
		if (x->R) {
			x->cnt += x->R->cnt;
			x->sum += x->R->sum;
		}
	}
	void addNodeLeft(node* parent, node* child) {
		if (parent != NULL) parent->L = child;
		if (child != NULL) child->P = parent;
	}
	void addNodeRight(node* parent, node* child) {
		if (parent != NULL) parent->R = child;
		if (child != NULL) child->P = parent;
	}
	bool isLeft(node* x) {
		if (x->P == NULL || x->P->L != x)return false;
		return true;
	}
	bool isRight(node* x) {
		if (x->P == NULL || x->P->R != x)return false;
		return true;
	}
	void Propagation(node* x) {
		if (x->lazy != 0) {
			if (x->L) {
				x->L->num += x->lazy;
				x->L->sum += x->lazy*x->L->cnt;
				x->L->lazy += x->lazy;
			}
			if (x->R) {
				x->R->num += x->lazy;
				x->R->sum += x->lazy*x->R->cnt;
				x->R->lazy += x->lazy;
			}
			x->lazy = 0;
		}
	}
	void Rotate(node* x) {
		if (x->P == NULL)return;
		Propagation(x);
		node* L = x->L;
		node* R = x->R;
		node* P = x->P;
		node* GP = x->P->P;
		bool isLeftP = isLeft(P);
		bool isLeftX = isLeft(x);
		bool isRightX = isRight(x);
		if (isLeftP) {
			addNodeLeft(GP, x);
		}
		else {
			addNodeRight(GP, x);
		}
		if (isLeftX) {
			addNodeRight(x, P);
			addNodeLeft(P, R);
		}
		else if (isRightX) {
			addNodeLeft(x, P);
			addNodeRight(P, L);
		}
		update(P);
		update(x);
		if (x->P == NULL)root = x;
	}
	void splay(node* x) {
		while (x->P != NULL) {
			if (x->P->P == NULL)Rotate(x);
			else if ((isLeft(x) && isLeft(x->P)) || (isRight(x) && isRight(x->P))) {
				Rotate(x->P);
				Rotate(x);
			}
			else {
				Rotate(x);
				Rotate(x);
			}
		}
	}
	void RangeAdd(int l,int r,Data_Ty a) {
		if (l > r)return;
		find(l-1);
		node* tmp = root;
		root = root->R;
		root->P = NULL;
		find(r+1);
		root = root->L;
		root->num += a;
		root->sum += a*root->cnt;
		root->lazy += a;
		addNodeRight(tmp, root->P);
		root = root->P->P;
	}
	Data_Ty GetRange(int l, int r) {
		if (l > r)return 0;
		find(l - 1);

		node* tmp = root;
		root = root->R;
		root->P = NULL;
		find(r + 1);
		root = root->L;
		Data_Ty ret = root->sum;
		addNodeRight(tmp, root->P);
		root = root->P->P;
		return ret;
	}
};
