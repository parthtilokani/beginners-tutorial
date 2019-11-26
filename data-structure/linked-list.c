// Program of linked list using structure insert(at any position), display, append(at end),
// delete(from any position) to implement stack use append and delete(from last position)

#include <stdio.h>
#include <stdlib.h>
// node of linked list
struct node{
	int info;
	struct node *next;
};

struct node *node;
struct node *head = NULL;

struct node* append(struct node *head, int element){
	if(head == NULL){
		head = (struct node*)malloc(sizeof(struct node));
		head->info = element;
		head->next = NULL;
		return head;
	}else{
		struct node *tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = (struct node*)malloc(sizeof(struct node));
		tmp->next->info = element;
		tmp->next->next = NULL; 
		return head;
	}
}

struct node* insert(struct node *head,int element, int index){
	struct node *tmp,*tmp1 = head;
	if(index == 0){
		tmp = head;
		head = (struct node*)malloc(sizeof(struct node));
		head->info = element;
		head->next = tmp;
		return head; 
	}else{
		while(index > 0){
			if(head == NULL){
				printf("%s\n","Out of range");
				return tmp1;
			}
			tmp = head;
			head = head->next;
			index--;
		}
		tmp->next = (struct node*)malloc(sizeof(struct node));
		tmp->next->info = element;
		tmp->next->next = head;
	}
	return tmp1;
}

int display(struct node *head){
	printf("\n%s\n", "linked list");
	while(head != NULL){
		printf("%d -> ", head->info);
		head = head->next;
	}
	printf("%s\n","NULL");
}

int memory_free(struct node *head){
	struct node *tmp = head;
	struct node *tmp1;
	if(head->next == NULL){
		printf("\n%s\n","Done cleaning" );
		free(head);
		head = NULL;
		return 0;
	}
	while(head->next != NULL){
		tmp1 = head;
		head = head->next;
	} 
	free(head);
	tmp1->next = NULL;
	memory_free(tmp);
}

struct node* delete(struct node *head, int index){
	struct node *tmp,*tmp1 = head;
	if(index == 0){
		tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
	while(index > 0){
		if(head->next == NULL){
			printf("%s\n","index out of bound");
			return 0;
		}
		tmp = head;
		head = head->next;
		index--;
	}
	tmp->next = head->next;
	free(head);
	return tmp1;
}

int main(int argc, char const *argv[])
{
	node = append(head, 2);
	node = append(node, 3);
	node = append(node, 4);
	node = insert(node,20,4);
	node = delete(node, 1);
	display(node);
	memory_free(node);
	return 0;
}
