#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
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
    cout << "[" << count++ << "] " << curr->name << " ordered " << curr->drink
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

  // for milestone 3
  deque<string> muffinQueue;
  // for milestone 4
  vector<string> braceletQueue;

  // part of Milestone 2
  for (int i = 0; i < 3; i++) {
    string n = names[rand() % 20];
    string d = drinks[rand() % 20];
    enqueue(head, tail, n, d);
  }

  // For muffin queue
  for (int i = 0; i < 3; i++) {
    string n = names[rand() % 20];
    muffinQueue.push_back(n);
  }

  for (int i = 0; i < 3; i++) {
    string n = names[rand() % 20];
    braceletQueue.push_back(n);
  }

  cout << "Initial queue for drinks:\n";
  printQueue(head);

  cout << "Initial queue for muffins:\n";
  for (int i = 0; i < muffinQueue.size(); i++) {
    cout << "[" << i + 1 << "] " << muffinQueue[i] << endl;
  }
  cout << endl;

  cout << "Initial queue for friendship bracelets:\n";
  for (int i = 0; i < braceletQueue.size(); i++) {
    cout << "[" << i + 1 << "] " << braceletQueue[i] << endl;
  }
  cout << endl;

  // running the simulation 10 times
  for (int round = 1; round <= 10; round++) {
    cout << "Round " << round << ":\n";
    // 50% probability
    if (rand() % 2 == 0) {
      // for drinks
      string n = names[rand() % 20];
      string d = drinks[rand() % 20];
      enqueue(head, tail, n, d);
      cout << "A new customer joined the coffee queue.\n";

      // for muffins
      string n = names[rand() % 20];
      muffinQueue.push_back(n);
      cout << "A new customer joined the muffin queue.\n";

      // for bracelets
      string n = names[rand() % 20];
      braceletQueue.push_back(n);
      cout << "A new customer joined the bracelet queue.\n";
    }
    dequeue(head, tail);

    if (!muffinQueue.empty()) {
      muffinQueue.pop_front();
    }

    if (!muffinQueue.empty()) {
      muffinQueue.pop_back();
    }

    cout << "Coffee booth queue:\n";
    printQueue(head);

    cout << "Muffin booth queue:\n";
    if (muffinQueue.empty()) {
      cout << "Empty queue.\n";
    } else {
      for (int i = 0; i < muffinQueue.size(); i++) {
        cout << "[" << i + 1 << "] " << muffinQueue[i] << endl;
      }
      cout << endl;
    }

    cout << "Friendship booth queue:\n";
    if (braceletQueue.empty()) {
      cout << "Empty queue.\n";
    } else {
      for (int i = 0; i < braceletQueue.size(); i++) {
        cout << "[" << i + 1 << "] " << braceletQueue[i] << endl;
      }
      cout << endl;
    }
  }
  return 0;
}