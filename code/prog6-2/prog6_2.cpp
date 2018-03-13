class Circle;//前向声明；

class Point {
	friend class Circle;
private:
	double m_x = 0, m_y = 0;//x和y的坐标；
};

class Circle {
	Point m_center;//圆心
	double m_radius = 1.0;//半径；
public:
	void moveXTo(double val) {//将圆心沿着x轴移到指定处；
		m_center.m_x = val;//直接访问Point私有成员；
	}
};

int main() {
	Circle a;
	a.moveXTo(1);
}