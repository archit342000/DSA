// https://www.geeksforgeeks.org/problems/most-frequent-element-in-an-array/1
// Difficulty: Easy
// Tags: Hashing

class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        unordered_map<int, int> freq;
        int maxFreq=1, maxVal=arr[0];
        
        for(int x: arr){
            freq[x]++;
            
            if(freq[x]==maxFreq){
                maxVal=max(x, maxVal);
            }
            if(freq[x]>maxFreq){
                maxFreq=freq[x];
                maxVal=x;
            }
        }
        
        return maxVal;
    }
};
