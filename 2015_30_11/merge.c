#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};
struct node * createNode(int);
struct node * createList(int);
struct node * merge(struct node *, struct node *);
int main(){
        int num1 = 14568;
	int num2 = 237;
        struct node *head1 = createList(num1);
	struct node *head2 = createList(num2);
	struct node *ptr = merge(head1, head2);
	struct node *cur = ptr;
	while(cur != NULL){
		printf("%d->", cur->num);
		cur = cur->next;
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

struct node * merge(struct node *head1, struct node *head2){
	struct node* ptr = NULL;
 	if(head1 == NULL && head2 == NULL)
		return NULL;
	else if(head1 == NULL) 
		return head2;
	else if(head2 == NULL) 
		return head1;
	if(head1->num <= head2->num){
		ptr = head1;
		ptr->next = merge(head1->next, head2);
  	}
	else{
		ptr = head2;
		ptr->next = merge(head1, head2->next);
  	}
	return ptr;
}
