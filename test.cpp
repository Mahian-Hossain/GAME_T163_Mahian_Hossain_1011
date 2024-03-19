#include <iostream>

template<typename T>
class Rectangle {
private:
    T length;
    T width;
public:
    Rectangle(T l, T w) : length(l), width(w) {}

    T getLength() const {
        return length;
    }

    void setLength(T l) {
        length = l;
    }

    T getWidth() const {
        return width;
    }

    void setWidth(T w) {
        width = w;
    }
};

template<typename T>
T Area(const Rectangle<T>& rect) {
    return rect.getLength() * rect.getWidth();
}

int main() {
    Rectangle<int> rect1(5, 10);
    Rectangle<float> rect2(2.5f, 3.75f);

    std::cout << "Rectangle 1: Width = " << rect1.getWidth() << ", Height = " << rect1.getLength() << std::endl;
    std::cout << "Rectangle 2: Width = " << rect2.getWidth() << ", Height = " << rect2.getLength() << std::endl;
    std::cout << "Area of Rectangle 1: " << Area(rect1) << std::endl;
    std::cout << "Area of Rectangle 2: " << Area(rect2) << std::endl;

    return 0;
}
