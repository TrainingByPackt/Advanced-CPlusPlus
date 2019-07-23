//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Description : Exercise 4 Chapter 5
//============================================================================

#include <iostream>
#include <thread>
#include <vector>
#include <string>

class Converter
{
	public:
	Converter(std::vector<std::string>& bufferIn)
		: m_bufferIn(bufferIn)
	{
	}

	Converter(Converter&& rhs)
		: m_bufferIn(std::move(rhs.m_bufferIn))
	{
	}

	Converter(const Converter&) = delete;
	Converter& operator=(const Converter&) = delete;
	Converter& operator=(Converter&&) = delete;

	void operator()(const int idx, std::vector<std::string>& result)
	{
		try
		{
			std::string::const_iterator end = m_bufferIn.at(idx).end();
			std::string bufferOut;

			for (std::string::const_iterator iter = m_bufferIn.at(idx).begin(); iter != end; iter++)
			{
				if (*iter >= 97 && *iter <= 122)
				{
					bufferOut += static_cast<char>(static_cast<int>(*iter) - 32);
				}
				else
				{
					bufferOut += *iter;
				}
			}
			result[idx] = bufferOut;
		}
		catch(...)
		{
			std::cout << "Invalid index" << std::endl;
		}
	}

	private:
	const std::vector<std::string>& m_bufferIn;
};

int main()
{
	const int numberOfTasks = 5;
	std::vector<Converter> functions;
	functions.reserve(numberOfTasks);
	std::vector<std::thread> threads;
	threads.reserve(numberOfTasks);

	std::vector<std::string> textArr;
	textArr.emplace_back("As a physical object, a book is a stack of usually rectangular pages (made of papyrus, parchment, vellum, or paper) oriented with one edge tied, \
sewn, or otherwise fixed together and then bound to the flexible spine of a protective cover of heavier, relatively inflexible material.[1] \
The technical term for this physical arrangement is codex (in the plural, codices). In the history of hand-held physical supports for extended written compositions or records, \
the codex replaces its immediate predecessor, the scroll. A single sheet in a codex is a leaf, and each side of a leaf is a page.");
	textArr.emplace_back("As an intellectual object, a book is prototypically a composition of such great length that it takes a considerable investment of time to compose and a still considerable, \
though not so extensive, investment of time to read. This sense of book has a restricted and an unrestricted sense. In the restricted sense, \
a book is a self-sufficient section or part of a longer composition, a usage that reflects the fact that, in antiquity, long works had to be written on several scrolls, \
and each scroll had to be identified by the book it contained. So, for instance, each part of Aristotle's Physics is called a book, \
as of course, the Bible encompasses many different books. In the unrestricted sense, a book is the compositional whole of which such sections, \
whether called books or chapters or parts, are parts.");
	textArr.emplace_back("The intellectual content in a physical book need not be a composition, nor even be called a book. Books can consist only of drawings, engravings, \
or photographs, or such things as crossword puzzles or cut-out dolls. In a physical book, the pages can be left blank or can feature an abstract set of lines \
as support for on-going entries, i.e., an account book, an appointment book, a log book, an autograph book, a notebook, a diary or day book, or a sketchbook. \
Some physical books are made with pages thick and sturdy enough to support other physical objects, like a scrapbook or photograph album. \
Books may be distributed in electronic form as e-books and other formats.");
	textArr.emplace_back("Although in ordinary academic parlance a monograph is understood to be a specialist academic work, rather than a reference work on a single scholarly subject, \
in library and information science monograph denotes more broadly any non-serial publication complete in one volume (book) or a finite number of volumes \
(even a novel like Proust's seven-volume In Search of Lost Time), in contrast to serial publications like a magazine, journal, or newspaper. \
An avid reader or collector of books or a book lover is a bibliophile or colloquially, \"bookworm\". A shop where books are bought and sold is a bookshop or bookstore. \
Books are also sold elsewhere. Books can also be borrowed from libraries. Google has estimated that as of 2010, approximately 130,000,000 distinct titles had been published.[2] \
In some wealthier nations, the sale of printed books has decreased because of the increased usage of e-books.[3]");
	textArr.emplace_back("The word book comes from Old English \"bōc\", which in turn comes from the Germanic root \"*bōk-\", cognate to \"beech\".[4]");

	for (int i = 0; i < numberOfTasks; ++i)
	{
	    functions.push_back(Converter(textArr));
	}

	std::vector<std::string> result;
	for (int i = 0; i < numberOfTasks; ++i)
	{
		result.push_back("");
	}
	int idx = 0;

	for (auto iter = functions.begin(); iter != functions.end(); ++iter)
	{
	    std::thread tmp(std::move(*iter), idx, std::ref(result));
	    threads.push_back(std::move(tmp));
	    idx++;
	}

	for (auto iter = threads.begin(); iter != threads.end(); ++iter)
	{
	    (*iter).detach();
	}

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(5s);

	for (const auto& str : result)
	{
		std::cout << str;
	}

	return 0;
}
