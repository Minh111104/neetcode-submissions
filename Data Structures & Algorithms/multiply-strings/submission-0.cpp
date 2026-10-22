class Solution {
public:
    string multiply(string num1, string num2) {
      int carry = 0;
      string res = "";
      vector<int> c(num1.size() + num2.size() - 1); // store multiplication results
      
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());

      for (int i = 0; i < num1.size(); ++i) {
        for (int j = 0; j < num2.size(); ++j) {
          // multiply each digit and store in c
          c[i + j] += (num1[i] - '0') * (num2[j] - '0');    // convert to int
        }
      }

      // handle carry and convert to string
      for (int i = 0; i < c.size(); ++i) {
        int sum = c[i] + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
      }

      // add any remaining carry
      while (carry > 0) {
        res.push_back((carry % 10) + '0');
        carry = carry / 10;
      }

      // remove leading zeros
      while (res.size() > 1 && res.back() == '0') {
        res.pop_back();     // eliminate ending 0
      }
      
      reverse(res.begin(), res.end());
      return res;       
    }
};