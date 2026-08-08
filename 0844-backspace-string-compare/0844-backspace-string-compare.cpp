class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int skip_S=0; 
        int skip_T=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skip_S++;
                    i--;
                }else if(skip_S>0){
                    skip_S--;
                    i--;
                }else break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    skip_T++;
                    j--;
                }else if(skip_T>0){
                    skip_T--;
                    j--;
                }else break;
            }
            char first=i<0?'$':s[i];
            char second=j<0?'$':t[j];
            if(first!=second) return 0;
            i--;
            j--;
        }
        return 1;
    }
};