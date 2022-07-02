class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCut, vector<int>& vCut) {
        long long int mod = 1e9 + 7;
        
        // sorting 
        sort(hCut.begin(),hCut.end());
        sort(vCut.begin(),vCut.end());
        
        // heights of all the cuts
        vector<int> heights;
        heights.push_back(hCut[0]); // initial cut --> first cut
        for(int i=1;i<hCut.size();i++)
            heights.push_back(hCut[i] - hCut[i-1]);
        heights.push_back(h - hCut[hCut.size()-1]); // last cut left
        
        // width of all the cuts
        vector<int> width;
        width.push_back(vCut[0]); // initial cut --> first cut
        for(int i=1;i<vCut.size();i++)
            width.push_back(vCut[i] - vCut[i-1]);
        width.push_back(w - vCut[vCut.size()-1]); // last cut left
        
        // get the max are from area of all the cuts formed
        /*
        int mx_area = 0;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<width.size();j++){
                mx_area = max(mx_area,(heights[i]%mod)*(width[j]%mod)%mod);
            }
        }
        */
        
        // more optimal is to get max height and max width form heigths and width
        long long int maxH = *max_element(heights.begin(),heights.end());
        long long int maxW = *max_element(width.begin(),width.end());
        // cout<<maxH<<" * "<<maxW<<" = "<<maxH*maxW<<endl;
        
        return (int)(maxH % mod * maxW % mod);
    }
};