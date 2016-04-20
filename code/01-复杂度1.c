#include<stdio.h>
void f(int list[],int k);
int main(){

  int k;
  scanf("%d",&k);
  int list[k];
  int i=0;
  while(i<k){
    scanf("%d",&list[i]);
    i++;
  }
  f(list,k);
  return 0;
}
void f(int list[],int k){

  int i,sum=0,max=list[0];
  for(i=0;i<k;i++){
    sum+=list[i];
    if(sum>max)max=sum;
    else if(sum<0) sum=0;
  }
  if (max<0) printf("%d",0 );
  else printf("%d",max);
}
