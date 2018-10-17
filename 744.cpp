class Solution {
public:
    char binaryLetterSearch(vector<char>& letters, char target, int front, int back) {
        if (letters.back() <= target) return letters[0];
        if (front == back) return letters[front];        
        int mid = front + ((back - front) / 2);
        
        if (letters[mid] <= target) return binaryLetterSearch(letters, target, mid + 1, back);
        else return binaryLetterSearch(letters, target, front, mid);
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        return binaryLetterSearch(letters, target, 0, letters.size()-1);
    }
};