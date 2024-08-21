//-----------------------------------------------------------------------------
// @brief  �v���C���[�N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "SkyDome.h"
#include"system.h"



//������
void Dome::Init()
{
// �R�c���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/ChickenModel/Dome_X501.pmx");

	//pos = VGet(0, 0, 0);
	pos = VGet(960, 520, -820);
	ang = 0;
	num = 0;
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, ang * DX_PI_F / 180.0f, 0.0f));//���f���̉�]
}


//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Dome::Update()
{
	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	
	/*
		// ��������Ă������ɐi��
	if (Key & PAD_INPUT_UP)
	{
		pos.z += 1;
	}
	// ���������Ă����牺�ɐi��
	if (Key & PAD_INPUT_DOWN)
	{
		pos.z -= 1;
	}
	

	

	// �E�������Ă�����E�ɐi��
	if (Key & PAD_INPUT_RIGHT)
	{
		pos.x += 1;
	}

	// ���������Ă����獶�ɐi��
	if (Key & PAD_INPUT_LEFT)
	{
		
	}
	
	pos.x -= 0.5;
	if (pos.x < 820)
	{
		pos.x = 1100;
	}
	
	*/

	MV1SetRotationXYZ(modelHandle, VGet(0.0f,ang * DX_PI_F / 180.0f, 0.0f));//���f���̉�]
	
	if (ang >= 360)
	{
		ang = 0;
	}
	ang+=0.1;
	
	
	

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void Dome::Draw()
{
	SetFontSize(100);
	//DrawFormatString(50, 50, GetColor(255, 255, 255), "X���W�F%f\nY���W�F%f\nZ���W�F%f",pos.x,pos.y, pos.z);
	SetFontSize(-1);
	//MV1SetScale(modelHandle, VGet(4.0f, 4.0f, 4.0f));
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
	SetUseLighting(TRUE);
	SetUseZBuffer3D(FALSE);
}