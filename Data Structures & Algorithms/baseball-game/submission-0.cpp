class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;

        for(string st:operations){
            if(st == "+"){
                int x = s.top();s.pop();
                int y = s.top();s.pop();
                int z = x+y;
                s.push(y);
                s.push(x);
                s.push(z);
            }else if(st=="D"){
                int t = s.top();
                 
                 t = 2*t;
                 s.push(t);
            }else if(st == "C"){
                s.pop();
            }else{
                s.push(stoi(st));
            }

        }
        int sum = 0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }

        return sum;
    }
};