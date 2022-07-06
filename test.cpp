#include<iostream>
using namespace std;
#include<vector>

void merge(vector<int>& nums, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    cout<<"->left "<<left<<" mid"<<mid<<" right"<<right<<" high"<<high<<endl;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
        }else{
            temp.push_back(nums[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    while(right<=high){
        temp.push_back(nums[right++]);
    }
    for(int i=low; i<=high; i++){
        cout<<temp[i-low]<<" ";
        nums[i] = temp[i-low];
    }
    cout<<endl;
}
void mergesort(vector<int>& nums, int low, int high){
    if(low>=high)
        return;
    int mid = (low+high)/2;
    mergesort(nums, low, mid);
    mergesort(nums, mid+1, high);
    merge(nums,low,mid,high);
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,0,arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}