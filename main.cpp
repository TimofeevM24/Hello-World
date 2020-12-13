#include <iostream>
#include <cctype>
#include <clocale>
#include <vector>



void read_float(float& f)
{
	while (!(std::cin >> f));
	{
		std::cin.clear();
		while (!std::isspace(std::cin.get()));
	} 
}

std::vector<float> mv_mult(const std::vector<float>& mat, const std::vector<float>& vec)
{
	std::vector<float> result(vec.size(), 0);

	for (std::size_t r = 0; r < vec.size(); r++)
		for (std::size_t cr = 0; cr < vec.size(); cr++)
			result[r] += mat[r * vec.size() + cr] * vec[cr];

	return result;
}

int main()
{
	std::setlocale(LC_ALL, "ru");

	std::size_t dim;
	std::cout << "Введите размерность: ";
	while (!(std::cin >> dim))
	{
		std::cin.clear();
		while (!std::isspace(std::cin.get()));
		std::cout << "Введите размерность: ";
	} 

	std::vector<float> vec(dim);
	std::vector<float> mat(dim * dim);

	std::cout << "Введите матрицу " << dim << "x" << dim << ":\n";
	for (std::size_t i = 0; i < dim * dim; i++)
		read_float(mat[i]);

	std::cout << "Введите вектор:\n";
	for (std::size_t i = 0; i < dim; i++)
		read_float(vec[i]);

	std::vector<float> res = mv_mult(mat, vec);
	std::cout << "Полученный вектор:\n";
	for (std::size_t i = 0; i < res.size(); i++)
		std::cout << res[i] << '\n';

	return 0;
}
