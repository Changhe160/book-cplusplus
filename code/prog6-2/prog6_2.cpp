class Circle;//ǰ��������

class Point {
	friend class Circle;
private:
	double m_x = 0, m_y = 0;//x��y�����ꣻ
};

class Circle {
	Point m_center;//Բ��
	double m_radius = 1.0;//�뾶��
public:
	void moveXTo(double val) {//��Բ������x���Ƶ�ָ������
		m_center.m_x = val;//ֱ�ӷ���Point˽�г�Ա��
	}
};

int main() {
	Circle a;
	a.moveXTo(1);
}