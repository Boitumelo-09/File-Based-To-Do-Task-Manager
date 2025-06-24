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
struct Task
{
    int id;
    std::string title;
    std::string description;
    std::string dueDate;
    bool isCompleted;
    Task *next;
};
void addTask(Task *&head);
int main()
{
    Task *head = nullptr;
    int menuOption;
    system("cls");
    do
    {
        userTerminal(menuOption);
        switch (menuOption)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
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
void userTerminal(int &option)
{
    system("cls");
    std::cout << "Hello, Welcome To The Task Manager App" << std::endl;
    std::cout << "Enter To Continue...";
    std::cin.get();
    system("cls");
    std::cout << ".....Task Manager Menu.....\n1. Add New Task \n2. View All Tasks \n3. Mark Task Complete \n4. Edit Task \n5. Delete Task \n6. Search Task \n7. Exit\n\n ";
    std::cin >> option;
}
void addTask(Task *&head)
{
    system("cls");
    Task *newTask = new Task();
}