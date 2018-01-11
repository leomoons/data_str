/*Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.*/
/*The function Reverse is supposed to return the reverse linked list of L, with a dummy header.*/


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); 
void Print( List L ); 
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */



List Reverse( List L ){
	List rtu,temp,Lold;
	rtu=(List)malloc(sizeof(struct Node));
	rtu->Next=NULL;
	Lold=L->Next;
	while(Lold){
		temp=Lold->Next;
		Lold->Next=rtu->Next;
		rtu->Next=Lold;
		Lold=temp;
	}
	temp=rtu->Next;
	Lold=L;
	while(temp){
		Lold->Next=temp;
		Lold=Lold->Next;
		temp=temp->Next;
	}
	/*Lold=L->Next;
	while(temp){
		Lold=temp;
		Lold=Lold->Next;
		temp=temp->Next;
	}
	*/
	/*L=rtu;*/
	return rtu;
}


List Read(){
	int num;
	scanf("%d",&num);
	List L,temp;
	L=(List)malloc(sizeof(struct Node));
	L->Next=NULL;
	temp=L;
	for(int i=0;i<num;i++){
		temp->Next=(List)malloc(sizeof(struct Node));
		scanf("%d",&(temp->Next->Element));
		temp=temp->Next;
	}
	return L;
}



void Print(List L){
	L=L->Next;
	while(L){
		printf("%d ",L->Element);
		L=L->Next;
	}
}
