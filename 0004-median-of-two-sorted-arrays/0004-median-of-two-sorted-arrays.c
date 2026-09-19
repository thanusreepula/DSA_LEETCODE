double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
if (nums1Size > nums2Size) {
        return findMedianSortedArrays(
            nums2, nums2Size, nums1, nums1Size
        );
    }

    int left = 0;
    int right = nums1Size;

    while (left <= right) {
        int cut1 = (left + right) / 2;
        int cut2 = (nums1Size + nums2Size + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == nums1Size) ? INT_MAX : nums1[cut1];

        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == nums2Size) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((nums1Size + nums2Size) % 2 == 1) {
                return left1 > left2 ? left1 : left2;
            }

            int maxLeft = left1 > left2 ? left1 : left2;
            int minRight = right1 < right2 ? right1 : right2;

            return (maxLeft + minRight) / 2.0;
        }

        if (left1 > right2) {
            right = cut1 - 1;
        } else {
            left = cut1 + 1;
        }
    }

    return 0;
}