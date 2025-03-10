class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atleast(k, word) - atleast(k + 1, word);
    }

    long long atleast(long long k, string word) {
        long long count = 0, consonants = 0, left = 0, n = word.size();
        unordered_map<char, long long> freq;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (long long right = 0; right < n; right++) {
            char ch = word[right];
            if (vowels.find(ch) == vowels.end()) consonants++;

            freq[ch]++;

            while (consonants >= k && hasAllVowels(freq)) {
                count += (n - right);
                char leftChar = word[left];
                if (vowels.find(leftChar) == vowels.end()) consonants--;
                if (--freq[leftChar] == 0) freq.erase(leftChar);
                left++;
            }
        }
        return count;
    }

    bool hasAllVowels(unordered_map<char, long long>& freq) {
        return freq['a'] > 0 && freq['e'] > 0 && freq['i'] > 0 && freq['o'] > 0 && freq['u'] > 0;
    }
};