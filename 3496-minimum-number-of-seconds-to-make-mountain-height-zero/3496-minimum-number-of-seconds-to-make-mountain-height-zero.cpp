class Solution {
public:
    // long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
    // }
    bool canCompleteInTime(int mountainHeight, const vector<int>& workerTimes, long long maxTime) {
    long long totalWorkDone = 0;

    // Calculate how much height each worker can reduce within maxTime
    for (int time : workerTimes) {
        long long left = 1, right = mountainHeight, maxHeight = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long totalTimeRequired = (mid * (mid + 1) / 2) * time;

            if (totalTimeRequired <= maxTime) {
                maxHeight = mid;
                left = mid + 1; // Try for more work
            } else {
                right = mid - 1; // Try for less work
            }
        }

        totalWorkDone += maxHeight;

        if (totalWorkDone >= mountainHeight) {
            return true; // Workers can finish in time
        }
    }

    return totalWorkDone >= mountainHeight; // Final check
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long left = 1, right = 1e18; // Use long long for binary search
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canCompleteInTime(mountainHeight, workerTimes, mid)) {
            result = mid;
            right = mid - 1; // Try to find a smaller maximum time
        } else {
            left = mid + 1; // Increase the time limit
        }
    }

    return result;
}
};