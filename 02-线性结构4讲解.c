#include<stdlib.h>
#include<stdio.h>

#define MaxSize 1000
//Stack implement with array
typedef struct node{
        int Data[MaxSize];
        int cap;
        int top;        //size = top+1
}Stack;

int M,N,K;
Stack *CreateStack(){
        Stack *PtrS = (Stack*)malloc(sizeof(struct node));
        PtrS->cap = MaxSize;
        PtrS->top = -1;
        return PtrS;
}

void Push(Stack *PtrS, int ele){
        if(PtrS->top == PtrS->cap-1){
                printf("FULL");
                return;
        }
        PtrS->top++;
        PtrS->Data[PtrS->top]=ele;
}

int top(Stack *PtrS){
        return PtrS->Data[PtrS->top];
}

void Pop(Stack *PtrS){
        if(PtrS->top==-1){
                printf("Empty");
                return;
        }
        PtrS->top--;
}

int check_stack(int v[]){
        int new_cap = M+1;
        Stack *ps = CreateStack();
        Push(ps,0);     //dummy element
        int idx = 0;    //index of v
        int num=1;      //to put to stack
        while(idx!=N){
                while(top(ps)<v[idx]&&idx!=N&&(ps->top+1)<new_cap)
                        Push(ps,num++);
                if(top(ps)==v[idx]){
                        Pop(ps);
                        idx++;
                }
                else
                        return 0;       //false
        }
        return 1;

}

int main(){
        //输入
        scanf("%d %d %d",&M,&N,&K);
        int *v = (int *)malloc(sizeof(int)*N);
        int i;
        for(;K!=0;--K){
                for(i = 0; i!= N; ++i)
                        scanf("%d",v+i);
                if(check_stack(v))
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
