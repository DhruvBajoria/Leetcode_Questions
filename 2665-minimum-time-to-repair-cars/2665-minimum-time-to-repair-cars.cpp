class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0,h=1e18;
        while(l<h){
            long long mid =l+(h-l)/2;
            long long car =0;
            for(auto x:ranks){
                car+=sqrt(mid/x);
            }
            if(car<cars){
                l=mid+1;
            }else{
                h=mid;
            }

        }
        return l;
        
    }
};