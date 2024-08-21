#include"DxLib.h"
#include"Title.h"
#include"Fps.h"
#include"Player.h"
#include"Enemy.h"
#include"SkyDome.h"
#include"3D.h"
#include"system.h"
#include"map.h"

void Title::Draw(bool& drawtitle, bool& gameover, System& system, Map& map, Player& player, Fps& fps, Enemy& enemy, Model& model,Dome&dome,int &gametime,int &countdown,bool& isC)
{
	if (drawtitle == true && system.isReturn == true)
		{
		int selectFrame = 100;
		int i = 0;
		mainsound = LoadSoundMem("data/sound/main1.mp3");
		sound = LoadSoundMem("data/sound/title1.mp3");
		InitMap(map);//�}�b�v�̏�����
		player.Initialize();	//�v���C���[������
		enemy.Initialize();		//�G�l�~�[������
		dome.Init();
		model.Init();//3d���f���̏�����

		gametime = GetNowCount();
		countdown = ((GetNowCount() - gametime) / 1000);
		isC = true;
		bool checkreturn = 0;
 




		
		if (CheckSoundMem(sound) == 0)
		{
			
			PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
		}
		
		while (1)
		{
			


			if (checkreturn == 1)
			{

				//ClearDrawScreen();                   // ����ʂ̃f�[�^��S�č폜

				//if (c >= 0 && c < 256)                    //c��0~256�̎�
					//SetDrawBright(c, c, c);        //�i�X�����邭(c= 0->255)
				//if (c >= 256 && c < 400)                  //c��256~400�̎�
					//SetDrawBright(255, 255, 255);  //�ʏ�̖��邳
				//if (c >= 400 && c < 400 + 256)              //c��400~400+256�̎�
				SetDrawBright(255 - c, 255 - c, 255 - c);//�i�X�Â�(c= 255->0)

				DrawBox(0, 0, 1920, 1080, GetColor(255, 255, 255), FALSE);  //��ʑS�̂ɔ����l�p�`��`��

				c += 5;;                                  //c���J�E���g�A�b�v

				if (c > 256)
				{
					drawtitle = false;
					player.Initialize();	// �v���C���[������
					//enemy.Initialize();		//�G�l�~�[������
					system.InitTime(gameover);//system�̏�����
					model.Init();//3d���f���̏�����


					if (CheckSoundMem(sound) == 1)
					{
						StopSoundMem(sound);
						PlaySoundMem(mainsound, DX_PLAYTYPE_LOOP);
					}
					break;                 //�Â��Ȃ�I�������I��
				}
				ScreenFlip();
			}
			
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
	
	
			ClearDrawScreen();
	
			fps.Update();
			fps.Wait();
			
			dome.Update();
			//model.Update(system);
			player.UpdateTitle();	// �v���C���[���X�V����
			
			dome.Draw();
			model.Draw();
			DrawMap(map);
			
			



			SetFontSize(100);
			DrawFormatString(580, 170, GetColor(200, 30, 30), "�ǂ炲����ȁ[", TRUE);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawBox(500, 320, 1420, 800, GetColor(112, 76, 56), TRUE);
			DrawBox(520, 340, 1400, 780, GetColor(226, 214, 207), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
			SetFontSize(60);
			DrawFormatString(550, 360, GetColor(0, 0, 0), "[���[������]\n\n�W�����v�F�X�y�[�X�L�[\n�������ԁF90�b", TRUE);
			SetFontSize(40);
			DrawFormatString(560, 500, GetColor(0, 0, 0), "\n\n\n��ʂ̉E����P���|����O���[���h���S����\n�W�����v�Ŕ����č��X�R�A�l����ڎw����");
			
			player.Drawtitle();	// �v���C���[��`�悷��
			
			DrawGraph(0, 200, graph, TRUE);
			if ((selectFrame / 5) % 2 == 0)
			{
				SetFontSize(25);
				DrawFormatString(790, 860, GetColor(255, 255, 255), "�G���^�[�L�[�������Ă�������", TRUE);
			}
			SetFontSize(-1);
	
	
			
			
	
	
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				checkreturn = 1;


				
			}
			else if (ProcessMessage() < 0)
			{
				DxLib_End();
				return;
				
			}
			// �����d�r�b�L�[��������Ă����烋�[�v���甲����
			else if (CheckHitKey(KEY_INPUT_ESCAPE))
			{
				DxLib_End();
				return;
				

			}


			ScreenFlip();

	
		}
		
	
	}
}