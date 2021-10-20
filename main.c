#include "ex.h"

BOOL cmp_char(void* element1, void* element2) /*function definition*/
{
    if (*(char*)element1 == *(char*)element2) /*If the 2 variables are equal*/
        return TRUE; /*return TRUE*/
    return FALSE; /*return FALSE*/
}

void free_char(void* element) /*function definition*/
{
    free((char*)element); /* make casting, free memory allocation*/
}

void print_char(void* element) /*function definition*/
{
    printf("%c", *(char*)element); /*make casting, print the variable*/
}

int main()
{
    char ch,*temp;
    int n,i;
    BOOL res;
    PNode head=NULL,tail=NULL;
	
    printf("Enter number of characters ");
    scanf("%d",&n);            
    printf("\nEnter %d characters,separated by enter: ",n);
    for(i=0;i<n;i++) 
    {
        temp=(char*)malloc(sizeof(char));
        if (NULL==temp)
	    {
	        printf("\nCan't allocate data memory");
	        freeAll(&head,free_char);
	        return 1;
        } 
        scanf(" %c",temp);
        res=insertEntry(&head,&tail,temp,cmp_char);
	    if(FALSE==res)  /* Can't allocate node memory or data is allready exists*/
	    {							
	        printf("\nCan't allocate node memory or data is allready exists");
	        freeAll(&head,free_char);
	        return 1;
	    }
    }  
     printAll(head,print_char); 

     printf("\nEnter an element for deleting: ");
     scanf(" %c",&ch);
     res=deleteNode(&head,&tail,&ch,cmp_char,free_char);
     if(FALSE==res)   
        printf("%c don't exists in list\n",ch);

     printAll(head,print_char);

     freeAll(&head,free_char);
     printf("\nYour list was destroyed\n");
	
     return 0;
}