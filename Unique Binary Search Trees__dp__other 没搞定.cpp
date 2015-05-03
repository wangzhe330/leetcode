/*


Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*/



class Solution {
public:
    int numTrees(int n) 
    {
        if(n<0) return 0;
    
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
    
        for(int k=2;k<=n;k++)
        {
            int sum=0;
            for(int i=1;i<=k;i++)
            {
                sum+=(result[i-1]*result[k-i]);
            }
    
            result.push_back(sum);
        }
    
        return result[n];
    }
};