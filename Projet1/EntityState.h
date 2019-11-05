#pragma once
namespace GameView
{
	enum EntityFiniteState
	{
		State_Idle = 0,
		State_Jump = 1
	};

	class EntityState
	{

	public:
		EntityState() {};
		~EntityState() {};

		void onEnter() {}
		void onExit() {}
		void update() {};
	};

	class StateIdle : public EntityState
	{
	private :
		void onEnter();
		void onExit();

	public :
		StateIdle();
		~StateIdle();

	};

}