#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};

struct node * createNode(int);
struct node * createList(int);
void reverseLinkedList1(struct node **);
struct node * reverseLinkedList2(struct node *);

int main(){
        int num = 345678;
        struct node *head1 = createList(num);
	struct node *head2 = createList(num);
	reverseLinkedList1(&head1);
	struct node *ptr = reverseLinkedList2(head2);
	struct node *x = head1;
	struct node *y = ptr;
	printf("Using reverseLinkedList1 function:\n");
	while(x){
		printf("%d->", x->num);
		x = x->next;
	}
	printf("\nUsing reverseLinkedList2 function:\n");
	while(y){
		printf("%d->", y->num);
		y = y->next;
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

void reverseLinkedList1(struct node **head){
	struct node *ptr = (struct node *)malloc(sizeof(struct node *));
	struct node *cur = (struct node *)malloc(sizeof(struct node *));
	if(*head == NULL)
		return;
	ptr = *head;
	cur = ptr->next;
	if(cur == NULL)
		return;
	reverseLinkedList1(&cur);
	ptr->next->next = ptr;
	ptr->next = NULL;
	*head = cur;
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
