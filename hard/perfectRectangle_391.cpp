class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //my failed approach

        // int n= rectangles.size();
        // vector<pair<long long int,long long int>> xpair;
        // vector<pair<long long int,long long int>> ypair;
        // for(int i=0;i<n;i++){
        //     xpair.push_back({rectangles[i][0],rectangles[i][2]});
        //     ypair.push_back({rectangles[i][1],rectangles[i][3]});
        // }
        // sort(xpair.begin(),xpair.end());
        // sort(ypair.begin(),ypair.end());
        // long long int a=xpair[0].second;
        // long long int b=ypair[0].second;
        // for(int i=0;i<n;i++){
        //     cout<<"("<<xpair[i].first<<","<<xpair[i].second<<") ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<"("<<ypair[i].first<<","<<ypair[i].second<<") ";
        // }
        // for(int i=1;i<n;i++){
        //     if(xpair[i].first>a){
        //         return false;
        //     }else{
        //         a=max(a,xpair[i].second);
        //     }
        //     if(ypair[i].first>b){
        //         return false;
        //     }else{
        //         b=max(b,ypair[i].second);
        //     }
        // }
       
        // long long int expectedArea= abs(xpair[0].first-a) * abs(ypair[0].first-b);
        // long long int exactArea=0;
        // for(int i=0;i<n;i++){
        //     exactArea+= abs(xpair[i].second-xpair[i].first) * abs(ypair[i].second-ypair[i].first);
        // }
        // return expectedArea==exactArea;


        map<pair<int,int>,int> mp;
        int n= rectangles.size();
        for(int i=0;i<n;i++){
            mp[{rectangles[i][0],rectangles[i][1]}]++;
            mp[{rectangles[i][2],rectangles[i][3]}]++;
            mp[{rectangles[i][0],rectangles[i][3]}]--;
            mp[{rectangles[i][2],rectangles[i][1]}]--;
        }

        int corners=0;
        for(auto it: mp){
            if(it.second!=0){
                if(abs(it.second)!=1) return false;
                corners++;
            }
        }
        return corners==4;
    }
};