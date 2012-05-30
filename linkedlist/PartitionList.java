public PartitionList {
    /*
     * Definition for singly-linked list.
     * http://www.leetcode.com/onlinejudge
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) {
     *         val = x;
     *         next = null;
     *     }
     * }
     */
    public ListNode partition(ListNode head, int x) {
        ListNode curr, tail;
        tail = curr = head;
        while (tail != null && tail.next != null) {
            tail = tail.next;
        }
        if (head == tail) return head;
        ListNode newtail = tail;
        ListNode prev = null;
        while (true) {
            ListNode nextNode = curr.next;
            if (curr.val >= x) {
                newtail.next = curr;
                newtail = curr;
                newtail.next = null;
                if (nextNode != null) {
                    if (prev == null) head = nextNode;
                    else prev.next = nextNode;
                }
            } else {
                prev = curr;
            }
            if (curr == tail) break;
            curr = nextNode;
        }
        return head;
    }
}
