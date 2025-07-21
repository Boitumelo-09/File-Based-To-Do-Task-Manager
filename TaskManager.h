#pragma once


#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>

#ifdef _WIN32
#define wipeScreen "cls"
#else
#define wipeScreen "clear"
#endif

struct Task {
    int id;
    std::string title;
    std::string description;
    std::string dueDate;
    bool isCompleted;
    Task* next;

    Task();
    Task(int id, std::string title, std::string description, std::string dueDate, bool isCompleted, Task* next);
};

void clearScreen();
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

#endif

