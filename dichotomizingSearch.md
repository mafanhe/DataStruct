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
          m= (m+n)/2;
          }else n=(m+n)/2;
        }
    }
##递归
    int Search(list[],int i,int m,int n){
      index = (m+n)/2;
      if(list[index]==i]) return index;
      else if(list[index]<i) Search(list,i,index,n);
      else Search(list,i,m,index);
      if(m=n)return -1;
    }
