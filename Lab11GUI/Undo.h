#pragma once

#include "Coat.h"
#include "Repository.h"

/*
Generic class for an undo action.
For each type of action (add, delete, update), a new class will be created, inheriting from this UndoAction.
*/

class UndoAction {
public:
	virtual void executeUndo() = 0;
	virtual ~UndoAction() {};

};

class UndoAdd : public UndoAction
{
private:
	Coat addedCoat;
	Repository& repo; // we keep a reference to the repository to be able to undo the action

public:
	UndoAdd(Repository& _repo,Coat& s): repo{ _repo },addedCoat { s } {}
	/*
	For the add operation, the reverse operation that must be executed is "remove".
	*/
	void executeUndo() override
	{
		this->repo.delete_coat(addedCoat.get_size(), addedCoat.get_colour());
	}
};

class UndoRemove : public UndoAction
{
private:
	Coat deletedCoat;
	Repository& repo;

public:
	UndoRemove(Repository& _repo,const Coat& s): repo{_repo}, deletedCoat{ s } {}

	void executeUndo() override
	{
		this->repo.add_coat(deletedCoat);
	}
};

class UndoUpdate : public UndoAction
{
private:
	Coat newCoat;
	Coat updatedCoat;
	Repository& repo;

public:
	UndoUpdate(Repository& _repo, const Coat& s,const Coat& s2) : repo{ _repo }, updatedCoat{ s }, newCoat{ s2 } {}

	void executeUndo() override
	{
		this->repo.update_coat(newCoat.get_size(), newCoat.get_colour(), updatedCoat);
	}
};