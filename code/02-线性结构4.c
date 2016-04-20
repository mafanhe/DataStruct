#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node * next;
}LinkStack;
LinkStack *Top;

LinkStack *CreateStack(){
  LinkStack *s;
  s=(LinkStack*)malloc(sizeof(struct Node));
  s->next=NULL;
  return s;
}
int IsEmpty(LinkStack *S){
  return (S->next==NULL);
}
void Push(int data,LinkStack *s){
  struct Node *TmpCell;
  TmpCell=malloc(sizeof(struct Node));
  TmpCell->data=data;
  TmpCell->next=s->next;
  s->next=TmpCell;
}
int Pop(LinkStack *s){
  struct Node *FirstCell;
  int TopElem;
  if(IsEmpty(s))return 0;
  else{
    FirstCell=s->next;
    s->next=FirstCell->next;
    TopElem=FirstCell->data;
    free(FirstCell);
    return TopElem;
  }
}
void Test(int m,int n,int s[]){
  int i=1,k=0,max=0,popdata;
  LinkStack *ls=CreateStack();
  while (k<n) {
    popdata=s[k];
    k++;
      //printf("popdata=%d\n",popdata );
    while(popdata>=i) {
      Push(i,ls);
      i++;
      max++;
      //printf("T!: i=%d,max=%d\n",i,max );
      if(max>m){printf("NO\n" ); return;}
    }
    if(popdata<=i){
      if (Pop(ls)!=popdata) {
          printf("NO\n" );
          return;
      }
      max--;
    }
  }
  if(k==7)printf("YES\n");
  else printf("NO\n");
}

int main(int argc, char const *argv[]) {

  int m;/*the maximum capacity of the stack*/
  int n;/*the length of push sequence*/
  int k;/*the number of pop sequences to be checked*/
  int da;
  int i,j;
  scanf("%d %d %d",&m,&n,&k );
  int s[n];
  for (i = 0;  i< k; i++) {

    for (j = 0; j < n; j++) {
      scanf("%d",&da );
      s[j]=da;

    }
    Test(m,n,s);
  }
  return 0;
}
