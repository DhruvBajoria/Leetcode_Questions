class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0;
        int n = arr.size();
        int odd=0,even=1;
        int sum=0;
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==1){
                ans=(ans+even)%MOD;
                odd++;
            }else{
                ans=(ans+odd)%MOD;
                even++;
            }
        } 
        return ans;
        
    }
};