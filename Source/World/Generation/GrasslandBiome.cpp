#include "GrasslandBiome.h"

#include "TreeGenerator.h"

GrasslandBiome::GrasslandBiome(int seed)
:   Biome  (getNoiseParameters(), 100, 50, seed)
{

}

ChunkBlock GrasslandBiome::getTopBlock(Rand& rand) const
{
    return BlockId::Grass;
}

ChunkBlock GrasslandBiome::getUnderWaterBlock(Rand& rand) const
{
    return rand.intInRange(0, 10) > 8 ?
        BlockId::Dirt :
        BlockId::Sand;
}

void GrasslandBiome::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
    makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters GrasslandBiome::getNoiseParameters()
{
    NoiseParameters heightParams;
    heightParams.octaves       = 9;
    heightParams.amplitude     = 85;
    heightParams.smoothness    = 235;
    heightParams.heightOffset  = -20;
    heightParams.roughness     = 0.51;

    return heightParams;
}

ChunkBlock GrasslandBiome::getPlant(Rand& rand) const
{
    return rand.intInRange(0, 10) > 6 ?
        BlockId::Rose :
        BlockId::TallGrass;
}
