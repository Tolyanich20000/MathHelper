#pragma once 
#include "stdafx.h"  

using namespace std;
namespace tags {
	class pairedtags {
	public:
		pairedtags() {};
		static int is_close(int poz, int ind);
		friend void TagsTest(string adres);
	};

}