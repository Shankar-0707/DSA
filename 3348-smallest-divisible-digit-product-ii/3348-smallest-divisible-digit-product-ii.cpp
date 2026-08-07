class Solution {
public:
    typedef long long ll;

    string func(ll num, int leng) {
        string str;

        for (int digit = 9; digit >= 2; digit--) {
            while (num % digit == 0) {
                str.push_back(digit + '0');
                num /= digit;
            }
        }

        while (str.length() < leng) {
            str.push_back('1');
        }

        reverse(str.begin(), str.end());

        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();

        ll temp = t;
        // if t means temp has prime factors other than 2,3,5,7 it means we can
        // not make any string for that so we return -1
        for (int primeFac : {2, 3, 5, 7}) {
            while (temp % primeFac == 0) {
                temp /= primeFac;
            }
        }

        if (temp != 1)
            return "-1";

        // Now we pre compute what are the remainingfactors we neeed for each
        // index
        vector<ll> remFactors(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';

            if (digit == 0)
                break;
            remFactors[i + 1] = remFactors[i] / gcd(remFactors[i], (ll)digit);
        }

        if (remFactors[n] == 1) { // the input itself is sufficient for t
            return num;
        }

        // Now we start with tha last positiion to be filled or we have 0 in our
        // string then we should start with its previous idx
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;
        if (zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        for (int i = zeroIdx; i >= 0; i--) {
            ll required = remFactors[i];
            int freeSlots = n - i - 1;

            for (int dig = (num[i] - '0') + 1; dig <= 9; dig++) {
                ll furtherRequired = required / gcd(required, dig);
                string requiredNumber = func(furtherRequired, freeSlots);

                if (requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) + (char)(dig + '0') +
                           requiredNumber;
                }
            }
        }
        // agar hm pure n length me hi number nhi nikal paye to ek place extend
        // krenge
        return func(t, n + 1);
    }
};