#include <iostream>
#include "Dictionary.h"
#include "SearchTree.h"
#include "SearchTreeNode.h"

using namespace std;
using namespace transformer;

int main()
{
  // since time is short, I've created a text dictionary of 4-letter words
  // with more time I would have expanded the program to work with words of any length

  Dictionary dictionary;
  string startWord;
  string endWord;
  dictionary.readFile();

  cout << "Please enter the 4-letter starting word: ";
  cin >> startWord;
  // check word format
  if (startWord.size() != 4)
  {
    cout << "Error: the word needs to be 4 letters long";
    return 0;
  }

  SearchTreeNode* node = new SearchTreeNode(startWord, NULL);
  SearchTree searchTree(node, &dictionary);

  cout << "Please enter the 4-letter ending word: ";
  cin >> endWord;
  // check word format
  if (endWord.size() != 4)
  {
    cout << "Error: the word needs to be 4 letters long";
    return 0;
  }

  searchTree.breadthFirstSearch(endWord);
  vector<string> solutionList = searchTree.getSolutionList();

  if (solutionList.size() <= 1)
    cout << "couldn't find a path from starting word to ending word" << endl;
  else
  {
    for (vector<string>::reverse_iterator rit = solutionList.rbegin(); rit != solutionList.rend(); ++rit)
      cout << *rit << endl;
  }
}
