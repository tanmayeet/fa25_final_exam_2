#include <iostream>
#include <string>
using namespace std;

// coffee booth queue simulation struct
struct Node {
  string name;
  string drink;
  Node* next;
};

// adds customer to end of the queue
// referenced notes on linked lists while writing this
void enqueue(Node*& head, Node*& tail, string n, string d) {
  Node* temp = new Node;
  temp->name = n;
  temp->drink = d;
  temp->next = nullptr;

  if (!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void deque(Node*& head, Node*& tail) {
  if (!head) {
    return;
  }
  Node* temp = head;
  head = head->next;

  if (!head) {
    tail = nullptr;
  }
  delete temp;
}

int main() {
  string names[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey"};
  string drinks[] = {"Latte", "Mocha", "Espresso", "Cappuccino", "Americano"};

  return 0;
}