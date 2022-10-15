// 15_3_AutoPtr.hpp

#ifndef FIFTEEN_THREE_AUTOPTR_HPP
#define FIFTEEN_THREE_AUTOPTR_HPP

#include <iostream>

template<class T>
class AutoPtr
{
public:
	T	*m_ptr = nullptr;

public:
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{	
		std::cout << "class AutoPtr default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "class AutoPtr destructor" << std::endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	// value semantics(copy semantics)
	// copy constructor
	AutoPtr(const AutoPtr &a)
	{
		std::cout << "class AutoPtr copy constructor" << std::endl;
		// m_ptr = a.m_ptr;
		// a.m_ptr = nullptr;
		// deep copy
		m_ptr = new T;
		// Resource class의 assignment operator overloading
		*m_ptr = *a.m_ptr;
	}

	// assignment operator
	// if no const argument : error: no viable overloaded '='
	// note: candidate function not viable: expects an lvalue for 1st argument
	AutoPtr& operator=(const AutoPtr &a)
	{
		std::cout << "class AutoPtr copy assignment" << std::endl;
		if (&a == this)
			// 그냥 this를 반환한다면 => 포인터이기 때문
			// error: non-const lvalue reference to type 'AutoPtr<Resource>' 
			// cannot bind to a temporary of type 'AutoPtr<Resource> *'
			return (*this);
		if (m_ptr != nullptr) delete m_ptr;
		// deep copy
		m_ptr = new T;
		// Resource class의 assignment operator overloading
		*m_ptr = *a.m_ptr;
		return (*this);
	}

	// move semantics(move)
	// move constructor
	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr)
	{
		// really necessary?
		// 위험 부담을 줄이기 위해 넣는 것이 좋다
		// 지우는 것을 수행하지 않도록
		a.m_ptr = nullptr;

		std::cout << "AuotPtr move constructor" << std::endl;
	}

	// move operator
	// && : 메모리에 자리잡는 것이 아니고 잠깐 생겼다가 사라질 것이다라는 것을 의미
	// 그냥 의미적으로 나타내는 것인가?
	// r-value 자체는 복사 연산 이후 다시 사용될 일이 없음
	// deep copy를 하는 대신에 r-value로 받아서 shallow copy를 수행
	// 이런 것을 보면 단순히 의미적으로 나타내는 것은 아닌 것 같음
	// 1. && -> &로 바꾸면 => error: no viable overloaded
	// 2. const를 적용하면 => double free 문제
	AutoPtr& operator=(AutoPtr&& a)
	{
		std::cout << "class AutoPtr move assignment" << std::endl;
		if (&a == this)
			return (*this);
		if (m_ptr != nullptr) delete m_ptr;
		// shallow copy(의미상으로는 move)
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;	// really necessary?
		return (*this);
	}

	// de-referencing operator
	T&		operator*() const { return (*m_ptr); }
	// member-selelction operator
	T*		operator->() const { return (m_ptr); }
	bool	isNull() const { return (m_ptr == nullptr); }
};

#endif