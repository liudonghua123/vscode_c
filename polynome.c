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
int init(polynome_node_tp* head) {
  *head = malloc(sizeof(polynome_node_t));
  (*head)->next = NULL;
  return *head != NULL;
}

/**
 * 插入多项式节点，在链表中我们按照指数从高到底排序，插入的关键是找到合适的位置，
 * 这里我们使用pre和current来保存待插入节点的前后两个节点
 */
void insert(polynome_node_tp head, int coefficient, int exponent) {
  polynome_node_tp pre = head;
  polynome_node_tp current = head->next;
  while (current) {
    // 当待插入节点的质数大于当前要比较的质数时即意味着找到合适的位置，可以退出循环
    if (exponent > current->exponent) {
      break;
    }
    pre = current;
    current = pre->next;
  }
  // 插入该多项式节点
  polynome_node_tp node = malloc(sizeof(polynome_node_t));
  if (node == NULL) {
    return 0;
  }
  // 设置节点数据
  node->coefficient = coefficient;
  node->exponent = exponent;
  // 设置链表中的链接
  pre->next = node;
  node->next = current;
  return 1;
}

/**
 * 根据指数项删除多项式节点
 */
int delete (polynome_node_tp head, int exponent) {
  polynome_node_tp pre = head;
  polynome_node_tp current = head->next;
  while (current) {
    // 找到指数项为 exponent 的项，执行删除操作
    if (exponent == current->exponent) {
      pre->next = current->next;
      free(current);
      return 1;

    }
    // 如果 exponent 大于当前项的指数，则说明不存在，因为是顺序排序的
    else if (exponent > current->exponent) {
      return 0;
    }
    pre = current;
    current = pre->next;
  }
  // 找到最后都没有找到
  return 0;
}

/**
 * 打印当前的多项式
 */
void print(polynome_node_tp head) {
  polynome_node_tp current = head->next;
  while (current) {
    printf("%dx^%d ", current->coefficient, current->exponent);
    current = current->next;
  }
  printf("\n");
}

/**
 *计算当前的多项式
 */
int calculate(polynome_node_tp head, int value) {
  polynome_node_tp current = head->next;
  int sum = 0;
  while (current) {
    sum += current->coefficient * (int)pow(value, current->exponent);
    current = current->next;
  }
  return sum;
}

int main(int argc, char const* argv[]) {
  // 定义一个带头节点的多项式列表
  polynome_node_tp head;
  init(&head);
  char command;
  int coefficient, exponent, value;
  printf(
      "Usage:\n"
      "i [coefficient] [exponent] for insert\n"
      "d [exponent] for delete\n"
      "c [value] for calculate\n"
      "p for print\n"
      "q for quit\n");
  printf("Enter the command:");
  scanf(" %c", &command);
  while (command != 'q') {
    switch (command) {
      case 'i':
        scanf("%d %d", &coefficient, &exponent);
        insert(head, coefficient, exponent);
        break;
      case 'd':
        scanf("%d", &exponent);
        delete (head, exponent);
        break;
      case 'p':
        print(head);
        break;
      case 'c':
        scanf("%d", &value);
        int result = calculate(head, value);
        printf("The result is %d\n", result);
        break;
    }
    printf("Enter the command:");
    scanf(" %c", &command);
  }
  return 0;
}
