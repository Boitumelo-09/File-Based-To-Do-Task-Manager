/*
🔧 Features You’ll Implement:

Delete Task
Find by ID and unlink + delete node.
Search Task by Keyword
Use substring matching in title/description.
Sort Tasks by Due Date (BONUS)
Reorder linked list based on string dates (lexicographically).
Save and Load from File (SUPER BONUS)
Save all tasks to a .txt or .csv file on exit.
Load them when program starts. 
*/

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
//Operations || Features
void greetUser();
void userTerminal(int &option);
void freememory(Task *&head);
void addTask(Task *&head, int &id);
void viewAllTasks(Task *head);
void markTasks(Task *&head);
void editTask(Task *&head);
void deleteTask(Task *&head);
void searchTask(Task*&head);

int main()
{
    srand(time(NULL));
    Task *head = nullptr;
    int menuOption;
    int id = (rand() % 1000) + 1050;
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
            markTasks(head);
            break;
        case 4:
            editTask(head);
            break;
        case 5:
            /* code */
            break;
        case 6:
            searchTask(head);
            break;
        case 7:
            freememory(head);
            return 0;
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
    std::cout << "Hello, Welcome To The Task Manager App\nFollow Prompts\nThe Title Of The ID Should Be One Word\n\n" << std::endl;
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

    std::cout << "\nTitle(One-Word) :";
    std::cin>>newTask->title;
    std::cin.ignore();
    std::cout << "\nDescription     :";
    getline(std::cin, newTask->description);

    std::cout << "\nDue Date        :";
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
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        system("cls");
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
void markTasks(Task *&head){
    int markOption;
    std::string taskTitle;
    Task *currentTask = head;
    system("cls");
    std::cout<<"Marking Task...\n\n";
    std::cout<<"Task Title:";
    std::cin.ignore();
       getline(std::cin,taskTitle);
    
       if(head==nullptr){
           std::cout << "\n\nTask Not Found...";
           std::cout << "\nPress Enter To Return To Main Menu...";
           std::cin.get();
           system("cls");
       }
       else
     {
         system("cls");
         for (; currentTask != nullptr; currentTask = currentTask->next)
         {
             if (currentTask->title == taskTitle)
             {
                 std::cout << "Task Found...\nDetails:";
                 std::cout << "\nTask ID      : " << currentTask->id;
                 std::cout << "\nTitle        : " << currentTask->title;
                 break;
             }
        
      }
      std::cout << "\n...................................................\n";
      std::cout << "\n\nOptions:\n1. Completed\n2. Still Pending\nChoice:";
      std::cin >> markOption;
      if (markOption==1)
      {
          std::cin.ignore();
          currentTask->isCompleted = true;
          system("cls");
          std::cout << "Task Update...\n\n";
          std::cout << "Details:";
          std::cout << "\nTask ID      : " << currentTask->id;
          std::cout << "\nTitle        : " << currentTask->title;
          std::cout << "\nDescription  : " << currentTask->description;
          std::cout << "\nStatus       : " << (currentTask->isCompleted ? "Completed" : "Pending");
          std::cout << "\n\nPress Enter To Continue...";
          std::cin.get();
          system("cls");
      }else
      {
          system("cls");
          std::cin.ignore();
          currentTask->isCompleted = false;
          std::cout << "\nTask ID      : " << currentTask->id;
          std::cout << "\nTitle        : " << currentTask->title;
          std::cout << "\nDescription  : " << currentTask->description;
          std::cout << "\nStatus       : " << (currentTask->isCompleted ? "Completed" : "Still Pending");
          std::cout << "Press Enter To Continue...";
          std::cin.get();
          system("cls");
      }
      }
       
    
}
void editTask(Task *&head){
    system("cls");
    bool isFound=false;
    Task *tempTask = head;
    std::string taskTitle;
    std::cout << "Editing Task...\nTask Title : ";
    std::cin >> taskTitle;
    if (tempTask == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        system("cls");
        return;
    }
    else{
        std::cin.ignore();
         std::string newTitle , newDescription;
        for (; tempTask != nullptr;tempTask=tempTask->next){
            if (taskTitle == tempTask->title)
            {
                isFound == true;
                int updateOption;
                std::cout << "Task Found...\nPress Enter To Contiue To Make Changes...\n";
                std::cin.get();
                system("cls");
                std::cout << "Making Updates...\nOptions\n1. Update Title\n2. Update Description\n3. Update Status\nOption:";
                std::cin >> updateOption;
                switch (updateOption)
                {
                case 1:
                    system("cls");
                    std::cout << "Updating Title...\n";
                    std::cout << "Current Title :" << tempTask->title;
                    std::cout << "\nNew Title     :";
                    std::cin >> newTitle;
                    tempTask->title = newTitle;
                    std::cin.ignore();
                    std::cout << "\nTask Title Has Been Successfully Updated";
                    std::cout << "\nPress Enter To Return To Menu...";
                    std::cin.get();
                    system("cls");
                    return;
                    break;
                case 2:
                    system("cls");
                    
                    std::cout << "Updating Description...\n";
                    std::cout << "Current Description :" << tempTask->description;
                    std::cin.ignore();
                    std::cout << "\nNew Description   :";
                    getline(std::cin,newDescription);
                    tempTask->description= newDescription;
                   
                    std::cout << "\nTask Description Has Been Successfully Updated";
                    std::cout << "\nPress Enter To Return To Menu...";
                    std::cin.get();
                    system("cls");
                    return;
                    break;
                default:
                 std::cin.ignore();
                 std::cout<<"Invalid Response\nPress Enter To Exit App...";
                 std::cin.get();
                    freememory(head);
                    break;
                }
            }
        }
          if(!isFound){
                system("cls");
                std::cout << "Task Not Found...\n";
                std::cout << "Press Enter To Return To Menu...";
                std::cin.get();
                system("cls");
                return;
          }
    }
}
void freememory(Task *&head){
   system("cls");
    Task* freeTask = head;
    if(head == nullptr){
        free(head);
    }
    else
   { 
    while(freeTask!=nullptr){

        freeTask = freeTask->next;
        free(freeTask);
    }
}
     std::cout << "Freeing Memory & Exiting App...\nGood Bye!!!\n";

    return;
}
void deleteTask(Task *&head){
    system("cls");
    std::string deleteEntry;
    Task *searchPtr = head;
    int counter = 1;
    if (head == nullptr)
    {
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
         system("cls");
        return;
    }
    else{
        std::cout<<"Enter Task Title : ";
         std::cin >> deleteEntry;
         

        
    }
}
void searchTask(Task*&head){
    system("cls");
    Task *tempTask = head;
    bool taskFound = false;
    std::string searchEntry;
    if (tempTask == nullptr)
    {
        
        std::cin.ignore();
        std::cout << "\nNo tasks available.\n";
        std::cout << "Press Enter To Return To Menu...";
        std::cin.get();
        system("cls");
        return;
    }
    else{

        std::cin.ignore();
        std::cout << "\nYou Are Going To Search By Title.\n";
        std::cout << "Press Enter To Search...";
        std::cin.get();
        system("cls");
         std::cout << "Search : ";
         std::cin >> searchEntry;
         for (; tempTask != nullptr; tempTask = tempTask->next)
         {
            
            if (tempTask->title == searchEntry)
            {
                taskFound = true;
                break;
            }
            
         }
         if (taskFound)
         {
             
             std::cout << "Task Found.\nPress Enter To See Details...";
             std::cin.ignore();
             std::cin.get();
             system("cls");
             std::cout << "\nTask ID      : " << tempTask->id;
             std::cout << "\nTitle        : " << tempTask->title;
             std::cout << "\nDescription  : " << tempTask->description;
             std::cout << "\nDue Date     : " << tempTask->dueDate;
             std::cout << "\nStatus       : " << (tempTask->isCompleted ? "Completed" : "Pending");
             std::cout << "\n-----------------------------------\n";
             std::cout << "\nPress Enter To Return To Main...";
             std::cin.get();
             system("cls");
             return;
         }
         else if(!taskFound){
            std::cin.ignore();
            std::cout << "Task Not Found.\nPress Enter To Return To Main...";
            std::cin.get();
            system("cls");
            return;
         }
         
    }
   
};