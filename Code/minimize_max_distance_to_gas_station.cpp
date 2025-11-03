// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// Difficulty: Hard
// Tags: Arrays, Binary Search

class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        
        double l=0;
        double r=0;
        
        for(int i=1; i<n; i++){
            r=max(r, double(stations[i]-stations[i-1]));
        }
        
        while(r-l>1e-6){
            double m=(l+r)/2;
            
            int count=0;
            for(int i=1; i<n; i++){
                int dist = stations[i]-stations[i-1];
                int q = dist/m;
                
                if(dist == q*m){
                    q--;
                }
                
                count += q;
            }
            
            if(count<=k){
                r=m;
            }
            else{
                l=m;
            }
        }
        
        return l;
    }
};