#ifndef __JAN_CAR_HPP_INCLUDED__
#define __JAN_CAR_HPP_INCLUDED__

#include <string>

namespace jan
{
	class car 
	{
		public:
			car();
			car(std::string& brand);
			~car();

		private:
			unsigned int max_speed;
			unsigned int chair_num;
			std::string brand;
	};

}

#endif
