#ifndef BASE_MATH_VECTOR2_H
#define BASE_MATH_VECTOR2_H


#include <cmath>


namespace base::math {
template<typename T>
class Vector2 {
    template<class> friend class Vector2;
public:
    union {
        struct {
            T x;
            T y;
        };
        T v[2];
    };
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Vector2() :
        x(),
        y() {
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <param name="obj"></param>
    Vector2(const Vector2& obj) {
        this->x = obj.x;
        this->y = obj.y;
    }
};

template<typename T, typename U = T>
float Distance(const Vector2<T>& a, const Vector2<U>& b) {
    auto dx = a.x - b.x;
    auto dy = a.y - b.y;

    float d = (dx * dx) + (dy * dy);
    return std::sqrt(d);
}

using Vector2S = Vector2<short>;
using Vector2U = Vector2<unsigned int>;
using Vector2I = Vector2<int>;
using Vector2F = Vector2<float>;
using Vector2L = Vector2<long>;
}
#endif // !BASE_MATH_VECTOR2_H