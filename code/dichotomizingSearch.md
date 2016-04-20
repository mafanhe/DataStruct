# 二分法 伪码描述
## 循环

    int Search(list[],int i,int size){
      m=0;
      n=size;
      loop{
        if(m=n)return -1;
        index=list[(m+n)/2]
        if(index=i)return index;
        else if(index>i){
          m= (m+n)/2+1;
          }else n=(m+n)/2-1;
        }
    }

##递归
    int Search(list[],int i,int m,int n){
      index = (m+n)/2;
      if(list[index]==i]) return index;
      else if(list[index]<i) Search(list,i,index+1,n);
      else Search(list,i,m,index-1);
      if(m=n)return -1;
    }
##java实现
    public static int binarySearch(int[] a,int key) {
      int lo = 0, hi =a.length-1;
      while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(key<mid) hi=mid-1;
        else if(key>mid)lo=mid+1;
        else return mid;
      }
      return -1;
    }
