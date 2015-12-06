#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};
struct node * createNode(int);
struct node * createList(int);
struct node * sortLinkedList(struct node*);
int main(){
	int num = 347658;
        struct node *head = createList(num);
	struct node *cur = sortLinkedList(head);
	struct node *ptr = cur;
	while(ptr){
		printf("%d->", ptr->num);
		ptr= ptr->next;
	}
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

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *cur;
	struct node *ptr;
	int temp;
	for (cur = head; cur->next != NULL; cur = cur->next){
		for (ptr = cur->next; ptr != NULL; ptr = ptr->next){
			if (cur->num > ptr->num){
				temp = cur->num;
				cur->num = ptr->num;
				ptr->num = temp;
			}
		}
	}
	return head;
}
