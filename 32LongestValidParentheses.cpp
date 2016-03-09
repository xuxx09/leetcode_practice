class Solution {
public:

     int longestValidParentheses(string s) {
         stack<int> sta;
         for(int i = 0; i < s.size(); i++)
         {
             if(sta.empty() || s[i] == '(')
             {
                 sta.push(i);
             }
             else
             {
                 if(s[sta.top()] == '(' && s[i] == ')' )
                 {
                     sta.pop();
                 }
                 else
                 {
                     sta.push(i);
                 }
             }
         }
         if(sta.empty() ) return s.size();
         int len = 0;
         int beg = s.size();
         while(!sta.empty())
         {
             len = max( beg - sta.top() - 1, len);
             beg = sta.top();
             sta.pop();
         }
         len = max(beg, len);
         return len>1? len : 0;
     }

};
