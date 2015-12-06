#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};
struct node * createNode(int);
struct node * createList(int);
struct node * addTwoLists(struct node *, struct node *);
int main(){
        int num1 = 14568;
        int num2 = 237;
        struct node *head1 = createList(num1);
        struct node *head2 = createList(num2);
	struct node *res = addTwoLists(head1, head2);
	struct node *ptr = res;
	while(ptr != NULL){
		printf("%d->", ptr->num);
		ptr = ptr->next;
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

struct node * addTwoLists(struct node *head1, struct node *head2){
	if(head1 == NULL && head2 == NULL)
		return NULL;
	else if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	int carry = 0;
	int sum;
	struct node *head = NULL;
	while(head1 != NULL || head2 != NULL){
		struct node *ptr = (struct node*)malloc(sizeof(struct node*));
		struct node *cur = head;
		sum = 0;
		if(head1)
			sum = carry + head1->num;
		else 
			sum = carry + 0;
		if(head2)
			sum += head2->num;
		if(sum >= 10){
			carry = sum / 10;
		}
		else
			carry = 0;
		sum = sum % 10;
		ptr->num = sum;
                ptr->next = NULL;
		if(head == NULL){
			head = ptr;
		}
		else{
			while(cur->next != NULL){
				cur = cur->next;
			}
			cur->next = ptr;
		}
		if(head1)
			head1 = head1->next;
		if(head2)
			head2 = head2->next;
	}
	return head;
}
