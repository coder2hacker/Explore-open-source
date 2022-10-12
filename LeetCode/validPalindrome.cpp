class Solution
{
private:
    // check is the chharacter is means gnore aloha numeric character
    bool valid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return 1;
        }
        return 0;
    }
    // converts uppercase letters into lower case letters
    char lowerCase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return ch;
        }
        else
        {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    // check palindrome characters
    bool checkPalindrome(string a)
    {
        int s = 0;
        int e = a.size() - 1;
        while (s <= e)
        {
            if (a[s] != a[e])
            {
                return 0;
            }
            else
            {
                s++;
                e--;
            }
        }
        return 1;
    }

public:
    bool isPalindrome(string s)
    {
        //        faltu char hatdo
        string temp = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (valid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }
        //         lower case mein krdo
        for (int j = 0; j < temp.length(); j++)
        {
            temp[j] = lowerCase(temp[j]);
        }
        return checkPalindrome(temp);
    }
};