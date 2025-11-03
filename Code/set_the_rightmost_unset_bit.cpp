// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
// Difficulty: Easy
// Tags: Bit Manipulation

class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int lsb = -1;
        int N_bak = N;
        for(int i=0; i<31; i++){
            if((N&1)==0){
                lsb = i;
                break;
            }
            N = N >> 1;
        }
        N = N_bak;
        if(lsb==-1){
            return N; 
        }
        return (N | (1 << lsb));
    }
};