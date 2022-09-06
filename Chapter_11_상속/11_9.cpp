// 11.9 다중 상속

// multiple inheritance
// 두 개 이상의 부모 클래스로부터 상속
// cin, cout도 다중 상속으로 구현

// diamond inheritance
// A : B1 : C, A : B2 : C
// C 클래스가 A 클래스의 사본 2개를 갖게 됨
// 여러 가지 문제가 발생해서 피하는 것이 좋음
// 다이아몬드 상속이 다 나쁜 것은 아님 => 주의하여 사용하자

#include <iostream>

class USBDevice
{
private:
	long	m_id;
public:
	USBDevice(long id)
		: m_id(id)
	{
		std::cout << "class USBDevice constructor" << std::endl;
	};

	long	getId() const { return (m_id); }
	void	plugAndPlay() {}

	~USBDevice()
	{
		std::cout << "class USBDevice destructor" << std::endl;
	};
};

class NetworkDevice
{
private:
	long	m_id;
public:
	NetworkDevice(long id)
		: m_id(id)
	{
		std::cout << "class NetworkDevice constructor" << std::endl;
	};

	long	getId() const { return (m_id); }
	void	netWorking() {}

	~NetworkDevice()
	{
		std::cout << "class NetworkDevice destructor" << std::endl;
	};
};

// 다중 상속
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{
		std::cout << "class USBNetworkDevice constructor" << std::endl;
	};

	// 경우에 따라서는 가능하지 않을수도 있음
	// USBNetworkDevice(long id)
	// 	: USBDevice(id), NetworkDevice(id)
	// {
	// 	std::cout << "class USBNetworkDevice constructor" << std::endl;
	// };

	~USBNetworkDevice()
	{
		std::cout << "class USBNetworkDevice destructor" << std::endl;
	};
};

int	main()
{
	USBNetworkDevice	my_device(314, 6022);

	my_device.netWorking();
	my_device.plugAndPlay();
	// error: member 'getId' found in multiple base classes of different types
	my_device.getId();
	// 해결
	my_device.USBDevice::getId();
	my_device.NetworkDevice::getId();

	return (0);
}

// 자료화면 캡쳐하기