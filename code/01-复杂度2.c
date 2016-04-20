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

  int i,sum=0,max=list[0],begin=list[0],begin2=list[0],end=list[0];
  for(i=0;i<k;i++){
    sum+=list[i];
    if(sum>max){max=sum;begin=begin2;end=list[i]; }
    //if(sum==max){if((i-begin2)<(end-begin)){begin=begin2;end=i;}}
    //计算和最大数字个数最小的开始下标与结束下标
    else if(sum<0) {sum=0;begin2=list[i+1];}
  }
  if (max<0) printf("%d %d %d",0,list[0],list[k-1] );
  else printf("%d %d %d",max,begin,end);
}
