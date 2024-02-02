//https://leetcode.com/problems/sequential-digits/

class Solution {
public:
    int countDigits(int num){
        int ct = 0;
        while(num){
            ct++; 
            num/=10;
        }
        return ct;
    }
    vector<int> sequentialDigits(int low, int high) {
        int a = countDigits(low);
        int b = countDigits(high);
        vector<int> ans;
        for(int d = a; d<=b; d++){
            for(int i = 1; i<=10-d; i++){
                int num = 0;
                char c = i+'0';
                string s = "";
                for(int j = 0; j<d; j++){
                    s.push_back(c); 
                    c++;
                }
                num = stoi(s);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }   

        return ans;
    }
};

// Time Complexity - O(d^3);  where d = 9 (number of digits like 1,2,3,.....9)
// Space Complexity - O(1)  