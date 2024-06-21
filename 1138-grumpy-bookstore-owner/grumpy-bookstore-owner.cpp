class Solution {
public:
    // int ss(vector<int>& c, vector<int>& g, int m) {
    //     int n = c.size();
    //     int total = 0;

    //     // Calculate the initial satisfaction without using the technique
    //     for (int i = 0; i < n; i++) {
    //         if (g[i] == 0) {
    //             total += c[i];
    //         }
    //     }

    //     // Calculate the maximum extra satisfied customers when using the
    //     // technique
    //     int extra = 0;
    //     int currentExtra = 0;

    //     // Initial window of size `m`
    //     for (int i = 0; i < m; i++) {
    //         if (g[i] == 1) {
    //             currentExtra += c[i];
    //         }
    //     }
    //     extra = currentExtra;

    //     // Slide the window across the entire array
    //     for (int i = m; i < n; i++) {
    //         if (g[i] == 1) {
    //             currentExtra += c[i];
    //         }
    //         if (g[i - m] == 1) {
    //             currentExtra -= c[i - m];
    //         }
    //         extra = max(extra, currentExtra);
    //     }

    //     return total + extra;
    // }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size(); // Get the number of elements in the customers array
    int maxi = INT_MIN; // Initialize the maximum value to the smallest possible integer
    int ind = -1; // Initialize the index of the start of the optimal 'minutes' window
    int un = 0; // Initialize the variable to store the number of unsatisfied customers
    int i = 0; // Initialize a counter for the initial loop

    // Calculate the number of unsatisfied customers in the first 'minutes' window
    for (i = 0; i < minutes; i++) {
        if (grumpy[i] == 1) {
            un += customers[i]; // Add the number of customers if the owner is grumpy
        }
    }
    // Update maxi and ind if the current unsatisfied customers are more than maxi
    if (un > maxi) {
        maxi = un;
        ind = i - minutes; // Set the start index of the optimal window
    }

    // Slide the window across the rest of the array
    for (int j = i; j < n; j++) {
        if (grumpy[j] == 1)
            un += customers[j]; // Add customers if the owner is grumpy in the new position
        if (grumpy[j - minutes] == 1)
            un -= customers[j - minutes]; // Subtract customers if the owner was grumpy in the old position
        // Update maxi and ind if the current unsatisfied customers are more than maxi
        if (un > maxi) {
            maxi = un;
            ind = j - minutes + 1; // Set the start index of the optimal window
        }
    }

    int sum = 0; // Initialize the variable to store the total number of satisfied customers
    for (int i = 0; i < n; i++) {
        // If the current index is within the optimal window, add all customers
        if (i >= ind && i <= ind + minutes - 1) {
            sum += customers[i];
        }
        // Otherwise, add customers only if the owner is not grumpy
        else if (grumpy[i] == 0) {
            sum += customers[i];
        }
    }

    return sum; // Return the total number of satisfied customers
}

};