/*
🔧 Features You’ll Implement:
Add a New Task

Input task title, description, due date.

Auto-generate unique ID using a counter.

Display All Tasks

Traverse and show pending and completed tasks with status icons ✅ / ❌.

Mark Task as Complete

Search by task ID and set isCompleted = true.

Delete Task

Find by ID and unlink + delete node.

Edit Task

Update title, description, or due date.

Search Task by Keyword

Use substring matching in title/description.

Sort Tasks by Due Date (BONUS)

Reorder linked list based on string dates (lexicographically).

Save and Load from File (SUPER BONUS)

Save all tasks to a .txt or .csv file on exit.

Load them when program starts. */
void userTerminal(int &option);
#include <iostream>
#include <fstream>
#include <ctime>
struct Task
{
    int id;
    std::string title;
    std::string description;
    std::string dueDate;
    bool isCompleted;
    Task *next;
};
void greetUser();
void addTask(Task *&head, int &id);
void viewAllTasks(Task *head);
int main()
{
    srand(time(NULL));
    Task *head = nullptr;
    int menuOption;
    int id = (rand() % 0001) + 1050;
    system("cls");
    greetUser();
    do
    {
        userTerminal(menuOption);
        switch (menuOption)
        {
        case 1:
            addTask(head, id);
            break;
        case 2:
            viewAllTasks(head);
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;

        default:
            std::cout << "Invalid Input\n";
            std::cout << "Exiting Application...";
            break;
        }
    } while (menuOption >= 1 && menuOption <= 7);

    return 0;
}
void greetUser()
{
    system("cls");
    std::cout << "Hello, Welcome To The Task Manager App" << std::endl;
    std::cout << "Enter To Continue...";
    std::cin.get();
    system("cls");
}
void userTerminal(int &option)
{

    std::cout << ".....Task Manager Menu.....\n1. Add New Task \n2. View All Tasks \n3. Mark Task Complete \n4. Edit Task \n5. Delete Task \n6. Search Task \n7. Exit\n\nOption:";
    std::cin >> option;
}
void addTask(Task *&head, int &id)
{
    system("cls");
    std::cout << "Adding Task...\n";
    Task *newTask = new Task();
    newTask->next = nullptr;
    newTask->isCompleted = false;
    std::cin.ignore();

    std::cout << "\nTitle       :";
    getline(std::cin, newTask->title);

    std::cout << "\nDescription :";
    getline(std::cin, newTask->description);

    std::cout << "\nDue Date    :";
    getline(std::cin, newTask->dueDate);

    std::cout << "\nDone!, Press Enter To Generate Task Id...";
    std::cin.get();
    system("cls");
    newTask->id = id++;

    if (head == nullptr)
    {

        head = newTask;
    }
    else
    {
        Task *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newTask;
    }
    std::cout << "Task Has Been Added Succesfully\n";
    std::cout << "Task ID :" << newTask->id;
    std::cout << "\nPress Enter To Return To Menu...";
    std::cin.get();
    system("cls");
}
void viewAllTasks(Task *head)
{
    Task *iterator = head;
    system("cls");
    std::cout << "All Tasks";
    if (iterator == nullptr)
    {
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        return;
    }

    while (iterator != nullptr)
    {
        std::cout << "\nTask ID      : " << iterator->id;
        std::cout << "\nTitle        : " << iterator->title;
        std::cout << "\nDescription  : " << iterator->description;
        std::cout << "\nDue Date     : " << iterator->dueDate;
        std::cout << "\nStatus       : " << (iterator->isCompleted ? "Completed" : "Pending");
        std::cout << "\n-----------------------------------\n";
        iterator = iterator->next;
    }
    std::cout << "End Of Task List\n";
    std::cin.ignore();
    std::cout << "\nPress Enter To Return To Menu...";
    std::cin.get();
    system("cls");
}