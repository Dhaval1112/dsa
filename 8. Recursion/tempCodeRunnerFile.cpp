string inttoword(int number, int level, string &ans)
// {
//     // Base condition
//     if (number == 0)
//     {
//         return ans;
//     }

//     string space = ans == "" ? "" : " ";
//     if (level == 2 || level == 5)
//     {
//         int tempNum = number % 10;
//         if (tempNum != 0)
//             ans = getNumDetails(tempNum, level) + space + ans;
//         number = number / 10;
//     }

//     if (level == 1 || level == 3 || level == 4)
//     {
//         int tempNum = number % 100;

//         ans = isSafe(getNumDetails(tempNum, level)) + space + ans;
//         number = number / 100;

//         if (level == 3 || level == 4 && (number > 0))
//         {
//             int tempNum = number % 10;
//             string result = getNumDetails(tempNum, 2);

//             if (result != "")
//             {
//                 ans = result + space + ans;
//             }
//             number = number / 10;
//         }
//     }
//     return inttoword(number, level + 1, ans);
// }
