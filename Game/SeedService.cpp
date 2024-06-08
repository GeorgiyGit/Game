#include "SeedService.h"
int SeedService::getSeed() {
	return SeedService::seed;
}
SeedService::SeedService(int seed) {
	SeedService::seed = seed;
}
int SeedService::seed = 123;

void SeedService::setSeed(int seed) {
	SeedService::seed = seed;
}