/*
奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

说明:

    应当保持奇数节点和偶数节点的相对顺序。
    链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    ListNode *lHead = NULL, *l = NULL, *rHead = NULL, *r = NULL;
    ListNode *cur = head;
    int i = 1;
    while (cur)
    {
      if (i % 2 == 1)
      {
        if (i == 1)
        {
          lHead = l = cur;
        }
        else
        {
          l->next = cur;
          l = l->next;
        }
      }
      else
      {
        if (i == 2)
        {
          rHead = r = cur;
        }
        else
        {
          r->next = cur;
          r = r->next;
        }
      }
      cur = cur->next;
      i++;
    }
    if (l)
    {
      l->next = rHead;
      head = lHead;
    }
    if (r)
    {
      r->next = NULL;
    }
    return head;
  }
};

int main()
{
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(1);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(5);
  ListNode *l5 = new ListNode(6);

  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  Solution s;
  s.oddEvenList(l1);
  return 0;
}
