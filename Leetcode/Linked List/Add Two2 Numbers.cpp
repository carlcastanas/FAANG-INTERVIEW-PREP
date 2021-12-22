/*  TC: O(max(m,n)) and Space O(max(m,n)) 
    The algorithm above iterates at most max(m,n) times and length of new string would be maximum of length O(m,n)+1

    Note: Here digits are stored in reverse order, which means 342 will be stored as 2->4->3 which is expected becz we've to start adding digits from back.
    But let's suppose if digits. are given in simple order like 342 as 3->4->2 then reverse both the lists, and add again reverse the list and return.

*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode prehead(0);
        ListNode *p = &prehead;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            int a = 0, b = 0;
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            int sum = a + b + carry;
            p->next = new ListNode(sum % 10);
            p = p->next;
            carry = sum < 10 ? 0 : 1;
        }
        return prehead.next;
    }
};

/* Add Two Numbers 2 i.e when no. are not in reverse order in linked list */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<ListNode *> s1, s2;
    while (l1 != NULL)
    {
        s1.push(l1);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        s2.push(l2);
        l2 = l2->next;
    }

    int sum = 0;
    ListNode dummy(0);
    ListNode *p = &dummy;

    while (!s1.empty() || !s2.empty() || sum)
    {
        if (!s1.empty() && s1.top())
            sum += s1.top()->val, s1.pop();
        if (!s2.empty() && s2.top())
            sum += s2.top()->val, s2.pop();

        ListNode *node = new ListNode(sum % 10);
        if (p->next == NULL)
            p->next = node;
        else
        {
            node->next = p->next;
            p->next = node;
        }

        sum /= 10;
    }
    return p->next;
}