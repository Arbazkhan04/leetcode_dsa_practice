// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      vector<int> arr;
      for(int i=1;i<=n;i++)
      {
          arr.push_back(i);
      }
        
        int ans;
        int si=0;
        int mid;
        int ei = arr.size()-1;
        while(si<=ei)
        {
           mid=si+ei/2;
            
           if(isBadVersion(arr[mid]))
           {
               if(!(isBadVersion(arr[mid-1])))
                  {
                      return arr[mid-1];
                  }
                 
                  ei = mid-1;
           }
          else
          {
             if(isBadVersion(arr[mid+1]))
                  {
                      return arr[mid+1];
                  }
                 
                  si = mid+1;
          }
            
        }
      return -1;
    }
};
