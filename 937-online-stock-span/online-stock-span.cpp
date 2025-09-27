class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;
        // Pop while current price is greater or equal
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */