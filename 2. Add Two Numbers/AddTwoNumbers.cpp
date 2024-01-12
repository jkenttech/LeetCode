#include <iostream>
#include <vector>
#include <map>
#include <iterator>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
			ListNode* l1Counter = l1;
			ListNode* l2Counter = l2;
			ListNode* answerStart = new ListNode();
			ListNode* answerCurrent = answerStart;
			int sum = 0;
			int carry = 0;
			int modsum = 0;

			while(l1Counter != nullptr || l2Counter != nullptr || answerCurrent != nullptr)
			{
				sum = carry;
				std::cout << "c" << sum;
				if(l1Counter != nullptr)
				{
					std::cout << "f";
					sum += l1Counter->val;
					std::cout << l1Counter->val;
					l1Counter = l1Counter->next;
				}
				if(l2Counter != nullptr)
				{
					std::cout << "s";
					sum += l2Counter->val;
					std::cout << l2Counter->val;
					l2Counter = l2Counter->next;
				}
				modsum = sum % 10;
				carry = (sum - modsum)/10;
				std::cout << "a" << modsum;

				std::cout << " sum-carry " << sum << "-" << carry << "=" << sum-carry;
				if((carry == 0) && (l1Counter == nullptr && l2Counter == nullptr))
				{
					answerCurrent->val = modsum;
				} else
				{
					answerCurrent->val = modsum;
					answerCurrent->next = new ListNode();
				}
				answerCurrent = answerCurrent->next;

				std::cout << std::endl;
			}

			return answerStart;
    }

	ListNode* convertVectorToListNode(std::vector<int> vect){
		ListNode* startNode = new ListNode();
		startNode->val = vect.at(0);
		startNode->next = nullptr;
		ListNode* currentNode = startNode;

		for(int i=1; i < vect.size(); i++)
		{
			ListNode* nextNode = new ListNode();
			currentNode->next = nextNode;
			nextNode->val = vect.at(i);
			nextNode->next = nullptr;
			currentNode = nextNode;
		}

		return startNode;
	}
};

int main()
{
    Solution sl = Solution();
		
		std::map<std::vector<int>, std::vector<int>> tcmap;

		tcmap[{2, 4, 3}] = {5, 6, 4};
		tcmap[{0}] = {0};
		tcmap[{9, 9, 9, 9, 9, 9, 9}] = {9, 9, 9, 9};
		tcmap[{2, 5, 6}] = {3, 9, 2};
		tcmap[{1,6,0,3,3,6,7,2,0,1}] = {6,3,0,8,9,6,6,9,6,1};
		tcmap[{1,6,0}] = {6,3,0};

		std::map<std::vector<int>, std::vector<int>>::iterator itr = tcmap.begin();
		while (itr != tcmap.end())
		{
            ListNode *test1 = sl.convertVectorToListNode(itr->first);
            ListNode *test2 = sl.convertVectorToListNode(itr->second);

			sl.addTwoNumbers(test1, test2);
			itr++;
		}

    return 0;
}
