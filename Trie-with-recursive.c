#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	递归实现，效率不高，锻炼思维用
*/

#define SIZE 26

typedef enum {true = 1, false = 0} bool;
typedef struct Node {
    int prefix;		// 当前节点为前缀的数量
    int endwith;	// 以当前节点为末尾的数量
    struct Node *next[SIZE];
} Node;

Node * newNode();
Node* insert(Node *root, const char *str);
Node* find(Node *root, const char *str);
bool delete(Node *root, const char  *str);
void clear(Node *root);

Node* newNode() {
    Node *node = (Node *)malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    return node;
}

/*
	递归插入节点，沿途修改prefix和endwith
*/
Node* insert(Node *root, const char *str) {
    if (!root) {
        root = newNode();
    }
    ++(root -> prefix);
    if(str[0] == '\0') {
        ++(root ->endwith);
        return root;
    }
    int i = str[0] - 'a';
    Node **p = &(root -> next[i]);
    *p = insert(*p, str + 1);
    return root;
}

/*
	递归查找str字符串，并返回叶子节点
*/
Node* find(Node *root, const char *str) {
    if (!root) {
        return NULL;
    }
    if(str[0] == '\0') {
        return root;
    }
    int i = str[0] - 'a';
    Node *p = root -> next[i];
    return find(p, str + 1);
}

/*
	在树中删除str字符串，如果未找到返回false
	沿途prefix和叶子节点endwith减一
*/
bool delete(Node *root, const char *str) {
    if (!root) {
        return false;
    }
    if(str[0] == '\0') {
        if (root -> endwith == 0) {
            return false;
        }
        --(root -> endwith);
        --(root -> prefix);
        return true;
    }
    int i = str[0] - 'a';
    Node *p = root -> next[i];
    if(delete(p, str + 1)) {
        --(root -> prefix);
        return true;
    }
    return false;

}

/*
	删除字典树，递归删除子节点
*/
void clear(Node *root) {
    if (root == NULL) {
        return ;
    }
    for (int i = 0; i < SIZE; ++i) {
        clear(root -> next[i]);
    }
    free(root);
}

int main() {
    char *p[4] = {"zha", "zhang", "", "zz"};

    Node *root = NULL;
    for (int i = 0; i < 4; ++i) {
        if (strcmp(p[i], "") != 0) {	// 字符串为空需忽略，否则会作为空字符串建立节点，root中的endwith和prefix会计数。
            root = insert(root, p[i]);
        }
    }
    printf("%d\n", find(root, "z") -> prefix);
    printf("%d\n", find(root, "") -> prefix);
    printf("%d\n", find(root, "zhan") -> prefix);
    delete(root, "zh");
    printf("%d\n", find(root, "zha") -> endwith);
    printf("%d\n", find(root, "") -> endwith);
    printf("%d\n", find(root, "zhang") -> endwith);

    return 0;
}
