/// <summary>
/// OpenGM library header.
/// </summary>
/// <author>Stanislav A. Kychanov (kychanov.sa@gmail.com)</author>
/// <created>14-06-2005</created>
/// <copyright>Copyright 2005-2024 Glacial Bytes. All Rights reserved.</copyright>
/// <notes></<notes>
#ifndef GM_H
#define GM_H

#include <stdint.h>
#include <math.h>
#include <xmmintrin.h>

#pragma warning(disable : 4522)

namespace GlacialBytes
{
  namespace OpenGm
  {
#ifdef GM_BUILDING_LIB
#define GMAPI
#else
#define GMAPI extern
#endif

#pragma region Compiler specific stuff
#if defined(_MSC_VER)
#ifndef FASTCALL
#	define FASTCALL __fastcall
#endif
#ifndef INLINE
#	define INLINE __forceinline
#endif
#ifndef STDCALL
#	define STDCALL __stdcall
#endif
#ifndef CDECL
#	define CDECL __cdecl
#endif
#if _MSVC_LANG > 201402L
#	define NODISCARD			[[nodiscard]]
#else
#	define NODISCARD
#endif
#	define DECLALIGN16			__declspec(align(16))
#	define DECLALIGN32			__declspec(align(32))
#	define DECLALIGN64			__declspec(align(64))
#ifndef NOTHROW
#	define NOTHROW				__declspec(nothrow)
#endif
#endif
#pragma endregion

#pragma region Constants
    /// <summary>
    /// Значение π.
    /// </summary>
    const float GM_PI = 3.1415926535897932384626433832795028841971693993751f;

    /// <summary>
    /// Значение 1/π
    /// </summary>
    const float GM_1BYPI = 0.31830988618379067153776752674508f;

    /// <summary>
    /// Значение корень из 2.
    /// </summary>
    const float GM_SQRT2 = 1.4142135623730950488016887242096980785696718753769f;

    /// <summary>
    /// Значение 2*π
    /// </summary>
    const float GM_2PI = 2.0f * GM_PI;

    /// <summary>
    /// Значение π/2
    /// </summary>
    const float GM_PI2 = GM_PI * 0.5f;

    /// <summary>
    /// Значение ε.
    /// </summary>
    const float GM_EPS = 1e-12f;

    /// <summary>
    /// Значение ε^2.
    /// </summary>
    const float GM_EPSPOW2 = GM_EPS * GM_EPS;

    /// <summary>
    /// Максимальное значение float.
    /// </summary>
    const float GM_MAXFLOAT = 1.0e+38f;

    /// <summary>
    /// Значение 1.0f как целое.
    /// </summary>
    const uint32_t GM_1_AS_INT = 0x3F800000;
#pragma endregion

#pragma region Type definitions
    /// <summary>
    /// Двухмерный вектор из float.
    /// </summary>
    struct _float2;

    /// <summary>
    /// Трёхмерный вектор из float.
    /// </summary>
    struct _float3;

    /// <summary>
    /// Четырёхмерный вектор из float.
    /// </summary>
    struct _float4;

#include "gmshuf.h"
#include "gmtypes.h"

    /// <summary>
    /// Двухмерный вектор из float выровненный по границе 16 байт.
    /// </summary>
    typedef _float2		 __declspec(align(16)) float2;

    /// <summary>
    /// Трёхмерный вектор из float выровненный по границе 16 байт.
    /// </summary>
    typedef _float3		 __declspec(align(16)) float3;

    /// <summary>
    /// Четырёхмерный вектор из float выровненный по границе 16 байт.
    /// </summary>
    typedef _float4		 __declspec(align(16)) float4;

    /// <summary>
    /// Матрица 2х2 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float2x2	 __declspec(align(16)) float2x2;

    /// <summary>
    /// Матрица 2х3 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float2x3	 __declspec(align(16)) float2x3;

    /// <summary>
    /// Матрица 2х4 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float2x4	 __declspec(align(16)) float2x4;

    /// <summary>
    /// Матрица 3х2 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float3x2	 __declspec(align(16)) float3x2;

    /// <summary>
    /// Матрица 3х3 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float3x3	 __declspec(align(16)) float3x3;

    /// <summary>
    /// Матрица 3х4 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float3x4	 __declspec(align(16)) float3x4;

    /// <summary>
    /// Матрица 4х2 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float4x2	 __declspec(align(16)) float4x2;

    /// <summary>
    /// Матрица 4х3 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float4x3	 __declspec(align(16)) float4x3;

    /// <summary>
    /// Матрица 4х4 из float выровненная по границе 16 байт.
    /// </summary>
    typedef _float4x4	 __declspec(align(16)) float4x4;

    /// <summary>
    /// 16-битное число с плавающей точкой.
    /// </summary>
    typedef int16_t float16;

    /// <summary>
    /// Модель трансформации перемещения, поворота и масштабирования.
    /// </summary>
    typedef _float4x3 xform3d;

#include "gmshuf.inl"
#include "gmtypes.inl"
#pragma endregion

#pragma region Functions
#include "gmfuncs_clang.h"
#include "gmfuncs_fpu.h"
#include "gmfuncs_sse.h"

    /// <summary>
    /// Абсолютное значение компонент вектора.
    /// </summary>
    constexpr auto& abs2 = abs2_clang;

    /// <summary>
    /// Абсолютное значение компонент вектора.
    /// </summary>
    constexpr auto& abs3 = abs3_clang;

    /// <summary>
    /// Абсолютное значение компонент вектора.
    /// </summary>
    constexpr auto& abs4 = abs4_clang;

    /// <summary>
    /// Возвращает true, если все компоненты верктора не равны нулю.
    /// </summary>
    constexpr auto& all2 = all2_clang;

    /// <summary>
    /// Возвращает true, если все компоненты верктора не равны нулю.
    /// </summary>
    constexpr auto& all3 = all3_clang;

    /// <summary>
    /// Возвращает true, если все компоненты верктора не равны нулю.
    /// </summary>
    constexpr auto& all4 = all4_clang;

    /// <summary>
    /// Возвращает true, если хоть один компонент верктора не равен нулю.
    /// </summary>
    constexpr auto& any2 = any2_clang;

    /// <summary>
    /// Возвращает true, если хоть один компонент верктора не равен нулю.
    /// </summary>
    constexpr auto& any3 = any3_clang;

    /// <summary>
    /// Возвращает true, если хоть один компонент верктора не равен нулю.
    /// </summary>
    constexpr auto& any4 = any4_clang;

    /// <summary>
    /// Приводит компоненты вектора к наименьшему целому числу, которое большее или равно значению компоненты.
    /// </summary>
    constexpr auto& ceil2 = ceil2_clang;

    /// <summary>
    /// Приводит компоненты вектора к наименьшему целому числу, которое большее или равно значению компоненты.
    /// </summary>
    constexpr auto& ceil3 = ceil3_clang;

    /// <summary>
    /// Приводит компоненты вектора к наименьшему целому числу, которое большее или равно значению компоненты.
    /// </summary>
    constexpr auto& ceil4 = ceil4_clang;

    /// <summary>
    /// Векторное произведение.
    /// </summary>
    constexpr auto& cross3 = cross3_clang;

    /// <summary>
    /// Векторное произведение. Компонента w будет равна 1.0.
    /// </summary>
    constexpr auto& cross4 = cross4_clang;

    /// <summary>
    /// Рассчитывает детерминант матрицы.
    /// </summary>
    constexpr auto& determinant2x2 = determinant2x2_clang;

    /// <summary>
    /// Рассчитывает детерминант матрицы.
    /// </summary>
    constexpr auto& determinant3x3 = determinant3x3_clang;

    /// <summary>
    /// Рассчитывает детерминант матрицы.
    /// </summary>
    constexpr auto& determinant4x4 = determinant4x4_clang;

    /// <summary>
    /// Рассчитывает расстояние между двумя точками на плоскости.
    /// </summary>
    constexpr auto& distance2 = distance2_clang;

    /// <summary>
    /// Рассчитывает расстояние между двумя точками в объёме.
    /// </summary>
    constexpr auto& distance3 = distance3_clang;

    /// <summary>
    /// Рассчитывает расстояние между двумя точками в объёме. Координата w игнорируется.
    /// </summary>
    constexpr auto& distance4 = distance4_clang;

    /// <summary>
    /// Возвращает вектор коэффициентов дистанции равный [1.0f, d, d*d, 1.0f / d].
    /// </summary>
    constexpr auto& dst = dst_clang;

    /// <summary>
    /// Скалярное произведение.
    /// </summary>
    constexpr auto& dot2 = dot2_clang;

    /// <summary>
    /// Скалярное произведение.
    /// </summary>
    constexpr auto& dot3 = dot3_clang;

    /// <summary>
    /// Скалярное произведение.
    /// </summary>
    constexpr auto& dot4 = dot4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& faceforward2 = faceforward2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& faceforward3 = faceforward3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& faceforward4 = faceforward4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& floor2 = floor2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& floor3 = floor3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& floor4 = floor4_clang;

    /// <summary>
    /// Вычисляет обратную матрицу 2x2.
    /// </summary>
    /// <param name="m">Исходная матрица.</param>
    /// <returns>Обратная матрица.</returns>
    constexpr auto& inverse2x2 = inverse2x2_clang;

    /// <summary>
    /// Вычисляет обратную матрицу 3x3.
    /// </summary>
    /// <param name="m">Исходная матрица.</param>
    /// <returns>Обратная матрица.</returns>
    constexpr auto& inverse3x3 = inverse3x3_clang;

    /// <summary>
    /// Вычисляет обратную матрицу 4x4.
    /// </summary>
    /// <param name="m">Исходная матрица.</param>
    /// <returns>Обратная матрица.</returns>
    constexpr auto& inverse4x4 = inverse4x4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& length2 = length2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& length3 = length3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& length4 = length4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& lerp2 = lerp2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& lerp3 = lerp3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& lerp4 = lerp4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mad2 = mad2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mad3 = mad3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mad4 = mad4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul2x2 = mul2x2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul3x3 = mul3x3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul4x4 = mul4x4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul2 = mul2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul3 = mul3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul4 = mul4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& mul43 = mul43_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& normalize2 = normalize2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& normalize3 = normalize3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& normalize4 = normalize4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& normal3 = normal3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& reflect2 = reflect2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& reflect3 = reflect3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& reflect4 = reflect4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& refract2 = refract2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& refract3 = refract3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& refract4 = refract4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& round2 = round2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& round3 = round3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& round4 = round4_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& transpose2x2 = transpose2x2_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& transpose3x3 = transpose3x3_clang;

    /// <summary>
    /// 
    /// </summary>
    constexpr auto& transpose4x4a = transpose4x4_clang;

    /// <summary>
    /// Returns max of two values.
    /// </summary>
    INLINE float fmax2(float x, float y);

    /// <summary>
    /// Returns max of three values.
    /// </summary>
    INLINE float fmax3(float x, float y, float z);

    /// <summary>
    /// Returns max of four values.
    /// </summary>
    INLINE float fmax4(float x, float y, float z, float w);

    /// <summary>
    /// Returns max of min values.
    /// </summary>
    INLINE float fmin2(float x, float y);

    /// <summary>
    /// Returns max of three values.
    /// </summary>
    INLINE float fmin3(float x, float y, float z);

    /// <summary>
    /// Returns max of four values.
    /// </summary>
    INLINE float fmin4(float x, float y, float z, float w);

    /// <summary>
    /// Returns sing of value.
    /// </summary>
    INLINE float fsign(float f);

    /// <summary>
    /// Returns reciprocal square root.
    /// </summary>
    INLINE float frsqrt(const float& f);

#include "gmfuncs.inl"

    /// <summary>
    /// Функции конвертирования.
    /// </summary>
    class Convert
    {
    public:
      /// <summary>
      /// Конвертирует число с плавающей точкой в целое.
      /// </summary>
      /// <param name="value"></param>
      /// <returns></returns>
      static INLINE int FASTCALL FloatToInt(const float value) noexcept;

      /// <summary>
      /// Конвертирует число в число с плавающей точкой.
      /// </summary>
      /// <param name="value"></param>
      /// <returns></returns>
      static INLINE float FASTCALL IntToFloat(const int value) noexcept;

      /// <summary>
      /// Конвертирует число с плавающей точкой 32-битной точности в число с плавающей точкой 16-битной точности.
      /// </summary>
      /// <param name="value"></param>
      /// <returns></returns>
      static INLINE float16 FASTCALL FloatToHalf(const float value) noexcept;

      /// <summary>
      /// Конвертирует число с плавающей точкой 16-битной точности в число с плавающей точкой 32-битной точности.
      /// </summary>
      /// <param name="value"></param>
      /// <returns></returns>
      static INLINE float FASTCALL HalfToFloat(const float16 value) noexcept;

      /// <summary>
      /// Переводит градусы в радианы.
      /// </summary>
      /// <param name="value">Значение в градусах.</param>
      /// <returns>Значение в радианах.</returns>
      static INLINE float FASTCALL DegreesToRadians(const float value) noexcept;

      /// <summary>
      /// Переводит радианы в градусы.
      /// </summary>
      /// <param name="value">Значение в радианах.</param>
      /// <returns>Значение в градусах.</returns>
      static INLINE float FASTCALL RadiansToDegrees(const float value) noexcept;

      /// <summary>
      /// Распаковывает ARGBG значение из двойного слова в вектор.
      /// </summary>
      /// <param name="value">ARGB значение.</param>
      /// <returns>Вектор цвета.</returns>
      static INLINE float4 FASTCALL ARGBToFloat4(const uint32_t value) noexcept;

      /// <summary>
      /// Упаковывает цветовой вектор в ARGB значение в виде двойного слова.
      /// </summary>
      /// <param name="value">Вектор цвета.</param>
      /// <returns>ARGB значение.</returns>
      static INLINE uint32_t FASTCALL Float4ToARGB(const float4& value) noexcept;

      /// <summary>
      /// Распаковывает RGBE значение из двойного слова в вектор.
      /// </summary>
      /// <param name="value">RGBE значение.</param>
      /// <returns>Вектор цвета.</returns>
      static INLINE float4 FASTCALL RGBEToFloat4(const uint32_t value) noexcept;

      /// <summary>
      /// Упаковывает цветовой вектор в RGBE значение в виде двойного слова.
      /// </summary>
      /// <param name="value">Вектор цвета.</param>
      /// <returns>RGBE значение.</returns>
      static INLINE uint32_t FASTCALL Float4ToRGBE(const float4& value) noexcept;

      /// <summary>
      /// Упаковывает вектор нормали в UDEC3 значение.
      /// </summary>
      /// <param name="value">Вектор нормали.</param>
      /// <returns>UDEC3 значение</returns>
      static INLINE uint32_t FASTCALL Float3ToUDEC3(const float3& value) noexcept;

      /// <summary>
      /// Упаковывает вектор нормали в DEC3N значение.
      /// </summary>
      /// <param name="value">Вектор нормали.</param>
      /// <returns>DEC3N значение.</returns>
      static INLINE int32_t FASTCALL Float3ToDEC3N(const float3& value) noexcept;

    private:
      static const __declspec(align(16)) float rad2deg;
      static const __declspec(align(16)) float deg2rad;
    };
#include "gmconvert.inl"

#pragma endregion
  }
}

#endif // GM_H