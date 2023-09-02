#pragma once
#include <Windows.h>
#include <vector>
#include <string>

class util {
public:
	static uintptr_t sigscan(std::string pattern, int times = 0, uintptr_t membase = (uintptr_t)GetModuleHandle(0)) {

		static auto patternToByte = [](const char* pattern)
		{
			auto       bytes = std::vector<int>{};
			const auto start = const_cast<char*>(pattern);
			const auto end = const_cast<char*>(pattern) + strlen(pattern);

			for (auto current = start; current < end; ++current)
			{
				if (*current == '?')
				{
					++current;
					if (*current == '?')
						++current;
					bytes.push_back(-1);
				}
				else { bytes.push_back(strtoul(current, &current, 16)); }
			}
			return bytes;
		};

		const auto dosHeader = (PIMAGE_DOS_HEADER)membase;
		const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)membase + dosHeader->e_lfanew);

		const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
		auto       patternBytes = patternToByte(pattern.c_str());
		const auto scanBytes = reinterpret_cast<std::uint8_t*>(membase);

		const auto s = patternBytes.size();
		const auto d = patternBytes.data();

		size_t nFoundResults = 0;

		for (auto i = 0ul; i < sizeOfImage - s; ++i)
		{
			bool found = true;
			for (auto j = 0ul; j < s; ++j)
			{
				if (scanBytes[i + j] != d[j] && d[j] != -1)
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				if (times != 0)
				{
					if (nFoundResults < times)
					{
						nFoundResults++;
						found = false;
					}
					else
					{
						return reinterpret_cast<uintptr_t>(&scanBytes[i]);
					}
				}
				else
				{
					return reinterpret_cast<uintptr_t>(&scanBytes[i]);
				}
			}
		}
		return 0;
	}
};