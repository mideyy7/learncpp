/*

Write a function: int solution (vector<int> &A); content_copy that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A. For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5. Given A = [1, 2, 3], the function should return 4. Given A = [−1, −3], the function should return 1. Write an efficient algorithm for the following assumptions: N is an integer within the range [1..100,000]; each element of array A is an integer within the range [−1,000,000..1,000,000].

*/

#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

int solution(vector<int>& A) {
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<vector<int>>> pq;
    int maxn = INT_MIN;
    for (int num: A) {
        if (num > 0 && st.find(num) == st.end()) {
            maxn = max(maxn, num);
            pq.push(num);
            st.insert(num);
        }
    }
    if (maxn == INT_MIN) return 1;
    for (int i = 1; i < maxn; i++) {
        int curr = pq.top(); pq.pop();
        if (curr == i) continue;
        return i;
    }
    return maxn + 1;




}
