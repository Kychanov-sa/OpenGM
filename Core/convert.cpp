#include "stdafx.h"
#include "registers.h"

namespace GlacialBytes
{
	namespace OpenGm
	{
		const __declspec(align(16)) float Convert::rad2deg = (180.0f / GM_PI);
		const __declspec(align(16)) float Convert::deg2rad = (GM_PI / 180.0f);
	}
}