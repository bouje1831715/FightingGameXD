#include "Action.h"
#include "Entity.h"

Action::Action(Entity* e)
{
	parent = e;
}

Action::~Action()
{

}


int Action::Update()
{
	return -1;
}
