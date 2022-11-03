// Alex Labitigan
// CPSC 120-12
// 2022-10-31
// alexlabitigan@csu.fullerton.edu
// @auhlz
//
// Lab 09-01
// Partners: @Menuk09
//
// Judge score
//

#include <iostream>
#include <string>
#include <vector>

double JudgeAverage(const std::vector<double>& scores) {
  double minimum_value{10000};
  double maximum_value{0.0};
  double sum_of_elems(0.0);
  double total{0};
  for (int i = 0; i < scores.size(); i++) {
    if (scores[i] < minimum_value ) {
      minimum_value = scores[i];
    }
  }
  for (int i = 0; i < scores.size(); i++) {
    if (scores[i] > maximum_value ) {
      maximum_value = scores[i];
  }
  }
 for (int i = 0; i < scores.size(); i++) {
     total += scores[i];
 }
sum_of_elems = total - maximum_value - minimum_value;
double average = sum_of_elems / (scores.size() - 2); 
  return average; 
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 4) {
    std::cout << "error: you must give at least three scores.\n";
    return 1;
  }
  std::vector<double> first;
  for (int i = 1; i < arguments.size(); i++){
    double v = stod(arguments[i]);
    first.push_back(v);
  }
double scores{0.0};
scores = JudgeAverage(first);
std::cout << "average is " << scores << "\n";

  return 0;
}

// Calculate and return the Olympics average of scores.
// The return value is the mean of all elements of scores, except for the
// minimum and maximum elements.
  // TODO: write statements to implement this function, and delete this comment
  // Hint:
  // - Write a loop that finds the minimum score.
  // - Write another loop that finds the maximum score.
  // - Write another loop that computes the total of all of the elements.
  // - Subtract the minimum and maximum from the total.
  // - Divide by the number of remaining elements.
  //   (The minimum and maximum don't count.)
// TODO: replace this return statement with one that actually works
  // TODO: validate that at least three arguments were provided.
  // If not, print
  // error: you must give at least three scores
  // and return a non-zero exit code.

  // TODO: Create a vector of doubles that will work as the scores argument
  // for the JudgeAverage function.
  // Use the Build a Vector pattern to write code that:
  //  - declares an empty vector of doubles
  //  - uses a loop to convert each argument to a double/float number, and
  //    use push_back to add the number to the back of the vector
  //  - the loop needs to skip the first element of arguments, which contains
  //    the command name "./judge"

  // TODO: Call the JudgeAverage function to calculate the average.
  // Store the return value of the function in a variable.

  // TODO: Use std::cout to print a message of the form
  // average is *the return value*

