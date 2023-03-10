class Solution {
public:
    vector<int> findSubstring(string inputStr, vector<string>& wordList) {
        vector<int> resultIndices;
        unordered_map<string, int> wordFreqMap; // stores frequency of each word in wordList
        
        // populate the word frequency map
        for (const string& word : wordList) {
            ++wordFreqMap[word];
        }
        
        int wordLength = wordList[0].length(); // length of each word in wordList
        
        // loop through each starting index of the substrings
        for (int i = 0; i <= inputStr.length() - wordLength * wordList.size(); ++i) {
            unordered_map<string, int> seenWords; // stores frequency of each word in current substring
            
            // loop through each word in the current substring
            for (int j = 0; j < wordList.size(); ++j) {
                int wordStartIndex = i + j * wordLength; // starting index of current word in inputStr
                string currWord = inputStr.substr(wordStartIndex, wordLength); // current word
                
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
                
                // add the starting index of the current word to resultIndices if all words have been seen in the current substring
                if (j == wordList.size() - 1) {
                    resultIndices.push_back(i);
                }
            }
        }
        
        return resultIndices;
    }
};

