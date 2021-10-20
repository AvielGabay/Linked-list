#ifndef _ HEADER_H
#define _ HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef  struct ListNode* PNode; /*struct declaration */
typedef enum { FALSE, TRUE } BOOL; /*True = 1 , False = 0*/

typedef BOOL (*compare_func)(void*, void*);
/*function declaration
function name: compare_func
input: 2 pointers of void*
output: Returns 1 if 2 variables are equal, otherwise returns 0*/

typedef void (*print_func)(void*);
/*function declaration
function name: print_func
input: 1 pointer of void*
output: make casting to variable, print the variable*/

typedef void (*free_func)(void*);
/*function declaration
function name: free_func
input: 1 pointer of void*
output: free memory allocation from variable*/

/***********************************************/
/*       public interface:                      */

/* inserting a new element.*/
BOOL insertEntry(PNode* head, PNode* tail, void *data, compare_func func);
/*function declaration
function name: insertEntry
input: 2 pointers of PNode*, i pointer of void*, 1 function
output: Returns 1 if the new node is successful, otherwise returns 0*/

/* deleting an element,pointered by todel*/
BOOL deleteNode(PNode* head, PNode* tail, void *todel, compare_func func1, free_func func2);
/*function declaration
function name: deleteNode
input: 2 pointers of PNode*, 1 pointer of void*, 2 functions
output: Returns 1 if node deletion was successful, otherwise returns 0*/

/* print the elements in the list */
void printAll(PNode head, print_func func);
/*function declaration
function name: printAll
input: 1 pointer of PNode, 1 function
output: print variable*/

/* deleting the entire list */
void freeAll(PNode* head, free_func func);
/*function declaration
function name: freeAll
input: 1 pointer of PNode*, 1 function
output: free memory allocation*/

#endif