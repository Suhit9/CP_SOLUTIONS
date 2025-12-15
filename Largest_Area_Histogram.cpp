class Solution {
public:
vector<int> rightSmallerEle(vector<int>&heights){
    int n = heights.size();
    vector<int>ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
         if(!st.empty()){
            ans[i]=st.top();
           
        }
         st.push(i);

    }
    return ans;
}
vector<int> leftSmallerEle(vector<int>&heights){
    int n = heights.size();
    vector<int>ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
           
        }
         st.push(i);

    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int curr_area = 0;
        int ans = INT_MIN;
        vector<int>temp1 = rightSmallerEle(heights);
        vector<int>temp2 = leftSmallerEle(heights);
        for(int i=0;i<n;i++){
            curr_area = heights[i]*(temp1[i]-temp2[i]-1);
            ans = max(ans,curr_area);
        }
        return ans;
    }
};