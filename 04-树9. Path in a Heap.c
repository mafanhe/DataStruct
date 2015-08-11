#include <stdio.h>
#include <stdlib.h>
typedef struct HeapStruct *MinHeap;
struct HeapStruct{
  int * Elements;
  int size;
  int capacity;
};
MinHeap Create(int Maxsize){
  MinHeap H=malloc(sizeof(struct HeapStruct));
  H->Elements=malloc((Maxsize+1)*sizeof(int));
  H->size=0;
  H->capacity=Maxsize;
  H->Elements[0]=0;
  return H;
}
void Insert(MinHeap H,int item){
  int i;
  i=++H->size;
  for(;H->Elements[i/2]>item;i/=2)
    H->Elements[i]=H->Elements[i/2];
  H->Elements[i]=item;
}
void PrintHeap(MinHeap H){
  int i;
  for(i=0;i<=H->size;i++)
    printf("%d ",H->Elements[i] );
}
void PrintPath(MinHeap H,int index){
  int i;
  for(i=index;i>1;i/=2)
    printf("%d ",H->Elements[i] );
  printf("%d\n",H->Elements[1] );
}
int main(int argc, char const *argv[]) {
  int m,n,i,j,temp,index;
  scanf("%d %d",&m,&n );
  if (m==0||n==0||m>1000) return 0;
  MinHeap H=Create(m);
  i=m;
  while(i){
    scanf("%d", &temp);
    Insert(H,temp);
    i--;
  }
  j=n;
  while (j) {
    scanf("%d", &index);
    PrintPath(H,index);
    j--;
  }
  //PrintHeap(H);
  return 0;
}
