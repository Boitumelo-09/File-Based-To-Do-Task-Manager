#include "TaskManager.h"
#include <iostream>
#include <ctime>


int main()
{
    srand(time(nullptr));
    Task *head = nullptr;
    int menuOption;
    int id = 1;
    clearScreen();
    greetUser();
    do
    {
        showMenu(menuOption);
        switch (menuOption)
        {
        case 1:
            addTask(head, id);
            break;

        case 2:
            viewAllTasks(head);
            break;
        case 3:
            markTasks(head);
            break;
        case 4:
            editTask(head);
            break;
        case 5:
            deleteTask(head);
            break;
        case 6:
            searchTask(head);
            break;
        case 7:
            saveToFile(head);
            break;
        case 8:
            loadfromFILE(head);
            break;
        case 9:
            freememory(head);
            return 0;
        default:
            clearScreen();
            std::cout << "Unknown User Input\n";
            std::cout << "Exiting Application...";
            break;
        }
    } while (menuOption >= 1 && menuOption <= 9);

    return 0;
}

