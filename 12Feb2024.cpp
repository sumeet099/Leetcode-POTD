//https://leetcode.com/problems/majority-element/
// logic - store frequency and find answer using frequency

------------------------------------------------------------------------------------
//1) hashmap solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x: nums)m[x]++;
        for(auto x: m)if(x.second > nums.size()/2)return x.first;
        return 0;
    }
};
// Time Complexity - O(n *log (n) )
// Space Complexity - O(n)

------------------------------------------------------------------------------------
//2) using sorting Algorithm solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
// Time Complexity - O(n *log (n) )
// Space Complexity - O(1)
------------------------------------------------------------------------------------
//3) using bit manipulation solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         
        int majorityElement = 0;

        for(int i = 0; i<32; i++){
            int bitCount = 0;
            for(auto x: nums){
                if((1<<i) & x){
                    bitCount +=1;
                }
            }

            if(bitCount > nums.size()/2 )majorityElement |= (1<<i);
        }
        return majorityElement;       
    }
};
// Time Complexity - O(n * 32 )
// Space Complexity - O(1)
------------------------------------------------------------------------------------
//4)Boyer-Moore Voting Algorithm 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = -1;
        int count = 0;

        for(auto x: nums){

            if(majorityElement==-1){
                majorityElement=x; 
                count +=1;
            }
            else{
                if(majorityElement==x){
                    count+=1;
                }
                else{
                    count-=1;
                    if(count==0){
                        majorityElement = -1;
                    }
                }
            }
        }
        count = 0;
        for(auto x: nums){
            if(majorityElement==x)count++;
        }
        return  count> nums.size()/2 ?  majorityElement : -1;
    }
};
// Time Complexity - O(n)
// Space Complexity - O(1)
