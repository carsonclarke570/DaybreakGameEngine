#ifndef _MATH_H_
#define _MATH_H_

#include "../utils/MathUtils.h"

#include <math.h>
#include <iostream>
#include <cmath>
#include <cstring>

namespace daybreak {

	namespace core {

		struct vec2 {
			float m_x, m_y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& sub(const vec2& other);
			vec2& mul(const vec2& other);
			vec2& div(const vec2& other);

			float length();
			vec2& normalize();

			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};

		struct vec3 {

			float m_x, m_y, m_z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& sub(const vec3& other);
			vec3& mul(const vec3& other);
			vec3& div(const vec3& other);

			vec3 lerp(const vec3& other, float frac) const;
			float dot(const vec3& other) const;
			vec3 cross(const vec3& other) const;

			float length() const;
			vec3 normalize() const;

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);

			friend vec3 operator+(vec3 left, const float& right);
			friend vec3 operator-(vec3 left, const float& right);
			friend vec3 operator*(vec3 left, const float& right);
			friend vec3 operator/(vec3 left, const float& right);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};

		struct vec4 {
			float m_x, m_y, m_z, m_w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& sub(const vec4& other);
			vec4& mul(const vec4& other);
			vec4& div(const vec4& other);

			float length();
			vec4& normalize();

			friend vec4 operator+(vec4 left, const vec4& right);
			friend vec4 operator-(vec4 left, const vec4& right);
			friend vec4 operator*(vec4 left, const vec4& right);
			friend vec4 operator/(vec4 left, const vec4& right);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		};

		struct Quaternion;

		struct mat4 {

			union {
				float elements[16];
				vec4 rows[4];
			};

			mat4();
			mat4(float diag);
			mat4(float* elements);
			mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3);

			static mat4 identity();

			mat4& mul(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			vec3 mul(const vec3& other) const;
			friend vec3 operator*(const mat4& left, const vec3& right);

			//vec4 mul(const vec4& other) const;
			//friend vec4 operator*(const mat4& left, const vec4& right);

			vec4 getColumn(int index) const;
			void setColumn(int index, const vec4& column);
			//inline vec3 getPosition() const { return vec3(getColumn(3)); }
			//inline void setPosition(const vec3& position) { setColumn(3, vec4(position, 1.0f)); }

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspect, float near, float far);
			static mat4 lookAt(const vec3& camera, const vec3& object, const vec3& up);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 rotation(const Quaternion& quat);
			static mat4 scale(const vec3& scale);

			static mat4 transpose(const mat4& matrix);
		};

		struct Quaternion {

			float m_x, m_y, m_z, m_w;

			Quaternion(float x, float y, float z, float w);
			Quaternion(const vec3& axis, float angle);

			float length() const;
			Quaternion normalize() const;
			Quaternion conjugate() const;

			Quaternion& mul(const Quaternion& other);

			mat4 toRotationMatrix();

			friend Quaternion operator*(Quaternion left, const Quaternion& right);
			friend Quaternion operator*(Quaternion left, const vec3& right);

			Quaternion& operator*=(const Quaternion& other);

			vec3 getForward();
			vec3 getBack();
			vec3 getRight();
			vec3 getLeft();
			vec3 getUp();
			vec3 getDown();

			inline float getX() { return m_x; }
			inline float getY() { return m_y; }
			inline float getZ() { return m_z; }
			inline float getW() { return m_w; }
		};

		
	}
}

#endif


