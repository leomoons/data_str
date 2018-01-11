/*Write a program to evaluate a postfix expression. You only have to handle four kinds of operators: +, -, x, and /.*/


#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );
/*where expr points to a string that stores the postfix expression. It is guaranteed
that there is exactly one space between any two operators or operands. The function 
EvalPostfix is supposed to return the value of the expression. If it is not a legal 
postfix expression, EvalPostfix must return a special value Infinity which is defin
ed by the judge program.*/
int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */


ElementType EvalPostfix( char *expr ){
	ElementType dig[Max_Expr];
	int top=0;
	int i=0;
	while(expr[i]!='\0'){          			//字符串最后以\0结尾
		while(expr[i]>='0'&&expr[i]<='9'){      //首字符为数字
			dig[top]=dig[top]*10.0+expr[i]-'0';
			i++;
			if(expr[i]=='.'){
				i++;
				double flag=10.0;
				while(expr[i]>='0'&&expr[i]<='9'){
					dig[top]=dig[top]+(expr[i]-'0')/flag;
					flag*=10.0;
					i++;
				}
			}
			if(expr[i]==' '||expr[i]=='\0'){
				top++;
			}
		}
		if(expr[i]=='+'){
			if(top<=1){
				return Infinity;
			}
			else{
				dig[top-2]=dig[top-2]+dig[top-1];
				dig[top-1]=0;
				top--;
				i++;
			}
		}
		if(expr[i]=='*'){
			if(top<=1){
				return Infinity;
			}
			else{
				dig[top-2]=dig[top-2]*dig[top-1];
				dig[top-1]=0;
				top--;
				i++;
			}
		}
		if(expr[i]=='-'){
			if(expr[i+1]==' '||expr[i+1]=='\0'){
				if(top<=1){
					return Infinity;
				}
				else{
					dig[top-2]=dig[top-2]-dig[top-1];
					dig[top-1]=0;
					top--;
					i++;
				}
			}
			else if(expr[i+1]>='0'&&expr[i+1]<='9'){ 
				i++;
				while(expr[i]<='9'&&expr[i]>='0'){
				 	dig[top]=dig[top]*10.0-(expr[i]-'0');
					i++;	
					if(expr[i]=='.'){
				 		i++;
						double flag=10.0;
						while(expr[i]>='0'&&expr[i]<='9'){
							dig[top]=dig[top]-(expr[i]-'0')/flag;
							flag*=10.0;
							i++;
						}
				 	}
					if(expr[i]==' '||expr[i]=='\0'){
						top++;
					}
				}
			}
		}
		if(expr[i]=='/'){
			if(top<=1){
				return Infinity;
			}
			else if(dig[top-1]==0){
				return Infinity;
			}
			else{
				dig[top-2]=dig[top-2]/dig[top-1];
				dig[top-1]=0;
				top--;
				i++;
			}
		}
		if(expr[i]==' '){
			i++;
		}
	}
	if(top==1){
		return dig[0];
	}
	else{
		return Infinity;
	}
}
