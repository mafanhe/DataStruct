#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
  int addr;
  int data;
  int nextaddr;
  struct LNode *next;
}List;
List *list;

//List *InsertByIndex(int ,int ,int,int,List*);//通过index插入
List *Insert(int ,int ,int,List*);//在列表尾部插入

List *FindKth(int data,List *list);
List *Reverse(int,int,List*);
void Traversal(List * list);
int main(int argc, char const *argv[]) {
  int addr,data,nextaddr;
  int firstaddr,num,k;
  scanf("%d %d %d",&firstaddr,&num,&k );
  int tag=num;
  List *list;
  while (tag) {
    scanf("%d %d %d",&addr,&data,&nextaddr );
    list=Insert(addr,data,nextaddr,list);


    tag--;
  }
  //Traversal(list);
  list=Reverse(num,k,list);
  Traversal(list);

  return 0;
}
List *Insert(int addr,int data,int nextaddr,List *list){
   List *temp,*p=list;
   temp=(List*)malloc(sizeof(List*));
   temp->addr=addr;
   temp->data=data;
   temp->nextaddr=nextaddr;
   temp->next=NULL;

   if(p==NULL){
     return temp;
   }
   else{
     while(p->next) p=p->next;
   }
   p->next=temp;
   return list;
}

List *FindKth(int data,List *list){
  List *p=list;
  while(p){
    if (p->data==data) return p;
    p=p->next;
  }
  return NULL;
}

void Traversal(List * list){
  List *pt=list;
  //printf("testtest\n" );
  while(pt){
    if (pt->nextaddr != -1 ){
      //格式输出，%.5意味着如果一个整数不足5位，输出时前面补0 如：22，输出：00022
      printf("%.5d %d %.5d\n", pt->addr, pt->data, pt->nextaddr);
    }else{
      //-1不需要以%.5格式输出
      printf("%.5d %d %d\n", pt->addr, pt->data, pt->nextaddr);
          }
      pt=pt->next;
    }
}
List *Reverse(int num,int k,List*list){
  List *p,*q;
  int index,mid;
  List *reverse=NULL;
  if(k==1) return list;
  else if(num==k){
    while(index-1){
      p=FindKth(index,list);
      q=FindKth(index-1,list);
      reverse=Insert(p->addr,p->data,q->addr,reverse);
      index--;
    }
    p=FindKth(index,list);
    reverse=Insert(p->addr,p->data,-1,reverse);
    return reverse;
  }else if(num%k==0){
    mid=k;
    index=num;
    while(mid-1){
      p=FindKth(mid,list);
      q=FindKth(mid-1,list);
      reverse=Insert(p->addr,p->data,q->addr,reverse);
      mid--;
    }
    p=FindKth(1,list);
    q=FindKth(index,list);
    reverse=Insert(p->addr,p->data,q->addr,reverse);
    while (index>k) {
      p=FindKth(index,list);
      q=FindKth(index-1,list);
      reverse=Insert(p->addr,p->data,q->addr,reverse);
      index--;
    }
    p=FindKth(index,list);
    reverse=Insert(p->addr,p->data,-1,reverse);
    return reverse;
  }else{
    index=k;
    int index2=k+1;
    while(index-1){
      p=FindKth(index,list);
      q=FindKth(index-1,list);
      reverse=Insert(p->addr,p->data,q->addr,reverse);
      index--;
    }
    p=FindKth(index,list);
    q=FindKth(index2,list);
    reverse=Insert(p->addr,p->data,q->addr,reverse);
    while (index2<num) {
      p=FindKth(index2,list);
      q=FindKth(index2+1,list);
      reverse=Insert(p->addr,p->data,q->addr,reverse);
      index2++;
    }
    p=FindKth(index2,list);
    reverse=Insert(p->addr,p->data,-1,reverse);
    return reverse;
  }
}
