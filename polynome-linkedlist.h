#ifndef POLYNOME_LINKEDLIST
#define POLYNOME_LINKEDLIST
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 定义数据节点
typedef struct polynome_node {
  // 系数
  int coefficient;
  // 指数
  int exponent;
  // 指向下一项
  struct polynome_node* next;
} polynome_node_t, *polynome_node_tp;

/**
 *  初始化链表操作，成功返回1，失败返回0（可能内存分配错误）
 */
int init(polynome_node_tp* head);

/**
 * 插入多项式节点，在链表中我们按照指数从高到底排序，插入的关键是找到合适的位置，
 * 这里我们使用pre和current来保存待插入节点的前后两个节点，
 * 成功返回1，失败返回0（可能内存分配错误）
 */
int insert(polynome_node_tp head, int coefficient, int exponent);

/**
 * 根据指数项删除多项式节点，成功返回1，失败返回0（可能内存分配错误）
 */
int delete (polynome_node_tp head, int exponent);

/**
 * 打印当前的多项式
 */
void print(polynome_node_tp head);

/**
 * 获取多项式表达式
 */
void toString(polynome_node_tp head, char* buffer);

/**
 *计算当前的多项式
 */
int calculate(polynome_node_tp head, int value);
#endif  // POLYNOME_LINKEDLIST
