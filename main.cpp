#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iomanip>

// Title Lab 2: Text Analysis
//
// Purpose: Read a file of english text and return the counts of conjunctions and palindromes
//
//Class: CSC2430 Winter 2019
//
//Author: Shawn Wilcox

using namespace std;

const string CONJUNCTIONS[] = { "FOR", "AND", "NOR", "BUT", "OR", "YET", "SO"}; // initializes array
const int ConjunctionSize = sizeof(CONJUNCTIONS) / sizeof(CONJUNCTIONS[0]); // array size
int k = 0; // declares array

bool IsPalindrome(string& str)
// checks if string is a palindrome
{
   int i = 0;
   int j = str.length()-1;
   while (j > i)
   {
      if (str[i++]!=str[j--])
       {
        return false;
       }
   }
   return true;
}

string ToUpper(string& str)
// converts string(s) to uppercase
{
 transform(str.begin(), str.end(), str.begin(), ::toupper);
 return str;
}

int IsPalindromeInArray(string& strng, string(&str)[100], int& k)
// returns the position of the palindrome
{
   for (int i = 0; i <= k; i++)
    {
      if (str[i] == strng)
       {
        return i;
       }
   }
   return -1;
}

void PrintPalindromeCount(string(&str)[100], size_t(&arr)[100],int& k)
// prints table of formatted palindromes
{
   for (int i = 0; i < k; i++)
    {
     cout << setw(15) << left << str[i];
     cout << setw(5) << left << arr[i] << endl;
    }
}

void CountWords(string& strng, const string(&str)[ConjunctionSize], size_t(&arr)[ConjunctionSize],const int& k)
//checks if is a conjunction, if it is finds position
 {
   for (int i = 0; i < k; i++)
    {
       if (str[i] == strng)
       {
        arr[i]++;
       }
   }
}

void PrintWordCount(const string(&str)[ConjunctionSize], size_t(&arr)[ConjunctionSize],const int& k)
// prints out table of formatted conjunctions
{
   for (int i = 0; i < k; i++)
    {
     cout << setw(15) << left << str[i];
     cout << setw(5) << left << arr[i] << endl;
    }
}

int main(int argc, char **argv)
{
 ifstream fin;
 fin.open("*2city10.txt");
 string word;

 string Palindrome_Words[100] = { "" };
 size_t Palindrome_Count[sizeof(Palindrome_Words) / sizeof(Palindrome_Words[0])] = { 0 };
 size_t Conjunction_Count[sizeof(CONJUNCTIONS) / sizeof(CONJUNCTIONS[0])] = { 0 };

 if (argc > 1)
    {
     fin.open(argv[1]);

     if (!fin)
        {
         cerr << "File Open Failed" << argv[1] << endl;
         return 1;
        }
    }
while (!fin.eof())
        {
         fin >> word;
         ToUpper(word);
         CountWords(word, CONJUNCTIONS, Conjunction_Count, ConjunctionSize);

        if (IsPalindrome(word))
            {
             int abc = IsPalindromeInArray(word, Palindrome_Words, k);
             if (abc == -1 && k < 100)
                {
                 Palindrome_Words[k] = word; Palindrome_Count[k]++; k++;
                }
             else
                {
             Palindrome_Count[abc]++;
                }
            }
        }

    for (int i = 0; i < 1 ; i++)
        {
         PrintWordCount(CONJUNCTIONS, Conjunction_Count, ConjunctionSize);
         cout << endl;
         cout << endl;
         PrintPalindromeCount(Palindrome_Words, Palindrome_Count, k);

        }

    return 0;
}
