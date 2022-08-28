#include <iostream>
#include <string>
using namespace std;

// Function prototypes
string character(string);
bool palindrome(string&, int, int);

int main()
{
    // Defining the variables
    string sentence;
    string newSentence;
    int first = 0;
    int last = string::npos;

    cout << "Enter a word or sentence" << endl;

    getline(cin, sentence);

    newSentence = character(sentence);

    cout << "Your word/sentence " << (palindrome(newSentence, first, last) ? "is a palindrome." : "is not a palindrome.") << endl;

    cin.get();

    return 0;
}

string character(string sentence) // Function definition of character
{
    string newSentence;

    for (unsigned int i = 0; i < sentence.length(); i++)
    {
        if (isalnum(sentence[i]))
        {
            newSentence += sentence[i];
        }
    }
    return newSentence;
}// This function will remove the spaces in between the words (if it is a sentence)

bool palindrome(string& newSentence, int first = 0, int last = string::npos)// Function definition of palindrome
{
    if (last == string::npos)
    {
        last = (newSentence.length() - 1);
    }
    if (newSentence[first] == newSentence[last])
    {
        if ((first - last) == 0)
        {
            return true; // If the first and the last letter is the same, it will return true
        }
        else if (first == (last - 1))
        {
            return true;
        }
        else
        {
            return palindrome(newSentence, first + 1, last - 1);
        }
    }
    else
    {
        return false; // If the sentence is not a palindrome, it will return false
    }
}
