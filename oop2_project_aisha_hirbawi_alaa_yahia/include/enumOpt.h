#pragma once
//---------------------change
const int MSGTIME = 1900;

const int Options_size = 8;

enum class Result {
	None,
	TimeEnd,
	Win,
	Lose
};

//every char represens diffrent object
enum class ObjectType_t
{
	ANIMAL = '@',
	TNT = '*',
	DIAMOND = 'D',
	GIFT = '$',
	S_GOLD = 'S',
	M_GOLD = 'M',
	L_GOLD ='L',
	GOLD_MINER = '&',
	ROLLER = '!',
	S_STONE = '-',
	M_STONE = '_',
	WALL_T = '#', 
	Empty_T = ' ',
	
};
