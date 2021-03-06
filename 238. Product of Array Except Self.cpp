#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string_view>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> res(n,1);
		for (int i = 1; i < n; ++i) {
			res[i] = res[i-1] * nums[i-1];
		}
		// for (auto i : res) cout << i << " ";
		// cout << endl;
		
		int right = 1;
		for (int i = n-1; i >= 0; i--) {
			res[i] *= right;
			right *= nums[i];
			// cout << res[i] << " " << right << endl;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{1,2,3,4};
	vector<int> res = s.productExceptSelf(A);
	for (auto i : res) cout << i << " ";
}