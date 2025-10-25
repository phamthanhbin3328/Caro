#ifndef ISCREEN_H
#define ISCREEN_H

enum ScreenID
{
	NONE = 0
	, SINGLEPLAY
	, MUTIPLAY
};

class IScreen
{
	public:
		virtual void show() = 0;
	protected:
		ScreenID m_enmScreenID;
};

#endif