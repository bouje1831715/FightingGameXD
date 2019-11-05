#pragma once
#include <vector>

using namespace std;

namespace GameView
{
	class Utils {
	public :
		static vector<string> Split(string s, char delim);
		static string readFromFile(const string& fileName);
	};
	

}