#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};

struct node * createNode(int);
struct node * createList(int);
int medianOfSortedLinkedList(struct node *);
int main(){
        int num = 345678;
        struct node *head = createList(num);
	int val = medianOfSortedLinkedList(head);
	printf("%d\n", val);
	return 0;	
}

struct node * createNode(int num) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = num;
        newNode->next = NULL;
        return newNode;

}

struct node * createList(int num) {
        struct node *head = createNode(num % 10);
        num /= 10;
        while (num) {
                struct node *newNode = createNode(num % 10);
                newNode->next = head;
                head = newNode;
                num /= 10;
        }
        return head;
}

int medianOfSortedLinkedList(struct node *head){	
	if (head != NULL){
		struct node *ptr = head;
		struct node *cur = head;
        	while (cur->next != NULL && cur != NULL){
            		cur = cur->next->next;
	            	ptr = ptr->next;
        	}
		return ptr->num;
    	}
	return 0;
}

