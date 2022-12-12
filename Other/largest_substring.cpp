#include <iostream>

int main() {
  std::string string1, string2;

  std::cout << "Enter first string: ";
  std::getline(std::cin, string1);
  std::cout << "Enter second string: ";
  std::getline(std::cin, string2);
  std::cin.sync();

  int str_array[string1.size()][string2.size()];
  int biggest_substr = 0;
  int str1_biggest_index = 0;

  for (int s2 = 0; s2 < string2.size(); s2++) {
    for (int s1 = 0; s1 < string1.size(); s1++) {
      if (s1 > 0 && s2 > 0) {
        if (string1.at(s1) == string2.at(s2)) {
          str_array[s2][s1] = 1 + str_array[s2 - 1][s1 - 1];
        } else {
          str_array[s2][s1] = 0;
        }
      } else {
        if (string1.at(s1) == string2.at(s2)) {
          str_array[s2][s1] = 1;
        } else {
          str_array[s2][s1] = 0;
        }
      }
      if (str_array[s2][s1] > biggest_substr) {
          biggest_substr = str_array[s2][s1];
          str1_biggest_index = s1;
      }
    }
  }

  std::cout << "Your biggest substring is: \'";
  for (int i = str1_biggest_index - biggest_substr + 1; i <= str1_biggest_index; i++) {
      std::cout << string1.at(i);
  }
  std::cout << "\'." << std::endl;

  return 0;
}