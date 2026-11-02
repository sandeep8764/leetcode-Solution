class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // if the arrays is Sorted then find the K th largest element 
        int n=nums.size();
        //we need largest element atrack so we create the Max- heap 
        // declaratrion of max-heap 
        priority_queue<int> maxheap; // by geafault th max-heap 
        for(int i=0;i<n;i++)
        {
            maxheap.push(nums[i]);
        }
        int top=0;
        for(int i=0;i<k;i++)
        {
             top=maxheap.top();
            maxheap.pop();
        }
        return top;

        
    }
};