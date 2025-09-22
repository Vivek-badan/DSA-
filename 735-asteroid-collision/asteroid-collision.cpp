class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } 
            else {  // asteroid going left
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // both destroyed
                } 
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]); // current survives
                }
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
