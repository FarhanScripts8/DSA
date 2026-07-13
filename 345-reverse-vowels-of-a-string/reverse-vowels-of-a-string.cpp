class Solution {
public:

    // Function to check whether a character is a vowel
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {
        int s1 = 0;
        int e = s.length() - 1;
        while (s1 < e) {

            // Both characters are vowels
            if (isVowel(s[s1]) && isVowel(s[e])) {
                swap(s[s1++], s[e--]);
            }

            // Left is vowel, right is not
            else if (isVowel(s[s1])) {
                e--;
            }

            // Right is vowel, left is not
            else if (isVowel(s[e])) {
                s1++;
            }

            // Neither is a vowel
            else {
                s1++;
                e--;
            }
        }
        return s;
    }
};