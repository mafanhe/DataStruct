#include <stdio.h>
#include <time.h>
#define MAXN 100
clock_t start, stop;
double duration;

double poly1(x){
  int i;
  double res=1;
  for ( i = 1; i <= MAXN; i++) res+=pow(x,i)/i;
  return res;
}
double poly2(x){
  int i;
  double res=1.0/MAXN;
  for ( i = MAXN-1; i >0; i--) res=1/i+x*res;
  return res;
}
void time(int i){
  if (i==1) {
    start=clock();
    poly1(1.1);
    stop=clock();
    duration = ((double)(stop-start))/CLK_TCK;
    printf("%f\n",(double)duration );
  }else{
    start=clock();
    poly1(1.1);
    stop=clock();
    duration = ((double)(stop-start))/CLK_TCK;
    printf("%f\n",(double)duration );
  }
}
int main(int argc, char const *argv[]) {
  time(1);
  time(2);
  return 0;
}
