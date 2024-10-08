class Solution {
public:
    // bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
    // }
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
    int count = 0;

    for (const string& word : message) {
        if (bannedSet.find(word) != bannedSet.end()) {
            count++;
            if (count >= 2) {
                return true;
            }
        }
    }

    return false;
}
};