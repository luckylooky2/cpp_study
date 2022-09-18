// 15_1_AutoPtr.hpp

#ifndef FIFTEEN_ONE_AUTOPTR_HPP
#define FIFTEEN_ONE_AUTOPTR_HPP

#include <iostream>

// C++ 98애 추가됨, C++ 11 사용하지 않고, C++ 17에서 제거
// std::auto_ptr<int>;
// 지금 예제에서는 여기서 위와 비슷하게 만드는 것
// why? 이 기능을 직접 구현해서 사용하는 사람들은 편한데 여러 복잡한 구조에서는 제대로 작동하지 않는 문제점
// r-value reference를 배우는데, 이것이 적용된 스마트 포인터를 사용하게 됨

template<class T>
class AutoPtr
{
public:
	T	*m_ptr = nullptr;

public:
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{	
	}

	// copy constructor
	AutoPtr(AutoPtr &a)
	{
		// double free 해결
		// 포인터를 l-value에 넘겨줌
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
	}

	~AutoPtr()
	{
		// 소멸자에서 nullptr가 아니면 지워버림
		// 이런 역할만 해줘도 상당히 편함
		if (m_ptr != nullptr) delete m_ptr;
	}

	// assignment operator
	AutoPtr& operator=(AutoPtr &a)
	{
		if (&a == this)
			return (this);
		delete m_ptr;
		// 소유권 이전
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return (*this);
	}

	// de-referencing operator
	T&		operator*() const { return (*m_ptr); }
	// member-selelction operator
	// 두 연산자로 진짜 포인터처럼 작동
	T*		operator->() const { return (m_ptr); }
	bool	isNull() const { return (m_ptr == nullptr); }
};

#endif