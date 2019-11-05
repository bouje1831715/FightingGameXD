#include "Monk.h"
#include "Animation.h"
#include "PlayerStanding.h"
#include "HeroActionsEnum.h"

Monk::Monk() : Hero("Monk", 50, 10, 30)
{
	AddAnimations();
	CurrentAction = PlayerStanding();
}

Monk::~Monk()
{
}

void Monk::ChangeAction(int enumIndex)
{
	switch ((PlayerAction)enumIndex)
	{
	case STAND:
		break;
	case WALK:
		animator.ChangeAnimation("Walk");
		break;
	case CROUNCH:
		break;
	case JUMP:
		break;
	case FALL:
		break;
	}
}

void Monk::AddAnimations()
{
	sf::Texture* texture = new Texture();
	texture->loadFromFile("Image/monk.png");
	int nbRows = 4;
	int nbColums = 10;
	Tileset ts = { texture, nbRows, nbColums};

	vector<Coord> indexes;
	vector<int> showTimes;

	indexes.push_back({ 0, 0 });
	showTimes.push_back(250);

	indexes.push_back({ 1, 0 });
	showTimes.push_back(250);

	indexes.push_back({ 2, 0 });
	showTimes.push_back(250);

	indexes.push_back({ 3, 0 });
	showTimes.push_back(250);

	animator.AddAnimation(new Animation(ts, indexes, showTimes), "Stand");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 4, 0 });
	showTimes.push_back(200);

	indexes.push_back({ 5, 0 });
	showTimes.push_back(100);

	indexes.push_back({ 6, 0 });
	showTimes.push_back(100);

	indexes.push_back({ 7, 0 });
	showTimes.push_back(75);

	indexes.push_back({ 8, 0 });
	showTimes.push_back(50);

	indexes.push_back({ 9, 0 });
	showTimes.push_back(50);

	animator.AddAnimation(new Animation(ts, indexes, showTimes, false), "Punch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 1 });
	showTimes.push_back(100);

	indexes.push_back({ 1, 1 });
	showTimes.push_back(100);

	indexes.push_back({ 2, 1 });
	showTimes.push_back(150);

	indexes.push_back({ 3, 1 });
	showTimes.push_back(100);

	indexes.push_back({ 4, 1 });
	showTimes.push_back(100);

	indexes.push_back({ 5, 1 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes), "Walk");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 6, 1 });
	showTimes.push_back(150);

	indexes.push_back({ 7, 1 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes), "Jump");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 8, 1 });
	showTimes.push_back(100);

	indexes.push_back({ 9, 1 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(ts, indexes, showTimes), "Fall");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 2 });
	showTimes.push_back(100);

	indexes.push_back({ 1, 2 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(ts, indexes, showTimes, false), "Flying kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 2, 2 });
	showTimes.push_back(150);

	indexes.push_back({ 3, 2 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes, false), "Crounch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 4, 2 });
	showTimes.push_back(150);

	indexes.push_back({ 5, 2 });
	showTimes.push_back(150);

	indexes.push_back({ 6, 2 });
	showTimes.push_back(150);

	indexes.push_back({ 7, 2 });
	showTimes.push_back(150);

	indexes.push_back({ 8, 2 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes, false), "Low kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 3 });
	showTimes.push_back(150);

	indexes.push_back({ 1, 3 });
	showTimes.push_back(150);

	indexes.push_back({ 2, 3 });
	showTimes.push_back(150);

	indexes.push_back({ 3, 3 });
	showTimes.push_back(150);

	indexes.push_back({ 4, 3 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes, false), "Roundhouse kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 3 });
	showTimes.push_back(150);

	indexes.push_back({ 6, 3 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(ts, indexes, showTimes), "Hurt");
}
