#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

namespace transformer
{
  string filePath = "dictionary.txt";

  void Dictionary::readFile()
  {
    ifstream dictionaryFile;
    try {
      dictionaryFile.open(filePath);
      if (dictionaryFile.is_open())
      {
        string word;
        while (getline(dictionaryFile, word)) {

          // make sure word is all lowercase
          transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) { return tolower(c); });

          dictionaryWords.push_back(word);
        }
        dictionaryFile.close();
      }
      else
        cout << "Dictionary file not found" << endl;
    }
    catch (ifstream::failure e) {
      cout << "Exception reading dictionary file" << endl;
    }
  }
}