#pragma once

class Fps
{
public:
	int mStartTime;      //����J�n����
	int mCount;          //�J�E���^
	float mFps;          //fps
	const int N = 60;  //���ς����T���v����
	const int FPS = 60;  //�ݒ肵��FPS

	void Initialize();
	bool Update();
	void Draw();
	void Wait();
};
