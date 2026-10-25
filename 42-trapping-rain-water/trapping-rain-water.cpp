class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int leftmax = height[0];
    int rightmax = height[n-1];
    int left = 0, right = n - 1;
    int water_trapped = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            leftmax = max(leftmax, height[left]);
            water_trapped += leftmax - height[left];
            ++left;
        } else {
            rightmax = max(rightmax, height[right]);
            water_trapped += rightmax - height[right];
            --right;
        }
    }
    return water_trapped;
}
};