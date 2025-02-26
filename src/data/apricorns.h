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
    // u8 padding:5;
};

const struct ApricornTree gApricornTrees[APRICORN_TREE_COUNT] =
{
    [APRICORN_TREE_NONE] =
    {},

    [APRICORN_TREE_EMPTY] =
    {},

    [RED_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_RED
    },

    [BLUE_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_BLUE
    },

    [PINK_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_PINK
    },

    [WHITE_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_WHITE
    },

    [BLACK_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_BLACK
    },

    [GREEN_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_GREEN
    },

    [YELLOW_APRICORN_TREE_ROUTE101] =
    {
        .apricornType = APRICORN_YELLOW
    },
};
