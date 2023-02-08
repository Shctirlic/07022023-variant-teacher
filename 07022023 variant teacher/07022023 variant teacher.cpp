#include <iostream>
#include <memory>
// auto ptr, weak ptr, unique ptr, shared ptr

class A {
public:
	//A(A &a) = delete;
	A() {
		std::cout << "Constructor A" << std::endl;
	}
	~A() {
		std::cout << "Destructor A" << std::endl;
	}
};

class Point {
public:
	Point(int x, int y) : _x(x), _y(y) {
		std::cout << "Point constructor" << std::endl;
	}

	int getX() const {
		return _x;
	}

	~Point() {
		std::cout << "Point destructor" << std::endl;
	}
private:
	int _x;
	int _y;

};

template <class T>
class SmartPtr {
	T* _ptr;
public:
	SmartPtr(T* t) : _ptr(t) {}

	T* operator->() {
		return _ptr; // _ptr->operator->
	}

	T* get() {
		return _ptr;
	}

	~SmartPtr() {
		delete _ptr;
	}
};

// template <typename T>
// auto_ptr {
// T * _ptrObj
// public:
// auto_ptr(T * ptrObj) : _ptrObj(ptrObj) {}

// unique_ptr почти как и любой пользовательский тип
// можно передавать в параметры функции по ссылке
//std::shared_ptr<Point> basicFunc(const std::unique_ptr<Point> &p) {
//	std::cout << p->getX() << std::endl;
//	std::shared_ptr<Point> sp2 = std::make_shared<Point>(55, 43);
//	return sp2;
//}
// std::shared_ptr<Point> sp3 = basicFunc(...)
//class Parent {};
//class Child : public Parent {};

// dynamic_cast<Point*>

class IVehicle {
public:
	virtual int getSpeed() const = 0;
	virtual const std::string& getType() const = 0;
	virtual ~IVehicle() {}
};

class Car : public IVehicle {
public:
	Car(int speed) : _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	const std::string& getType() const override {
		return _type;
	}
private:
	int _speed;
	std::string _type = "Car";
};

class Van : public Car {
public:
	Van(int speed) : Car(speed) {}
	const std::string& getType() const override {
		return _type;
	}
private:
	std::string _type = "Van";
};

void funcCar(std::shared_ptr<Car> carPtr) {
	std::cout << "Inside funcCar" << std::endl;
	std::cout << carPtr->getSpeed() << std::endl;
	std::cout << carPtr->getType() << std::endl;
}

int main() {
	std::shared_ptr<Van> v = std::make_shared<Van>(50);
	std::cout << v->getSpeed() << std::endl;
	std::cout << v->getType() << std::endl;
	std::cout << "--------------" << std::endl;
	// std::dynamic_pointer_cast<new-type>(object to cast)
	std::shared_ptr<Car> c = std::dynamic_pointer_cast<Car>(v);

	std::cout << c->getSpeed() << std::endl;
	std::cout << c->getType() << std::endl;
	std::cout << "-----------------" << std::endl;

	funcCar(c);
	// embedded
}

//int main()
//{
	// C++11: Deprecated, C++17 deleted
	//std::auto_ptr<A> p(new A());
	//std::auto_ptr<A> p2 = p;
	// 
	// shared_ptr - имеет контрольный блок, в котором
	// помимо прочего лежит счетчик указателей
	// unique_ptr - гарантирует, что только один указатель
	// будет владеть одним объектом

	//std::unique_ptr<A> uptr(new A());
	//std::unique_ptr<A> uptr2 = uptr;

	//std::unique_ptr<Point> pPoint(new Point(5, 4));
	//std::cout << pPoint->getX() << std::endl;
	//pPoint.get()->getX();
	//pPoint.release()
	//pPoint.reset()
	// cppreference


	/*SmartPtr<Point> sm(new Point(5,4));
	std::cout << sm->getX() << std::endl;*/
	//std::unique_ptr<Point> p5 = std::make_unique<Point>(5, 4);
	////p5 = std::make_unique<Point>(5, 4);

	//std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);

	//std::shared_ptr<Point> sp2 = sp1;


//}