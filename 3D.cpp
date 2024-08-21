//-----------------------------------------------------------------------------
// @brief  �v���C���[�N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "3D.h"
#include"system.h"



//������
void Model::Init()
{
	// �R�c���f���̓ǂݍ���
	modelHandle = MV1LoadModel("data/ChickenModel/Chicken.mv1");

	//pos = VGet(0, 0, 0);
	MV1SetScale(modelHandle, VGet(17.0f, 17.0f, 17.0f));
	pos = VGet(960, 500, -750);
	ang = 0;
	num = 0;
	MV1SetRotationXYZ(modelHandle, VGet(0.0f,0, 0.0f));//���f���̉�]d
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
	size = 0;
	isSize = 0;
	isMove = 0;
}


//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Model::Update(System&system)
{
	

	MV1SetRotationXYZ(modelHandle, VGet(0.0f, ang * DX_PI_F / 180.0f, 0.0f));//���f���̉�]

	ang += 0.6;
	num++;
	
	

	if (size > 3.0f)
	{
		isSize = 1;
	}
	else if (size < 0.0f)
	{
		isSize = 0;
	}

	if (move > 5.0f)
	{
		isMove = 1;
	}
	else if (move < 0.0f)
	{
		isMove = 0;
	}

	MV1SetScale(modelHandle, VGet(17.0f, 17.0f, 17.0f));


	if (system.gamecount % 20 == 0 && system.gamecount != 0)
	{
		if (isSize == 0)
		{
			size+=0.5f;
		}
		else if (isSize == 1)
		{
			size-=0.5f;
		}

		MV1SetScale(modelHandle, VGet(17.0f+size, 17.0f + size, 17.0f + size));
	}
	else
	{
		if (isMove == 0)
		{
			move+=0.1f;
		}
		else if (isMove == 1)
		{
			move -= 0.1f;
		}
		pos = VGet(960 , 500 + move, -750);
	}

	MV1SetScale(modelHandle, VGet(17.0f, 17.0f, 17.0f));
	
}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void Model::Draw()
{
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
	
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);

}