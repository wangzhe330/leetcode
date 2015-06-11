/*
Contains Duplicate

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> existed;
        vector<int>::iterator it = nums.begin();
        for( ; it != nums.end() ; it++){
            if(existed.find(*it) != existed.end()){
                return true;
            }else{
                existed.insert(*it);
            }
        }
        return false;
    }
};