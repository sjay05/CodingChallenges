/* --- Singly Linked List --- */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
};

class linked_list {
private:
    node *head, *tail;
public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }
    void add(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if (head == NULL) {
            head = tmp; tail = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void trav() {
        node *tmp;
        tmp = head;
        while (tmp != NULL) {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
};

int main() {
    
};