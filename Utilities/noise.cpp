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

float bias(const float a, const float b)
{
	return powf(a, logf(b) / logf(0.5f));
}

float gain(const float a, const float b)
{
	if (a < 0.001f)	return 0; else if (a > 0.999f) return 1.0f;

	float p = logf(1.0f - b) / logf(0.5f);

	if (a < 0.5f) return float(powf(2 * a, p) / 2);
	else return 1 - float(powf(2 * (1.0f - a), p) / 2);
}

namespace OpenGm
{
	namespace Utilities
	{
		GMAPI float gmuNoise1(const float s)
		{
			int		bx0, bx1;
			float	rx0, rx1, sx, t, u, v;

			coord_setup(s, bx0, bx1, rx0, rx1);

			sx = s_curve(rx0);
			u = rx0 * g1[p[bx0]];
			v = rx1 * g1[p[bx1]];
			return ab_lerp(sx, u, v);
		}

		GMAPI float gmuNoise2(const float2& pnt)
		{
			int		bx0, bx1, by0, by1, b00, b10, b01, b11;
			float	rx0, rx1, ry0, ry1, *q, sx, sy, a, b, t, u, v;
			int		i, j;

			coord_setup(pnt.x, bx0, bx1, rx0, rx1);
			coord_setup(pnt.y, by0, by1, ry0, ry1);

			i = p[bx0];
			j = p[bx1];

			b00 = p[i + by0];
			b10 = p[j + by0];
			b01 = p[i + by1];
			b11 = p[j + by1];

			sx = s_curve(rx0);
			sy = s_curve(ry0);


			q = g2[b00]; u = at2(rx0, ry0);
			q = g2[b10]; v = at2(rx1, ry0);
			a = ab_lerp(sx, u, v);

			q = g2[b01]; u = at2(rx0, ry1);
			q = g2[b11]; v = at2(rx1, ry1);
			b = ab_lerp(sx, u, v);

			return ab_lerp(sy, a, b);
		}

		GMAPI float gmuNoise3(const float3& pnt)
		{
			int		bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
			float	rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t, u, v;
			int		i, j;

			coord_setup(pnt.x, bx0, bx1, rx0, rx1);
			coord_setup(pnt.y, by0, by1, ry0, ry1);
			coord_setup(pnt.z, bz0, bz1, rz0, rz1);

			i = p[bx0];
			j = p[bx1];

			b00 = p[i + by0];
			b10 = p[j + by0];
			b01 = p[i + by1];
			b11 = p[j + by1];

			t = s_curve(rx0);
			sy = s_curve(ry0);
			sz = s_curve(rz0);

			q = g3[b00 + bz0]; u = at3(rx0, ry0, rz0);
			q = g3[b10 + bz0]; v = at3(rx1, ry0, rz0);
			a = ab_lerp(t, u, v);

			q = g3[b01 + bz0]; u = at3(rx0, ry1, rz0);
			q = g3[b11 + bz0]; v = at3(rx1, ry1, rz0);
			b = ab_lerp(t, u, v);

			c = ab_lerp(sy, a, b);

			q = g3[b00 + bz1]; u = at3(rx0, ry0, rz1);
			q = g3[b10 + bz1]; v = at3(rx1, ry0, rz1);
			a = ab_lerp(t, u, v);

			q = g3[b01 + bz1]; u = at3(rx0, ry1, rz1);
			q = g3[b11 + bz1]; v = at3(rx1, ry1, rz1);
			b = ab_lerp(t, u, v);

			d = ab_lerp(sy, a, b);

			return ab_lerp(sz, c, d);
		}

		GMAPI float gmuTurbulence2(const float2& v, float freq)
		{
			float t = 0.0f;

			do
			{
				t += gmuNoise2(v*freq) / freq;
				freq *= 0.5f;
			} while (freq >= 1.0f);
			return t;
		}

		GMAPI float gmuTurbulence3(const float3& v, float freq)
		{
			float t = 0.0f;

			do
			{
				t += gmuNoise3(v*freq) / freq;
				freq *= 0.5f;
			} while (freq >= 1.0f);
			return t;
		}

		GMAPI float gmuTileableNoise1(const float s, const float w)
		{
			return (gmuNoise1(s)     * (w - s) +
				gmuNoise1(s - w) *      s) / w;
		}

		GMAPI float gmuTileableNoise2(const float2& v, float w, float h)
		{
			return (gmuNoise2(float2(v.x, v.y))     * (w - v.x) * (h - v.y) +
				gmuNoise2(float2(v.x - w, v.y))     *      v.x  * (h - v.y) +
				gmuNoise2(float2(v.x, v.y - h)) * (w - v.x) *      v.y +
				gmuNoise2(float2(v.x - w, v.y - h)) *      v.x  *      v.y) / (w * h);
		}

		GMAPI float gmuTileableNoise3(const float3& v, float w, float h, float d)
		{
			return (gmuNoise3(float3(v.x, v.y, v.z))     * (w - v.x) * (h - v.y) * (d - v.z) +
				gmuNoise3(float3(v.x - w, v.y, v.z))     *      v.x  * (h - v.y) * (d - v.z) +
				gmuNoise3(float3(v.x, v.y - h, v.z))     * (w - v.x) *      v.y  * (d - v.z) +
				gmuNoise3(float3(v.x - w, v.y - h, v.z))     *      v.x  *      v.y  * (d - v.z) +
				gmuNoise3(float3(v.x, v.y, v.z - d)) * (w - v.x) * (h - v.y) *      v.z +
				gmuNoise3(float3(v.x - w, v.y, v.z - d)) *      v.x  * (h - v.y) *      v.z +
				gmuNoise3(float3(v.x, v.y - h, v.z - d)) * (w - v.x) *      v.y  *      v.z +
				gmuNoise3(float3(v.x - w, v.y - h, v.z - d)) *      v.x  *      v.y  *      v.z) / (w * h * d);
		}

		GMAPI float gmuTileableTurbulence2(const float2& v, float w, float h, float freq)
		{
			float t = 0.0f;

			do
			{
				t += gmuTileableNoise2(v*freq, w * freq, h * freq) / freq;
				freq *= 0.5f;
			} while (freq >= 1.0f);
			return t;
		}

		GMAPI float gmuTileableTurbulence3(const float3& v, float w, float h, float d, float freq)
		{
			float t = 0.0f;

			do
			{
				t += gmuTileableNoise3(v*freq, w * freq, h * freq, d * freq) / freq;
				freq *= 0.5f;
			} while (freq >= 1.0f);
			return t;
		}

		GMAPI void gmuRandNoise(int seed)
		{
			int i, j, k;

			srand(seed);
			for (i = 0; i<GMUNOISE_B; ++i)
			{
				p[i] = i;
				g1[i] = (float)((rand() % (GMUNOISE_B + GMUNOISE_B)) - GMUNOISE_B) / GMUNOISE_B;

				for (j = 0; j<2; ++j)
					g2[i][j] = (float)((rand() % (GMUNOISE_B + GMUNOISE_B)) - GMUNOISE_B) / GMUNOISE_B;
				normalize2((float2&)g2[i]);

				for (j = 0; j<3; ++j)
					g3[i][j] = (float)((rand() % (GMUNOISE_B + GMUNOISE_B)) - GMUNOISE_B) / GMUNOISE_B;
				normalize3((float3&)g3[i]);
			}

			while (--i)
			{
				k = p[i];
				p[i] = p[j = rand() % GMUNOISE_B];
				p[j] = k;
			}

			for (i = 0; i<GMUNOISE_B + 2; ++i)
			{
				p[GMUNOISE_B + i] = p[i];
				g1[GMUNOISE_B + i] = g1[i];
				for (j = 0; j<2; ++j)
					g2[GMUNOISE_B + i][j] = g2[i][j];
				for (j = 0; j<3; ++j)
					g3[GMUNOISE_B + i][j] = g3[i][j];
			}
		}
	}
}