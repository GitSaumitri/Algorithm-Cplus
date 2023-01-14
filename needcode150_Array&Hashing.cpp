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

    // hashmap solution
    bool isAnagram1(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) return false;
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
 
    //soln
/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            } else {
                m.insert({nums[i], i});
            }
        }
        
        return result;
    }


//4. https://leetcode.com/problems/group-anagrams/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>> res;
        
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            res.push_back(it->second);
        }
        
        return res;
    }

//soln
/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/
class Solution4 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};


//5. https://leetcode.com/problems/top-k-frequent-elements/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hash;
        vector<int> res;
        vector<pair<int,int>> arr;
        
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
            
        map<int, int>::iterator it;
        for(it = hash.begin(); it!= hash.end(); it++){
            arr.push_back(pair(it->second, it->first));
        }
        sort(arr.begin(), arr.end(), greater());
        for(int i=0; i<arr.size() && i<k ; i++){
            res.push_back(arr[i].second);
            
        }
        return res;
    }

/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]
    
    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// Time: O(n)
// Space: O(n)

class Solution5 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};



//6. https://leetcode.com/problems/product-of-array-except-self/

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result(nums.size());
        prefix[0] = 1;
        suffix[nums.size()-1] = 1;

        //Caluculating prefix array
        for(int i=1; i<nums.size(); i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        //Caluculating suffix array
        for(int i=nums.size()-2; i>=0; i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        // Caluculating nums array
        for(int i=0; i<nums.size(); i++){
            result[i] = suffix[i] * prefix[i];
        }
        return result;
    }
//how to optimise space??

//7.  https://leetcode.com/problems/valid-sudoku/

//8.  https://leetcode.com/problems/encode-and-decode-strings/
   
//9. https://leetcode.com/problems/longest-consecutive-sequence/   

  int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int num: nums){
            hashSet.insert(num);
        }
        int longestSteak = 0;
        for(int num: nums){
           if(!hashSet.count(num-1)){
               int currentNum = num;
               int currentSteak = 1;

               while(hashSet.count(currentNum+1)){
                   currentNum += 1;
                   currentSteak +=1 ;
               }

               longestSteak = max(longestSteak, currentSteak);
           }
       }
       return longestSteak;
    }



