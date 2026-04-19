class Solution {
public:
    int maxDistance(vector<int>& arr1, vector<int>& arr2) {

        int ptr1 = 0 , ptr2 = 0;
        int dist = 0 , maxdist = INT_MIN;

        while (ptr1 < arr1.size() && ptr2 < arr2.size()) {

            if (arr1[ptr1] <= arr2[ptr2]) {

                dist = ptr2 - ptr1;

                maxdist = max(maxdist , dist);

                ptr2++;

            } else if (arr1[ptr1] > arr2[ptr2]) {

                ptr1++;
                ptr2++;

            }

        }

        return maxdist==INT_MIN?0:maxdist;

    }
};