// Alex Labitigan
// CPSC 120-12
// 2022-10-31
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 09-02
// Partners: @Menuk09
//
// Spell check
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Read all the words from the given filename, and return them as a vector
// of strings.
// If the file cannot be opened, return an empty vector.
  // TODO: declare an empty vector
  // TODO: open a std::ifstream
  // TODO: write a loop that reads each word from the ifstream, and
  // uses push_back to add each word to the vector
  // TODO: return the vector
// TODO: replace this return statement with one that actually works  

std::vector<std::string> ReadWords(const std::string& filename) {
  std::vector<std::string> first;
  std::ifstream input_file_stream(filename);
  while (input_file_stream.good()) {
    std::string line_buffer;
    input_file_stream >> line_buffer;
    if(input_file_stream){
      first.push_back(line_buffer);
    }
    // std::getline(input_file_stream, line_buffer);
    // first.push_back(line_buffer);
    // std::cout << line_buffer;
    }
  input_file_stream.close();

  return first;
}
//std::vector<std::string>()

// Return true if word is present in dictionary, or false otherwise.
// dictionary is intended to be a vector containing all words from a words.txt
// file.
// word is intended to be a string from a document file, that may or may not
// be spelled properly.
  // TODO: write a linear search loop that determines whether or not
  // word is present in dictionary.
  // TODO: return true if word is present, or false otherwise
// TODO: replace this return statement with one that actually works

bool InDictionary(const std::vector<std::string>& dictionary,
                  const std::string& word) {
// bool word_present = true;
for (int i = 0; i < dictionary.size(); i++){
  if (dictionary[i] == word){
    // word_present = false;
    return true;
  }
}
  return false;
}

// Return a vector containing all of the misspelled words in document.
// dictionary is intended to be a vector containing all words from a words.txt
// file.
// document is intended to be a vector of all of the words from a document
// file.
  // TODO: declare an empty vector
  // TODO: write a loop that checks each word string in document;
  //   calls InDictionary to determine whether the word is in dictionary;
  //   and adds the word to your vector if it not found
  // TODO: return your vector
// TODO: replace this return statement with one that actually works}

std::vector<std::string> MisspelledWords(
    const std::vector<std::string>& dictionary,
    const std::vector<std::string>& document) {
  std::vector<std::string> first;
  // std::string word;
  for (int i = 0; i < document.size(); i++){
    if (!InDictionary(dictionary,document.at(i))){
      first.push_back(document.at(i));
    }
      
  }
  return first;
    }
//std::vector<std::string>()


  // TODO: validate that one argument was provided.
  // If not, print
  // error: you must give a document filename
  // and return a non-zero exit code.

  // TODO: store the first and only command line argument, which holds a
  // document filename, in a variable

  // TODO: call ReadWords to read the contents of words.txt, and store the
  // return value in a variable for the dictionary

  // TODO: call ReadWords to read the contents of the document filename,
  // and store the return value in a variable for the document

  // TODO: call MisspelledWords to find the list of all misspelled words, and
  // store the return value in a variable for the output

  // TODO: print
  // spelling errors:
  // and then use a loop to print out each of the misspelled words

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
// for(int i = 0; i < for_doc.size(); i++){
//   std::cout << for_doc.at(i);
// }

std::vector<std::string> miss_word = MisspelledWords(for_dict,for_doc);

// miss_word = MisspelledWords(for_dict,for_doc);


// for(int i = 0; i < miss_word.size(); i++){
//   std::cout << miss_word.at(i);
// }
std::cout << "spelling errors: \n";
for (int i = 0; i < miss_word.size(); i++){
   std::cout << miss_word.at(i) << "\n";
}
  return 0;
}
