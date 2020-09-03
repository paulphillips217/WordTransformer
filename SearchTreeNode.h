#pragma once
#include <string>
#include <vector>
#include "Dictionary.h"

using namespace std;

namespace transformer
{
  class SearchTreeNode
  {
  private:
    string nodeWord;
    SearchTreeNode* nodeParent;

  public:
    vector<SearchTreeNode*> closeWords;
    SearchTreeNode(string word, SearchTreeNode* node);
    string getNodeWord();
    SearchTreeNode* getParentNode();
    vector<SearchTreeNode*> getCloseWords();
    bool isDifferentByOne(string a, string b);
    bool wordMatchesNode(string word);
  };
}
