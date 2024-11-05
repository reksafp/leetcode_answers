class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int increment = 1;
        int size = digits.size();
        int nums1, nums2;

        for(int i = size-1; i >= 0; i--){
            if(i == size-1){
                    digits[i] = digits[i] + increment;

                    if(size == 1 && digits[i] == 10){
                        nums1 = digits[i] % 10;
                        nums2 = digits[i] / 10 % 10;
                        digits[i] = nums1;
                        if(digits[i] == 0){
                            digits.erase(digits.begin());
                        }
                        digits.push_back(nums2);
                        digits.push_back(nums1);
                        break;
                    }

                if(digits[i] == 10){
                    nums1 = digits[i] % 10;
                    nums2 = digits[i] / 10 % 10;
                    digits[i] = nums1;
                    digits[i-1] = digits[i-1] + nums2;
                }
            }

            if(digits[i] == 10 && i == 0){
                digits[i] = nums1;
                digits.insert(digits.begin(), nums2);
            } else if(digits[i] == 10 && i != 0){
                nums1 = digits[i] % 10;
                nums2 = digits[i] / 10 % 10;
                digits[i] = nums1;
                digits[i-1] = digits[i-1] + nums2;
            }
        }

        return digits;
    }
};
