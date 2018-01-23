#include<stdio.h>
#include"node.h"
#include<string.h>
int main(){
    link lnk={0};//创建一个链表
    link_init(&lnk);//初始化
    int size=link_size(&lnk);
    printf("this link size is %d\n",size);//查看是否清空链表
    link_insert(&lnk,1,"where is father",(float)7.6);
    link_insert(&lnk,2,"where is mather",(float)2.5);
    link_insert(&lnk,3,"where is brother",(float)4.6);
    link_insert(&lnk,4,"where is sister",(float)9.6);
    link_insert(&lnk,5,"where is uncle",(float)5.2);
    size=link_size(&lnk);
    printf("this link size is %d\n",size);//查看是否添加进链表
    node *t_node;//声明结构体指针接收查找到的结构体地址
    int i;
    for(i=1;i<6;i++){
       t_node=link_get(&lnk,i);
       printf("movie name is %s score is %lg\n",t_node->name,t_node->score);
    }
    link_remove(&lnk,2);//删除编号为2的节点
    t_node=link_get(&lnk,2);//检查是否删除
    printf("%d\n",(t_node==NULL));
    return 0;

}  

