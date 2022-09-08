// 11.5 상속과 접근 지정자

// 클래스에서 멤버 변수를 외부에서 접근할 수 있는가를
// 접근 지정자(public, protected, private)를 통해 확인

#include <iostream>

class Base
{
public:
	int	m_public;

protected:
	int	m_protected;

private:
	int	m_private;
};

// public이 아니라 protected, private으로 상속하게 되면
// 외부에서 접근할 때, 더 제한된 방향으로 상속
// 내부에서는, 다음 상속받는 클래스 멤버를 제한하는 기능
class Derived : protected Base
{
public:
	Derived()
	{
		// : pulic Base
		// 가능
		m_public = 1;
		m_protected = 1;
		// 불가
		// error: 'm_private' is a private member of 'Base'
		m_private = 1;

		// : private Base
		// 부모 클래스에서 받아온 것을 강조하기 위해(헷갈릴 때) => Base::
		// 내부에서 접근할 때는 상관 없음
		// 가능
		Base::m_public = 2;
		Base::m_protected = 2;
		// 불가
		Base::m_private = 2;
	};
};

// 기능 1 : 자식 클래스 내부에서 접근 범위를 제한할 수 있음
// class Derived : protected Base 이기 떄문에
// m_private를 가져올 수 없음
// class Derived : private Base 이기 떄문에
// m_private, m_protected를 가져올 수 없음
class GrandChild : public Derived
{
public:
	GrandChild()
	{
		// private으로 상속받은 클래스에서는 모두 사용할 수 없음
		Derived::m_public = 1;
		Derived::m_protected = 1;
		Derived::m_private = 1;

		// protected로 상속받은 클래스에서는 private만 사용하지 못함
		// 가능
		Derived::m_public = 1;
		Derived::m_protected = 1;
		// 불가
		Derived::m_private = 1;
	};
};

int	main()
{
	Base	base;
	Derived	derived;

	// Base
	// 가능
	base.m_public = 1;
	// 불가
	// error: 'm_protected' is a protected member of 'Base'
	base.m_protected = 1;
	base.m_private = 1;

	// 기능 2 : 자식 클래스 외부에서 접근을 제한
	// Derived : public Base
	// 외부에서 접근할 때, 더 제한된 방향으로 public까지 허용
	// 가능
	derived.m_public = 2;
	// 불가
	derived.m_protected = 2;
	derived.m_private = 2;

	// Derived : protected Base
	// 외부에서 접근할 때, 더 제한된 방향으로 모두 비허용
	// 불가
	// error: 'm_public' is a protected member of 'Base'
	// note: constrained by protected inheritance here
	derived.m_public = 2;
	derived.m_protected = 2;
	derived.m_private = 2;

	return (0);
}