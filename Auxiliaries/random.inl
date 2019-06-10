/// <summary>
/// OpenGM library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>16-12-2018</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifdef GMAUX_RANDOM_INL
#error Nested inclusion of random.inl
#else
#define GMAUX_RANDOM_INL
#endif

Random::Random()
	: _randomGenerator(_randomDevice())
{
}

Random::Random(uint32_t seed)
	: _randomGenerator(_randomDevice())
{
	_randomGenerator.seed(seed);
}

int32_t Random::NextInt(void)
{
	return std::uniform_int_distribution<int32_t>(0x80000000, 0x7FFFFFFF)(_randomGenerator);
}

int32_t Random::NextInt(int32_t maxValue)
{
	return std::uniform_int_distribution<int32_t>(0, maxValue)(_randomGenerator);
}

int32_t Random::NextInt(int32_t minValue, int32_t maxValue)
{
	return std::uniform_int_distribution<int32_t>(minValue, maxValue)(_randomGenerator);
}

float Random::NextFloat(float maxValue = 1.0f)
{
	return std::uniform_real_distribution<float>(0.0f, maxValue)(_randomGenerator);
}

float Random::NextFloat(float minValue, float maxValue)
{
	return std::uniform_real_distribution<float>(minValue, maxValue)(_randomGenerator);
}

void Random::SetSeed(uint32_t seed)
{
	_randomGenerator.seed(seed);
}