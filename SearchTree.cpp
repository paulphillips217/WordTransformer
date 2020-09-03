#include "SearchTree.h"

namespace transformer
{
  SearchTree::SearchTree(SearchTreeNode* node, Dictionary* dictionary)
  {
    nodeDictionary = dictionary;
    rootNode = node;
    solutionList.clear();
  }

  vector<string> SearchTree::getSolutionList()
  {
    return solutionList;
  }

  void SearchTree::breadthFirstSearch(string targetWord)
  {
    solutionList.push_back(targetWord);
    vector<SearchTreeNode*> parentTier;
    parentTier.push_back(rootNode);
    vector<SearchTreeNode*> currentTierNodes;

    // loop through tiers of the tree, up to depth limit
    for (int tier = 0; tier < maxSearchDepth; tier++)
    {
      // find close words for all the nodes in this tier
      for (SearchTreeNode* node : parentTier)
      {
        if (findCloseWords(node, targetWord))
        {
          // if we found the target word, we're done searching, make the solution vector
          solutionList.push_back(node->getNodeWord());
          makeSoltuionList(targetWord, node);
          return;
        }
        vector<SearchTreeNode*> closeWords = node->getCloseWords();
        currentTierNodes.insert(currentTierNodes.end(), closeWords.begin(), closeWords.end());
      }

      // prepare for next tier
      parentTier = currentTierNodes;
      currentTierNodes.clear();
    }
  }
  
  bool SearchTree::wordInParentTree(SearchTreeNode* node, string word)
  {
    if (node->wordMatchesNode(word))
      return true;

    //if we're at the root we stop
    SearchTreeNode* parent = node->getParentNode();
    if (!parent)
      return false;

    return wordInParentTree(parent, word);
  }

  bool SearchTree::findCloseWords(SearchTreeNode* node, string targetWord)
  {
    for (string dictionaryWord : nodeDictionary->dictionaryWords)
    {
      if (node->isDifferentByOne(node->getNodeWord(), dictionaryWord) && !wordInParentTree(node, dictionaryWord))
      {
        SearchTreeNode* newNode = new SearchTreeNode(dictionaryWord, node);
        node->closeWords.push_back(newNode);
        if (dictionaryWord.compare(targetWord) == 0)
          return true;
      }
    }
    return false;
  }

  void SearchTree::makeSoltuionList(string targetWord, SearchTreeNode* node)
  {    
    SearchTreeNode* parent = node->getParentNode();
    while (parent != NULL)
    {
      solutionList.push_back(parent->getNodeWord());
      parent = parent->getParentNode();
    } 
  }
}
