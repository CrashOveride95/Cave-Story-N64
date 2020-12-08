#include "npcxxx.h"
#include "game.h"
#include "mychar.h"
#include "map.h"
#include "draw.h"
#include "sound.h"

//NPC 060 - Toroko
#include "data/bitmap/npc_toroko.inc.c"

void Npc060_Act(NPCHAR *npc)
{
	//Move and animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			npc->xm = 0;
			//Fallthrough
		case 1:
			if (Random(0, 120) == 10)
			{
				npc->act_no = 2;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			
			if (npc->x - (16 * 0x200) < gMC.x && npc->x + (16 * 0x200) > gMC.x && npc->y - (16 * 0x200) < gMC.y && npc->y + (16 * 0x200) > gMC.y)
			{
				if (npc->x > gMC.x)
					npc->direct = 0;
				else
					npc->direct = 2;
			}
			break;
			
		case 2:
			if (++npc->act_wait > 8)
			{
				npc->act_no = 1;
				npc->ani_no = 0;
			}
			break;
			
		case 3:
			npc->act_no = 4;
			npc->ani_no = 1;
			npc->ani_wait = 0;
			//Fallthrough
		case 4:
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 4)
				npc->ani_no = 1;
			
			if (npc->flag & 1)
			{
				npc->direct = 2;
				npc->xm = 0x200;
			}
			if (npc->flag & 4)
			{
				npc->direct = 0;
				npc->xm = -0x200;
			}
			
			if (npc->direct == 0)
				npc->xm = -0x400;
			else
				npc->xm = 0x400;
			break;
			
		case 6:
			npc->act_no = 7;
			npc->act_wait = 0;
			npc->ani_no = 1;
			npc->ani_wait = 0;
			npc->ym = -0x400;
			//Fallthrough
		case 7:
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 4)
				npc->ani_no = 1;
			
			if (npc->direct == 0)
				npc->xm = -0x100;
			else
				npc->xm = 0x100;
			
			if (npc->act_wait++ != 0 && npc->flag & 8)
				npc->act_no = 3;
			break;
			
		case 8:
			npc->ani_no = 1;
			npc->act_wait = 0;
			npc->act_no = 9;
			npc->ym = -0x200;
			//Fallthrough
		case 9:
			if (npc->act_wait++ != 0 && npc->flag & 8)
				npc->act_no = 0;
			break;
			
		case 10:
			npc->act_no = 11;
			npc->ani_no = 6;
			npc->ym = -0x400;
			PlaySoundObject(50, 1);
			
			if (npc->direct == 0)
				npc->xm = -0x100;
			else
				npc->xm = 0x100;
			break;
			
		case 11:
			if (npc->act_wait++ != 0 && npc->flag & 8)
			{
				npc->act_no = 12;
				npc->ani_no = 7;
				npc->bits |= NPC_INTERACTABLE;
			}
			break;
			
		case 12:
			npc->xm = 0;
			break;
	}
	
	//Fall and move
	npc->ym += 0x40;
	
	if (npc->xm > 0x400)
		npc->xm = 0x400;
	if (npc->xm < -0x400)
		npc->xm = -0x400;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	
	npc->x += npc->xm;
	npc->y += npc->ym;
}

void Npc060_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{  0, 0,  16, 16},
		{ 16, 0,  32, 16},
		{ 32, 0,  48, 16},
		{ 16, 0,  32, 16},
		{ 48, 0,  64, 16},
		{ 16, 0,  32, 16},
		{112, 0, 128, 16},
		{128, 0, 144, 16},
	};
	
	LoadTLUT_CI4(npc_toroko_tlut);
	LoadTex_CI4(144, 16, npc_toroko_tex + (72 * 16) * (npc->direct != 0));
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 061 - King
#include "data/bitmap/npc_king.inc.c"

void Npc061_Act(NPCHAR *npc)
{
	s32 i;
	
	//Move and animate
	switch (npc->act_no)
	{
		case 0: //Stood
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			npc->xm = 0;
			//Fallthrough
		case 1:
			if (Random(0, 120) == 10)
			{
				npc->act_no = 2;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			break;
			
		case 2: //Blink
			if (++npc->act_wait > 8)
			{
				npc->act_no = 1;
				npc->ani_no = 0;
			}
			break;
			
		case 5: //Lying down
			npc->ani_no = 3;
			npc->xm = 0;
			break;
			
		case 6: //Being knocked-back
			npc->act_no = 7;
			npc->act_wait = 0;
			npc->ani_wait = 0;
			npc->ym = -0x400;
			//Fallthrough
		case 7:
			npc->ani_no = 2;
			
			if (npc->direct == 0)
				npc->xm = -0x200;
			else
				npc->xm = 0x200;
			
			//If touching ground, enter 'lying down' state (the `act_wait` check is probably
			//so he doesn't do it before he even leaves the ground in the first place)
			if (npc->act_wait++ != 0 && npc->flag & 8)
				npc->act_no = 5;
			break;
			
		case 8: //Walking
			npc->act_no = 9;
			npc->ani_no = 4;
			npc->ani_wait = 0;
			//Fallthrough
		case 9:
			if (++npc->ani_wait > 4)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 7)
				npc->ani_no = 4;
			
			if (npc->direct == 0)
				npc->xm = -0x200;
			else
				npc->xm = 0x200;
			break;
			
		case 10: //Running
			npc->act_no = 11;
			npc->ani_no = 4;
			npc->ani_wait = 0;
			//Fallthrough
		case 11:
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 7)
				npc->ani_no = 4;
			
			if (npc->direct == 0)
				npc->xm = -0x400;
			else
				npc->xm = 0x400;
			break;
			
		case 20: //Spawn his sword, before entering his 'idle' state
			SetNpChar(145, 0, 0, 0, 0, 2, npc, 0x100);
			npc->ani_no = 0;
			npc->act_no = 0;
			break;
			
		case 30: //Flying through air after being attacked by Misery
			npc->act_no = 31;
			npc->act_wait = 0;
			npc->ani_wait = 0;
			npc->ym = 0;
			//Fallthrough
		case 31:
			npc->ani_no = 2;
			
			if (npc->direct == 0)
				npc->xm = -0x600;
			else
				npc->xm = 0x600;
			
			if (npc->flag & 1)
			{
				npc->direct = 2;
				npc->act_no = 7;
				npc->act_wait = 0;
				npc->ani_wait = 0;
				npc->ym = -0x400;
				npc->xm = 0x200;
				PlaySoundObject(71, 1);
				SetDestroyNpChar(npc->x, npc->y, 0x800, 4);
			}
			break;
			
		case 40: //Dying
			npc->act_no = 42;
			npc->act_wait = 0;
			npc->ani_no = 8;
			PlaySoundObject(29, 1);
			//Fallthrough
		case 42:
			if (++npc->ani_no > 9)
				npc->ani_no = 8;
			
			if (++npc->act_wait > 100)
			{
				for (i = 0; i < 4; i++)
					SetNpChar(4, npc->x + (Random(-12, 12) * 0x200), npc->y + (Random(-12, 12) * 0x200), Random(-341, 341), Random(-0x600, 0), 0, NULL, 0x100);
				npc->act_no = 50;
				npc->ani_no = 10;
			}
			break;
			
		case 60: //Leap (used to attack Balrog in the Sand Zone storehouse)
			npc->ani_no = 6;
			npc->act_no = 61;
			npc->ym = -0x5FF;
			npc->xm = 0x400;
			npc->count2 = 1;
			break;
			
		case 61: //Leap - part 2
			npc->ym += 0x40;
			if (npc->flag & 8)
			{
				npc->act_no = 0;
				npc->count2 = 0;
				npc->xm = 0;
			}
			break;
	}
	
	//Fall and move
	if (npc->act_no < 30 || npc->act_no >= 40)
	{
		npc->ym += 0x40;
		if (npc->xm > 0x400)
			npc->xm = 0x400;
		if (npc->xm < -0x400)
			npc->xm = -0x400;
		if (npc->ym > 0x5FF)
			npc->ym = 0x5FF;
	}
	
	npc->x += npc->xm;
	npc->y += npc->ym;
}

void Npc061_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][11] = {
		{
			{  0, 0,  16, 16},
			{ 16, 0,  32, 16},
			{ 32, 0,  48, 16},
			{ 48, 0,  64, 16},
			{ 64, 0,  80, 16},
			{  0, 0,  16, 16},
			{ 80, 0,  96, 16},
			{  0, 0,  16, 16},
			{ 48, 0,  64, 16},
			{  0, 0,   0,  0},
			{112, 0, 128, 16},
		},
		{
			{  0, 16,  16, 32},
			{ 16, 16,  32, 32},
			{ 32, 16,  48, 32},
			{ 48, 16,  64, 32},
			{ 64, 16,  80, 32},
			{  0, 16,  16, 32},
			{ 80, 16,  96, 32},
			{  0, 16,  16, 32},
			{ 48, 16,  64, 32},
			{  0,  0,   0,  0},
			{112,  0, 128, 16},
		},
	};
	
	LoadTLUT_CI4(npc_king_tlut);
	LoadTex_CI4(112, 32, npc_king_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}

//NPC 062 - Kazuma at Computer
#include "data/bitmap/npc_computeruser.inc.c"

void Npc062_Act(NPCHAR *npc)
{
	//Animate
	switch (npc->act_no)
	{
		case 0:
			npc->x -= 4 * 0x200;
			npc->y += 16 * 0x200;
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			//Fallthrough
		case 1:
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 1)
				npc->ani_no = 0;
			
			if (Random(0, 80) == 1)
			{
				npc->act_no = 2;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			if (Random(0, 120) == 10)
			{
				npc->act_no = 3;
				npc->act_wait = 0;
				npc->ani_no = 2;
			}
			break;
			
		case 2:
			if (++npc->act_wait > 40)
			{
				npc->act_no = 3;
				npc->act_wait = 0;
				npc->ani_no = 2;
			}
			break;
			
		case 3:
			if (++npc->act_wait > 80)
			{
				npc->act_no = 1;
				npc->ani_no = 0;
			}
			break;
	}
}

void Npc062_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{ 0, 0, 16, 24},
		{16, 0, 32, 24},
		{32, 0, 48, 24},
	};
	
	LoadTLUT_CI4(npc_computeruser_tlut);
	LoadTex_CI4(48, 48, npc_computeruser_tex);
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 063 - Toroko with stick
void Npc063_Act(NPCHAR *npc)
{
	//Move and animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->act_wait = 0;
			npc->ani_wait = 0;
			npc->ym = -0x400;
			//Fallthrough
		case 1:
			if (npc->ym > 0)
				npc->bits &= ~NPC_IGNORE_SOLIDITY;
			
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 3)
				npc->ani_no = 0;
			
			if (npc->direct == 0)
				npc->xm = -0x100;
			else
				npc->xm = 0x100;
			
			if (npc->act_wait++ != 0 && npc->flag & 8)
				npc->act_no = 2;
			break;
			
		case 2:
			npc->act_no = 3;
			npc->act_wait = 0;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			//Fallthrough
		case 3:
			if (++npc->ani_wait > 2)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			if (npc->ani_no > 3)
				npc->ani_no = 0;
			
			if (++npc->act_wait > 50)
			{
				npc->act_wait = 40;
				npc->xm *= -1;
				
				if (npc->direct == 0)
					npc->direct = 2;
				else
					npc->direct = 0;
			}
			
			if (npc->act_wait > 35)
				npc->bits |= NPC_SHOOTABLE;
			
			if (npc->direct == 0)
				npc->xm -= 0x40;
			else
				npc->xm += 0x40;
			
			if (npc->shock)
			{
				npc->act_no = 4;
				npc->ani_no = 4;
				npc->ym = -0x400;
				npc->bits &= ~NPC_SHOOTABLE;
				npc->damage = 0;
			}
			break;
			
		case 4:
			if (npc->direct == 0)
				npc->xm = -0x100;
			else
				npc->xm = 0x100;
			
			if (npc->act_wait++ != 0 && npc->flag & 8)
			{
				npc->act_no = 5;
				npc->bits |= NPC_INTERACTABLE;
			}
			break;
			
		case 5:
			npc->xm = 0;
			npc->ani_no = 5;
			break;
	}
	
	//Fall and move
	npc->ym += 0x40;
	if (npc->xm > 0x400)
		npc->xm = 0x400;
	if (npc->xm < -0x400)
		npc->xm = -0x400;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	
	npc->x += npc->xm;
	npc->y += npc->ym;
}

void Npc063_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{ 64, 0,  80, 16},
		{ 80, 0,  96, 16},
		{ 64, 0,  80, 16},
		{ 96, 0, 112, 16},
		{112, 0, 128, 16},
		{128, 0, 144, 16},
	};
	
	LoadTLUT_CI4(npc_toroko_tlut);
	LoadTex_CI4(144, 16, npc_toroko_tex + (72 * 16) * (npc->direct != 0));
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 064 - First Cave Critter
#include "data/bitmap/npc_critter.inc.c"

void Npc064_Act(NPCHAR *npc)
{
	switch (npc->act_no)
	{
		case 0: //Initialize
			npc->y += 3 * 0x200;
			npc->act_no = 1;
			//Fallthrough
		case 1: //Waiting
			//Look at player
			if (npc->x > gMC.x)
				npc->direct = 0;
			else
				npc->direct = 2;
			
			if (npc->tgt_x < 100)
				npc->tgt_x++;
			
			//Open eyes near player
			if (npc->act_wait >= 8 && npc->x - (112 * 0x200) < gMC.x && npc->x + (112 * 0x200) > gMC.x && npc->y - (80 * 0x200) < gMC.y && npc->y + (80 * 0x200) > gMC.y)
			{
				npc->ani_no = 1;
			}
			else
			{
				if (npc->act_wait < 8)
					npc->act_wait++;
				npc->ani_no = 0;
			}
			
			//Jump if attacked
			if (npc->shock)
			{
				npc->act_no = 2;
				npc->ani_no = 0;
				npc->act_wait = 0;
			}
			
			//Jump if player is nearby
			if (npc->act_wait >= 8 && npc->tgt_x >= 100 && npc->x - (64 * 0x200) < gMC.x && npc->x + (64 * 0x200) > gMC.x && npc->y - (80 * 0x200) < gMC.y && npc->y + (48 * 0x200) > gMC.y)
			{
				npc->act_no = 2;
				npc->ani_no = 0;
				npc->act_wait = 0;
			}
			break;
			
		case 2: //Going to jump
			if (++npc->act_wait > 8)
			{
				//Set jump state
				npc->act_no = 3;
				npc->ani_no = 2;
				
				//Jump
				npc->ym = -0x5FF;
				PlaySoundObject(30, 1);
				
				//Jump in facing direction
				if (npc->direct == 0)
					npc->xm = -0x100;
				else
					npc->xm = 0x100;
			}
			break;
			
		case 3: //Jumping
			//Land
			if (npc->flag & 8)
			{
				npc->xm = 0;
				npc->act_wait = 0;
				npc->ani_no = 0;
				npc->act_no = 1;
				PlaySoundObject(23, 1);
			}
			break;
	}
	
	//Fall and move
	npc->ym += 0x40;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	npc->x += npc->xm;
	npc->y += npc->ym;
}

void Npc064_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][3] = {
		{
			{0, 0, 16, 16},
			{16, 0, 32, 16},
			{32, 0, 48, 16},
		},
		{
			{0, 16, 16, 32},
			{16, 16, 32, 32},
			{32, 16, 48, 32},
		},
	};
	
	LoadTLUT_CI4(npc_critter_cemet_tlut);
	LoadTex_CI4(96, 32, npc_critter_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}

//NPC 065 - First Cave Bat
#include "data/bitmap/npc_bat.inc.c"

void Npc065_Act(NPCHAR *npc)
{
	//Movement
	switch (npc->act_no)
	{
		case 0:
			npc->tgt_x = npc->x;
			npc->tgt_y = npc->y;
			npc->count1 = 120;
			npc->act_no = 1;
			npc->act_wait = Random(0, 50);
			//Fallthrough
		case 1:
			if (++npc->act_wait < 50)
				break;
			npc->act_wait = 0;
			npc->act_no = 2;
			npc->ym = 0x300;
			break;
			
		case 2:
			if (gMC.x < npc->x)
				npc->direct = 0;
			else
				npc->direct = 2;
			
			if (npc->tgt_y < npc->y)
				npc->ym -= 0x10;
			if (npc->tgt_y > npc->y)
				npc->ym += 0x10;
			
			if (npc->ym > 0x300)
				npc->ym = 0x300;
			if (npc->ym < -0x300)
				npc->ym = -0x300;
			break;
	}

	npc->x += npc->xm;
	npc->y += npc->ym;
	
	//Animate
	if (++npc->ani_wait > 1)
	{
		npc->ani_wait = 0;
		npc->ani_no++;
	}
	if (npc->ani_no > 2)
		npc->ani_no = 0;
}

void Npc065_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][4] = {
		{
			{32, 0, 48, 16},
			{48, 0, 64, 16},
			{64, 0, 80, 16},
			{80, 0, 96, 16},
		},
		{
			{32, 16, 48, 32},
			{48, 16, 64, 32},
			{64, 16, 80, 32},
			{80, 16, 96, 32},
		},
	};
	
	LoadTLUT_CI4(npc_bat_cemet_tlut);
	LoadTex_CI4(96, 32, npc_bat_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}

//NPC 070 - Sparkle
#include "data/bitmap/npc_sparkle.inc.c"

void Npc070_Act(NPCHAR *npc)
{
	//Animate
	if (++npc->ani_wait > 3)
	{
		npc->ani_wait = 0;
		npc->ani_no++;
	}
	if (npc->ani_no > 3)
		npc->ani_no = 0;
}

void Npc070_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{ 0, 0, 16, 16},
		{16, 0, 32, 16},
		{32, 0, 48, 16},
		{48, 0, 64, 16},
	};
	
	LoadTLUT_CI4(npc_sparkle_tlut);
	LoadTex_CI4(64, 16, npc_sparkle_tex);
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 071 - Chinfish
#include "data/bitmap/npc_chinfish.inc.c"

void Npc071_Act(NPCHAR *npc)
{
	//Move
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->tgt_x = npc->x;
			npc->tgt_y = npc->y;
			npc->ym = 0x80;
			//Fallthrough
		case 1:
			if (npc->tgt_y < npc->y)
				npc->ym -= 8;
			if (npc->tgt_y > npc->y)
				npc->ym += 8;
			
			if (npc->ym > 0x100)
				npc->ym = 0x100;
			if (npc->ym < -0x100)
				npc->ym = -0x100;
			break;
	}
	
	npc->x += npc->xm;
	npc->y += npc->ym;
	
	//Animate
	if (++npc->ani_wait > 4)
	{
		npc->ani_wait = 0;
		npc->ani_no++;
	}
	
	if (npc->ani_no > 1)
		npc->ani_no = 0;
	
	if (npc->shock)
		npc->ani_no = 2;
}

void Npc071_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][3] = {
		{
			{ 0, 0, 16, 16},
			{16, 0, 32, 16},
			{32, 0, 48, 16},
		},
		{
			{ 0, 16, 16, 32},
			{16, 16, 32, 32},
			{32, 16, 48, 32},
		},
	};
	
	LoadTLUT_CI4(npc_chinfish_tlut);
	LoadTex_CI4(48, 32, npc_chinfish_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}

//NPC 072 - Sprinkler
#include "data/bitmap/npc_sprinkler.inc.c"

void Npc072_Act(NPCHAR *npc)
{
	//Animate and generate water droplets
	if (npc->direct == 0)
	{
		if (++npc->ani_wait > 1)
		{
			npc->ani_wait = 0;
			npc->ani_no++;
		}
		
		if (npc->ani_no > 1)
		{
			npc->ani_no = 0;
			return;
		}
		
		if (gMC.x < npc->x + (((SCREEN_WIDTH / 2) + 160) * 0x200) && gMC.x > npc->x - (((SCREEN_WIDTH / 2) + 160) * 0x200) && gMC.y < npc->y + (((SCREEN_HEIGHT / 2) + 120) * 0x200) && gMC.y > npc->y - (((SCREEN_HEIGHT / 2) + 120) * 0x200))
		{
			if (++npc->act_no % 2)
				SetNpChar(73, npc->x, npc->y, Random(-0x200, 0x200) * 2, Random(-0x200, 0x80) * 3, 0, NULL, 0x100);
			SetNpChar(73, npc->x, npc->y, Random(-0x200, 0x200) * 2, Random(-0x200, 0x80) * 3, 0, NULL, 0x100);
		}
	}
}

void Npc072_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{ 0, 0, 16, 16},
		{16, 0, 32, 16},
	};
	
	LoadTLUT_CI4(npc_sprinkler_tlut);
	LoadTex_CI4(32, 16, npc_sprinkler_tex);
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 073 - Water Droplet
#include "data/bitmap/npc_waterdrop.inc.c"

void Npc073_Act(NPCHAR *npc)
{
	s16 map_l;
	
	//Select random frame
	npc->ani_no = Random(0, 4);
	
	//Fall and move
	npc->ym += 0x20;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	
	npc->x += npc->xm;
	npc->y += npc->ym;
	
	//Delete conditions
	if (++npc->act_wait > 10)
	{
		if (npc->flag & 1)
			npc->cond = 0;
		if (npc->flag & 4)
			npc->cond = 0;
		if (npc->flag & 8)
			npc->cond = 0;
		if (npc->flag & 0x100)
			npc->cond = 0;
	}
	
	GetMapData(NULL, NULL, &map_l);
	if (npc->y > map_l * 0x200 * 0x10)
		npc->cond = 0;
}

void Npc073_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][5] = {
		{
			{0, 0,  2, 2},
			{2, 0,  4, 2},
			{4, 0,  6, 2},
			{6, 0,  8, 2},
			{8, 0, 10, 2},
		},
		{
			{0, 2,  2, 4},
			{2, 2,  4, 4},
			{4, 2,  6, 4},
			{6, 2,  8, 4},
			{8, 2, 10, 4},
		},
	};
	
	LoadTLUT_CI4(npc_waterdrop_tlut);
	LoadTex_CI4(16, 4, npc_waterdrop_tex);
	PutBitmap(&rect[npc->direct == 2][npc->ani_no], x, y);
}

//NPC 074 - Jack
#include "data/bitmap/npc_jack.inc.c"

void Npc074_Act(NPCHAR *npc)
{
	//Move and animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			npc->xm = 0;
			//Fallthrough
		case 1:
			if (Random(0, 120) == 10)
			{
				npc->act_no = 2;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			break;
			
		case 2:
			if (++npc->act_wait > 8)
			{
				npc->act_no = 1;
				npc->ani_no = 0;
			}
			break;
			
		case 8:
			npc->act_no = 9;
			npc->ani_no = 2;
			npc->ani_wait = 0;
			//Fallthrough
		case 9:
			if (++npc->ani_wait > 4)
			{
				npc->ani_wait = 0;
				npc->ani_no++;
			}
			
			if (npc->ani_no > 5)
				npc->ani_no = 2;
			
			if (npc->direct == 0)
				npc->xm = -0x200;
			else
				npc->xm = 0x200;
			break;
	}
	
	//Fall and move
	npc->ym += 0x40;
	
	if (npc->xm > 0x400)
		npc->xm = 0x400;
	if (npc->xm < -0x400)
		npc->xm = -0x400;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	
	npc->x += npc->xm;
	npc->y += npc->ym;
}

void Npc074_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][6] = {
		{
			{ 0, 0, 16, 16},
			{16, 0, 32, 16},
			{32, 0, 48, 16},
			{ 0, 0, 16, 16},
			{48, 0, 64, 16},
			{ 0, 0, 16, 16},
		},
		{
			{ 0, 16, 16, 32},
			{16, 16, 32, 32},
			{32, 16, 48, 32},
			{ 0, 16, 16, 32},
			{48, 16, 64, 32},
			{ 0, 16, 16, 32},
		},
	};
	
	LoadTLUT_CI4(npc_jack_tlut);
	LoadTex_CI4(64, 32, npc_jack_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}

//NPC 075 - Kanpachi fishing
#include "data/bitmap/npc_kanpachi.inc.c"

void Npc075_Act(NPCHAR *npc)
{
	//Animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			//Fallthrough
		case 1:
			if (npc->x - (48 * 0x200) < gMC.x && npc->x + (48 * 0x200) > gMC.x && npc->y - (48 * 0x200) < gMC.y && npc->y + (16 * 0x200) > gMC.y)
				npc->ani_no = 1;
			else
				npc->ani_no = 0;
			break;
	}
}

void Npc075_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2] = {
		{ 0, 0, 24, 24},
		{24, 0, 48, 24},
	};
	
	LoadTLUT_CI4(npc_kanpachi_tlut);
	LoadTex_CI4(48, 24, npc_kanpachi_tex);
	PutBitmap(&rect[npc->ani_no], x, y);
}

//NPC 076 - Flowers
#include "data/bitmap/npc_plant.inc.c"

void Npc076_Put(NPCHAR *npc, s32 x, s32 y)
{
	RECT rect;
	rect.left = npc->code_event * 16;
	rect.top = 0;
	rect.right = rect.left + 16;
	rect.bottom = 16;
	
	LoadTLUT_CI4(npc_plant_tlut);
	LoadTex_CI4(96, 16, npc_plant_tex);
	PutBitmap(&rect, x, y);
}

//NPC 077 - Yamashita
#include "data/bitmap/npc_yamashita.inc.c"

void Npc077_Act(NPCHAR *npc)
{
	//Animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->ani_no = 0;
			npc->ani_wait = 0;
			//Fallthrough
		case 1:
			if (Random(0, 120) == 10)
			{
				npc->act_no = 2;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			break;
			
		case 2:
			if (++npc->act_wait > 8)
			{
				npc->act_no = 1;
				npc->ani_no = 0;
			}
			break;
	}
}

void Npc077_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect = { 0, 0, 48, 32};
	
	LoadTLUT_CI4(npc_yamashita_tlut);
	LoadTex_CI4(48, 32, npc_yamashita_tex + (24 * 32) * ((npc->direct != 0) ? 2 : npc->ani_no));
	PutBitmap(&rect, x, y);
}

//NPC 078 - Pot
#include "data/bitmap/npc_pot.inc.c"

void Npc078_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[] = {
		{ 0, 0, 16, 16},
		{16, 0, 32, 16},
	};
	
	LoadTLUT_CI4(npc_pot_tlut);
	LoadTex_CI4(32, 16, npc_pot_tex);
	PutBitmap(&rect[npc->direct != 0], x, y);
}

//NPC 079 - Mahin
#include "data/bitmap/npc_mahin.inc.c"

void Npc079_Act(NPCHAR *npc)
{
	//Animate
	switch (npc->act_no)
	{
		case 0:
			npc->act_no = 1;
			npc->ani_no = 2;
			npc->ani_wait = 0;
			break;
			
		case 2:
			npc->ani_no = 0;
			
			if (Random(0, 120) == 10)
			{
				npc->act_no = 3;
				npc->act_wait = 0;
				npc->ani_no = 1;
			}
			
			if (npc->x - (32 * 0x200) < gMC.x && npc->x + (32 * 0x200) > gMC.x && npc->y - (32 * 0x200) < gMC.y && npc->y + (16 * 0x200) > gMC.y)
			{
				if (npc->x > gMC.x)
					npc->direct = 0;
				else
					npc->direct = 2;
			}
			break;
			
		case 3:
			if (++npc->act_wait > 8)
			{
				npc->act_no = 2;
				npc->ani_no = 0;
			}
			break;
	}
	
	//Fall and move
	npc->ym += 0x40;
	if (npc->ym > 0x5FF)
		npc->ym = 0x5FF;
	npc->y += npc->ym;
}

void Npc079_Put(NPCHAR *npc, s32 x, s32 y)
{
	static const RECT rect[2][3] = {
		{
			{0, 0, 16, 16},
			{16, 0, 32, 16},
			{32, 0, 48, 16},
		},
		{
			{0, 16, 16, 32},
			{16, 16, 32, 32},
			{32, 16, 48, 32},
		},
	};
	
	LoadTLUT_CI4(npc_mahin_tlut);
	LoadTex_CI4(48, 32, npc_mahin_tex);
	PutBitmap(&rect[npc->direct != 0][npc->ani_no], x, y);
}
