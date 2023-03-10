class Solution {
public:
    vector<int> findSubstring(string inputStr, vector<string>& wordList) {
        vector<int> resultIndices; // stores indices of concatenated substrings

        // create a map to store the frequency of each word in the wordList
        unordered_map<string, int> wordFreqMap;
        
        // get the number of words in the wordList and the length of each word
        int wordCount = wordList.size(), wordLength = wordList[0].length();
        
        // calculate the length of the sliding window
        int windowLength = wordCount * wordLength;

        // if the length of the input string is less than the window length, return an empty vector
        if (inputStr.length() < windowLength) {
            return resultIndices;
        }
        
        // populate the word frequency map
        for (const string& word : wordList) {
            ++wordFreqMap[word];
        }
        
        // loop through each substring in the input string
        for (int i = 0; i <= inputStr.length() - windowLength; ++i) {
            // create a map to store the frequency of each word in the current substring
            unordered_map<string, int> seenWords;
            
            int j = i; // set the starting index of the substring
            
            // loop through each word in the current substring
            while (j < i + windowLength) {
                // get the current word
                string currWord = inputStr.substr(j, wordLength);
                
                // if the current word is not in the word frequency map or has already been seen in the current substring, break out of the loop
                if (wordFreqMap.find(currWord) == wordFreqMap.end() || seenWords[currWord] >= wordFreqMap[currWord]) {
                    break;
                }
                
                // add the current word to the seenWords map
                ++seenWords[currWord];
                
                // move the index to the start of the next word
                j += wordLength;
            }
            
            // if all words in the wordList have been seen in the current substring, add the starting index to the resultIndices vector
            if (j == i + windowLength) {
                resultIndices.push_back(i);
            }
        }
        
        return resultIndices;
    }
};
