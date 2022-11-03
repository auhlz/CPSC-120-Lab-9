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
  for (double score : scores) {
    if (score < minimum_value) {
      minimum_value = score;
    }
  }
  for (double score : scores) {
    if (score > maximum_value) {
      maximum_value = score;
    }
  }
  for (double score : scores) {
    total += score;
  }
  sum_of_elems = total - maximum_value - minimum_value;
  double average = sum_of_elems / double(scores.size() - 2);
  return average;
}
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 4) {
    std::cout << "error: you must give at least three scores.\n";
    return 1;
  }
  std::vector<double> first;
  for (int i = 1; i < arguments.size(); i++) {
    double v = stod(arguments[i]);
    first.push_back(v);
  }
  double scores{0.0};
  scores = JudgeAverage(first);
  std::cout << "average is " << scores << "\n";

  return 0;
}