#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int xs;
  int zs;
  struct Node *Next;
}List;
List L,*Ptrl;
List *MakeEmpty(){
  List *PtrL;
  Ptrl=(List*)malloc(sizeof(List));
  PtrL->Next=NULL;
  return PtrL;
}
List *FindKth(int K,List *PtrL){
  int i=1;
  List *p=PtrL;
  while(p&&i<K){
    p=p->Next;
    i++;
  }
  if(i==K)  return p;
  else return NULL;
}
List*Insert(int X,int Y,int i,List *PtrL){/*新节点插入到第i-1节点的后面*/
  List *p,*s;
  if(i==1){
    s=(List*)malloc(sizeof(List));
    s->xs=X;
    s->zs=Y;
    s->Next=PtrL;
    return s;
  }
  p=FindKth(i-1,PtrL);
  if(p==NULL){
    printf("参数i错");
    return NULL;
  }else{
    s=(List *)malloc(sizeof(List));
    s->xs=X;
    s->zs=Y;
    s->Next=p->Next;
    p->Next=s;
    return PtrL;
  }
}
void Traversal(List * PtrL){
  List *pt=PtrL;
  while(pt){
    if(pt->zs==0) printf("%d %d",pt->xs,pt->zs );
    else  printf("%d %d ",pt->xs,pt->zs );
    pt=pt->Next;
  }
}
void Derivation(List *PtrL){
  List *p=PtrL;
  if(p->zs==0&&p->xs==0)  {printf("0 0");return;}
  int a,b;
  while(p){
    if(p->xs&&p->zs) {
      a=(p->xs)*(p->zs);
      b=(p->zs)-1;
      if(b==0) printf("%d 0",a );
      else printf("%d %d ",a,b );
    }

    p=p->Next;
  }
}
int main(int argc, char const *argv[]) {
  List *p;
  //p=MakeEmpty();
  int a,b,i=1;
  scanf("%d %d",&a,&b );
  while(b){
    p=Insert(a,b,i,p);
    i++;
    //Traversal(p);
    scanf("%d %d",&a,&b );
  }
  p=Insert(a,b,i,p);
  //Traversal(p);
  Derivation(p);
  return 0;
}
