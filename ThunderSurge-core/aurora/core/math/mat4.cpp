#include "mat4.h"

namespace aurora {

	namespace math {

		mat4::mat4() {
			memset(m_m, 0, sizeof(float) * 16);
		}

		mat4::mat4(float diag) {
			memset(m_m, 0, sizeof(float) * 16);
			m_m[0 + 0 * 4] = diag;
			m_m[1 + 1 * 4] = diag;
			m_m[2 + 2 * 4] = diag;
			m_m[3 + 3 * 4] = diag;
		}

		mat4 mat4::identity() {
			return mat4(1.0f);
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			mat4 result(1.0f);

			result.m_m[0 + 0 * 4] = 2.0f / (right - left);
			result.m_m[1 + 1 * 4] = 2.0f / (top - bottom);
			result.m_m[2 + 2 * 4] = 2.0f / (near - far);

			result.m_m[0 + 3 * 4] = (left + right) / (left - right);
			result.m_m[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.m_m[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(float fov, float aspect, float near, float far) {
			mat4 result(1.0f);

			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspect;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.m_m[0 + 0 * 4] = a;
			result.m_m[1 + 1 * 4] = q;
			result.m_m[2 + 2 * 4] = b;
			result.m_m[3 + 2 * 4] = -1.0f;
			result.m_m[2 + 3 * 4] = c;

			return result;
		}

		mat4 mat4::translation(const vec3& translation) {
			mat4 result(1.0f);

			result.m_m[0 + 3 * 4] = translation.m_x;
			result.m_m[1 + 3 * 4] = translation.m_y;
			result.m_m[2 + 3 * 4] = translation.m_z;

			return result;
		}

		mat4 mat4::rotation(float angle, const vec3& axis) {
			mat4 result(1.0f);

			float rad = toRadians(angle);
			float c = cos(rad);
			float s = sin(rad);
			float omc = 1.0f - c;

			float x = axis.m_x;
			float y = axis.m_y;
			float z = axis.m_z;

			result.m_m[0 + 0 * 4] = x * x * omc + c;
			result.m_m[1 + 0 * 4] = y * x * omc + z * s;
			result.m_m[2 + 0 * 4] = x * z * omc - y * s;

			result.m_m[0 + 1 * 4] = x * y * omc - z * s;
			result.m_m[1 + 1 * 4] = y * y * omc + c;
			result.m_m[2 + 1 * 4] = y * z * omc + x * s;

			result.m_m[0 + 2 * 4] = x * z * omc + y * s;
			result.m_m[1 + 2 * 4] = y * z * omc - x * s;
			result.m_m[2 + 2 * 4] = z * z * omc + c;

			return result;
		}

		mat4 mat4::rotation(const vec3& forward, const vec3& up, const vec3& right) {
			mat4 result(1.0f);
			
			result.m_m[0 + 0 * 4] = right.m_x;
			result.m_m[1 + 0 * 4] = up.m_x;
			result.m_m[2 + 0 * 4] = forward.m_x;

			result.m_m[0 + 1 * 4] = right.m_y;
			result.m_m[1 + 1 * 4] = up.m_y;
			result.m_m[2 + 1 * 4] = forward.m_y;

			result.m_m[0 + 2 * 4] = right.m_z;
			result.m_m[1 + 2 * 4] = up.m_z;
			result.m_m[2 + 2 * 4] = forward.m_z;

			return result;
		}

		mat4 mat4::scale(const vec3& scale) {
			mat4 result(1.0f);

			result.m_m[0 + 0 * 4] = scale.m_x;
			result.m_m[1 + 1 * 4] = scale.m_y;
			result.m_m[2 + 2 * 4] = scale.m_z;

			return result;
		}

		mat4 mat4::camera(const vec3& forward, const vec3& up) {
			vec3 r = up.cross(forward).normalize();
			mat4 result(1.0f);

			result.m_m[0 + 0 * 4] = r.m_x;
			result.m_m[1 + 0 * 4] = up.m_x;
			result.m_m[2 + 0 * 4] = forward.m_x;

			result.m_m[0 + 1 * 4] = r.m_y;
			result.m_m[1 + 1 * 4] = up.m_y;
			result.m_m[2 + 1 * 4] = forward.m_y;

			result.m_m[0 + 2 * 4] = r.m_z;
			result.m_m[1 + 2 * 4] = up.m_z;
			result.m_m[2 + 2 * 4] = forward.m_z;

			return result;
		}

		mat4& mat4::mul(const mat4& other) {
			float data[16];
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += m_m[c + e * 4] * other.m_m[e + r * 4];
					}
					data[c + r * 4] = sum;
				}
			}
			memcpy(m_m, data, sizeof(float) * 16);
			return *this;
		}

		vec3 mat4::mul(const vec3& other) {
			float x = m_m[0 + 0 * 4] * other.m_x + m_m[0 + 1 * 4] * other.m_y + m_m[0 + 2 * 4] * other.m_z + m_m[0 + 3 * 4];
			float y = m_m[1 + 0 * 4] * other.m_x + m_m[1 + 1 * 4] * other.m_y + m_m[1 + 2 * 4] * other.m_z + m_m[1 + 3 * 4];
			float z = m_m[2 + 0 * 4] * other.m_x + m_m[2 + 1 * 4] * other.m_y + m_m[2 + 2 * 4] * other.m_z + m_m[2 + 3 * 4];

			return vec3(x, y, z);
		}

		mat4 operator*(mat4 left, const mat4& right) {
			return left.mul(right);
		}

		vec3 operator*(mat4 left, const vec3& right) {
			return left.mul(right);
		}

		mat4& mat4::operator*=(const mat4& other) {
			return mul(other);
		}

		vec3 mat4::operator*=(const vec3& other) {
			return mul(other);
		}
	}
}