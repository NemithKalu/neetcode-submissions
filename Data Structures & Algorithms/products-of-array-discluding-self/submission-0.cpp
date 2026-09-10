class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int totalProduct = 1;
        int zeroCount = 0;
        int singleZeroIndex;

        // get totalProduct 
        for (int i = 0; i < nums.size(); i++) {
            
            // only take for product if non zero
            if (nums[i] == 0) {
                zeroCount++;
                singleZeroIndex = i;
            } else {
                totalProduct *= nums[i];
            }
        }

        vector<int> productArray;

        // if only 1 zero then only that index would have a non zero product
        if (zeroCount == 1) {
            for (int i = 0; i < nums.size(); i++) {
                // fill non zero indexes with zeros
                if (i != singleZeroIndex) {
                    productArray.push_back(0);
                } else {
                    productArray.push_back(totalProduct);
                }
            }

            return productArray;
        }


        // more than 1 zero => all zero array
        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }


        // if no zeros
        for (int i = 0; i < nums.size(); i++) {
            productArray.push_back((int) (totalProduct/nums[i]));
        }

        return productArray;
    }
};
