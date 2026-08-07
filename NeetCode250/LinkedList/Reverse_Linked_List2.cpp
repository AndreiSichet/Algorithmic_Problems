/*
Reverse Linked List II:
Reverse only the nodes between positions left and right.
Use a dummy node to handle reversing from the head.
Find:
before = node before left
start = first node of the section to reverse
Reverse exactly: right - left + 1 nodes using the normal linked list reversal.
After reversing:
before->next = new head of reversed section
start->next = first node after the reversed section
Main insight:
This is simply Reverse
Linked List applied to a
sublist, followed by
reconnecting the two ends.
Time Complexity:
O(n)
Space Complexity:
O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        // Move before to node before 'left'
        for (int i = 1; i < left; i++)
            before = before->next;
        ListNode* start = before->next;
        ListNode* prev = nullptr;
        ListNode* curr = start;
        // Reverse right-left+1 nodes
        for (int i = 0; i <= right - left; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Reconnect
        before->next = prev;
        start->next = curr;
        return dummy->next;
    }
};