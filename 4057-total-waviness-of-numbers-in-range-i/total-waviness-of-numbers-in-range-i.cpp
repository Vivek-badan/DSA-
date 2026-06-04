class Solution {
public:

    int findwavie(int num) {
        string s = to_string(num);

        if(s.length() < 3)
            return 0;

        int score1 = 0;

        for(int i = 1; i < s.length() - 1; i++) {

            // Peak
            if(s[i] > s[i-1] && s[i] > s[i+1])
                score1++;

            // Valley
            else if(s[i] < s[i-1] && s[i] < s[i+1])
                score1++;
        }

        return score1;
    }

    int totalWaviness(int num1, int num2) {

        int score = 0;

        for(int num = num1; num <= num2; num++) {
            score += findwavie(num);
        }

        return score;
    }
};