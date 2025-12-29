class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0, end = mountainArr.length() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                start = mid + 1;
            else
                end = mid;
        }
        int peak = start;
        start = 0, end = peak;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) < target)
                start = mid + 1;
            else if (mountainArr.get(mid) > target)
                end = mid - 1;
            else
                return mid;
        }
        start = peak + 1, end = mountainArr.length() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) > target)
                start = mid + 1;
            else if (mountainArr.get(mid) < target)
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};