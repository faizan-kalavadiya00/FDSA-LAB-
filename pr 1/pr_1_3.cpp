#include <iostream>
using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string word = "";
    string longestWord = "";
    int maxLength = 0;

    for(int i = 0; i <= sentence.length(); i++)
    {
        if(sentence[i] != ' ' && sentence[i] != '\0')
        {
            word = word + sentence[i];
        }
        else
        {
            if(word.length() > maxLength)
            {
                longestWord = word;
                maxLength = word.length();
            }

            word = "";
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << maxLength << endl;

    return 0;
}