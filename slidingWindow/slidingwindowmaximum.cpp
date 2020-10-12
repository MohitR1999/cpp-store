/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
*/

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(nums.size()==0 || nums.size()<k){
            return {};
        }
        deque<int> q;
        int i;
        for(i=0;i<k;i++){
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans;
        for(i;i<nums.size();i++){
            ans.push_back(nums[q.front()]);
            while(!q.empty() && q.front()<=i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        ans.push_back(nums[q.front()]);
        return ans;
        
    }
};
