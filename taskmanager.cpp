
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#ifdef _WIN32
#define wipeScreen "cls"

#else
#define wipeScreen "clear"

#endif

class Task
{
public:
    int id{0};
    std::string title{""};
    std::string description{""};
    std::string dueDate{""};
    bool isCompleted{false};
    Task *next{nullptr};

    Task() = default;

    Task(int id, std::string title, std::string description, std::string dueDate, bool isCompleted, Task *next) : id(id), title(title), description(description), dueDate(dueDate), isCompleted(isCompleted), next(next)
    {
    }
};
void clearScreen()
{
    system(wipeScreen);
}
void greetUser();
void showMenu(int &option);
void freememory(Task *&head);
void addTask(Task *&head, int &id);
void viewAllTasks(Task *head);
void markTasks(Task *&head);
void editTask(Task *&head);
void deleteTask(Task *&head);
void searchTask(Task *head);
void saveToFile(Task *&head);
void loadfromFILE(Task *head);
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

void greetUser()
{
    clearScreen();
    std::cout << "Hello, Welcome To The Task Manager App\nFollow Prompts\nOnly One Word Will Be Accepted For Task Title.\n\n"
              << std::endl;
    std::cout << "Press Enter To Continue...";
    std::cin.get();
    clearScreen();
}

void showMenu(int &option)
{
    std::cout << "\t\tTask Manager Menu\n\n1. Add New Task \n2. View All Tasks \n3. Mark Task \n4. Edit Task \n5. Delete Task \n6. Search Task\n7. Save Tasks To File\n8. Load Tasks From A File \n9. Exit\n\nOption : ";
    std::cin >> option;
}

void addTask(Task *&head, int &id)
{
    clearScreen();
    std::cout << "Adding Task...\n";
    Task *newTask = new Task();
    newTask->next = nullptr;
    newTask->isCompleted = false;

    std::cout << "\nTitle(One-Word) :";
    std::cin >> newTask->title;
    std::cin.ignore();
    std::cout << "\nDescription     :";
    getline(std::cin, newTask->description);
    std::cout << "\nDue Date        :";
    getline(std::cin, newTask->dueDate);

    std::cout << "\nDone!, Press Enter To Generate Task Id...";
    std::cin.get();
    clearScreen();
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
    clearScreen();
}

void viewAllTasks(Task *head)
{
    Task *iterator = head;
    clearScreen();
    std::cout << "All Tasks";
    if (iterator == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
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
    clearScreen();
}

void freememory(Task *&head)
{
    clearScreen();
    Task *freeTask = head;
    while (freeTask != nullptr)
    {
        Task *freshTask = freeTask->next;
        delete freeTask;
        freeTask = freshTask;
    }
    head = nullptr;
    std::cout << "Freeing Memory & Exiting App...\nGood Bye!!!\n";
    return;
}

void deleteTask(Task *&head)
{
    clearScreen();
    std::string deleteEntry;
    Task *searchPtr = head;
    Task *prev = nullptr;
    bool found = false;

    if (head == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    std::cin.ignore();
    std::cout << "Enter Task Title : ";
    std::getline(std::cin, deleteEntry);

    while (searchPtr != nullptr && searchPtr->title != deleteEntry)
    {
        prev = searchPtr;
        searchPtr = searchPtr->next;
    }

    if (searchPtr == nullptr)
    {
        std::cout << "\nTask Not Found.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    if (prev == nullptr)
    {
        head = head->next;
    }
    else
    {
        prev->next = searchPtr->next;
    }

    delete searchPtr;
    std::cout << "\nTask Successfully Deleted.\n";
    std::cout << "Press Enter To Return To Menu...";
    std::cin.get();
    clearScreen();
    return;
}

void markTasks(Task *&head)
{
    int markOption;
    std::string taskTitle;
    Task *currentTask = head;
    clearScreen();
    std::cout << "Marking Task...\n\n";
    std::cout << "Task Title:";
    std::cin.ignore();
    getline(std::cin, taskTitle);

    while (currentTask != nullptr && currentTask->title != taskTitle)
    {
        currentTask = currentTask->next;
    }

    if (currentTask == nullptr)
    {
        std::cout << "\n\nTask Not Found...";
        std::cout << "\nPress Enter To Return To Main Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    std::cout << "Task Found...\nDetails:";
    std::cout << "\nTask ID      : " << currentTask->id;
    std::cout << "\nTitle        : " << currentTask->title;
    std::cout << "\n...................................................\n";
    std::cout << "\n\nOptions:\n1. Completed\n2. Still Pending\nChoice:";
    std::cin >> markOption;
    currentTask->isCompleted = (markOption == 1);
    std::cin.ignore();
    clearScreen();
    std::cout << "Task Update...\n\n";
    std::cout << "Details:";
    std::cout << "\nTask ID      : " << currentTask->id;
    std::cout << "\nTitle        : " << currentTask->title;
    std::cout << "\nDescription  : " << currentTask->description;
    std::cout << "\nStatus       : " << (currentTask->isCompleted ? "Completed" : "Pending");
    std::cout << "\n\nPress Enter To Continue...";
    std::cin.get();
    clearScreen();
}

void editTask(Task *&head)
{
    clearScreen();
    Task *tempTask = head;
    std::string taskTitle;
    std::cout << "Editing Task...\nTask Title : ";
    std::cin.ignore();
    getline(std::cin, taskTitle);

    while (tempTask != nullptr && tempTask->title != taskTitle)
    {
        tempTask = tempTask->next;
    }

    if (tempTask == nullptr)
    {
        std::cout << "\nTask Not Found...\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    std::cout << "Task Found...\nPress Enter To Continue To Make Changes...\n";
    std::cin.get();
    clearScreen();
    int updateOption;
    std::string newTitle, newDescription;
    std::cout << "Making Updates...\nOptions\n1. Update Title\n2. Update Description\n3. Update Status\nOption:";
    std::cin >> updateOption;
    std::cin.ignore();

    switch (updateOption)
    {
    case 1:
        clearScreen();
        std::cout << "Updating Title...\n";
        std::cout << "Current Title :" << tempTask->title;
        std::cout << "\nNew Title     :";
        std::cin >> newTitle;
        tempTask->title = newTitle;
        break;
    case 2:
        clearScreen();
        std::cout << "Updating Description...\n";
        std::cout << "Current Description :" << tempTask->description;
        std::cout << "\nNew Description   :";
        getline(std::cin, newDescription);
        tempTask->description = newDescription;
        break;
    case 3:
        clearScreen();
        int statusChoice;
        std::cout << "Updating Status...\nOptions:\n1. Completed\n2. Pending\nChoice:";
        std::cin >> statusChoice;
        tempTask->isCompleted = (statusChoice == 1);
        break;
    default:
        std::cout << "Invalid Response\nPress Enter To Exit App...";
        std::cin.get();
        freememory(head);
        exit(0);
    }

    std::cout << "\nTask Successfully Updated\nPress Enter To Return To Menu...";
    std::cin.get();
    clearScreen();
}

void searchTask(Task *head)
{
    clearScreen();
    Task *tempTask = head;
    std::string searchEntry;

    if (tempTask == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    std::cin.ignore();
    std::cout << "Search : ";
    std::getline(std::cin, searchEntry);

    while (tempTask != nullptr && tempTask->title != searchEntry)
    {
        tempTask = tempTask->next;
    }

    if (tempTask == nullptr)
    {
        std::cout << "Task Not Found.\nPress Enter To Return To Main...";
        std::cin.get();
        clearScreen();
        return;
    }

    std::cout << "Task Found.\nPress Enter To See Details...";
    std::cin.get();
    clearScreen();
    std::cout << "\nTask ID      : " << tempTask->id;
    std::cout << "\nTitle        : " << tempTask->title;
    std::cout << "\nDescription  : " << tempTask->description;
    std::cout << "\nDue Date     : " << tempTask->dueDate;
    std::cout << "\nStatus       : " << (tempTask->isCompleted ? "Completed" : "Pending");
    std::cout << "\n-----------------------------------\n";
    std::cout << "\nPress Enter To Return To Main...";
    std::cin.get();
    clearScreen();
}

void saveToFile(Task *&head)

{
    int optionChoice;
    clearScreen();

    Task *printTaskPtr = head;

    if (printTaskPtr == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks availave to save.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }
    else
    {
        std::cout << "\t\tOptions\n\n";
        std::cout << "\t\t1. Append Tasks\n";
        std::cout << "\t\t2. Overwrite Tasks\n";
        std::cout << "\tOption_:";
        std::cin >> optionChoice;
        if (optionChoice == 1)
        {
            std::ofstream file("to_do_list.txt", std::ios::app);
            file << "Tasks!";
            file << "\n...............................\n";
            while (printTaskPtr != nullptr)
            {

                file << printTaskPtr->id << "\n"
                     << printTaskPtr->title << "\n"
                     << printTaskPtr->description << "\n"
                     << printTaskPtr->dueDate << "\n";
                if (printTaskPtr->isCompleted)
                {
                    file << "Completed";
                }
                else
                {
                    file << "Still Pending";
                }

                file << "\n_______________________________\n";
                printTaskPtr = printTaskPtr->next;
            }
            file << "\nEnd Of List...";
            file.close();
        }
        else if (optionChoice == 2)
        {
            std::ofstream file("to_do_list.txt");
            file << "Tasks!";
            file << "\n...............................\n";
            while (printTaskPtr != nullptr)
            {

                file << printTaskPtr->id << "\n"
                     << printTaskPtr->title << "\n"
                     << printTaskPtr->description << "\n"
                     << printTaskPtr->dueDate << "\n";
                if (printTaskPtr->isCompleted)
                {
                    file << "Completed";
                }
                else
                {
                    file << "Still Pending";
                }

                file << "\n_______________________________\n";
                printTaskPtr = printTaskPtr->next;
            }
            file << "\nEnd Of List...";
            file.close();
        }
        else
        {
            std::cin.ignore();
            std::cout << "\nAn Error Occured\n";
            std::cout << "Press Enter To Return To Menu...";
            std::cin.get();
            clearScreen();
            return;
        }
        std::cin.ignore();
        std::cout << "\nTasks Saved.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
    }

    return;
}

void loadfromFILE(Task *head)
{
    std::ifstream file("to_do_list.txt");
    std::string line;
    clearScreen();
    std::cin.ignore();
    std::cout << "Loading From A File...\nPress Enter To View Your Tasks...";
    std::cin.get();
    clearScreen();
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }

        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();

        return;
    }
    else
    {
        std::cout << "File Not Found...";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        clearScreen();
        return;
    }

    file.close();
}