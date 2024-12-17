// Apricorn type lookup table, added to allow adding new apricorns without being forced to rearrange the item constants.
const u16 ApricornTypes[APRICORN_COUNT] =
{
    [APRICORN_RED]    = ITEM_RED_APRICORN,
    [APRICORN_BLUE]   = ITEM_BLUE_APRICORN,
    [APRICORN_YELLOW] = ITEM_YELLOW_APRICORN,
    [APRICORN_GREEN]  = ITEM_GREEN_APRICORN,
    [APRICORN_PINK]   = ITEM_PINK_APRICORN,
    [APRICORN_WHITE]  = ITEM_WHITE_APRICORN,
    [APRICORN_BLACK]  = ITEM_BLACK_APRICORN,
};

struct ApricornTree
{
    u8 apricornType:3; // ensure that there's enough bits for APRICORN_COUNT, default 7 is 3 bits
    // u8 padding:4;
};

const struct ApricornTree gApricornTrees[APRICORN_TREE_COUNT] =
{
    [APRICORN_TREE_NONE] =
    {
        .apricornType = APRICORN_RED,
    },

    [APRICORN_TREE_ROUTE101_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_ROUTE101_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_ROUTE101_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_ROUTE101_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_ROUTE101_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_ROUTE101_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_ROUTE101_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },
    
    [APRICORN_TREE_ROUTE102_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_ROUTE102_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_ROUTE102_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_ROUTE102_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_ROUTE102_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_ROUTE102_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_ROUTE102_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },

    [APRICORN_TREE_ROUTE116_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_ROUTE116_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_ROUTE116_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_ROUTE116_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_ROUTE116_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_ROUTE116_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_ROUTE116_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },

    [APRICORN_TREE_PETALBURG_WOODS_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_PETALBURG_WOODS_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_PETALBURG_WOODS_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_PETALBURG_WOODS_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_PETALBURG_WOODS_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_PETALBURG_WOODS_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_PETALBURG_WOODS_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },

    [APRICORN_TREE_DEEP_PETALBURG_WOODS_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_DEEP_PETALBURG_WOODS_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },

    [APRICORN_TREE_ROUTE120_RED_TREE] =
    {
        .apricornType = APRICORN_RED,
    },
    [APRICORN_TREE_ROUTE120_WHITE_TREE] =
    {
        .apricornType = APRICORN_WHITE,
    },
    [APRICORN_TREE_ROUTE120_PINK_TREE] =
    {
        .apricornType = APRICORN_PINK,
    },
    [APRICORN_TREE_ROUTE120_BLACK_TREE] =
    {
        .apricornType = APRICORN_BLACK,
    },
    [APRICORN_TREE_ROUTE120_BLUE_TREE] =
    {
        .apricornType = APRICORN_BLUE,
    },
    [APRICORN_TREE_ROUTE120_GREEN_TREE] =
    {
        .apricornType = APRICORN_GREEN,
    },
    [APRICORN_TREE_ROUTE120_YELLOW_TREE] =
    {
        .apricornType = APRICORN_YELLOW,
    },

};
