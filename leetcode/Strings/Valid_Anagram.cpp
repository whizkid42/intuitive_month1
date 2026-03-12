// Problem: Valid Anagram
// Difficulty: Easy
// Concept: Hash Map
// Time Complexity: O(n)

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int>count;
        for(char c :s){
            count[c]++;
        }
        for(char c : t){
            count[c]--;
            if(count[c]<0){
                return false;
            }
        }
        return true;
    }
};

/*
if ( s.length() !=t.length())
	return false
create unordered_map <char,int> count
for each char in s
	count[char]++
for each char in t
	count[char]--
if count[char] < 0
	return false

return true
	
*/