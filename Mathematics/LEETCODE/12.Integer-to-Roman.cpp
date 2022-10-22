class Solution
{
public:
    string intToRoman(int num)
    {
        string result;

        if (!num)
            return result;

        vector<pair<int, string>> manual = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};

        for (const auto &[value, symbol] : manual)
        {
            while (num >= value)
            {
                num -= value;
                result += symbol;
            }
        }

        return result;
    }
};