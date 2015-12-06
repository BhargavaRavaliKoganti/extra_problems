#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};
struct node * createNode(int);
struct node * createList(int, int);
struct node * merge(struct node *, struct node *);
int rthValueInTableMerge(struct node*, struct node*, int);
int main(){
	int num1 = 3;
	int num2 = 5;
	int r = 5;
	struct node *head1 = createList(num1, (r));
	struct node *head2 = createList(num2, (r));
	int rthNum = rthValueInTableMerge(head1, head2, r);
	printf("%d\n", rthNum);
	return 0;
}

struct node * createNode(int num) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = num;
        newNode->next = NULL;
        return newNode;

}

struct node * createList(int num, int r) {
        struct node *head = createNode(num * r);
	r--;
        while (r) {
                struct node *newNode = createNode(num * r);
                newNode->next = head;
                head = newNode;
		r--;
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
        else if(head1->num > head2->num){
		ptr = head2;
                ptr->next = merge(head1, head2->next);
        }
	return ptr;
}

int rthValueInTableMerge(struct node *head1, struct node *head2, int r){
	struct node *head = merge(head1, head2);
	struct node *cur = head;
	while(cur->next != NULL){
		if(cur->num == cur->next->num){
			cur->next = cur->next->next;
		}
		else
			cur = cur->next;
	}
	struct node *ptr = head;
	int val = 0;
	while(r){
		if(ptr->next != NULL){
			val = ptr->num;
			ptr = ptr->next;
			r--;			
		}
		else
			break;
	}
	return val;
}
