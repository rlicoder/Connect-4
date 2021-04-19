#include <bits/stdc++.h>
#include "GameHist.h"

using namespace std;
/* GameHist function definition
 * ----------------------------------------------------
 * This function will store the moves history and both
 * players' names when it receives this info.
 */
GameHist::GameHist(string po_name, string px_name, string moveHist)
{
	this->moves = moveHist;  // Store moves history
	this->playerO = po_name; // Store player O name
	this->playerX = px_name; // Store player X name
}
