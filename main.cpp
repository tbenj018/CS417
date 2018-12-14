#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "dividedDiff.h"


int main(int argc, char** argv){
  if (argc != 3)
	{
		std::cout << "Usage:  divided [input file] [output file]" << std::endl;
		return 0;
	}

  std::ifstream fin(argv[2]);
	std::ofstream fout(argv[2]);

  Divideddiff divider;
  divider.divide(finInput);

  return 0;
}
