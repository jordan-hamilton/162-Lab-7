/***********************************************************************************************
** Program name: Lab 7
** Author: Jordan Hamilton
** Date: 11/11/2018
** Description: This program displays a menu asking the user to add an integer to the end of a
** queue in a new node, display the integer data member of the node at the front of the queue,
** remove the node at the front of the queue, display the values of all nodes in the queue, or
** quit the program. A method in the Queue object performs the appropriate action on a
** circular linked list based on the user's choice.
***********************************************************************************************/

#include <iostream>

#include "Menu.hpp"
#include "Queue.hpp"

using std::cout;
using std::endl;

void populateMenu(Menu *mainMenu);

/***********************************************************************************************
** Description: This program can be run via the lab7 executable generated by make.
***********************************************************************************************/
int main() {

  int choice;
  Menu* mainMenu = nullptr;
  Queue* queue = nullptr;

  mainMenu = new Menu("Select from the following options:");
  populateMenu(mainMenu);

  queue = new Queue;

  do {

    choice = mainMenu->getIntFromPrompt(1, mainMenu->getMenuChoices(), true);

    cout << endl;

    switch (choice)  {

      case 1 : queue->addBack( mainMenu->getIntFromPrompt("Enter an integer to add to the back of the queue:", -100000, 100000, false) );
               break;

      case 2 : if ( !queue->isEmpty() ) {
                  cout << queue->getFront() << endl;
               } else {
                  cout << "No values exist in this queue." << endl;
               }

               break;

      case 3 : if ( !queue->isEmpty() ) {
                  queue->removeFront();
               } else {
                  cout << "No values exist in this queue." << endl;
               }

               break;

      case 4 : queue->printQueue();
               break;

      default : {}

    }

    cout << endl;

  } while(choice != 5);

  if (queue) {
    delete queue;
    queue = nullptr;
  }

  delete mainMenu;
  mainMenu = nullptr;

  return 0;

}


/***********************************************************************************************
** Description: This function takes a pointer to a Menu object, then calls the addMenuItem
** method to add the approprate menu options to the program's menu.
***********************************************************************************************/
void populateMenu(Menu* mainMenu) {

  mainMenu->addMenuItem("Add a value to the back of the queue");
  mainMenu->addMenuItem("Display the front value");
  mainMenu->addMenuItem("Remove the front node");
  mainMenu->addMenuItem("Display the queue's content");
  mainMenu->addMenuItem("Exit");

}
