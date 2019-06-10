/// <summary>
/// OpenGM Auxiliaries library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2018 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifndef GMAUX_H
#define GMAUX_H
#pragma once

#include <random>
#include <gm\gm.h>

namespace OpenGm
{
#ifdef GMAPI
#undef GMAPI
#endif
	namespace Auxiliaries
	{
#ifdef GM_BUILDING_LIB
#define GMAPI
#else
#define GMAPI extern
#endif

		/// <summary>
		/// Random number generator.
		/// </summary>
		class Random
		{
		public:
			/// <summary>
			/// Constructor.
			/// </summary>
			Random();

			/// <summary>
			/// Constructor.
			/// </summary>
			/// <param name="seed">A number used to calculate a starting value for the pseudo-random number generator.</param>
			Random(uint32_t seed);

			/// <summary>
			/// Returns next 32-bit integer random value.
			/// </summary>
			/// <returns>Next random value.</returns>
			/// <remarks>Default int range is [MIN_INT, MAX_INT].  Max value is included.</remarks>
			__forceinline int32_t NextInt(void);

			/// <summary>
			/// Returns next 32-bit integer random value that is less then the specified maximum.
			/// </summary>
			/// <param name="maxValue">The exclusive upper bound of the random number to be generated.</param>
			/// <returns>Next random value.</returns>
			__forceinline int32_t NextInt(int32_t maxValue);

			/// <summary>
			/// Returns next 32-bit integer random value that is within a specified range.
			/// </summary>
			/// <param name="minValue">The inclusive lower bound of the random number returned.</param>
			/// <param name="maxValue">The exclusive upper bound of the random number to be generated.</param>
			/// <returns>Next random value.</returns>
			__forceinline int32_t NextInt(int32_t minValue, int32_t maxValue);

			/// <summary>
			/// Returns next 32-bit float random value that is less then the specified maximum.
			/// </summary>
			/// <param name="maxValue">The exclusive upper bound of the random number to be generated.</param>
			/// <returns>Next random value.</returns>
			/// <remarks>Default float range is [0.0f, 1.0f).  Max value is excluded.</remarks>
			__forceinline float NextFloat(float maxValue = 1.0f);
			
			/// <summary>
			/// Returns next 32-bit float random value that is within a specified range.
			/// </summary>
			/// <param name="minValue">The inclusive lower bound of the random number returned.</param>
			/// <param name="maxValue">The exclusive upper bound of the random number to be generated.</param>
			/// <returns>Next random value.</returns>
			__forceinline float NextFloat(float minValue, float maxValue);
			
			/// <summary>
			/// Initialize random generator using specified seed value.
			/// </summary>
			/// <param name="seed">A number used to calculate a starting value for the pseudo-random number generator.</param>
			__forceinline void SetSeed(uint32_t seed);
			
		private:
			std::random_device _randomDevice;
			std::minstd_rand _randomGenerator;
		};		

#include "random.inl"
	}
}

#endif