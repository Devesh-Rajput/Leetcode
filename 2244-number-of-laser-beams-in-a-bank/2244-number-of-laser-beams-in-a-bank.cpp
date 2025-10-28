class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDevices = 0;   // number of devices in previous non-empty row
        int totalBeams = 0;    // result
        
        for (string& row : bank) {
            int currDevices = count(row.begin(), row.end(), '1');
            
            if (currDevices > 0) {
                totalBeams += prevDevices * currDevices;
                prevDevices = currDevices;
            }
        }
        
        return totalBeams;
    }
};
