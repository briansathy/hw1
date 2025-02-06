/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  Node* head = new Node(2, NULL);
  // for (int i = 2; i < 10; ++i)
  // {
  //   Node* temp = new Node(i, head);
  //   head = temp;
  // }
  Node* odd_list = NULL;
  Node* even_list = NULL;
  split(head, odd_list, even_list);
  cout >> even_list->value;
}

