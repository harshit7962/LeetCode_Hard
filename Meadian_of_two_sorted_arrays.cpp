class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) {
            return findMedianSortedArrays(b, a);
        }
        int low=0, n1= a.size(), n2=b.size(), high=n1;
        while(low<=high) {
            int i1=(low+high)/2;
            int i2=(n1+n2+1)/2-i1;
        
            int min1=(i1==n1)?INT_MAX:a[i1];
            int max1=(i1==0)?INT_MIN:a[i1-1];
        
            int min2=(i2==n2)?INT_MAX:b[i2];
            int max2=(i2==0)?INT_MIN:b[i2-1];
            
            if(min1>=max2 && min2>=max1) {
                if((n1+n2)%2==0)
                return (double) (max(max1, max2)+min(min1, min2))/2;
                else
                return max(max1, max2);
            } else if(max1>min2) {
                high=i1-1;
            }
            else {
                low=i1+1;
            }
        }
        return 0;
    }
};
