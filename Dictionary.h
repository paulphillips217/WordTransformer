#pragma once
#include <vector>

using namespace std;

namespace transformer
{
  class Dictionary
  {
  public:
    vector<string> dictionaryWords;
    void readFile();
  };
}

