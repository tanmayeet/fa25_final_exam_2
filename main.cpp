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

void dequeue(Node*& head, Node*& tail) {
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

void printQueue(Node* head) {
  if (!head) {
    cout << "Empty queue.\n";
    return;
  }

  int count = 1;
  Node* curr = head;
  while (curr) {
    cout << "[" << count++ << "]" << curr->name << " ordered " << curr->drink
         << endl;
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  srand(time(0));
  // updated to have 20 names and 20 drinks
  string names[] = {"Alex",   "Jordan", "Taylor",  "Morgan",  "Casey",
                    "Riley",  "Jamie",  "Avery",   "Quinn",   "Parker",
                    "Drew",   "Reese",  "Skyler",  "Rowan",   "Emerson",
                    "Hayden", "Blake",  "Cameron", "Kendall", "Logan"};
  string drinks[] = {"Latte",
                     "Mocha",
                     "Espresso",
                     "Cappuccino",
                     "Americano",
                     "Flat White",
                     "Macchiato",
                     "Iced Latte",
                     "Cold Brew",
                     "Nitro Cold Brew",
                     "Chai Latte",
                     "Matcha Latte",
                     "Hot Chocolate",
                     "Caramel Latte",
                     "Vanilla Latte",
                     "Pumpkin Spice Latte",
                     "Cinnamon Dolce Latte",
                     "White Mocha",
                     "Iced Americano",
                     "Iced Mocha"};

  Node* head = nullptr;
  Node* tail = nullptr;

  // part of Milestone 2
  for (int i = 0; i < 3; i++) {
    string n = names[rand() % 20];
    string d = drinks[rand() % 20];
    enqueue(head, tail, n, d);
  }
  cout << "Initial queue:\n";
  printQueue(head);

  for (int round = 1; round <= 10; round++) {
    cout << "Round " << round << ":\n";
    if (rand() % 2 == 0) {
      string n = names[rand() % 20];
      string d = drinks[rand() % 20];
      enqueue(head, tail, n, d);
      cout << "A new customer joined the queue.\n";
    }
    dequeue(head, tail);
    printQueue(head);
  }

  return 0;
}