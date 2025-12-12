// COMSC210 | Final Exam 2 | Tanmayee Chalamalasetti
// IDE used: VS Code

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const int namesNum = 20;
const int drinksNum = 20;
const int init = 3;
const int sim = 10;
const int prob = 2;

// coffee booth queue simulation struct
struct Node {
  string name;
  string drink;
  Node* next;
};

// adds customer to end of the queue
// referenced notes on linked lists while writing this

// enqueue() adds a new customer to the end of the coffee booth queue
// arguments: head (pointer to the front of the queue), tail (pointer to the end
// of the queue), n (customer name), d (drink order)
// returns: nothing
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

// dequeue() removes a customer at the front of the coffee booth queue
// arguments: head (pointer to the front of the queue), tail (pointer to the end
// of the queue)
// returns: nothing
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

// printQueue() displays all the customers currently in the coffee booth queue
// arguments: head (pointer to the front of the queue)
// returns: nothing
void printQueue(Node* head) {
  if (!head) {
    cout << "Empty queue.\n";
    return;
  }

  int count = 1;
  Node* curr = head;
  while (curr) {
    cout << "[" << count++ << "] " << curr->name << " ordered a(n) "
         << curr->drink << endl;
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
  // for milestone 5
  stack<string> saxStack;

  // part of Milestone 2
  for (int i = 0; i < init; i++) {
    string n = names[rand() % namesNum];
    string d = drinks[rand() % drinksNum];
    enqueue(head, tail, n, d);
  }

  // For muffin queue
  for (int i = 0; i < init; i++) {
    string n = names[rand() % namesNum];
    muffinQueue.push_back(n);
  }

  for (int i = 0; i < init; i++) {
    string n = names[rand() % namesNum];
    braceletQueue.push_back(n);
  }

  for (int i = 0; i < init; i++) {
    string n = names[rand() % namesNum];
    saxStack.push(n);
  }

  cout << "Initial queue for drinks:\n";
  printQueue(head);
  cout << endl;

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

  cout << "Initial stack for saxophones:\n";
  stack<string> temp = saxStack;
  int pos = 1;
  while (!temp.empty()) {
    cout << "[" << pos++ << "] " << temp.top() << endl;
    temp.pop();
  }

  cout << "\n";

  // running the simulation 10 times
  for (int round = 1; round <= sim; round++) {
    cout << "Round " << round << ":\n";
    // 50% probability
    if (rand() % prob == 0) {
      // for drinks
      string n = names[rand() % namesNum];
      string d = drinks[rand() % drinksNum];
      enqueue(head, tail, n, d);
      cout << "A new customer joined the coffee queue.\n";
    }

    if (rand() % prob == 0) {
      // for muffins
      string n = names[rand() % namesNum];
      muffinQueue.push_back(n);
      cout << "A new customer joined the muffin queue.\n";
    }

    if (rand() % prob == 0) {
      // for bracelets
      string n = names[rand() % namesNum];
      braceletQueue.push_back(n);
      cout << "A new customer joined the bracelet queue.\n";
    }

    if (rand() % prob == 0) {
      // for saxophones
      string n = names[rand() % namesNum];
      saxStack.push(n);
      cout << "A new customer joined the saxophone stack.\n";
    }

    cout << endl;
    dequeue(head, tail);

    if (!muffinQueue.empty()) {
      muffinQueue.pop_front();
    }

    if (!braceletQueue.empty()) {
      braceletQueue.erase(braceletQueue.begin());
    }

    if (!saxStack.empty()) {
      saxStack.pop();
    }

    cout << "Coffee booth queue:\n";
    printQueue(head);
    cout << endl;

    cout << "Muffin booth queue:\n";
    if (muffinQueue.empty()) {
      cout << "Empty queue.\n";
    } else {
      for (int i = 0; i < muffinQueue.size(); i++) {
        cout << "[" << i + 1 << "] " << muffinQueue[i] << endl;
      }
    }
    cout << endl;

    cout << "Friendship booth queue:\n";
    if (braceletQueue.empty()) {
      cout << "Empty queue.\n";
    } else {
      for (int i = 0; i < braceletQueue.size(); i++) {
        cout << "[" << i + 1 << "] " << braceletQueue[i] << endl;
      }
    }
    cout << endl;

    cout << "Saxophone booth stack:\n";
    if (saxStack.empty()) {
      cout << "Empty stack.\n";
    } else {
      stack<string> temp2 = saxStack;
      int pos2 = 1;
      while (!temp2.empty()) {
        cout << "[" << pos2++ << "] " << temp2.top() << endl;
        temp2.pop();
      }
    }
    cout << endl;
  }
  return 0;
}