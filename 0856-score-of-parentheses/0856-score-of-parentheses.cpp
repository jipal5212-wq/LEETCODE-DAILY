class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>store;
        store.push(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                store.push(0);
            }else{
                int p1= store.top();
                store.pop();
                int p2= store.top();
                store.pop();
                int temp= p2+ max(2*p1,1);
                store.push(temp);
            }

        }
   return store.top(); }
};