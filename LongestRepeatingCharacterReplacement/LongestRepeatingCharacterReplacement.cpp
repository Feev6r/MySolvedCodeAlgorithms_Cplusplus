#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int characterReplacement(string s, int k) {
    
	int maxLength = 0;
	int kTemp = k;

	for (int i = 'A'; i < 'Z'; i++)
	{
		int L = 0;
		k = kTemp;
		for (int R = 0; R <= s.size(); R++)
		{	
			if (i != s[R]) k--;

			while (k < 0) {
				if (s[L] != i) k++;
				L++;
			}

			maxLength = max(maxLength, R - L + 1);
		}
	}
	return maxLength;
}

int characterReplacement(string s, int k) {
    // Base case...
    if (s.size() == 0) return 0;
    // Make an array...
    vector <int> arr(128);
    // Initialize largestCount & beg pointer...
    int beg = 0, largestCount = 0;
    // Traverse all characters through the loop...
    for (int end = 0; end < s.size(); end++) {
        // Get the largest count of a single, unique character in the current window...
        largestCount = max(largestCount, ++arr[s[end]]);
        // We are allowed to have at most k replacements in the window...
        // So, if max character frequency + distance between beg and end is greater than k...
        // That means we have met a largest possible sequence, we can move the window to right...
        if (end - beg + 1 - largestCount > k)
        {
            arr[s[beg]]--;
            beg++;
        }       // The main equation is: end - beg + 1 - largestCount...
    }
    // Return the sequence we have passes, which is s.length() - beg...
    return s.length() - beg;
}


int characterReplacement(string s, int k) {
    int n = s.size();
    int maxi = 0, r = 0, l = 0, mx = 0;

    vector<int> freq(26, 0);

    while (r < n) {

        freq[s[r] - 'A']++;

        mx = max(mx, freq[s[r] - 'A']);
     
        while (r - l + 1 - mx > k) {
            freq[s[l] - 'A']--;
            l++;
        }
        maxi = max(maxi, r - l + 1);
        r++;
    }
    return maxi;
}

int main()
{

}
