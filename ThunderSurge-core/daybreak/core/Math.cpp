#include "Math.h"

namespace daybreak {
	
	namespace core {

		vec2::vec2() {
			m_x = 0.0f;
			m_y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y) {
			m_x = x;
			m_y = y;
		}

		vec2& vec2::add(const vec2& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			return *this;
		}

		vec2& vec2::sub(const vec2& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			return *this;
		}

		vec2& vec2::mul(const vec2& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			return *this;
		}

		vec2& vec2::div(const vec2& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			return *this;
		}

		float vec2::length() {
			return sqrt(m_x * m_x + m_y * m_y);
		}

		vec2& vec2::normalize() {
			float len = length();
			m_x /= len;
			m_y /= len;
			return *this;
		}

		vec2 operator+(vec2 left, const vec2& right) {
			return left.add(right);
		}

		vec2 operator-(vec2 left, const vec2& right) {
			return left.sub(right);
		}

		vec2 operator*(vec2 left, const vec2& right) {
			return left.mul(right);
		}

		vec2 operator/(vec2 left, const vec2& right) {
			return left.div(right);
		}

		bool vec2::operator==(const vec2& other) {
			return m_x == other.m_x && m_y == other.m_y;
		}

		bool vec2::operator!=(const vec2& other) {
			return !(*this == other);
		}

		vec2& vec2::operator+=(const vec2& other) {
			return add(other);
		}

		vec2& vec2::operator-=(const vec2& other) {
			return sub(other);
		}

		vec2& vec2::operator*=(const vec2& other) {
			return mul(other);
		}

		vec2& vec2::operator/=(const vec2& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec2& vector) {
			stream << "vec2: (" << vector.m_x << ", " << vector.m_y << ")";
			return stream;
		}

		vec3::vec3() {
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f;
		}

		vec3::vec3(const float& x, const float& y, const float& z) {
			m_x = x;
			m_y = y;
			m_z = z;
		}

		vec3& vec3::add(const vec3& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			m_z += other.m_z;
			return *this;
		}

		vec3& vec3::sub(const vec3& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			m_z -= other.m_z;
			return *this;
		}

		vec3& vec3::mul(const vec3& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			m_z *= other.m_z;
			return *this;
		}

		vec3& vec3::div(const vec3& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			m_z /= other.m_z;
			return *this;
		}

		vec3 vec3::lerp(const vec3& other, float frac) const {
			float x = (1 - frac) * m_x + frac * other.m_x;
			float y = (1 - frac) * m_y + frac * other.m_y;
			float z = (1 - frac) * m_z + frac * other.m_z;
			return vec3(x, y, z);
		}

		float vec3::dot(const vec3& other) const {
			return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
		}

		vec3 vec3::cross(const vec3& other) const {
			float x = m_y * other.m_z - m_z * other.m_y;
			float y = m_z * other.m_x - m_x * other.m_z;
			float z = m_x * other.m_y - m_y * other.m_x;

			return vec3(x, y, z);
		}

		float vec3::length() const {
			return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
		}

		vec3 vec3::normalize() const {
			float len = length();
			return vec3(m_x / len, m_y / len, m_z / len);
		}

		vec3 operator+(vec3 left, const vec3& right) {
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right) {
			return left.sub(right);
		}

		vec3 operator*(vec3 left, const vec3& right) {
			return left.mul(right);
		}

		vec3 operator/(vec3 left, const vec3& right) {
			return left.div(right);
		}

		vec3 operator+(vec3 left, const float& right) {
			return left.add(vec3(right, right, right));
		}

		vec3 operator-(vec3 left, const float& right) {
			return left.sub(vec3(right, right, right));
		}

		vec3 operator*(vec3 left, const float& right) {
			return left.mul(vec3(right, right, right));
		}

		vec3 operator/(vec3 left, const float& right) {
			return left.div(vec3(right, right, right));
		}

		bool vec3::operator==(const vec3& other) {
			return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
		}

		bool vec3::operator!=(const vec3& other) {
			return !(*this == other);
		}

		vec3& vec3::operator+=(const vec3& other) {
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other) {
			return sub(other);
		}

		vec3& vec3::operator*=(const vec3& other) {
			return mul(other);
		}

		vec3& vec3::operator/=(const vec3& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
			stream << "vec3: (" << vector.m_x << ", " << vector.m_y << ", " << vector.m_z << ")";
			return stream;
		}

		vec4::vec4() {
			m_x = 0.0f;
			m_y = 0.0f;
			m_z = 0.0f;
			m_w = 0.0f;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			m_x = x;
			m_y = y;
			m_z = z;
			m_w = w;
		}

		vec4& vec4::add(const vec4& other) {
			m_x += other.m_x;
			m_y += other.m_y;
			m_z += other.m_z;
			m_w += other.m_w;
			return *this;
		}

		vec4& vec4::sub(const vec4& other) {
			m_x -= other.m_x;
			m_y -= other.m_y;
			m_z -= other.m_z;
			m_w -= other.m_w;
			return *this;
		}

		vec4& vec4::mul(const vec4& other) {
			m_x *= other.m_x;
			m_y *= other.m_y;
			m_z *= other.m_z;
			m_w *= other.m_w;
			return *this;
		}

		vec4& vec4::div(const vec4& other) {
			m_x /= other.m_x;
			m_y /= other.m_y;
			m_z /= other.m_z;
			m_w /= other.m_w;
			return *this;
		}

		float vec4::length() {
			return sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
		}

		vec4& vec4::normalize() {
			float len = length();
			m_x /= len;
			m_y /= len;
			m_z /= len;
			m_w /= len;
			return *this;
		}

		vec4 operator+(vec4 left, const vec4& right) {
			return left.add(right);
		}

		vec4 operator-(vec4 left, const vec4& right) {
			return left.sub(right);
		}

		vec4 operator*(vec4 left, const vec4& right) {
			return left.mul(right);
		}

		vec4 operator/(vec4 left, const vec4& right) {
			return left.div(right);
		}

		bool vec4::operator==(const vec4& other) {
			return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z && m_w == other.m_w;
		}

		bool vec4::operator!=(const vec4& other) {
			return !(*this == other);
		}

		vec4& vec4::operator+=(const vec4& other) {
			return add(other);
		}

		vec4& vec4::operator-=(const vec4& other) {
			return sub(other);
		}

		vec4& vec4::operator*=(const vec4& other) {
			return mul(other);
		}

		vec4& vec4::operator/=(const vec4& other) {
			return div(other);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
			stream << "vec4: (" << vector.m_x << ", " << vector.m_y << ", " << vector.m_z << ", " << vector.m_w << ")";
			return stream;
		}

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

		Quaternion::Quaternion(float x, float y, float z, float w) :
			m_x(x), m_y(y), m_z(z), m_w(w) {
		}

		Quaternion::Quaternion(const vec3& axis, float angle) {
			float s = sinf(toRadians(angle / 2));

			m_x = axis.m_x * s;
			m_y = axis.m_y * s;
			m_z = axis.m_z * s;
			m_w = cosf(toRadians(angle / 2));
		}

		float Quaternion::length() const {
			return (float)sqrt(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w);
		}

		Quaternion Quaternion::normalize() const {
			float len = length();
			return Quaternion(m_x / len, m_y / len, m_z / len, m_w / len);
		}

		Quaternion Quaternion::conjugate() const {
			return Quaternion(-m_x, -m_y, -m_z, m_w);
		}

		Quaternion& Quaternion::mul(const Quaternion& other) {
			float w = m_w * other.m_w - m_x * other.m_x - m_y * other.m_y - m_z * other.m_z;
			float x = m_x * other.m_w + m_w * other.m_x + m_y * other.m_z - m_z * other.m_y;
			float y = m_y * other.m_w + m_w * other.m_y + m_z * other.m_x - m_x * other.m_z;
			float z = m_z * other.m_w + m_w * other.m_z + m_x * other.m_y - m_y * other.m_x;

			m_w = w;
			m_x = x;
			m_y = y;
			m_z = z;

			return *this;
		}

		mat4 Quaternion::toRotationMatrix() {
			return mat4::rotation(*this);
		}

		vec3 Quaternion::getForward() {
			return getBack() * vec3(-1, -1, -1);
		}

		vec3 Quaternion::getBack() {
			return vec3(2.0f * (m_x * m_z - m_w * m_y), 2.0f * (m_y * m_z + m_w * m_x), 1.0f - 2.0f * (m_x * m_x + m_y * m_y));
		}

		vec3 Quaternion::getRight() {
			return vec3(1.0f - 2.0f * (m_y * m_y + m_z * m_z), 2.0f * (m_x * m_y - m_w * m_z), 2.0f * (m_x * m_z + m_w * m_y));
		}

		vec3 Quaternion::getLeft() {
			return getRight() * vec3(-1, -1, -1);
		}

		vec3 Quaternion::getUp() {
			return vec3(2.0f * (m_x * m_y + m_w * m_z), 1.0f - 2.0f * (m_x * m_x + m_z * m_z), 2.0f * (m_y * m_z - m_w * m_x));
		}

		vec3 Quaternion::getDown() {
			return getUp() * vec3(-1, -1, -1);
		}

		Quaternion& Quaternion::operator*=(const Quaternion& other) {
			return mul(other);
		}

		Quaternion operator*(Quaternion left, const Quaternion& right) {
			return left.mul(right);
		}

		Quaternion operator*(Quaternion left, const vec3& right) {
			float w = -left.getX() * right.m_x - left.getY() * right.m_y - left.getZ() * right.m_z;
			float x = left.getW() * right.m_x + left.getY() * right.m_z - left.getZ() * right.m_y;
			float y = left.getW() * right.m_y + left.getZ() * right.m_x - left.getX() * right.m_z;
			float z = left.getW() * right.m_z + left.getX() * right.m_y - left.getY() * right.m_x;

			return Quaternion(x, y, z, w);
		}
	}
}