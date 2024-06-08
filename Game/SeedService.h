#pragma once
class SeedService
{
private:
	static int seed;
public:
	SeedService(int seed);
	static int getSeed();
	static void setSeed(int seed);
};

