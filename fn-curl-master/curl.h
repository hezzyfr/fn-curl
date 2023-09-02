#pragma once
#include "util.h"
#include "minhook/MinHook.h"
#include <regex>

#define HYBRID 1 //set to 0 to redirect all

#define CURLOPT_SSL_VERIFYPEER 64
#define CURLOPT_URL 10002
#define CURLE_BAD_FUNCTION_ARGUMENT 43

std::regex ohost("https:\\/\\/(.*)\\.ol\\.epicgames.com");
std::string nhost("http://127.0.0.1");
std::string routes[] = { "/content/api/pages/fortnite-game/", "/fortnite/api/game/v2/profile/", "/fortnite/api/cloudstorage/system" };

int (*oCurlEasySetopt)(void* handle, int option, ...);

int hkCurlEasySetopt(void* handle, int option, va_list parameter) {

	if (!handle) return CURLE_BAD_FUNCTION_ARGUMENT;

	if (option == CURLOPT_SSL_VERIFYPEER)
		return oCurlEasySetopt(handle, option, 0);

	if (option == CURLOPT_URL) {
		std::string ourl(parameter);
#if HYBRID
		for (int i = 0; i < sizeof(routes) / sizeof(*routes); i++) {

			if (strstr(ourl.c_str(), routes[i].c_str()))
				ourl = std::regex_replace(ourl, ohost, nhost);
		}
#else 
		ourl = std::regex_replace(ourl, ohost, nhost);
#endif
		return oCurlEasySetopt(handle, option, ourl.c_str());
	}

	return oCurlEasySetopt(handle, option, parameter);
}

void hookCurl() {

	uintptr_t aCurlEasySetopt = util::sigscan("89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 48 85 C9 75 08 8D 41 2B 48 83 C4 28 C3 4C");

	MH_Initialize();
	MH_CreateHook((LPVOID)aCurlEasySetopt, hkCurlEasySetopt, (LPVOID*)&oCurlEasySetopt);
	MH_EnableHook((LPVOID)aCurlEasySetopt);
}
