class Solution {
public:

    string add(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += char('0' + sum % 10);
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool check(string num, int i, int j) {

        string a = num.substr(0, i);
        string b = num.substr(i, j - i);

        // Leading zero is not allowed
        if (a.size() > 1 && a[0] == '0')
            return false;

        if (b.size() > 1 && b[0] == '0')
            return false;

        int pos = j;
        int count = 2;

        while (pos < num.size()) {

            string c = add(a, b);

            // Does the next part match a + b?
            if (num.substr(pos, c.size()) != c)
                return false;

            pos += c.size();

            a = b;
            b = c;
            count++;
        }

        return count >= 3;
    }

    bool isAdditiveNumber(string num) {

        int n = num.size();

        // i = length of first number
        for (int i = 1; i <= n - 2; i++) {

            // j = ending position of second number
            for (int j = i + 1; j <= n - 1; j++) {

                if (check(num, i, j))
                    return true;
            }
        }

        return false;
    }
};