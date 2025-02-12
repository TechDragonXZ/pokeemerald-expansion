#include "even_crafting.h"

// Medicine
const struct CraftingIngredient sPotionIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_ORAN_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sSuperPotionIngredients[] =
{
    [0] =
    {
        .item = ITEM_POTION,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sHyperPotionIngredients[] =
{
    [0] =
    {
        .item = ITEM_SUPER_POTION,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_VIVICHOKE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sMaxPotionIngredients[] =
{
    [0] =
    {
        .item = ITEM_SITRUS_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_KING_LEAF,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sFullRestoreIngredients[] =
{
    [0] =
    {
        .item = ITEM_FULL_HEAL,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_MAX_POTION,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sReviveIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_VIVICHOKE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sMaxReviveIngredients[] =
{
    [0] =
    {
        .item = ITEM_KING_LEAF,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_REVIVE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sRemedyIngredients[] =
{
    [0] =
    {
        .item = ITEM_BUGWORT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sFineRemedyIngredients[] =
{
    [0] =
    {
        .item = ITEM_REMEDY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sSuperbRemedyIngredients[] =
{
    [0] =
    {
        .item = ITEM_FINE_REMEDY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_VIVICHOKE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

// Restoration
const struct CraftingIngredient sFullHealIngredients[] =
{
    [0] =
    {
        .item = ITEM_ASPEAR_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_CHERI_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_PECHA_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [3] =
    {
        .item = ITEM_RAWST_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sAntidoteIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PECHA_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sAwakeningIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_CHESTO_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sBurnHealIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_RAWST_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sIceHealIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_ASPEAR_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sParalyzeHealIngredients[] =
{
    [0] =
    {
        .item = ITEM_MEDICINAL_LEEK,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_CHERI_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sMaxEtherIngredients[] =
{
    [0] =
    {
        .item = ITEM_LEPPA_BERRY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sMaxElixerIngredients[] =
{
    [0] =
    {
        .item = ITEM_MAX_ETHER,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

// Utility
const struct CraftingIngredient sAuxPowerIngredients[] =
{
    [0] =
    {
        .item = ITEM_SWORDCAP,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sAuxGuardIngredients[] =
{
    [0] =
    {
        .item = ITEM_IRON_BARKTONGUE,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_PEPUP_PLANT,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sAuxPowerGuardIngredients[] =
{
    [0] =
    {
        .item = ITEM_AUX_POWER,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_AUX_GUARD,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_KING_LEAF,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sAuxEvasionIngredients[] =
{
    [0] =
    {
        .item = ITEM_DOPPEL_BONNETS,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_CANDY_TRUFFLE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sDireHitIngredients[] =
{
    [0] =
    {
        .item = ITEM_DIRESHROOM,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_CANDY_TRUFFLE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

// Pokéballs
const struct CraftingIngredient sPremierballIngredients[] =
{
    [0] =
    {
        .item = ITEM_WHITE_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_RED_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sHeavyballIngredients[] =
{
    [0] =
    {
        .item = ITEM_BLACK_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sLoveballIngredients[] =
{
    [0] =
    {
        .item = ITEM_PINK_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sLureballIngredients[] =
{
    [0] =
    {
        .item = ITEM_BLUE_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sFriendballIngredients[] =
{
    [0] =
    {
        .item = ITEM_GREEN_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sLevelballIngredients[] =
{
    [0] =
    {
        .item = ITEM_RED_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sFastballIngredients[] =
{
    [0] =
    {
        .item = ITEM_WHITE_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sMoonballIngredients[] =
{
    [0] =
    {
        .item = ITEM_YELLOW_APRICORN,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_IRON_CHUNK,
        .count = 1,
        .isConsumed= TRUE,
    },
};

// Misc
const struct CraftingIngredient sStarPieceIngredients[] =
{
    [0] =
    {
        .item = ITEM_RED_SHARD,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_GREEN_SHARD,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_BLUE_SHARD,
        .count = 1,
        .isConsumed= TRUE,
    },
    [3] =
    {
        .item = ITEM_YELLOW_SHARD,
        .count = 1,
        .isConsumed= TRUE,
    },
    [4] =
    {
        .item = ITEM_STARDUST,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sRareCandyIngredients[] =
{
    [0] =
    {
        .item = ITEM_EXP_CANDY_XS,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_EXP_CANDY_S,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_EXP_CANDY_M,
        .count = 1,
        .isConsumed= TRUE,
    },
    [3] =
    {
        .item = ITEM_CANDY_TRUFFLE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingIngredient sDynamaxCandyIngredients[] =
{
    [0] =
    {
        .item = ITEM_MAX_HONEY,
        .count = 1,
        .isConsumed= TRUE,
    },
    [1] =
    {
        .item = ITEM_MAX_MUSHROOMS,
        .count = 1,
        .isConsumed= TRUE,
    },
    [2] =
    {
        .item = ITEM_CANDY_TRUFFLE,
        .count = 1,
        .isConsumed= TRUE,
    },
};

const struct CraftingRecipe sCraftingRecipes[] =
{
    // Medicine
    [RECIPE_POTION] =
    {
        .outputItem = ITEM_POTION,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sPotionIngredients,
        .recipeName = _("Potion"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_SUPER_POTION] =
    {
        .outputItem = ITEM_SUPER_POTION,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sSuperPotionIngredients,
        .recipeName = _("Super Potion"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_HYPER_POTION] =
    {
        .outputItem = ITEM_HYPER_POTION,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sHyperPotionIngredients,
        .recipeName = _("Hyper Potion"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_MAX_POTION] =
    {
        .outputItem = ITEM_MAX_POTION,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sMaxPotionIngredients,
        .recipeName = _("Max Potion"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_FULL_RESTORE] =
    {
        .outputItem = ITEM_FULL_RESTORE,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sFullRestoreIngredients,
        .recipeName = _("Full Restore"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_REVIVE] =
    {
        .outputItem = ITEM_REVIVE,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sReviveIngredients,
        .recipeName = _("Revive"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_MAX_REVIVE] =
    {
        .outputItem = ITEM_MAX_REVIVE,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sMaxReviveIngredients,
        .recipeName = _("Max Revive"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_REMEDY] =
    {
        .outputItem = ITEM_REMEDY,
        .outputQuantity = 1,
        .ingredientCount = 1,
        .numDifferentIngredients = 1,
        .ingredients = sRemedyIngredients,
        .recipeName = _("Remedy"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_FINE_REMEDY] =
    {
        .outputItem = ITEM_FINE_REMEDY,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sFineRemedyIngredients,
        .recipeName = _("Fine Remedy"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    [RECIPE_SUPERB_REMEDY] =
    {
        .outputItem = ITEM_SUPERB_REMEDY,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sSuperbRemedyIngredients,
        .recipeName = _("Superb Remedy"),
        .category = RECIPE_CATEGORY_MEDICINE,
        .isDiscoverable = TRUE,
    },
    // Restoration
    [RECIPE_ANTIDOTE] =
    {
        .outputItem = ITEM_ANTIDOTE,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sAntidoteIngredients,
        .recipeName = _("Anitdote"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_BURN_HEAL] =
    {
        .outputItem = ITEM_BURN_HEAL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sBurnHealIngredients,
        .recipeName = _("Burn Heal"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_ICE_HEAL] =
    {
        .outputItem = ITEM_ICE_HEAL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sIceHealIngredients,
        .recipeName = _("Ice Heal"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_PARALYZE_HEAL] =
    {
        .outputItem = ITEM_PARALYZE_HEAL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sParalyzeHealIngredients,
        .recipeName = _("Paralyze Heal"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_AWAKENING] =
    {
        .outputItem = ITEM_AWAKENING,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sAwakeningIngredients,
        .recipeName = _("Awakening"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_FULL_HEAL] =
    {
        .outputItem = ITEM_FULL_HEAL,
        .outputQuantity = 1,
        .ingredientCount = 4,
        .numDifferentIngredients = 4,
        .ingredients = sFullHealIngredients,
        .recipeName = _("Full Heal"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_MAX_ETHER] =
    {
        .outputItem = ITEM_MAX_ETHER,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sMaxEtherIngredients,
        .recipeName = _("Max Ether"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    [RECIPE_MAX_ELIXER] =
    {
        .outputItem = ITEM_MAX_ELIXIR,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sMaxElixerIngredients,
        .recipeName = _("Max Elixer"),
        .category = RECIPE_CATEGORY_RESTORATION,
        .isDiscoverable = TRUE,
    },
    // Utility
    [RECIPE_AUX_POWER] =
    {
        .outputItem = ITEM_AUX_POWER,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sAuxPowerIngredients,
        .recipeName = _("Aux Power"),
        .category = RECIPE_CATEGORY_UTILITY,
        .isDiscoverable = TRUE,
    },
    [RECIPE_AUX_GUARD] =
    {
        .outputItem = ITEM_AUX_GUARD,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sAuxGuardIngredients,
        .recipeName = _("Aux Guard"),
        .category = RECIPE_CATEGORY_UTILITY,
        .isDiscoverable = TRUE,
    },
    [RECIPE_AUX_POWERGUARD] =
    {
        .outputItem = ITEM_AUX_POWERGUARD,
        .outputQuantity = 1,
        .ingredientCount = 3,
        .numDifferentIngredients = 3,
        .ingredients = sAuxPowerGuardIngredients,
        .recipeName = _("Aux Powerguard"),
        .category = RECIPE_CATEGORY_UTILITY,
        .isDiscoverable = TRUE,
    },
    [RECIPE_AUX_EVASION] =
    {
        .outputItem = ITEM_AUX_EVASION,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sAuxEvasionIngredients,
        .recipeName = _("Aux Evasion"),
        .category = RECIPE_CATEGORY_UTILITY,
        .isDiscoverable = TRUE,
    },
    [RECIPE_DIRE_HIT] =
    {
        .outputItem = ITEM_DIRE_HIT,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sDireHitIngredients,
        .recipeName = _("Dire Hit"),
        .category = RECIPE_CATEGORY_UTILITY,
        .isDiscoverable = TRUE,
    },
    // Pokéballs
    [RECIPE_PREMIER_BALL] =
    {
        .outputItem = ITEM_PREMIER_BALL,
        .outputQuantity = 1,
        .ingredientCount = 3,
        .numDifferentIngredients = 3,
        .ingredients = sPremierballIngredients,
        .recipeName = _("Premier Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_HEAVY_BALL] =
    {
        .outputItem = ITEM_HEAVY_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sHeavyballIngredients,
        .recipeName = _("Heavy Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_LURE_BALL] =
    {
        .outputItem = ITEM_LURE_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sLureballIngredients,
        .recipeName = _("Lure Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_FRIEND_BALL] =
    {
        .outputItem = ITEM_FRIEND_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sFriendballIngredients,
        .recipeName = _("Friend Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_LOVE_BALL] =
    {
        .outputItem = ITEM_LOVE_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sLoveballIngredients,
        .recipeName = _("Love Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_LEVEL_BALL] =
    {
        .outputItem = ITEM_LEVEL_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sLevelballIngredients,
        .recipeName = _("Level Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_FAST_BALL] =
    {
        .outputItem = ITEM_FAST_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sFastballIngredients,
        .recipeName = _("Fast Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    [RECIPE_MOON_BALL] =
    {
        .outputItem = ITEM_MOON_BALL,
        .outputQuantity = 1,
        .ingredientCount = 2,
        .numDifferentIngredients = 2,
        .ingredients = sMoonballIngredients,
        .recipeName = _("Moon Ball"),
        .category = RECIPE_CATEGORY_POKEBALLS,
        .isDiscoverable = TRUE,
    },
    // Misc
    [RECIPE_STAR_PIECE] =
    {
        .outputItem = ITEM_STAR_PIECE,
        .outputQuantity = 2,
        .ingredientCount = 5,
        .numDifferentIngredients = 5,
        .ingredients = sStarPieceIngredients,
        .recipeName = _("Star Piece"),
        .category = RECIPE_CATEGORY_MISC,
        .isDiscoverable = TRUE,
    },
    [RECIPE_RARE_CANDY] =
    {
        .outputItem = ITEM_RARE_CANDY,
        .outputQuantity = 2,
        .ingredientCount = 4,
        .numDifferentIngredients = 4,
        .ingredients = sRareCandyIngredients,
        .recipeName = _("Rare Candy"),
        .category = RECIPE_CATEGORY_MISC,
        .isDiscoverable = TRUE,
    },
    [RECIPE_DYNAMAX_CANDY] =
    {
        .outputItem = ITEM_DYNAMAX_CANDY,
        .outputQuantity = 2,
        .ingredientCount = 3,
        .numDifferentIngredients = 3,
        .ingredients = sDynamaxCandyIngredients,
        .recipeName = _("Dynamax Candy"),
        .category = RECIPE_CATEGORY_MISC,
        .isDiscoverable = TRUE,
    },
};

const u8 sItemIngredientSettings[ITEMS_COUNT] =
{
    //  Add ingredients here with all the flags that they should have

    // Plants
    [ITEM_ASPEAR_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_BUGWORT] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_CHERI_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_CHESTO_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_DIRESHROOM] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_DOPPEL_BONNETS] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_IRON_BARKTONGUE] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_KING_LEAF] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_LEPPA_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_MAX_MUSHROOMS] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_MEDICINAL_LEEK] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_ORAN_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_PECHA_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_PEPUP_PLANT] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_RAWST_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_REVIVAL_HERB] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_SITRUS_BERRY] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_SWORDCAP] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_VIVICHOKE] = 1u << INGREDIENT_CATEGORY_PLANT | ITEM_IS_CONSUMED_ON_ATTEMPT,

    // Fluids
    [ITEM_FULL_HEAL] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_HYPER_POTION] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_MAX_POTION] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_POTION] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_SUPER_POTION] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    
    // Misc
    [ITEM_BLACK_TUMBLESTONE] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_BLUE_SHARD] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_CANDY_TRUFFLE] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_EXP_CANDY_L] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_EXP_CANDY_M] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_EXP_CANDY_S] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_EXP_CANDY_XL] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_EXP_CANDY_XS] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_GREEN_SHARD] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_IRON_CHUNK] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_MAX_ETHER] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_MAX_HONEY] = 1u << INGREDIENT_CATEGORY_FLUID | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_RED_SHARD] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_REVIVE] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_SKY_TUMBLESTONE] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_STARDUST] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_TUMBLESTONE] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_YELLOW_SHARD] = 1u << INGREDIENT_CATEGORY_MISC | ITEM_IS_CONSUMED_ON_ATTEMPT,

    // Apricorns
    [ITEM_BLACK_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_BLUE_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_BROWN_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_GREEN_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_RED_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_PINK_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_WHITE_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
    [ITEM_YELLOW_APRICORN] = 1u << INGREDIENT_CATEGORY_APRICORN | ITEM_IS_CONSUMED_ON_ATTEMPT,
};
