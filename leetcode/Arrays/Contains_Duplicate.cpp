// Problem: Contains Duplicate
// Difficulty: Easy
// Concept: Hash Set
// Time Complexity: O(n)

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int i =0 ; i < nums.size(); i++){
            if(seen.count(nums[i])){
                return true;
            }
            seen.insert(nums[i]);

        }
        return false;
        
    }
};

/* Pseudo code
create empty map
for i from 0 to n-1
	if(nums[i] present in map)
			return true
	else
			map.append(nums[i])

return false*/