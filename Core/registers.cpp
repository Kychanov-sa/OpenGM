#include "stdafx.h"
#include "registers.h"

// Temporary register
__declspec( align(16) ) __declspec(thread) float r0;
__declspec( align(16) ) __declspec(thread) float r1;
__declspec( align(16) ) __declspec(thread) float r2;
__declspec( align(16) ) __declspec(thread) float r3;
__declspec( align(16) ) __declspec(thread) float r4;
__declspec( align(16) ) __declspec(thread) float r5;
__declspec( align(16) ) __declspec(thread) float r6;
__declspec( align(16) ) __declspec(thread) float r7;
__declspec( align(16) ) __declspec(thread) float r8;
__declspec( align(16) ) __declspec(thread) float r9;
__declspec( align(16) ) __declspec(thread) float r10;
__declspec( align(16) ) __declspec(thread) float r11;

//// Constant registers
//const __declspec( align(16) ) float rad2deg = (180.0f / GM_PI);	// c0
//const __declspec( align(16) ) float deg2rad = (GM_PI / 180.0f);	// c1
//const __declspec( align(16) ) float _0_47 = 0.47f;				// c2
//const __declspec( align(16) ) float _1_47 = 1.47f;				// c3
//const __declspec( align(16) ) float _0_50 = 0.50f;				// c4
//const __declspec( align(16) ) float _1_00 = 1.0f;				// c5