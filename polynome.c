#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "polynome-linkedlist.h"

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
