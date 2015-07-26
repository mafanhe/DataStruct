#include<stdio.h>
#define MAX_SIZE 100004

typedef struct tagLNode{
    int addr;      //节点位置Address
    int data;      //Data值
    int nextAddr;  //下个节点位置
    struct tagLNode *next;  //指向下个节点的指针
} LNode;
/*
    LNode *listReverse(LNode *head, int k);
    反转单链表函数
    参数1：单链表的头节点，
    参数2：反转子链表的长度，
    返回值：反转后的链表的第一个节点(不是头结点)

*/
LNode *listReverse(LNode *head, int k);
//输出单链表 参数为单链表的头结点
void printList(LNode *a);

int main()
{
    int firstAddr;
    int n = 0;            //节点数 N
    int k = 0;            //反转子链表的长度K
    int num = 0;          //链表建好之后的链表节点数
    int data[MAX_SIZE];   //存data值 节点位置作为索引值
    int next[MAX_SIZE];   //存next值 节点位置为索引
    int tmp;              //临时变量，输入的时候用

    scanf("%d %d %d", &firstAddr, &n, &k);
    LNode a[n+1];                //能存n+1个几点的数组。
    a[0].nextAddr = firstAddr;   //a[0] 作为头节点
    //读输入的节点
    int i = 1;
    for (; i < n+1; i++){
        scanf("%d", &tmp);
        scanf("%d %d", &data[tmp], &next[tmp]);
    }

    //构建单链表
    i = 1;
    while (1){
        if (a[i-1].nextAddr == -1){
            a[i-1].next = NULL;
            num = i-1;
            break;
        }
        a[i].addr = a[i-1].nextAddr;
        a[i].data = data[a[i].addr];
        a[i].nextAddr = next[a[i].addr];
        a[i-1].next = a+i;

        i++;
    }

    LNode *p = a;                    //p指向链表头结点
    LNode *rp = NULL;                //反转链表函数的返回值
    if (k <= num ){

        for (i = 0; i < (num/k); i++){
            rp = listReverse(p, k);  //
            p->next = rp;            // 第一次执行，a[0]->next 指向第一段子链表反转的第一个节点
            p->nextAddr = rp->addr;  // 更改Next值，指向逆转后它的下一个节点的位置

            int j = 0;
            //使p指向下一段需要反转的子链表的头结点（第一个节点的前一个节点）
            while (j < k){
                p = p->next;
                j++;
            }

        }
    }

    printList(a);
}

LNode *listReverse(LNode *head, int k)
{
    int count = 1;
    LNode *new = head->next;
    LNode *old = new->next;
    LNode *tmp = NULL;

    while (count < k){
        tmp = old->next;
        old->next = new;
        old->nextAddr = new->addr;
        new = old;   //new向后走一个节点
        old = tmp;   //tmp向后走一个节点
        count++;
    }
    //使反转后的最后一个节点指向下一段子链表的第一个节点
    head->next->next = old;
    if (old != NULL){
        //修改Next值，使它指向下一个节点的位置
        head->next->nextAddr = old->addr;
    }else{
        //如果old为NULL,即没有下一个子链表，那么反转后的最后一个节点即是真个链表的最后一个节点
        head->next->nextAddr = -1;
    }
    return new;
}

void printList(LNode *a)
{
    LNode *p = a;

    while (p->next != NULL){
        p = p->next;
        if (p->nextAddr != -1 ){
            //格式输出，%.5意味着如果一个整数不足5位，输出时前面补0 如：22，输出：00022
            printf("%.5d %d %.5d\n", p->addr, p->data, p->nextAddr);
        }else{
            //-1不需要以%.5格式输出
            printf("%.5d %d %d\n", p->addr, p->data, p->nextAddr);
        }
    }

}
