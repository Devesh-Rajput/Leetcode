class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string,int> mp;
        for(int i=0; i<n; i++){
            string str="";
            for(int j=i; j<n; j++){
                if(str.empty() || str.back()==s[j]){
                    str.push_back(s[j]);
                    mp[str]++;
                }else{
                    break;
                }
            }
        }

        int len=0;
        for(auto &it:mp){
            string sub=it.first;
            int cnt=it.second;
            if(cnt>=3 && sub.size()>len){
                len=sub.size();
            }
        }
        
        return len==0?-1:len;
    }
};