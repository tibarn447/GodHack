#ifndef GUARD_CONSTANTS_BERRY_H
#define GUARD_CONSTANTS_BERRY_H

#define BERRY_NONE 0

#define BERRY_FIRMNESS_UNKNOWN     0
#define BERRY_FIRMNESS_VERY_SOFT   1
#define BERRY_FIRMNESS_SOFT        2
#define BERRY_FIRMNESS_HARD        3
#define BERRY_FIRMNESS_VERY_HARD   4
#define BERRY_FIRMNESS_SUPER_HARD  5

#define FLAVOR_SPICY   0
#define FLAVOR_DRY     1
#define FLAVOR_SWEET   2
#define FLAVOR_BITTER  3
#define FLAVOR_SOUR    4
#define FLAVOR_COUNT   5

#define BERRY_STAGE_NO_BERRY    0  // there is no tree planted and the soil is completely flat.
#define BERRY_STAGE_PLANTED     1
#define BERRY_STAGE_SPROUTED    2
#define BERRY_STAGE_TALLER      3
#define BERRY_STAGE_FLOWERING   4
#define BERRY_STAGE_BERRIES     5
#define BERRY_STAGE_SPARKLING   255

// Berries can be watered in the following stages:
// - BERRY_STAGE_PLANTED
// - BERRY_STAGE_SPROUTED
// - BERRY_STAGE_TALLER
// - BERRY_STAGE_FLOWERING
#define NUM_WATER_STAGES 4

// IDs for berry tree objects, indexes into berryTrees in SaveBlock1
// Named for whatever berry is initially planted there on a new game
// Those with no initial berry are named "soil"
#define BERRY_TREE_LAULEV_CANYON_PECHA    1
#define BERRY_TREE_LAULEV_CANYON_ORAN     2
#define BERRY_TREE_ROUTE_104_SOIL_1   3
#define BERRY_TREE_ROUTE_104_ORAN_1   4
#define BERRY_TREE_ROUTE_103_CHERI_1  5
#define BERRY_TREE_ROUTE_103_LEPPA    6
#define BERRY_TREE_ROUTE_103_CHERI_2  7
#define BERRY_TREE_ROUTE_104_CHERI_1  8
#define BERRY_TREE_ROUTE_104_SOIL_2   9
#define BERRY_TREE_ROUTE_104_LEPPA    10
#define BERRY_TREE_ROUTE_104_ORAN_2   11
#define BERRY_TREE_ROUTE_104_SOIL_3   12
#define BERRY_TREE_ROUTE_104_PECHA    13
#define BERRY_TREE_ROUTE_123_QUALOT_1 14
#define BERRY_TREE_ROUTE_123_POMEG_1  15
#define BERRY_TREE_ROUTE_110_NANAB_1  16
#define BERRY_TREE_ROUTE_110_NANAB_2  17
#define BERRY_TREE_ROUTE_110_NANAB_3  18
#define BERRY_TREE_ROUTE_111_RAZZ_1   19
#define BERRY_TREE_ROUTE_111_RAZZ_2   20
#define BERRY_TREE_ROUTE_112_RAWST_1  21
#define BERRY_TREE_ROUTE_112_PECHA_1  22
#define BERRY_TREE_ROUTE_112_PECHA_2  23
#define BERRY_TREE_ROUTE_112_RAWST_2  24
#define BERRY_TREE_ROUTE_116_PINAP_1  25
#define BERRY_TREE_ROUTE_116_CHESTO_1 26
#define BERRY_TREE_ROUTE_117_WEPEAR_1 27
#define BERRY_TREE_ROUTE_117_WEPEAR_2 28
#define BERRY_TREE_ROUTE_117_WEPEAR_3 29
#define BERRY_TREE_ROUTE_123_POMEG_2  30
#define BERRY_TREE_ROUTE_118_SITRUS_1 31
#define BERRY_TREE_ROUTE_118_SOIL     32
#define BERRY_TREE_ROUTE_118_SITRUS_2 33
#define BERRY_TREE_ROUTE_119_POMEG_1  34
#define BERRY_TREE_ROUTE_119_POMEG_2  35
#define BERRY_TREE_ROUTE_119_POMEG_3  36
#define BERRY_TREE_ROUTE_120_ASPEAR_1 37
#define BERRY_TREE_ROUTE_120_ASPEAR_2 38
#define BERRY_TREE_ROUTE_120_ASPEAR_3 39
#define BERRY_TREE_ROUTE_120_PECHA_1  40
#define BERRY_TREE_ROUTE_120_PECHA_2  41
#define BERRY_TREE_ROUTE_120_PECHA_3  42
#define BERRY_TREE_ROUTE_120_RAZZ     43
#define BERRY_TREE_ROUTE_120_NANAB    44
#define BERRY_TREE_ROUTE_120_PINAP    45
#define BERRY_TREE_ROUTE_120_WEPEAR   46
#define BERRY_TREE_ROUTE_121_PERSIM   47
#define BERRY_TREE_ROUTE_121_ASPEAR   48
#define BERRY_TREE_ROUTE_121_RAWST    49
#define BERRY_TREE_ROUTE_121_CHESTO   50
#define BERRY_TREE_ROUTE_121_SOIL_1   51
#define BERRY_TREE_ROUTE_121_NANAB_1  52
#define BERRY_TREE_ROUTE_121_NANAB_2  53
#define BERRY_TREE_ROUTE_121_SOIL_2   54
#define BERRY_TREE_ROUTE_115_BLUK_1   55
#define BERRY_TREE_ROUTE_115_BLUK_2   56
#define BERRY_TREE_UNUSED             57
#define BERRY_TREE_ROUTE_123_POMEG_3  58
#define BERRY_TREE_ROUTE_123_POMEG_4  59
#define BERRY_TREE_ROUTE_123_GREPA_1  60
#define BERRY_TREE_ROUTE_123_GREPA_2  61
#define BERRY_TREE_ROUTE_123_LEPPA_1  62
#define BERRY_TREE_ROUTE_123_SOIL     63
#define BERRY_TREE_ROUTE_123_LEPPA_2  64
#define BERRY_TREE_ROUTE_123_GREPA_3  65
#define BERRY_TREE_ROUTE_116_CHESTO_2 66
#define BERRY_TREE_ROUTE_116_PINAP_2  67
#define BERRY_TREE_ROUTE_114_PERSIM_1 68
#define BERRY_TREE_ROUTE_115_KELPSY_1 69
#define BERRY_TREE_ROUTE_115_KELPSY_2 70
#define BERRY_TREE_ROUTE_115_KELPSY_3 71
#define BERRY_TREE_ROUTE_123_GREPA_4  72
#define BERRY_TREE_ROUTE_123_QUALOT_2 73
#define BERRY_TREE_ROUTE_123_QUALOT_3 74
#define BERRY_TREE_ROUTE_104_SOIL_4   75
#define BERRY_TREE_ROUTE_104_CHERI_2  76
#define BERRY_TREE_ROUTE_114_PERSIM_2 77
#define BERRY_TREE_ROUTE_114_PERSIM_3 78
#define BERRY_TREE_ROUTE_123_QUALOT_4 79
#define BERRY_TREE_ROUTE_111_ORAN_1   80
#define BERRY_TREE_ROUTE_111_ORAN_2   81
#define BERRY_TREE_ROUTE_130_LIECHI   82
#define BERRY_TREE_ROUTE_119_HONDEW_1 83
#define BERRY_TREE_ROUTE_119_HONDEW_2 84
#define BERRY_TREE_ROUTE_119_SITRUS   85
#define BERRY_TREE_ROUTE_119_LEPPA    86
#define BERRY_TREE_ROUTE_123_PECHA    87
#define BERRY_TREE_ROUTE_123_SITRUS   88
#define BERRY_TREE_ROUTE_123_RAWST    89

// Remainder are unused

#define BERRY_TREES_COUNT 128

#endif // GUARD_CONSTANTS_BERRY_H
