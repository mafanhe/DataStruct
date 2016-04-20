#include <stdio.h>
#include <time.h>

clock_t start, stop;
/* clock_t是clock()函数返回的变量类型*/
double duration;
/* 记录被测试函数运行时间，以秒为单位*/
int main(int argc, char const *argv[]) {
  /*不再测试范围内的准备给哦你作写在clock()调用之前*/
  start=clock();
  MyFunction();
  stop=clock();
  duration = ((double)(stop-start))/CLK_TCK;
  return 0;
}
