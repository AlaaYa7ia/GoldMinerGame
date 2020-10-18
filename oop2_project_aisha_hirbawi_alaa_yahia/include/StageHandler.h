#pragma once
#include "Board.h"
#include "TextDrawer.h"
#include "Window.h"
#include"ResourceManager.h"
#include <vector>
#include <functional>
#include <sstream>
#include <iomanip>
#include "Menu.h"

const int BASICGOAL = 900;
//pair of bar list menu
typedef std::pair<std::string, std::function<std::string(Window&)>> element;

const float LEVEL_Timer= 2.f;
const int WIN_LEVEL = 30;
const int TIME_LEVEL = 30;


class StageHandler
{
public:

	StageHandler();
	// ------- draw the bar on screen ----------------
	void barDrawer(Window& w);
	//------ set bigen of Results bar value ------
	inline void setBegin(float b) { s_begin = b; };

	// -------- set limit for the bar ----------------
	inline void setLimit(float min, float max) {s_min_limit = min;s_max_limit = max;};

	// --------- load new stage -------------
	void LoadNewStage(Roller** d, Board& b);

	// ------- intialize stage values ----------------
	void initializeStage(const Board& b);
	//-------- timer for the level-------
	inline Result timerCountDown(int score)
	{
		s_points = score;
		if (s_countdown.getElapsedTime().asSeconds() >= 1.f*1.8/s_stageNum) { --s_timer; s_countdown.restart(); }
		return(s_timer <= -1 && !GoalReached())? Result::TimeEnd: (s_timer<=-1)?Result::Win: Result::None;
	}
	//===== check if we reached goal =====
	inline bool GoalReached() const {
	return(s_points >= s_goal) ? true : false; }
	//------- check the results that returned--------
	void handleEvents(Window& window, Menu& mainMenu, Result r,
		Roller*& d, Board& b);
	//-------- function to print win/lost/time msg--------
	inline Window& msgprnt(Window& w, std::string msg, const bool& clear = true, sf::Color col=sf::Color::Green)
	{
		sMsg.setText(msg, w.getWidth() / 2.f,
			w.getHeight() / 2.f, 70, col);
		sMsg.centerText();
		if (clear)//if we can to disply msg in balck screen or on the game background
			w.clear();
		sMsg.draw(w);
		w.display();
		return w;
	}

private:
	sf::Clock s_countdown;
	int s_points = 0, s_stageNum, s_goal;

	float s_min_limit, s_max_limit, s_begin, s_timer;
	sf::Sound NXTLvl;

	//------ return stage number ------
	inline void setStage(int s) { s_stageNum = s; s_goal = BASICGOAL* s; };
	//------ set timer for stage ------
	inline void setTimer() { s_timer =  WIN_LEVEL; };
	//--------reset the points for new lvl--------
	inline void resetPoints() { s_points = 0; }

	TextDrawer s_bar;
	TextDrawer sMsg;
	std::vector<element> barList;

	//------ initialize results bar ------
	void initializeBar();

	//------ add text to the bar ------
	inline void add(std::string t, std::function<std::string(Window&)> f)
	{
		barList.push_back(std::pair(t, f));
	}
	//------ casting integer to string ------
	inline std::string toString(int i)
	{
		std::ostringstream os;
		os << i;
		return os.str();
	};

};
// ----- output operator to print on screen -------------- 
inline Window& operator<<(Window& w, StageHandler& s) { s.barDrawer(w); return w; }