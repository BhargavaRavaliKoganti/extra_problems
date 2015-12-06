#include<stdio.h>
#include<stdlib.h>
struct node{
        int num;
        struct node *next;
};

struct node * createNode(int);
struct node * createList(int);
struct node * insertIntoCircularList(struct node *, int);
int len = 0;

int main(){
        int num = 34578;
	struct node *head = createList(num);
	int value = 6;
	struct node * ptr = insertIntoCircularList(head, value);
	int i =0;
	struct node *temp = ptr;
	struct node *cur = ptr->next;
	do{
		printf("%d->", temp->num);
		temp = temp->next;
		i++;
	}while(i != len+1);
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
	len++;
        num /= 10;
        while (num) {
                struct node *newNode = createNode(num % 10);
                newNode->next = head;
                head = newNode;
		len++;
                num /= 10;
        }
	struct node *ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = head;
        return head;
}

struct node * insertIntoCircularList(struct node * head, int num){
	if(head == NULL)
		return NULL;
	struct node * ptr = head;
	struct node * cur = (struct node *)malloc(sizeof(struct node*));
	cur->num = num;
	if(ptr->num > num){
		cur->next = head;
		head = cur;
	}
	else{	
		while(ptr){
			if(ptr->next->num > num){
				cur->next = ptr->next;
				ptr->next = cur;
				break;
			}
			ptr = ptr->next;
		}
	}
	return head;	
}
