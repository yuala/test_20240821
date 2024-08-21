#include"DxLib.h"
#include"system.h"
#include"Enemy.h"
#include"Player.h"
#include"SkyDome.h"
#include"3D.h"

System::System()
{
	CrWhite = GetColor(250, 250, 250);
	CrBlack = GetColor(5, 5, 5);
	timeframeGraph = LoadGraph("data/texture/fukidasi.png");
	
}

void System::InitScreen()
{
    screenH = SCREEN_H;
    screenW = SCREEN_W;

}

void System::InitTime(bool&gameover)
{
    gametime = GetNowCount();
    isClear = false;
	gameover = false;
	timeframeGraph = LoadGraph("data/texture/fukidasi_1.png");
	timer = LoadGraph("data/texture/time2.png");
}


void System::DrawTime()
{
	ChangeFont("Ubuntu-Title");
	scoreGraph = LoadGraph("data/texture/score.png");
    gamecount = ((GetNowCount() - gametime)/1000);
    

	//����_�Q�[�W�`��
	DrawBox(800, 35, 1900, 125, GetColor(130,130,130), TRUE);
	DrawBox(810, 40, 1890, 120, CrBlack, TRUE);
	DrawBox(810, 40, 810+gamecount*12.0f, 120, GetColor(50,230,80), TRUE);

	//���v�`��
	SetFontSize(80);
	DrawBox(700, 30, 800, 130, GetColor(130, 130, 130), TRUE);
	DrawBox(705, 35, 795, 125, CrBlack, TRUE);
	DrawGraph(710, 40, timer, TRUE);

	//����_�����`��
    DrawFormatString(1200, 40, CrWhite, "%d", gamecount);
	DrawFormatString(1280, 40, CrWhite, "/90");

	//�X�R�A�`��
	SetFontSize(70);
	DrawFormatString(40, 35, CrWhite, "�x�X�g�X�R�A�F%d\n�X�R�A�F%d",best*250, gamecount*250);
	DrawGraph(40, 105, scoreGraph, TRUE);

	ChangeFont("�قɂ᎚Re");
	//�o�ߎ��ԕ`��
    if (gamecount % 20 == 0&&gamecount!=0)
    {
		if (gamecount % 20 == 0 && gamecount != 0)
		{
			tmptime = gamecount;
		}
		
           
		DrawGraph(680, 150, timeframeGraph, TRUE);
		
        SetFontSize(90);
        DrawFormatString(780, 210, CrBlack, "%d�b�o��!!",tmptime);
    }
    if (gamecount > 90)
    {
        isClear = true;
    }
    SetFontSize(-1);

}




void System::DrawResult(bool& title,bool&gameover,Model&model,Dome&dome)
{
	System system;
	//resultframeGraph = LoadGraph("data/texture/fukidasi_3.png");
    if (isClear == true||gameover==true)
    {
		
		int selectFrame = 100;
		int i = 0;
	

		while (1)
		{
			ClearDrawScreen();
			i++;

			if (i == 10)
			{
				selectFrame -= 1;
			}
			else if (i > 10)
			{
				i = 0;
			}

			if (selectFrame < 0)
			{
				selectFrame = 100;
			}


			
			dome.Update();
			dome.Draw();
			SetFontSize(100);
			
			int num = gamecount;
			if (best < num)
			{
				best = num;
			}

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			//DrawBox(500, 320, 1420, 800, GetColor(112, 76, 56), TRUE);
			//DrawBox(520, 340, 1400, 780, GetColor(226, 214, 207), TRUE);
			//DrawGraph(500, 320, resultframeGraph, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			

			SetFontSize(120);
			DrawFormatString(750, 170, CrWhite, "���U���g", TRUE);
			SetFontSize(95);

			if (gameover == true)
			{
				DrawFormatString(550, 400, GetColor(180, 15, 15), "�Q�[���I�[�o�[�I�I", TRUE);
				
			}
			else
			{
				DrawFormatString(750, 400, GetColor(180, 15, 15), "�N���A�I�I", TRUE);
				
				
			}
			SetFontSize(90);
			DrawFormatString(550, 580, CrBlack, "�x�X�g�X�R�A�F%d", best * 250, TRUE);
			DrawFormatString(795, 660, CrBlack, "�X�R�A�F%d", gamecount*250, TRUE);
			SetFontSize(-1);


			if ((selectFrame / 10) % 2 != 0)
			{

				SetFontSize(25);
				DrawFormatString(800, 900, CrWhite, "�G���^�[�L�[�������Ă�������" ,TRUE);
				SetFontSize(-1);
				
			}
			


			ScreenFlip();

			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				title = true;
				isReturn = false;
				
			}
			else if (title == true && isReturn == false)
			{
				isReturn = true;
				ClearDrawScreen();
				break;
			}
			else if (ProcessMessage() < 0)
			{
				DxLib_End();
				return ;
				// �\�t�g�̏I��
			}
			// �����d�r�b�L�[��������Ă����烋�[�v���甲����
			else if (CheckHitKey(KEY_INPUT_ESCAPE))
			{
				DxLib_End();
				return;
				// �\�t�g�̏I��
			}

		}

    }
}