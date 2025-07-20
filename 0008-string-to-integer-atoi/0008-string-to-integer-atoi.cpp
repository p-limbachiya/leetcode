class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        int n = s.length();
    
    while (i < n && s[i] == ' ') {
        i++;
    }

    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

         long long ans = recursiveFunction(s, i, 0, sign);

        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return static_cast<int>(ans);
    }

    long long recursiveFunction(const string& s, int i, long long acc, int sign) {
        if (i >= s.length() || !isdigit(s[i])) {
            return acc * sign;
        }

        int digit = s[i] - '0';

        if (acc > (numeric_limits<int>::max() - digit) / 10) {
            return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
        }

        long long new_acc = acc * 10 + digit;

        return recursiveFunction(s, i + 1, new_acc, sign);
    }
};