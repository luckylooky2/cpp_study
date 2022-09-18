// 15_4_AutoPtr.hpp

#ifndef FIFTEEN_FOUR_AUTOPTR_HPP
#define FIFTEEN_FOUR_AUTOPTR_HPP

#include <iostream>

// value, move semantics를 모두 허용
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
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// assignment operator
	AutoPtr& operator=(const AutoPtr &a)
	{
		std::cout << "class AutoPtr copy assignment" << std::endl;
		if (&a == this)
			return (*this);
		if (m_ptr != nullptr) delete m_ptr;
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
		return (*this);
	}

	// move semantics(move)
	// move constructor
	AutoPtr(AutoPtr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
		std::cout << "AuotPtr move constructor" << std::endl;
	}

	// move operator
	AutoPtr& operator=(AutoPtr&& a)
	{
		std::cout << "class AutoPtr move assignment" << std::endl;
		if (&a == this)
			return (*this);
		if (m_ptr != nullptr) delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return (*this);
	}

	// de-referencing operator
	T&		operator*() const { return (*m_ptr); }
	// member-selelction operator
	T*		operator->() const { return (m_ptr); }
	bool	isNull() const { return (m_ptr == nullptr); }
};

#endif