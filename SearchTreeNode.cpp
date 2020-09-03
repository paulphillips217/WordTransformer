#include <algorithm>
#include <iostream>
#include "SearchTreeNode.h"

namespace transformer
{  
  SearchTreeNode::SearchTreeNode(string word, SearchTreeNode* node)
  {
    nodeWord = word;
    nodeParent = node;
    closeWords.clear();
  }

  string SearchTreeNode::getNodeWord()
  {
    return nodeWord;
  }

  SearchTreeNode* SearchTreeNode:: getParentNode()
  {
    return nodeParent;
  }

  vector<SearchTreeNode*> SearchTreeNode::getCloseWords()
  {
    return closeWords;
  }

  bool SearchTreeNode::isDifferentByOne(string a, string b)
  {
    if (a.length() != b.length())
      return false;

    // return true if the words are different by one letter
    int diffCount = 0;
    for (size_t i = 0; i < a.length(); i++)
    {
      diffCount += ((a[i] == b[i]) ? 0 : 1);
    }
    return (diffCount == 1);
  }

  bool SearchTreeNode::wordMatchesNode(string word)
  {
    // match if the word matches the root word
    if (nodeWord.compare(word) == 0)
      return true;

    // search the closeWords vector
    auto it = find_if(closeWords.begin(), closeWords.end(), [word](SearchTreeNode* closeWord)
      {
        return (closeWord->getNodeWord().compare(word) == 0);
      });
    return (it != closeWords.end());
  }
}
