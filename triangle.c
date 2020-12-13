#include "triangle.h"
#include <math.h>

//Trigonometry tables
const s32 gSin[0x100] = {
	   0,   12,   25,   37,   50,   62,   75,   87,   99,  112,  124,  136,  148,  160,  172,  184, 
	 195,  207,  218,  230,  241,  252,  263,  273,  284,  294,  304,  314,  324,  334,  343,  353, 
	 362,  370,  379,  387,  395,  403,  411,  418,  425,  432,  439,  445,  451,  457,  462,  468, 
	 473,  477,  482,  486,  489,  493,  496,  499,  502,  504,  506,  508,  509,  510,  511,  511, 
	 511,  511,  511,  510,  509,  508,  506,  504,  502,  499,  496,  493,  489,  486,  482,  477, 
	 473,  468,  462,  457,  451,  445,  439,  432,  425,  418,  411,  403,  395,  387,  379,  370, 
	 362,  353,  343,  334,  324,  314,  304,  294,  284,  273,  263,  252,  241,  230,  218,  207, 
	 195,  184,  172,  160,  148,  136,  124,  112,   99,   87,   75,   62,   50,   37,   25,   12, 
	   0,  -12,  -25,  -37,  -50,  -62,  -75,  -87,  -99, -112, -124, -136, -148, -160, -172, -184, 
	-195, -207, -218, -230, -241, -252, -263, -273, -284, -294, -305, -315, -324, -334, -343, -353, 
	-362, -370, -379, -387, -395, -403, -411, -418, -425, -432, -439, -445, -451, -457, -462, -468, 
	-473, -477, -482, -486, -489, -493, -496, -499, -502, -504, -506, -508, -509, -510, -511, -511, 
	-511, -511, -511, -510, -509, -508, -506, -504, -502, -499, -496, -493, -489, -486, -482, -477, 
	-473, -468, -462, -457, -451, -445, -439, -432, -425, -418, -411, -403, -395, -387, -379, -370, 
	-362, -353, -343, -334, -324, -314, -304, -294, -284, -273, -263, -252, -241, -230, -218, -207, 
	-195, -184, -172, -160, -148, -136, -124, -112,  -99,  -87,  -75,  -62,  -50,  -37,  -25,  -12, 
};
const s16 gTan[0x21] = {
	0x0000, 0x00C9, 0x0192, 0x025C, 0x0326, 0x03F2, 0x04BF, 0x058D, 0x065D, 0x072F, 0x0803, 0x08DB, 0x09B5, 0x0A92, 0x0B73, 0x0C58, 
	0x0D41, 0x0E2F, 0x0F22, 0x101B, 0x111A, 0x1220, 0x132E, 0x1443, 0x1561, 0x1689, 0x17BB, 0x18F9, 0x1A43, 0x1B9A, 0x1D00, 0x1E77, 
	0x2000,
};

//Trigonometry functions
s32 GetSin(u8 deg)
{
	return gSin[deg];
}

s32 GetCos(u8 deg)
{
	deg += 0x40;
	return gSin[deg];
}

u8 GetArktan(s32 x, s32 y)
{
	s16 k;
	u8 a = 0;
	
	x *= -1;
	y *= -1;
	
	if (x > 0)
	{
		if (y > 0)
		{
			if (x > y)
			{
				k = (y * 0x2000) / x;
				while (k > gTan[a])
					a++;
			}
			else
			{
				k = (x * 0x2000) / y;
				while (k > gTan[a])
					a++;
				a = 0x40 - a;
			}
		}
		else
		{
			if (x > -y)
			{
				k = (-y * 0x2000) / x;
				while (k > gTan[a])
					a++;
				a = 0x100 - a;
			}
			else
			{
				k = (x * 0x2000) / -y;
				while (k > gTan[a])
					a++;
				a = 0x100 - 0x40 + a;
			}
		}
	}
	else
	{
		if (y > 0)
		{
			if (-x > y)
			{
				k = (y * 0x2000) / -x;
				while (k > gTan[a])
					a++;
				a = 0x80 - a;
			}
			else
			{
				k = (-x * 0x2000) / y;
				while (k > gTan[a])
					a++;
				a = 0x40 + a;
			}
		}
		else
		{
			if (-x > -y)
			{
				k = (-y * 0x2000) / -x;
				while (k > gTan[a])
					a++;
				a = 0x80 + a;
			}
			else
			{
				k = (-x * 0x2000) / -y;
				while (k > gTan[a])
					a++;
				a = 0x100 - 0x40 - a;
			}
		}
	}
	
	return a;
}
