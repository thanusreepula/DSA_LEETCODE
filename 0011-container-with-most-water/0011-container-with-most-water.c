int maxArea(int* height, int heightSize) {
int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int shorter = height[left] < height[right]
                    ? height[left]
                    : height[right];

        int area = shorter * (right - left);

        if (area > maxWater) {
            maxWater = area;
        }

        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;    
}