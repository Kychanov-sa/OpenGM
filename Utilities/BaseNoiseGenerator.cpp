#include "stdafx.h"

#define GMUNOISE_B	0x1000
#define GMUNOISE_BM 0xff

#define GMUNOISE_N	0x1000
#define GMUNOISE_NP 12   /* 2^N */
#define GMUNOISE_NM 0xfff

static int		p[GMUNOISE_B + GMUNOISE_B + 2];
static float	g3[GMUNOISE_B + GMUNOISE_B + 2][3];
static float	g2[GMUNOISE_B + GMUNOISE_B + 2][2];
static float	g1[GMUNOISE_B + GMUNOISE_B + 2];

#define s_curve(t)						(t * t * (3 - 2 * t))
#define ab_lerp(t, a, b)				(a + t * (b - a))
#define coord_setup(i, b0, b1, r0, r1)	t = i + GMUNOISE_N;				\
										b0 = ((int) t) & GMUNOISE_BM;	\
										b1 = (b0 + 1) & GMUNOISE_BM;	\
										r0 = t - (int) t;				\
										r1 = r0 - 1;
#define at2(rx, ry)						(rx * q[0] + ry * q[1])
#define at3(rx,ry,rz)					(rx * q[0] + ry * q[1] + rz * q[2])

namespace GlacialBytes
{
	namespace OpenGm
	{
		namespace Utilities
		{
			BaseNoiseGenerator::BaseNoiseGenerator()
			{
				p = new int[GMUNOISE_B + GMUNOISE_B + 2];
				g3 = new float[GMUNOISE_B + GMUNOISE_B + 2][3];
				g2 = new float[GMUNOISE_B + GMUNOISE_B + 2][2];
				g1 = new float[GMUNOISE_B + GMUNOISE_B + 2];
			}

			BaseNoiseGenerator::~BaseNoiseGenerator()
			{

			}
		}
	}
}