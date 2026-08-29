#include <iostream>

using namespace std;

class HasRoundBrackets {
private:
  int capacity;
  int *posParenthesis;
  int posTop;

public:
  HasRoundBrackets(int cap) {
    this->capacity = cap;
    this->posParenthesis = new int[capacity];
    this->posTop = -1;
  }

  ~HasRoundBrackets() { delete[] posParenthesis; }

  void push(int pos);
  int pop();

  int isParenthesis(char phrase[]);
};

int HasRoundBrackets::isParenthesis(char phrase[]) {
  for (int i = 0; phrase[i] != '\0'; i++) {
    char word = phrase[i];

    if (word == '(') {
      push(i);
    } else if (word == ')') {
      if (posTop == -1) {
        return i;
      } else {
        pop();
      }
    }
  }

  if (posTop != -1) {
    return posParenthesis[posTop];
  }

  return -1;
}

void HasRoundBrackets::push(int pos) {
  if (posTop < capacity - 1) {
    posTop++;
    posParenthesis[posTop] = pos;
  }
}

int HasRoundBrackets::pop() { return posParenthesis[posTop--]; }

int main() {
  char phrase[255];

  cin.getline(phrase, 255);

  HasRoundBrackets stack(254);

  int result = stack.isParenthesis(phrase);

  if (result == -1) {
    cout << "correto" << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}
