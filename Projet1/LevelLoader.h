#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

struct TileIdentity 
{
public:
	string Tileset;
	vector<int> IndexesX;
	vector<int> IndexesY;
	vector<int> ShowTimesMS;
};

class LevelLoader
{
public:
	LevelLoader();
	~LevelLoader();

	vector<vector<vector<TileIdentity>>> LoadFromFile(string path);


private:
	vector<string> Split(string s, char delim);
	TileIdentity GetAnimatedTileInfo(string data);
	map<const int, const string> tileTilesesNames;
};

