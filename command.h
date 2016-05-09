#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
		OpCommand(int cmd) {
			root = new Op(cmd);
		};
};

class AddCommand : public Command {
	//AddCommand Code Here
    public:
        AddCommand(Command * last_cmd, int cmd) {
            root = new Add(last_cmd->get_root(), new Op(cmd));
        };
};

class SubCommand : public Command {
	//SubCommand Code Here
    public:
        SubCommand(Command * last_cmd, int cmd) {
            root = new Sub(last_cmd->get_root(), new Op(cmd));
        };
};

class MultCommand : public Command {
	//MultCommand Code Here
    public:
        MultCommand(Command * last_cmd, int cmd) {
           root = new Mult(last_cmd->get_root(), new Op(cmd));
        };
};

class SqrCommand : public Command {
	//SqrCommand Code Here
    public:
        SqrCommand(Command * last_cmd) {
            root = new Sqr(last_cmd->get_root());
        };
};

#endif //__COMMAND_CLASS__
