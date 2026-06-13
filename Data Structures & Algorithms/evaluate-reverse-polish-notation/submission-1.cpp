class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
       
        stack<int>st;

        for(string s:tokens){
            if(s == "*" || s== "/" || s == "+" || s == "-"){
                if(s == "+"){
                    int x = st.top();
                    st.pop();
                    int y  = st.top();
                    st.pop();
                    st.push(x+y);
                }
                if(s == "-"){
                    int x = st.top();
                    st.pop();
                    int y  = st.top();
                    st.pop();
                    st.push(y-x);
                }
                if(s == "*"){
                     int x = st.top();
                    st.pop();
                    int y  = st.top();
                    st.pop();
                    st.push(x*y);
                }
                if(s== "/"){
                     int x = st.top();
                    st.pop();
                    int y  = st.top();
                    st.pop();
                    st.push(y/x);
                }
            }else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};
