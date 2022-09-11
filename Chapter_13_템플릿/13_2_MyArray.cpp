// 13_2_MyArray.cpp

#include "13_2_MyArray.hpp"

// 템플릿이 없는 일반적인 경우
// void	MyArray::print()
// {
// 	for (int i = 0; i < m_length; i++)
// 		std::cout << m_data[i] << " ";
// 	std::cout << std::endl;
// }

// 템플릿이 있는 경우
// 같은 파일 안에 있는 경우는 괜찮지만, 다른 cpp 파일로 옮긴 경우
// error: Undefined symbols for architecture arm64
template<typename T>
void	MyArray<T>::print()
{
	for (int i = 0; i < m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation
// 컴파일을 할 때, char 타입으로 컴파일 해야 한다라고 알려주는 것
// 함수 템플릿에서는 컴파일러가 자동으로 해 준 것이었음 
template void MyArray<char>::print();
template void MyArray<double>::print();
// 번거로움 => 클래스 자체를 하는 방법
template class MyArray<char>;
template class MyArray<double>;