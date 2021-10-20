#include "ex.h"

typedef struct  ListNode /*struct definition*/
{
	void* data;
	struct  ListNode* next;
} ListNode;

BOOL insertEntry(PNode* head, PNode* tail, void* data, compare_func func) /*function definition*/
{
	PNode temp = *head;
	if (*head == NULL) /* If this is the first node */
	{
		(*head) = (PNode)malloc(sizeof(ListNode)); /*Dynamic memory allocation*/
		if (*head == NULL) /*if Dynamic memory allocation failed*/
			return FALSE; /*return FALSE*/
		(*head)->data = data; 
		(*head)->next = NULL;
		(*tail) = (*head);
		return TRUE; /*return TRUE*/
	}
	while ((temp!=NULL) && (func(temp->data, data) == 0)) /*while loop until function call return 1, and temp is equal to NULL*/
		temp = temp->next; /*dvanced to the next node*/
	if (temp == NULL) /*if temp = NULL, this means that this node must be inserted*/
	{
		temp = (PNode)malloc(sizeof(ListNode)); /*Dynamic memory allocation*/
		if (temp == NULL) /*if Dynamic memory allocation failed*/
			return FALSE; /*return FALSE*/
		temp->data = data;
		temp->next = NULL;
		(*tail)->next = temp; /*Update list*/
		(*tail) = temp; /*Update tail*/
		return TRUE; /*return TRUE*/
	}
	return FALSE; /*return FALSE*/
}

BOOL deleteNode(PNode* head, PNode* tail, void* todel, compare_func func1, free_func func2) /*function definition*/
{
	int i = 0;
	PNode TempToFree = *head, prev;
	if (*head == NULL) /*if its the first node*/
		return FALSE; /*return FALSE*/
	prev = TempToFree; 
	while ((TempToFree!=NULL) && (func1(TempToFree->data, todel) == 0)) /*while loop until function call return 1, and TempToFree is equal to NULL*/
	{
		prev = TempToFree; /*prev gets the node*/
		TempToFree = TempToFree->next; /*TempToFree gets the next node*/
		i++; /*i = i + 1*/
	}
	if (TempToFree != NULL && i != 0) /*if we found that variable and we nedd to delete the node*/
	{
		func2(TempToFree->data); /*function call to free memory from variable of void**/
		prev->next = TempToFree->next; /*Update list*/
		if (TempToFree->next == NULL) /*If its the last node*/
			tail = prev; /*Update tail*/
		return TRUE; /*return TRUE*/
	}
	else if (TempToFree != NULL && i == 0) /* If its the first node*/
	{
		func2(TempToFree->data); /*function call to free memoty from variable of void**/
		(*head) = (*head)->next; /*update list*/
		return TRUE; /*return TRUE*/
	}
	return FALSE; /*return FALSE*/
}

void freeAll(PNode* head, free_func func) /*function definition*/
{
	while (*head != NULL) /*while loop until *head = NULL*/
	{
		func((*head)->data); /*function call to free memory from variable of void***/
		(*head) = (*head)->next; /*advanced to the next node*/
	}
}

void printAll(PNode head, print_func func) /*function definition*/
{
	PNode temp = head;
	while (temp != NULL) /*while loop until temp = NULL*/
	{
		func((&(*temp))->data); /*function call, to print variable of void**/
		temp = temp->next; /*advanced to the next node*/
	}
}