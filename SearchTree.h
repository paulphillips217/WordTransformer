#pragma once
#include <vector>
#include "SearchTreeNode.h"

constexpr int maxSearchDepth = 10;

namespace transformer
{
  class SearchTree
  {
  private:
    SearchTreeNode* rootNode;
    vector<string> solutionList;
    Dictionary* nodeDictionary;
    bool wordInParentTree(SearchTreeNode* node, string word);
    bool findCloseWords(SearchTreeNode* node, string targetWord);
    void makeSoltuionList(string targetWord, SearchTreeNode* node);

  public:
    SearchTree(SearchTreeNode* node, Dictionary* dictionary);
    vector<string> getSolutionList();
    void breadthFirstSearch(string targetWord);
  };
}
