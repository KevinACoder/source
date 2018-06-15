#ifndef SRC_HASK_TABL_HEADER
#define SRC_HASK_TABL_HEADER

#include "defines.h"
#include <map>
#include <string>
#include <vector>
#include <set>
using std::map;
using std::string;
using std::vector;
using std::set;
typedef map<char, int> mapChCount;
typedef vecotr<string> vstring;

namespace hash_table
{
  int num_of_jewell(string stone, string jewel);
  vstring char_in_same_row_of_keyboard(vstring& words);
};

namespace hash_table_test
{
 void test_num_of_jewell();
};

#endif