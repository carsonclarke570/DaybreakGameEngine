#include "mat4.h"

#include "Quaternion.h"

namespace daybreak {

	namespace math {

		mat4::mat4() {
			memset(elements, 0, sizeof(float) * 16);
		}

		mat4::mat4(float diag) {
			memset(elements, 0, sizeof(float) * 16);
			elements[0 + 0 * 4] = diag;
			elements[1 + 1 * 4] = diag;
			elements[2 + 2 * 4] = diag;
			elements[3 + 3 * 4] = diag;
		}

		mat4::mat4(float* elements) {
			memcpy(this->elements, elements, 4 * 4 * sizeof(float));
		}

		// WARNING: This function has not been tested
		mat4::mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3) {
			rows[0] = row0;
			rows[1] = row1;
			rows[2] = row2;
			rows[3] = row3;
		}

		mat4 mat4::identity() {
			return mat4(1.0f);
		}

		mat4& mat4::mul(const mat4& other) {
			float data[16];
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += elements[c + e * 4] * other.elements[e + r * 4];
					}
					data[c + r * 4] = sum;
				}
			}
			memcpy(elements, data, sizeof(float) * 16);
			return *this;
		}

		vec3 mat4::mul(const vec3& other) const {
			float x = rows[0].m_x * other.m_x + rows[0].m_y * other.m_y + rows[0].m_z * other.m_z + rows[0].m_w;
			float y = rows[1].m_x * other.m_x + rows[1].m_y * other.m_y + rows[1].m_z * other.m_z + rows[1].m_w;
			float z = rows[2].m_x * other.m_x + rows[2].m_y * other.m_y + rows[2].m_z * other.m_z + rows[2].m_w;

			return vec3(x, y, z);
		}

		mat4 operator*(mat4 left, const mat4& right) {
			return left.mul(right);
		}

		mat4& mat4::operator*=(const mat4& other) {
			return mul(other);
		}

		vec3 operator*(const mat4& left, const vec3& right) {
			return left.mul(right);
		}

		vec4 mat4::getColumn(int index) const {
			return vec4(elements[index + 0 * 4], elements[index + 1 * 4], elements[index + 2 * 4], elements[index + 3 * 4]);
		}

		void mat4::setColumn(int index, const vec4& column) {
			elements[index + 0 * 4] = column.m_x;
			elements[index + 1 * 4] = column.m_y;
			elements[index + 2 * 4] = column.m_z;
			elements[index + 3 * 4] = column.m_w;
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(float fov, float aspect, float near, float far) {
			mat4 result(1.0f);

			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspect;
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = c;

			return result;
		}

		// WARNING: This function has not been tested
		mat4 mat4::lookAt(const vec3& camera, const vec3& object, const vec3& up) {
			mat4 result = identity();
			vec3 f = (object - camera).normalize();
			vec3 s = f.cross(up.normalize());
			vec3 u = s.cross(f);

			result.elements[0 + 0 * 4] = s.m_x;
			result.elements[0 + 1 * 4] = s.m_y;
			result.elements[0 + 2 * 4] = s.m_z;

			result.elements[1 + 0 * 4] = u.m_x;
			result.elements[1 + 1 * 4] = u.m_y;
			result.elements[1 + 2 * 4] = u.m_z;

			result.elements[2 + 0 * 4] = -f.m_x;
			result.elements[2 + 1 * 4] = -f.m_y;
			result.elements[2 + 2 * 4] = -f.m_z;

			return result * translation(vec3(-camera.m_x, -camera.m_y, -camera.m_z));
		}

		mat4 mat4::translation(const vec3& translation) {
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.m_x;
			result.elements[1 + 3 * 4] = translation.m_y;
			result.elements[2 + 3 * 4] = translation.m_z;

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

			result.elements[0 + 0 * 4] = x * x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;
				  
			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;
				   
			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * z * omc + c;

			return result;
		}

		// WARNING: This function has not been tested
		mat4 mat4::rotation(const Quaternion& quat) {
			mat4 result = identity();

			float qx, qy, qz, qw, qx2, qy2, qz2, qxqx2, qyqy2, qzqz2, qxqy2, qyqz2, qzqw2, qxqz2, qyqw2, qxqw2;
			qx = quat.m_x;
			qy = quat.m_y;
			qz = quat.m_z;
			qw = quat.m_w;
			qx2 = (qx + qx);
			qy2 = (qy + qy);
			qz2 = (qz + qz);
			qxqx2 = (qx * qx2);
			qxqy2 = (qx * qy2);
			qxqz2 = (qx * qz2);
			qxqw2 = (qw * qx2);
			qyqy2 = (qy * qy2);
			qyqz2 = (qy * qz2);
			qyqw2 = (qw * qy2);
			qzqz2 = (qz * qz2);
			qzqw2 = (qw * qz2);

			result.rows[0] = vec4(((1.0f - qyqy2) - qzqz2), (qxqy2 - qzqw2), (qxqz2 + qyqw2), 0.0f);
			result.rows[1] = vec4((qxqy2 + qzqw2), ((1.0f - qxqx2) - qzqz2), (qyqz2 - qxqw2), 0.0f);
			result.rows[2] = vec4((qxqz2 - qyqw2), (qyqz2 + qxqw2), ((1.0f - qxqx2) - qyqy2), 0.0f);
			return result;
		}

		mat4 mat4::scale(const vec3& scale) {
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.m_x;
			result.elements[1 + 1 * 4] = scale.m_y;
			result.elements[2 + 2 * 4] = scale.m_z;

			return result;
		}

		// WARNING: This function has not been tested
		mat4 mat4::transpose(const mat4& matrix) {
			return mat4(
				vec4(matrix.rows[0].m_x, matrix.rows[1].m_x, matrix.rows[2].m_x, matrix.rows[3].m_x),
				vec4(matrix.rows[0].m_y, matrix.rows[1].m_y, matrix.rows[2].m_y, matrix.rows[3].m_y),
				vec4(matrix.rows[0].m_z, matrix.rows[1].m_z, matrix.rows[2].m_z, matrix.rows[3].m_z),
				vec4(matrix.rows[0].m_w, matrix.rows[1].m_w, matrix.rows[2].m_w, matrix.rows[3].m_w)
			);
		}
	}
}