// Alex Labitigan
// CPSC 120-12
// 2022-10-31
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 09-02
// Partners: @Menulk09
//
// Spell check
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> ReadWords(const std::string& filename) {
  std::vector<std::string> first;
  std::ifstream input_file_stream(filename);
  while (input_file_stream.good()) {
    std::string line_buffer;
    input_file_stream >> line_buffer;
    if (input_file_stream) {
      first.push_back(line_buffer);
    }
  }
  input_file_stream.close();

  return first;
}
bool InDictionary(const std::vector<std::string>& dictionary,
                  const std::string& word) {
  for (int i = 0; i < dictionary.size(); i++) {
    if (dictionary[i] == word) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> MisspelledWords(
    const std::vector<std::string>& dictionary,
    const std::vector<std::string>& document) {
  std::vector<std::string> first;
  // std::string word;
  for (int i = 0; i < document.size(); i++) {
    if (!InDictionary(dictionary, document.at(i))) {
      first.push_back(document.at(i));
    }
  }
  return first;
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 2) {
    std::cout << "error: you must give a document filename.\n";
    return 1;
  }
  std::string hold{arguments[1]};
  std::string words_list{"words.txt"};

  std::vector<std::string> for_dict;
  for_dict = ReadWords(words_list);

  std::vector<std::string> for_doc;
  for_doc = ReadWords(hold);
  std::vector<std::string> miss_word = MisspelledWords(for_dict, for_doc);

  std::cout << "spelling errors: \n";
  for (int i = 0; i < miss_word.size(); i++) {
    std::cout << miss_word.at(i) << "\n";
  }
  return 0;
}