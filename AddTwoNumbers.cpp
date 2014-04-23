/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* aList = new ListNode(0);
		ListNode* aw = aList;
		ListNode* w1 = l1;
		ListNode* w2 = l2;
		int carry = 0;
		int sum = 0;
		int sum1 = 0; 
		int sum2 = 0;

		while((w1 != nullptr) || (w2 != nullptr)) {
			sum1 = (w1 != nullptr) ? w1->val : 0;
			sum2 = (w2 != nullptr) ? w2->val : 0;
			sum = sum1 + sum2;

			if(sum >= 10) {
				aw->val += sum - 10;
			} else {
				aw->val += sum;
			}

			carry = sum / 10;

			if(carry) {
				aw->next = new ListNode(carry);
			} else if(aw->val >= 10) {
				aw->val -= 10;
				aw->next = new ListNode(1);
			}

			if(w1->next == nullptr && w2->next != nullptr) {
				w1->next = new ListNode(0);
			}

			if(w2->next == nullptr && w1->next != nullptr) {
				w2->next = new ListNode(0);
			}

			if(w1->next == nullptr && w2->next == nullptr) {
				break;
			} else {
				if(aw->next == nullptr) {
					aw->next = new ListNode(0);
					aw = aw->next;
				} else {
					aw = aw->next;
				}

				w1 = w1->next;
				w2 = w2->next;
			}
		}
		
		return aList;    
	}
};