#include "utils.hpp"
#include <vector>


std::vector<Area> SliceArea(Area &areaToSlice) {
	std::vector<Area> slices;
	if (areaToSlice.width < 50 || areaToSlice.depth < 50) {
		slices.push_back(areaToSlice);
		return slices;
	}
	float widthSubArea1 = areaToSlice.width / 2;
	float depthSubArea1 = areaToSlice.depth / 2;

	Area sub1 = {areaToSlice.pos, widthSubArea1, depthSubArea1};
	Vec3f posSub2 = { areaToSlice.pos.x + widthSubArea1, areaToSlice.pos.y, areaToSlice.pos.z + depthSubArea1};
	Area sub2 = { posSub2, areaToSlice.width - widthSubArea1, areaToSlice.depth - depthSubArea1 };
	slices.push_back(sub1);
	slices.push_back(sub2);
	return slices;
}
