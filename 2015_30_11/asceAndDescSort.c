#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};

struct node * createNode(int);
struct node * createList(int);
struct node * sortLinkedList(struct node *);
struct node * reverseLinkedList2(struct node *);
int main(){
        int num = 3459876;
        struct node *head = createList(num);
	struct node *ptr = sortLinkedList(head);
	struct node *cur = ptr;
	printf("Sorted linked list\n");
	while(cur){
		printf("%d->", cur->num);
                cur = cur->next;    
        }
	printf("\n");
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

struct node * sortLinkedList(struct node *head){
	struct node *ptr = head;
	int lastNum;
	while(ptr){
		if(ptr->next == NULL)
			lastNum = ptr->num;
		ptr = ptr->next;
	}
	struct node *cur = head;
	while(cur){
		if(cur->next->num > lastNum){
			cur = cur->next;
			break;
		}
		cur = cur->next;
	}
	struct node *x = reverseLinkedList2(cur);
	struct node *y = x;
	struct node *z = head;
	while(z){
		if(z->next->num > y->num){
			z->next = y;
			break;
		}
		z = z->next;
	}
	return head;
}

struct node * reverseLinkedList2(struct node *head){
        struct node *ptr = NULL;
        struct node *cur = head;
        struct node *temp = (struct node*)malloc(sizeof(struct node*));
        while(cur != NULL){
                temp = cur->next;
                cur->next = ptr;
                ptr = cur;
                cur = temp;
        }
        return ptr;
}

