#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.fieldmap.h"
#include "constants/regions.h"

static inline u32 GetCurrentRegion(void)
{
    // TODO: Since there's no current multi-region support, we have this constant for the purposes of regional form comparisons.
    if (gMapHeader.region == REGION_HOENN)
    {
        return REGION_HOENN;
    }
    else if (gMapHeader.region == REGION_KANTO)
    {
        return REGION_KANTO;
    }
    else if (gMapHeader.region == REGION_SEVII)
    {
        return REGION_SEVII;
    }
    else if (gMapHeader.region == REGION_DRACON)
    {
        return REGION_DRACON;
    }
    else if (gMapHeader.region == REGION_SINNOH)
    {
        return REGION_SINNOH;
    }
    else if (gMapHeader.region == REGION_HISUI)
    {
        return REGION_HISUI;
    }
    else if (gMapHeader.region == REGION_UNOVA)
    {
        return REGION_UNOVA;
    }
    else if (gMapHeader.region == REGION_KALOS)
    {
        return REGION_KALOS;
    }
    else if (gMapHeader.region == REGION_ALOLA)
    {
        return REGION_ALOLA;
    }
    else if (gMapHeader.region == REGION_GALAR)
    {
        return REGION_GALAR;
    }
    else if (gMapHeader.region == REGION_PALDEA)
    {
        return REGION_PALDEA;
    }
    else {
        return REGION_HOENN;
    }
}

#endif // GUARD_REGIONS_H
