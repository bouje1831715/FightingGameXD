#pragma once
class Entity;

class Action
{
public:
	Action(Entity* e);
	~Action();
	virtual int Update();
protected:
	Entity* parent;
};

