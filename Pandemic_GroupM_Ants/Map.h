#pragma once

#include "CommonLibrary.h"

//City Node Class //////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CityNode
{
	//Attributes//////////////////////////////
	string name;
	InfectType area;
	int infectionLevel[NUM_OF_DISEASES];
	vector<CityNode*> connections;
	bool researchStation;

public:
	//Constructors////////////////////////////
	CityNode();
	CityNode(string name, InfectType area, bool researchStation = false);
	~CityNode();

	//Get and Set////////////////////////////
	string getName();
	
	InfectType getArea();

	int getInfectionLevel(InfectType infection);
	void increaseInfectionLevel(InfectType infection);
	
	bool hasResearchStation();
	void addResearchStation();
	
	vector<CityNode*> getConnections();
	void addConnection(CityNode* city);
};

//GAME MAP CLASS///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class GameMap
{
	//Attributes/////////////////////////////////////
	CityNode* head;
	vector<CityNode*> cityList;

public:
	//Constructors///////////////////////////////////
	GameMap();
	GameMap(string filename);
	~GameMap();

	//Get and Set////////////////////////////////////
	CityNode* getHead();

	CityNode* getCity(string name);

private:
	//Helper Functions///////////////////////////////
	void loadStartingMap(string filename);
};
