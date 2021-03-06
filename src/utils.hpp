#ifndef __UTILS_H_
#define __UTILS_H_

#include "structs.hpp"
#include <vector>
std::vector<Area> SliceAreaInto(Area &areaToSlice, int slices);
std::vector<Area> SliceArea(Area &areaToSlice);
std::vector<Area> SliceAreas(std::vector<Area> areas);

#endif // __UTILS_H_
