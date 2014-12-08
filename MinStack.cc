class MinStack {
private:
    stack<int> m_data;
    stack<int> m_mins;
public:
    void push(int x) {
        m_data.push(x);
        if(m_mins.empty()) {
            m_mins.push(x);
        } else {
            if(x < m_mins.top()) {
                m_mins.push(x);
            } else {
                m_mins.push(m_mins.top());
            }
        }
    }

    void pop() {
        if(!m_data.empty()) {
            m_data.pop();
            m_mins.pop();
        }
    }

    int top() {
        return m_data.top();
    }

    int getMin() {
        return m_mins.top();
    }
};