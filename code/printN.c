/*解决问题方法的效率与空间的利用效率有关*/
#include <stdio.h>
//循环
void printN1(int n) {
  for (int i = 1; i <= n; i++) {
    printf("%d\t",i );
  }
}
//递归，消耗空间
void printN2(int n){
  if(n){
    printN2(n-1);
    printf("%d\t",n );
  }
  //printf("%d\t",n );
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d",&n );
  printN1(n);
  printN2(n);
  return 0;
}
