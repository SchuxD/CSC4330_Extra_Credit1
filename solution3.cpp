class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> wordFreqMap; // stores frequency of each word in words

        // populate the word frequency map
        for (const string& word : words) {
            ++wordFreqMap[word];
        }

        int wordLength = words[0].length(); // length of each word in words

        // loop through each starting index of the substrings
        for (int i = 0; i <= s.length() - wordLength * words.size(); ++i) {
            unordered_map<string, int> seenWords; // stores frequency of each word in current substring

            // loop through each word in the current substring
            int j = 0;
            for (; j < words.size(); ++j) {
                int wordStartIndex = i + j * wordLength; // starting index of current word in s
                string currWord = s.substr(wordStartIndex, wordLength); // current word

                // check if current word is in the word frequency map and update the seenWords map
                if (wordFreqMap.find(currWord) != wordFreqMap.end()) {
                    ++seenWords[currWord];

                    // break out of the loop if the frequency of the current word in seenWords is greater than its frequency in wordFreqMap
                    if (seenWords[currWord] > wordFreqMap[currWord]) {
                        break;
                    }
                }
                else {
                    break; // break out of the loop if current word is not in wordFreqMap
                }
            }

            // add the starting index of the current substring to result if all words have been seen in the current substring
            if (j == words.size()) {
                result.push_back(i);
            }
        }

        return result;
    }
};

