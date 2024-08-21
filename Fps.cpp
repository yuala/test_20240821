#include <math.h>
#include "DxLib.h"
#include "Fps.h"

//������
void Fps::Initialize() {
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}
//FPS����
bool Fps::Update() {
    if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
        mStartTime = GetNowCount();
    }
    if (mCount == N) { //30�t���[���ڂȂ畽�ς��v�Z����
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}
//FPS�\��
void Fps::Draw()
{
    SetFontSize(20);
    DrawFormatString(1830, 10, GetColor(255, 255, 255), "FPS:%.0f", mFps);
    SetFontSize(-1);
}
void Fps::Wait() {
    int tookTime = GetNowCount() - mStartTime;  //������������
    int waitTime = mCount * 1000 / FPS - tookTime;  //�҂ׂ�����
    if (waitTime > 0) {
        Sleep(waitTime);  //�ҋ@
    }
}