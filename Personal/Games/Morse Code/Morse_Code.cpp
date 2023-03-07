#include <iostream>
using namespace std;

void Morse(string word);

int main() {

  cout << "Welcome to the Morse Code translator!" << endl;
  cout << "To use this program, you must enter letters only--no numbers or "
          "symbols."
       << endl;
  cout << "To stop using the program, enter \'#\' by itself." << endl << endl;

  while (true) {
    string user_string;
    cout << "Enter a word: ";
    getline(cin, user_string);
    if (user_string == "#") {
      break;
    }
    Morse(user_string);
  }

  cout << "\nThank you for using the Morse Code translator!" << endl;

  return 0;
}

void Morse(string word) {
  bool valid_word = true;

  for (int i = 0; i < word.size(); i++) {
    if (word.at(i) >= 'A' && word.at(i) <= 'Z') {
      word.at(i) += 32;
    } else if (word.at(i) == ' ') {
      word.at(i) = '_';
    }
    if ((word.at(i) < 'a' || word.at(i) > 'z') && word.at(i) != '_') {
      valid_word = false;
      break;
    }
  }
  if (valid_word) {
    for (int j = 0; j < word.size(); j++) {
      switch (word.at(j)) {
      case 'a':
        cout << ".- ";
        break;
      case 'b':
        cout << "-... ";
        break;
      case 'c':
        cout << "-.-. ";
        break;
      case 'd':
        cout << "-.. ";
        break;
      case 'e':
        cout << ". ";
        break;
      case 'f':
        cout << "..-. ";
        break;
      case 'g':
        cout << "--. ";
        break;
      case 'h':
        cout << ".... ";
        break;
      case 'i':
        cout << ".. ";
        break;
      case 'j':
        cout << ".--- ";
        break;
      case 'k':
        cout << "-.- ";
        break;
      case 'l':
        cout << ".-.. ";
        break;
      case 'm':
        cout << "-- ";
        break;
      case 'n':
        cout << "-. ";
        break;
      case 'o':
        cout << "--- ";
        break;
      case 'p':
        cout << ".--. ";
        break;
      case 'q':
        cout << "--.- ";
        break;
      case 'r':
        cout << ".-. ";
        break;
      case 's':
        cout << "... ";
        break;
      case 't':
        cout << "- ";
        break;
      case 'u':
        cout << "..- ";
        break;
      case 'v':
        cout << "...- ";
        break;
      case 'w':
        cout << ".-- ";
        break;
      case 'x':
        cout << "-..- ";
        break;
      case 'y':
        cout << "-.-- ";
        break;
      case 'z':
        cout << "--.. ";
        break;
      case '_':
        cout << "  ";
        break;
      default:
        cout << "[ERROR] ";
        break;
      }
    }
  } else {
    cout << "[ERROR: UNRECOGNIZED CHARACTER(S)]";
  }
  cout << endl;
}