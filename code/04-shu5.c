/*并查集-数组的实现
 *还需要考虑树的的实现。。。。。
*/

#include <stdio.h>
#include <stdlib.h>

int connected(int p, int q,int id[]){
	return id[p]==id[q];
}
void union1(int p, int q,int id[],int n){
	int pid= id[p];
	int qid=id[q];
	int j;
	for(j=0;j<n+1;j++){
		if (id[j]==pid) id[j]=qid;
	}
}
void components(int id[],int n){
	int i,num=0;
	int cz[n+1];
	for (i = 0; i < n+1; i++) {
		cz[i]=0;
	}
	for (i = 1; i < n+1; i++) {
		cz[id[i]]++;
	}
	for (i = 1; i < n+1; i++) {
		if (cz[i]!=0) {
			num++;
		}
	}
	if (num==1) printf("The network is connected.\n");
	else printf("there are %d components.\n",num );
}
int main(int argc, char const *argv[]) {

	int n,m,i,p,q;
	char c;
	scanf("%d", &n);
	/*初始化*/
	int id[n+1];
	for (i = 0; i < n+1; i++)
		id[i] = i;
	while(1){
		scanf("%c",&c);
		if (c=='C') {
			scanf("%d %d",&p,&q );
			if(connected(p,q,id)){
				printf("yes\n");
			}else
				printf("no\n");
		}else if(c=='I'){
			scanf("%d %d",&p,&q );
			union1(p,q,id,n);
		}else if(c=='S') break;

	}
	/*for ( i = 1; i < n+1; i++) {
		printf("%d ",i );
	}
	printf("\n");
	for ( i = 1; i < n+1; i++) {

		printf("%d ",id[i] );
	}*/
	components(id,n);
	return 0;
}
