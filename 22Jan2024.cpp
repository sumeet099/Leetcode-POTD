//https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        vector<int> vis(n+1,0);

        for(int i = 0; i<n; i++)vis[nums[i]]++;

        vector<int> ans(2);
        for(int i =1; i<=n; i++){
            if(vis[i]==2){
                ans[0] = i;
            }
            else if(vis[i]==0){
                ans[1] = i;
            }
        }

        return ans;
    }
};

//Time Complexity - O(N);
//Space Complexity - O(N);


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(2);
        for(int i= 0; i<nums.size(); i++){
            if(nums[i]==nums[i+1]){
                ans[0] = nums[i];
                if(nums[i]==i+1){
                    i++;
                    while(i<nums.size() && nums[i]==i)i++;
                    ans[1] = i;
                }
                else{
                    while(i>=0 && nums[i]==i+2){
                        i--;
                    }
                    i++;
                    ans[1] = nums[i]-1;
                }
                break;
            }
        }
        return ans;
    }
};


//Time Complexity - O(N log N);
//Space Complexity - O(1);

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long int n = nums.size();
        long long int es = (n*(n+1))/2;
        long long int es2 = (n*(n+1)*(2*n+1)/6);
        long long int s1 = 0, s2 = 0;
        for(int i = 0; i<n; i++){
            s1+= nums[i];
            s2 += 1LL * nums[i] * nums[i];
        }
        long long int val1 = s1-es;
        long long int val2 = (s2 - es2)/ (s1-es);

        // x is repeated, y is missing
        long long int x = (val1+val2)/2;
        long long int y = val2 - x;

        vector<int> ans(2);
        ans[0] = x;
        ans[1] = y;
        return ans;
    }
};


//Time Complexity - O(N);
//Space Complexity - O(1);