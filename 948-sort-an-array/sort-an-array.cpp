class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int index = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = index;

        if (left < n && nums[largest] < nums[left]) {
            largest = left;
        }

        if (right < n && nums[largest] < nums[right]) {
            largest = right;
        }

        if (largest != index) {
            swap(nums[largest], nums[index]);
            index = largest;
            heapify(nums, n, index);
        }
    }

    // Function to build a Heap from array.
    // TC-->O(N) of bulid heap
    void buildHeap(vector<int>& nums, int n) {

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
    }

    // Function to sort an array using Heap Sort.
    // TC-->O(NLOGN)
    void heapSort(vector<int>& nums, int n) {
        buildHeap(nums, n);
        //  while(n!=0)
        while ((n - 1) != 0) {
            swap(nums[n - 1], nums[0]);
            n--;
            heapify(nums, n, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};