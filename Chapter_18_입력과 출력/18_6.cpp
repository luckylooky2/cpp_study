// 18.6 기본적인 파일 입출력

// 지금까지는 콘솔 입출력 예제가 많았음

#include <fstream>	// file stream
#include <iostream>
#include <string>
#include <cstdlib>	// exit()
#include <sstream>

int	main()
{
	// writing
	if (true)
	{
		// 파일 출력 스트림을 생성, 있으면 덮어씀
		// 1. 생성자 파라미터를 이용하는 방식
		// ios:app : append mode, ios::binary 
		std::ofstream	ofs("my_first_file.dat", std::ios::app);
		// 2. 메서드를 이용하는 방식
		// ofs.open("my_first_file.dat");

		// file I/O는 예외 처리를 신중하게 할 필요가 있음
		if (!ofs)
		{
			std::cerr << "Couldn't open file" << std::endl;
			exit(1);
		}

		// 스트림에 write
		// 1. ASCII : write하는 속도가 느림
		ofs << "Line 1" << std::endl;
		ofs << "Line 2" << std::endl;

		// 2. binary : 속도가 훨씬 빠름
		// binary로 저장할 때는 데이터가 어디까지인지 알 수가 없음
		// 어떤 데이터가 몇 개가 저장될지를 미리 약속을 해서 알고 있어야 함
		// 파일을 저장하는 사람과 읽는 사람이 약속을 해야 함
		const unsigned	num_data = 10;

		ofs.write((char *)&num_data, sizeof(num_data));
		// 0 ~ 9까지 binary로 write
		// binary이기 떄문에 직접 눈으로 확인할 수 없음
		for (int i = 0; i < num_data; ++i)
			ofs.write((char *)&i, sizeof(i));

		// 파일 스트림이 소멸하면서 자동으로 닫아주기 때문에 not necessary
		ofs.close();
	}

	// reading
	if (true)
	{
		std::ifstream	ifs("my_first_file.dat");

		if (!ifs)
		{
			std::cerr << "Couldn't open file" << std::endl;
			exit(1);
		}

		// 스트림을 read
		// 1. ASCII
		while (false)
		{
			std::string	str;

			std::getline(ifs, str);
			if (!ifs)
				break;
			std::cout << str << std::endl;
		}
		// Line 1
		// Line 2

		// 2. binary
		unsigned num_data = 0;
		ifs.read((char *)&num_data, sizeof(num_data));
		for (unsigned i = 0; i < num_data; ++i)
		{
			int num;

			ifs.read((char *)&num, sizeof(num));
			std::cout << num << std::endl;
		}

	}

	return (0);
}