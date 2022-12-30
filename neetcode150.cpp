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


// TWO POINTERS

//https://leetcode.com/problems/valid-palindrome/
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while (i < j && !isalnum(s[i]))
        i++;
      while (i < j && !isalnum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;
    }

    return true;
  }


// STACK 

//https://leetcode.com/problems/min-stack/

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    
public:
    void push(int x) {
        mainStack.push(x);
        // if x == currentMin, also push x to minStack
        // because when popping, x == currentMin will be
        // popped
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        int x = mainStack.top();
        mainStack.pop();
        if (x == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

class MinStack {
public:
    MinStack() {
        min_val = INT_MAX;
    }  
    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }   
    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }  
    int top() {
        return st.top();
    }    
    int getMin() {
        return min_val;
    }

private:
    int min_val;
    stack<int> st;
};


class MinStack {
private : 
vector<int> arr;
int start;
int min;
public:
    MinStack() {
       min = INT_MAX; 
       start = 0;
    }
    
    void push(int val) {
        if (start == arr.size()) arr.push_back(0);
        if (val <= min)
        {
            arr[start++] = min;
            min = val;
        }
        if (start == arr.size()) arr.push_back(0);
        arr[start++] = val;
    }
    
    void pop() {
        if (arr[start-1]==min)
        {
            start--;
            min = arr[--start];
        }
        else
        start--;
    }
    
    int top() {
        return arr[start-1];
    }
    
    int getMin() {
        return min;
    }
};

//https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> s;
        for (auto a : tokens) {
            if (a.size() == 1 && !isdigit(a[0])) {  // check if an operator
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                switch (a[0]) {  // note switch use char or integer
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                        break;
                }
            } else {  // if an number push to stack
                s.push(atoi(a.c_str()));
            }
        }
        return s.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string t = tokens.back();
        tokens.pop_back();
        if(t != "+" && t != "-" && t != "*" && t != "/") return stoi(t);
        else{
            int b = evalRPN(tokens);
            int a = evalRPN(tokens);
            if(t == "+") return a + b;
            else if(t == "-") return a - b;
            else if(t == "*") return a * b;
            else return a / b;
        }
    }
};
