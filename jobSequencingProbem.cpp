//  You are given a set of N jobs where each job comes with a deadline and profit. 
//  The profit can only be earned upon completing the job within its deadline. 
//  Find the number of jobs done and the maximum profit that can be obtained. 
//  Each job takes a single unit of time and only one job can be performed at a time.

// Basic Outline of the approach:-

// Sort the jobs in descending order of profit. 
// If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
// For every job check if it can be performed on its last day.
// If possible mark that index with the job id and add the profit to our answer. 
// If not possible, loop through the previous indexes until an empty slot is found.

// Time Complexity: O(N log N) + O(N*M).
// Space Complexity: O(M) 

#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 