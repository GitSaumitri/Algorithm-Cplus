// https://neetcode.io/roadmap

/* Arrays & Hashing */

//1. https://leetcode.com/problems/contains-duplicate/

   bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto it: nums){
            if(umap.find(it)!=umap.end()){
                return true;
            }
            umap[it]=0;
        }
        return false;
    }

//2. https://leetcode.com/problems/valid-anagram/
    bool isAnagram(string s, string t) {
        int map[128]={0};
        for(int i=0; i<s.size(); i++){
            map[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            map[t[i]]--;
        }
        for(int i=0; i<128; i++){
            if(map[i]!=0)
                return false;
        }
        return true;
    }

// 3. https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++){
            if(um.count(target - nums[i]))
                return {um[target-nums[i]],i};
            um[nums[i]]=i;    
        }
        return {-1,-1};
    }

//4. https://leetcode.com/problems/group-anagrams/

