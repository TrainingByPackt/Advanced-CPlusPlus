//============================================================================
// Name        : Exercise8.cpp
// Author      : Olena Lizina
// Description : Exercise 8
//============================================================================
#include <aio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <thread>

bool isDone{};

void
aioSigHandler(int no, siginfo_t* si, void*)
{
	std::cout << "Signo: " << no << std::endl;
	if (si->si_code == SI_ASYNCIO)
	{
		std::cout << "I/O completion signal received" << std::endl;
	}
	isDone = true;
}

void
fillAiocb(aiocb& item, const int& fileDescriptor,
          char* buffer, const int& bufSize)
{
	item.aio_fildes = fileDescriptor;
	item.aio_buf = static_cast<void*>(buffer);
	item.aio_nbytes = bufSize;
	item.aio_reqprio = 0;
	item.aio_offset = 0;
	item.aio_sigevent.sigev_notify = SIGEV_SIGNAL;
	item.aio_sigevent.sigev_signo = SIGUSR1;
	item.aio_sigevent.sigev_value.sival_ptr = &item;
}

bool
initSigAct(struct sigaction& item)
{
	item.sa_flags = SA_RESTART | SA_SIGINFO;
	item.sa_sigaction = aioSigHandler;

	if (-1 == sigaction(SIGUSR1, &item, NULL))
	{
		std::cerr << "sigaction usr1 failed" << std::endl;
		return false;
	}
	std::cout << "Successfully set up a async IO handler to SIGUSR1 action" << std::endl;
	return true;
}

int main(int argc, char* argv[])
{
	constexpr int bufSize = 100;
	char* buffer = new char(bufSize);

	if (!buffer)
	{
		std::cerr << "Failed to allocate buffer" << std::endl;
		return -1;
	}

	const std::string fileName("Test.txt");
	int descriptor = open(fileName.c_str(), O_RDONLY);
	if (-1 == descriptor)
	{
		std::cerr << "Failed to opene file for reading" << std::endl;
		return -1;
	}
	std::cout << "Successfully opened file for reading" << std::endl;

	struct sigaction sa;
	if (!initSigAct(sa))
	{
		std::cerr << "failed registering signal" << std::endl;
		return -1;
	}

	aiocb aiocbObj;
	fillAiocb(aiocbObj, descriptor, buffer, bufSize);

	if (-1 == aio_read(&aiocbObj))
	{
		std::cerr << "aio_read failed" << std::endl;
	}

	while (!isDone)
	{
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(3ms);
	}

	std::cout << "Successfully finished read operation. Buffer: " << std::endl << buffer;

	return 0;
}
