#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct TreeNode {
	int weight;
	char ch;
	TreeNode * left;
	TreeNode * right;
}TreeNode;
typedef struct NODE {
	TreeNode * ptree;
	char ch;
	int key;
}Node;
typedef struct M_heap {
	Node heap[MAX];
	int size;
}Heap;
Heap * mk_heap() {
	Heap * preturn = NULL;
	preturn = (Heap *)malloc(sizeof(Heap));
	memset(preturn, 0, sizeof(Heap));
	return preturn;
}
void insert_heap(Heap * h, Node data) {
	int i = ++h->size;
	while ((i != 1) && data.key < h->heap[i / 2].key) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = data;
}
Node delete_heap(Heap * h) {
	int parent = 1, child = 2;
	int i = 1;
	Node item = h->heap[1], tmp = h->heap[h->size--];
	while (child <= h->size) {
		if (child < h->size && h->heap[child].key > h->heap[child + 1].key) {
			child++;
		}
		if (tmp.key < h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}
TreeNode * make_tree(TreeNode * left, TreeNode * right) {
	TreeNode * preturn = (TreeNode *)malloc(sizeof(TreeNode));
	memset(preturn, 0, sizeof(TreeNode));
	preturn->left = left;
	preturn->right = right;
	return preturn;
}
void print_codes(TreeNode * root, int codes[], int top) {
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);

	}
	if ((root->left==NULL&&root->right==NULL)) {
		printf("%c: ", root->ch);
		for (int i = 0; i < top; i++) {
			printf("%d", codes[i]);
		}
		printf("\n");
	}
}
void huffman_Tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode * node, *x;
	Heap * heap;
	Node e, e1, e2;
	int codes[100];
	int top = 0;
	heap = mk_heap();
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		node->ch = e.ch = ch_list[i];
		node->weight = e.key = freq[i];
		e.ptree = node;
		insert_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		e1 = delete_heap(heap);
		e2 = delete_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
		insert_heap(heap, e);
	}
	e = delete_heap(heap);
	print_codes(e.ptree, codes, top);

}
int main()
{
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4,6,8,12,15 };
	huffman_Tree(freq, ch_list, 5);

	return 0;
}