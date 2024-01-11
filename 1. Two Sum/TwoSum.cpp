#include <iostream>
#include <vector>
#include <map>
#include <iterator>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
       std::vector<int> result = {};
       for(int i=0; i < nums.size()-1; i++){
           for(int j=1; j < nums.size(); j++){
               if(i != j && nums[i] + nums[j] == target){
                   result.push_back(i);
                   result.push_back(j);
									 std::cout << "[" << i << "][" << j << "], " << nums[i] << "+" << nums[j] << "=" << target << std::endl;
                   return result;
               }
           }
       } 
       return result;
    }
};

int main()
{
		std::map<int, std::vector<int>> tcmap;

		tcmap[9] = {2,7,11,15};
		tcmap[6] = {3,2,4};
		tcmap[4] = {1, 7, 9, 5, 2, 3};

		Solution sl = Solution();
		std::map<int, std::vector<int>>::iterator itr = tcmap.begin();
		while (itr != tcmap.end())
		{
				sl.twoSum(itr->second, itr->first);
				itr++;
		}

		return 0;
}
