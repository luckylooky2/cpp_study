// 13_5_Storage8.hpp

#ifndef THIRTEEN_FIVE_STORAGE8_HPP
#define THIRTEEN_FIVE_STORAGE8_HPP

#include <iostream>

template<class T>
class Storage8
{
private:
	T	m_array[8];

public:
	void	set(int index, const T& value)
	{
		m_array[index] = value;
	}
	const	T& get(int index) { return (m_array[index]); }
};

template<>
class Storage8<bool>
{
private:
	// 1개의 bool 타입(1 bit)만 처리하고 싶어도 주소 할당 단위는  1 byte
	unsigned char	m_data;

public:
	Storage8()
		: m_data(0)
	{}
	
	void	set(int index, bool value)
	{
		unsigned char mask = 1 << index;	// bit mask

		if (value)
			m_data |= mask;		// 장착
		else
			m_data &= ~mask;	// 해제
	}

	bool	get(int index)
	{
		unsigned char	mask = 1 << index;
		return ((m_data & mask) != 0);
	}
};

#endif