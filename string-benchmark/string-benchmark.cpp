// string-benchmark.cpp : Defines the entry point for the application.
//

#include "string-benchmark.h"

std::string const first{ "first" };
std::string const second{ "second" };
std::string const expected{ "firstsecond" };

void BM_strcat(benchmark::State& state)
{
	for (auto& _ : state)
	{
		// Yes, this works.
		// No, don't do this.
		std::string result{ first };
		result.resize(first.size() + second.size());
		strcat(result.data(), second.c_str()); // since C++17
		assert(result == expected);
	}
}

BENCHMARK(BM_strcat);

void BM_sprintf(benchmark::State& state)
{
	for (auto& _ : state)
	{
		std::string result;
		result.resize(first.size() + second.size());
		sprintf(result.data(), "%s%s", first.c_str(), second.c_str());
		assert(result == expected);
	}
}

BENCHMARK(BM_sprintf);


void BM_stringstream(benchmark::State& state)
{
	for (auto& _ : state)
	{
		std::ostringstream oss;
		oss << first << second;
		auto const& result = oss.str();
		assert(result == expected);
	}
}

BENCHMARK(BM_stringstream);


void BM_insert(benchmark::State& state)
{
	for (auto& _ : state)
	{
		std::string result{ first };
		result.insert(result.size(), second);
		assert(result == expected);
	}
}

BENCHMARK(BM_insert);


void BM_insert_iter(benchmark::State& state)
{
	for (auto& _ : state)
	{
		std::string result{ first };
		result.insert(result.end(), second.begin(), second.end());
		assert(result == expected);
	}
}

BENCHMARK(BM_insert_iter);


void BM_append(benchmark::State& state)
{
	for (auto& _ : state)
	{
		std::string result{ first };
		result.append(second);
		assert(result == expected);
	}
}

BENCHMARK(BM_append);


void BM_abseil(benchmark::State& state)
{
	for (auto& _ : state)
	{
		auto const& result = absl::StrCat(first, second);
		assert(result == expected);
	}
}

BENCHMARK(BM_abseil);

/*

void BM_<name>(benchmark::State& state)
{
	for (auto& _ : state)
	{
		// your code here
	}
}

*/

BENCHMARK_MAIN();
