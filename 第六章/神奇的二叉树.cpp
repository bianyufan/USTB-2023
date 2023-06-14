/*
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct Node 
{
    char data;
    struct Node* lchild, * rchild;
}Node;
Node* init(char data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->lchild = NULL;    
    node->rchild = NULL;
    node->data = data;
    return node;
}
Node* build(char pre_str[], char in_str[], int len) 
{
    Node* p = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (pos < len - 1) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}
void postorder(Node* node) 
{
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%c", node->data);
}
void image_postorder(Node* node) 
{
    if (node->rchild != NULL) {
        image_postorder(node->rchild);
    }
    if (node->lchild != NULL) {
        image_postorder(node->lchild);
    }
    printf("%c", node->data);
}
int main() 
{
    char pre_str[50], in_str[50];
    cin >> pre_str >> in_str;
    Node* root = build(pre_str, in_str, strlen(pre_str));
    postorder(root);
    cout << endl;
    image_postorder(root);
    cout << endl;
    return 0;
}*/

#include<iostream>
#include<string.h>
using namespace std;
struct Node
{
	char data;
	Node* lchild, * rchild;
};
//搜索二叉树
int search(int k, char* in, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (in[i] == k)  return i;
	}
	return -1;
}
//建立二叉树
Node* fmb(char* pre, char* in, int len)
{
	if (len <= 0) return NULL;
	Node* root = new Node;
	int mark = search(*pre, in, len);
	root->data = *pre;
	root->lchild = fmb(pre + 1, in, mark);
	root->rchild = fmb(pre + mark + 1, in + mark + 1, len - mark - 1);
	return root;
}
//后序遍历
void postorder(Node* node)
{
	if (node == NULL)return;
	postorder(node->lchild);
	postorder(node->rchild);
	cout << node->data;
}
//镜像后序遍历
void mirror_postorder(Node* node)
{
	if (node == NULL)return;
	mirror_postorder(node->rchild);
	mirror_postorder(node->lchild);
	cout << node->data;
}
int main()
{
	char pre_str[50], in_str[50];
	cin >> pre_str >> in_str;
	Node *root = fmb(pre_str, in_str, strlen(pre_str));
	postorder(root);
	cout << endl;
	mirror_postorder(root);
	return 0;
}


