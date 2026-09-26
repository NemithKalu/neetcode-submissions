using namespace std;

class Solution {
public:

    int getArea(int left, int right, vector<int>& heights) {
        int height = min(heights[left], heights[right]);
        int length = right - left;
        return height * length;
    }


    int maxArea(vector<int>& heights) {
        
        int max_area = 0;
        int left = 0;
        int right = heights.size() - 1;

        // 2 pointers travel inwards
        while (left < right) {
            
            // reaplace max_area if greater area found
            int area = getArea(left, right, heights);
            if (area > max_area) max_area = area;

            // 
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_area;
    }
};
