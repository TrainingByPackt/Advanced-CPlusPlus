//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Description : Exercise 5 Chapter 5
//============================================================================

#include <iostream>
#include <thread>
#include <future>

class CalcSum
{
	public:
	int operator()(int from, int to)
	{
		long long int sum{0};
		for (int i= from; i < to; ++i )
		{
			sum += i;
		}
		return sum;
	}

	void operator()(int from, int to, std::promise<int> result)
	{
		long long int sum{0};
		for (int i= from; i < to; ++i )
		{
			sum += i;
		}
		result.set_value(sum);
	}
};

int main()
{
	int from = 0;
	int to = 500;
	int step = 300;

	CalcSum calcSum1;
	std::packaged_task<int(int,int)> sumTask1(calcSum1);
	std::future<int> sumResult1= sumTask1.get_future();
	std::thread thr1(std::move(sumTask1), from, to);
	thr1.detach();

	from = to;
	to += step;

	CalcSum calcSum2;
	std::future<int> sumResult2 = std::async(calcSum2, from, to);

	from = to;
	to += step;

	CalcSum calcSum3;
	std::promise<int> sumRes;
	std::future<int> sumResult3 = sumRes.get_future();
	std::thread thr2(calcSum3, to, from, std::move(sumRes));
	thr2.detach();

	sumResult3.wait();
	auto sum = sumResult1.get() + sumResult2.get() + sumResult3.get();
	std::cout << "sum = " << sum << std::endl;

	return 0;
}
