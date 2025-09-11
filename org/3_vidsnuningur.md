
# Table of Contents

1.  [Vidsnuningur (reversal)](#org42998b2)
    1.  [`std::reverse`](#orgbe88198)
    2.  [Manual reverse](#orgfac57b9)



<a id="org42998b2"></a>

# [Vidsnuningur (reversal)](https://open.kattis.com/problems/vidsnuningur)

-   Not necessarily "trivial". I tried two things:
    1.  with the `reverse` function from `<algorithm>` (requires iterators)
    2.  without `<string>` but instead with C-style strings and `<cstring>`
        and manual reversal in a reverse `for` loop.

-   Problem: Take a string of letters and digits without whitespace as
    input and print the reverse string as output.

-   Constraints: Input should be one line containing 1 to 1000 English
    letters and digits. There's no need to check the limit in the code.

-   Testing:
    
        Input: 2202annaloksdlahmarfinppekranutirroF
        Output: Forritunarkeppniframhaldskolanna2022
        
        Input: amma
        Output: amma

-   Plan:
    
    1.  use `cin` and `std::reverse` from `<algorithm>`.
    2.  code problem manually.
    
    With `reverse`:
    
        Stream input with cin
        Print std::input.reverse(string, first=0, last=length())


<a id="orgbe88198"></a>

## `std::reverse`

-   Test use of `reverse` for a string.
    
    1.  Define a start and an end iterator.
    2.  Use them as arguments.
    
        string s = "Hello";
        string::iterator a = s.begin();
        auto b = s.end()-1;
        cout << *a << endl;
        cout << *b << endl;
        reverse(s.begin(),s.end()); // reverses in place!
        cout << s;
    
        H
        o
        olleH

-   Solution 1: with `reverse`
    
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str;

-   Testing the solution: (org-babel-tangle)
    
        cd ../src
        make reversal
    
        cd ../src
        echo "2202annaloksdlahmarfinppekranutirroF" | ./reversal
        echo
        echo "amma" | ./reversal

-   [Submission 1:](https://open.kattis.com/submissions/17747785) OK
    
        #include <iostream>
        #include <string>
        #include <algorithm>
        
        int main()
        {
          std::string str;
          std::cin >> str;
          reverse(str.begin(), str.end());
          std::cout << str;
        
          return 0;
        }


<a id="orgfac57b9"></a>

## Manual reverse

-   Plan: Step through the string from the end and print each character.

-   Stepping through a string:
    
        string str = "Hello";
        
        for (char chr : str)
          cout << chr; // original string
        
        cout << "\n" << str.length() << endl;
        
        for (int i = 0; i < str.length(); i++)
          cout << str[i]; // original string
        
        cout << endl;
        
        for (int i = str.length()-1; i >= 0; i--)
          cout << str[i];
    
        Hello
        5
        Hello
        olleH

-   Let's use `gdb` to find the error here:
    
        #include <iostream>
        #include <string>
        
        int main()
        {
          std::string str = "Hello";
          for (int i = str.length()-1; i == 0; i--)
            std::cout << str[i];
        
          return 0;
        }
    
    1.  Compile with `-g` options: `g++ -g rev.cpp -o rev`
    2.  Enter debugger with `gdb rev`
    3.  In (gdb) console:
        -   `list` (list file with line numbers)
        -   `break 7` (line number for break stop)
        -   `run` (run up to `break` line number)
        -   `step` (next step)
    4.  Turns out that the loop is never entered because the condition
        i==0 is malformatted: it is only satisfied when i is 0 but at the
        start it is i = 4.
    5.  Correction: Change to i >= 0;

-   Even more C-style without `string` but with `char []` instead:
    
        #include <iostream>
        
        int main()
        {
          char str[] = "2202annaloksdlahmarfinppekranutirroF";
          int size = sizeof(str);
          for (int i = size-2; i >= 0; i--)
            std::cout << str[i];
        
          return 0;
        }

-   Submission 2: does not compile at kattis.com!  Reason: `cin` cannot
    stream into an uninitialized pointer-to-char. You need either a
    C-style array like `char str[1000];` or use `string`.
    
        #include <iostream>
        
        int main()
        {
          char *str = nullptr;
          std::cin >> str;
          int size = sizeof(str);
          for (int i = size-2; i >= 0; i--)
        
            std::cout << str[i];
        
          return 0;
        }
    
    Segmentation fault!
    
        cd ../src
        g++ rev2.cpp -o rev2
        echo "2202annaloksdlahmarfinppekranutirroF" | ./rev2
        echo
        echo "amma" | ./rev2

-   Corrected submission 2:
    
        #include <iostream>
        
        int main()
        {
          char str[1000];
          for (int i=0; i<1000; i++)
            {
              scanf("%c",&str[i]);
              printf("%c ", str[i]);
            }
          return 0;
        }
    
    Testing
    
        cd ../src
        g++ rev3.cpp -o rev3
        ##echo "2202annaloksdlahmarfinppekranutirroF" | ./rev3
        ##echo
        ##echo "amma" | ./rev3
        echo "Hello" | ./rev3

-   String instead of character: Need to find out when the entered
    string stops!
    
        #include <iostream>
        
        int main()
        {
          char str[1000];
          int count=0;
          scanf("%s",str);
          std::cout << str;
          for (int i=0; i<1000;i++)
            {
              if (str[i] == '\0')
            {
              std::cout << "\n" << i;
              break;
            }
              count++;
            }
          std::cout << count << "\n";
          for (int i=count-1; i>=0; i--)
            std::cout << str[i];
          return 0;
        }
    
    Testing:
    
        cd ../src
        g++ rev4.cpp -o rev4
        echo "Hello" | ./rev4

-   [Submission 2: OK](https://open.kattis.com/submissions/17748022)
    
    With `#include <cstring>` and `strlen(str)`.
    
        #include <iostream>
        #include <cstring>
        
        int main()
        {
          char str[1000];
          std::cin >> str;
          int size = strlen(str);
          for (int i = size-1; i >= 0; i--)
            std::cout << str[i];
          return 0;
        }
    
    Testing:
    
        cd ../src
        g++ rev5.cpp -o rev5
        echo "Hello" | ./rev5

