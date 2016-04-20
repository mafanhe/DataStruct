/*解决问题方法的效率与算法的巧妙程度有关*/
#include <stdio.h>
#include <math.h>
#include <time.h>

#define  MAXN 10 /* 多项式最大项数，*/
clock_t start,stop;
double duration;
//多项式计算f(x)=a0+a1x+...an-1x^n-1=anx^n
double poly(int n,double a[],double x){
  int i;
  double p=a[0];
  for (i=1; i <=n; i++) {
      p+=a[i]*pow(x,i);
  }
  return p;
}
//f(x)=a0+x(a1=x(...(an-1+x(an))...))
double poly2(int n,double a[],double x){
  int i;
  double p=a[n];
  for (i=n; i>=0; i--) {
      p=a[i-1]+x*p;
  }
  return p;
}

int main(int argc, char const *argv[]) {

  int i;
  double a[MAXN];
  for (i = 0; i < MAXN; i++) a[i]=(double)i;
  start=clock();
  poly(MAXN-1,a,1.1);
  stop=clock();
  duration = ((double)(stop-start))/CLK_TCK;
  printf("%f\n",(double)duration );
  return 0;
}
