#ifndef TASK_H
#define TASK_H
#include<string>
#include<iostream>
using namespace std;

class Task
{
public:
	int id;
	int priority;
	string description;
	Task() : id(0), priority(0), description("")
	{}

	Task(int id, int priority, string description)
	{
		this->id = id;
		this->priority = priority;
		this->description = description;
	}
};

#endif // !TASK_H
