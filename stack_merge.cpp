#include <iostream>
#include <stack>

std::stack<int> stack_merge(std::stack<int>& s1, std::stack<int>& s2)
{
	std::stack<int> s3, s4;
	while(!s1.empty() && !s2.empty())
	{ 
		if (s1.top() > s2.top())
		{
			s3.push(s2.top());
			s2.pop();
		}
		else
		{
			s3.push(s1.top());
			s1.pop();
		}
	}
	while (!s1.empty())
	{
		s3.push(s1.top());
		s1.pop();
	}
	while (!s2.empty())
	{
		s3.push(s2.top());
		s2.pop();
	}

	while (!s3.empty())
	{
		s4.push(s3.top());
		s3.pop();
	}

	return s4;
}

int main()
{
	std::stack<int> s1, s2, s3;
	s1.push(10);
	s2.push(9);
	s1.push(8);
	s2.push(7);
	s1.push(6);
	s3 = stack_merge(s1, s2);
	while (!s3.empty())
	{
		std::cout << s3.top() << std::endl;
		s3.pop();
	}
}
