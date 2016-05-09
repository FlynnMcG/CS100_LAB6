#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
		};
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if(initialized())
			{
				cout<<history.at(history_index)->execute();
			}
			else
				cout<<'0';
		};
		bool initialized() {
			if(history.size()!=0)
			{
				return true;
			}
			else
				return false;
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
		};
		void add_command(Command* cmd) {
			history.push_back(cmd);
			history_index++;
			//Adds a command to history in the appropriate posiiton (based on history_index)
		};
		Command* get_command() {
			if(initialized())
			{
				return history.at(history_index);
			}
			//Returns the command in history we are currently referring to (based on history_index)
		};
		void undo() {
			if(history_index!=0)
			{
				history_index--;
			}
			//Moves to the last command in history (if possible)
		};
		void redo() {
			if(history_index!=history.size()-1)
			{	
				history_index++;
			}
			//Moves to the next command in history (if possible)
		};
};

#endif //__MENU_CLASS__
