#include <iostream>
#include <vector>

int main()
{
    std::vector<int>vec = { -5, 2, 8, -4, -10, 12, 7, -3 };
	std::vector<int>temp(vec.size(), 0);
	int sum = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (sum - vec[i] > sum)
		{

		}
	}

    return 0;
}