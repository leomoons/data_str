/*Write a function to add two polynomials. Do not destroy the input. Use a linked list 
  *implementation with a dummy head node. Note: The zero polynomial is represented by 
  *an empty list with only the dummy head node.
*/

/*where Polynomial is defined as the following:*/
/* Nodes are sorted in decreasing order of exponents.*/

/*The function Add is supposed to return a polynomial which is the sum of a and b.*/



#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */



Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial rtu; //the adress would be returned
    rtu = (Polynomial)malloc(sizeof(struct Node));
    rtu->Next=NULL;
    a=a->Next;
    b=b->Next;
    Polynomial temp = rtu;  //set a temp point so that rtu will not change its head to
    while(a&&b){
        Polynomial dev;
        if(a->Exponent>b->Exponent){
      	    dev=a;
	    a=a->Next;
	    dev->Next = NULL;
	}
	else if(a->Exponent<b->Exponent){
	    dev=b; 
	    b=b->Next;
	    dev->Next = NULL;
	}
	else{
	    dev = (Polynomial)malloc(sizeof(struct Node));
	    dev->Coefficient=a->Coefficient+b->Coefficient;
            dev->Exponent=a->Exponent;
	    a=a->Next;
	    b=b->Next;
	    dev->Next=NULL;
	    if(dev->Coefficient==0)
                continue;
	}
	temp->Next=dev;
	temp=temp->Next;
    }
     while(a){  
        temp->Next=a;  
        temp=temp->Next;  
        a=a->Next;  
    }  
    while(b){  
        temp->Next=b;  
        temp=temp->Next;  
        b=b->Next;  
    }  
    temp->Next=NULL;
    return rtu;
}




/*将多项式读入*/

Polynomial Read( ){
	int n;
	Polynomial pol;   				//定义返回的dummy head
	pol=(Polynomial)malloc(sizeof(struct Node));
	pol->Next =NULL;
	Polynomial temp=pol;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Polynomial dev;
		dev=(Polynomial)malloc(sizeof(struct Node));
 		scanf("%d",&dev->Coefficient);
		scanf("%d",&dev->Exponent);
		temp->Next=dev;
		temp=temp->Next;
		temp->Next = NULL;
	}
	return pol;
}


/*将多项式链表写在屏幕上*/
void Print(Polynomial p){
	p=p->Next;
	if(p==NULL){
		printf("0");
	}
	else{
		while(p!=NULL){
			printf("%d ",p->Coefficient);
			printf("%d ",p->Exponent);
			p=p->Next;
		}
	}
}
