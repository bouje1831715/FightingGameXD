#include "levelLoader.h"
#include <fstream>
#include <iostream>


LevelLoader::LevelLoader()
{
}


LevelLoader::~LevelLoader()
{
}

vector<vector<vector<TileIdentity>>> LevelLoader::LoadFromFile(string path)
{

	ifstream content(path);
	int startIndex = -1;
	int width = 0;
	int height = 0;
	int i = 0;
	string line;
	while (getline(content, line))
	{
		int lineWidth = size(Split(line, '|')) - 1;
		if (lineWidth > width)
			width = lineWidth;
		if (line.at(0) == '|')
		{
			height++;
			if (startIndex == -1)
				startIndex = i;
		}
		i++;
	}



	vector<vector<TileIdentity>> backTI(width, vector<TileIdentity>(height));  // vector<vector<TileIdentity>>(width, vector<TileIdentity>(height));
	vector<vector<TileIdentity>> defaultTI(width, vector<TileIdentity>(height)); //= vector<vector<TileIdentity>>(width, vector<TileIdentity>(height));
	vector<vector<TileIdentity>> frontTI(width, vector<TileIdentity>(height)); //= vector<vector<TileIdentity>>(width, vector<TileIdentity>(height));

	content = ifstream(path);

	tileTilesesNames.clear();

	i = 0;
	while (getline(content, line))
	{
		if (line[0] == '>')
		{
			vector<string> splittedLine = Split(line, '-');
			int key = stoi(Split(splittedLine[0], '>')[1]);
			string value = splittedLine[1];
			tileTilesesNames.insert(make_pair(key, value));
		}
		else if (line[0] == '|')
		{
			vector<string> splittedLine = Split(line.substr(1), '|');
			for (unsigned int j = 0; j < size(splittedLine); j++)
			{

				vector<string> splittedTilesInfo = Split(splittedLine[j], '+');
				vector<string> animationSplit = Split(splittedTilesInfo[0], '>');

				TileIdentity newTI = { };

				if (size(animationSplit) > 1)
				{
					newTI = GetAnimatedTileInfo(splittedTilesInfo[0]);
				}
				else
				{
					vector<string> splittedTileInfo = Split(animationSplit[0], ':');
					newTI = { tileTilesesNames[0], { stoi(splittedTileInfo[1]) },{ stoi(splittedTileInfo[2]) } };
				}

				if (size(splittedTilesInfo) > 1)
				{
					backTI[j][i - startIndex] = newTI;

					animationSplit = Split(splittedTilesInfo[1], '>');
					if (size(animationSplit) > 1)
					{

						newTI = GetAnimatedTileInfo(splittedTilesInfo[1]);
					}
					else
					{
						vector<string> splittedTileInfo = Split(animationSplit[0], ':');
						newTI.Tileset = tileTilesesNames[stoi(splittedTileInfo[0])];
						newTI.IndexesX = { stoi(splittedTileInfo[1]) };
						newTI.IndexesY = { stoi(splittedTileInfo[2]) };
					}
				}
				else
				{
					backTI[j][i - startIndex] = { "NA", { 0 }, { 0 }, {} };
				}

				defaultTI[j][i - startIndex] = newTI;

				if (size(splittedTilesInfo) == 3)
				{
					animationSplit = Split(splittedTilesInfo[2], '>');
					if (size(animationSplit) > 1)
					{
						newTI = GetAnimatedTileInfo(splittedTilesInfo[2]);
					}
					else
					{
						vector<string> splittedTileInfo = Split(animationSplit[0], ':');
						newTI.Tileset = tileTilesesNames[stoi(splittedTileInfo[0])];
						newTI.IndexesX = { stoi(splittedTileInfo[1]) };
						newTI.IndexesY = { stoi(splittedTileInfo[2]) };
					}
					frontTI[j][i - startIndex] = newTI;
				}
				else
				{
					frontTI[j][i - startIndex] = { };
				}
			}
		}
		i++;
	}
	vector<vector<vector<TileIdentity>>> toReturn(3, vector<vector<TileIdentity>>());
	toReturn[0] = backTI;
	toReturn[1] = defaultTI;
	toReturn[2] = frontTI;

	return toReturn;
}

TileIdentity LevelLoader::GetAnimatedTileInfo(string data)
{
	TileIdentity ti;
	ti.IndexesX = vector<int>();
	ti.IndexesY = vector<int>();
	ti.ShowTimesMS = vector<int>();

	vector<string> splittedData = Split(data, '>');

	for (unsigned int i = 0; i < size(splittedData) / 2; i++)
	{
		vector<string> splittedTileInfo = Split(splittedData[i * 2], ':');
		if (size(splittedTileInfo) == 3)
		{
			ti.Tileset = tileTilesesNames[stoi(splittedTileInfo[0])];
			ti.IndexesX.push_back(stoi(splittedTileInfo[1]));
			ti.IndexesY.push_back(stoi(splittedTileInfo[2]));
		}
		else
		{
			ti.IndexesX.push_back(stoi(splittedTileInfo[0]));
			ti.IndexesY.push_back(stoi(splittedTileInfo[1]));
		}
		ti.ShowTimesMS.push_back(stoi(splittedData[i * 2 + 1]));

	}

	return ti;
}

vector<string> LevelLoader::Split(string s, char delim) {
	vector<string> elems;
	string current = "";
	for (char& c : s)
	{
		if (c != delim)
		{
			current += c;
		}
		else
		{
			elems.push_back(current);
			current = "";
		}
	}
	elems.push_back(current);
	return elems;
}


