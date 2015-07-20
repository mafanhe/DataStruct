/*最大子列和问题*/
/*算法一*/
int MaxSumOfList(int a[],int n){
  int thisSum,MaxSum;
  int i,j,k;
  for (i = 0; i < n; i++) {/*i是子列左端位置*/
    for (j = i; j < n; j++) {/*j是子列右端位置*/
      thisSum=0;/*thisSum是a[i]到a[j]的和*/
      for (K = i; K <j; K++) thisSum+=a[k];
      if (thisSum>MaxSum) MaxSum=thisSum;
    }
  }
  return MaxSum;
}
/*算法二*/
int MaxSumOfList(int a[],int n){
  int thisSum,MaxSum;
  int i,j;
  for (i = 0; i < n; i++) {/*i是子列左端位置*/
    thisSum=0;/*thisSum是a[i]到a[j]的和*/
    for (j = i; j < n; j++) {/*j是子列右端位置*/
      thisSum+=a[j];
      if (thisSum>MaxSum) MaxSum=thisSum;
    }
  }
  return MaxSum;
}
/*算法三：分而治之*/
/*算法四：在线算法*/
int MaxSubseqSum4( int A[], int N )
{
  int ThisSum, MaxSum;
  int i;
  ThisSum = MaxSum = 0;
  for( i = 0; i < N; i++ ) {
    ThisSum += A[i]; /* 向右累加 */
      if( ThisSum > MaxSum )
        MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
      else if( ThisSum < 0 ) /* 如果当前子列和为负 */
        ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
  }
    return MaxSum;
}
