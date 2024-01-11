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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return nullptr;
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

		std::map<std::vector<int>, std::vector<int>>::iterator itr = tcmap.begin();
		while (itr != tcmap.end())
		{
            ListNode *test1 = sl.convertVectorToListNode(itr->first);
            ListNode *test2 = sl.convertVectorToListNode(itr->second);

			// for debugging
			for(int i=0; i < itr->first.size(); i++)
			{
				std::cout << itr->first[i];
			}
			std::cout << ",";
			for(int i=0; i < itr->second.size(); i++)
			{
				std::cout << itr->second[i];
			}
			std::cout << std::endl;
			sl.addTwoNumbers(test1, test2);
			itr++;
		}

    return 0;
}
