// article.cpp

#include <iostream>

int main()
{
	unsigned char	option_viewed = 0x01;
	unsigned char	option_edited = 0x02;
	unsigned char	option_liked = 0x04;
	unsigned char	option_shared = 0x08;
	unsigned char	option_deleted = 0x80;

	unsigned char	my_article_flags = 0;

	// 다음 경우에 대해 플래그를 바꿔보세요
	// 1. 기사를 봤을 때
	my_article_flags |= option_viewed;
	std::cout << std::bitset<8>(my_article_flags) << std::endl;		// 0000 0001
	// 2. 기사의 좋아요를 클릭했을 때
	my_article_flags |= option_liked;
	std::cout << std::bitset<8>(my_article_flags) << std::endl;		// 0000 0101
	// 3. 기사의 좋아요를 다시 클릭했을 때
	my_article_flags &= ~option_liked;
	std::cout << std::bitset<8>(my_article_flags) << std::endl;		// 0000 0001
	// 4. 본 기사만 삭제할 때
	my_article_flags |= option_deleted;
	std::cout << std::bitset<8>(my_article_flags) << std::endl;		// 1000 0001

	return (0);
}