#ifndef GUARD_CONSTANTS_EVEN_CRAFTING_CONSTANTS_H
#define GUARD_CONSTANTS_EVEN_CRAFTING_CONSTANTS_H

enum Recipes {
    // Medicine
    RECIPE_POTION,
    RECIPE_SUPER_POTION,
    RECIPE_HYPER_POTION,
    RECIPE_MAX_POTION,
    RECIPE_ANTIDOTE,
    RECIPE_AWAKENING,
    RECIPE_BURN_HEAL,
    RECIPE_ICE_HEAL,
    RECIPE_PARALYZE_HEAL,
    RECIPE_FULL_HEAL,
    RECIPE_FULL_RESTORE,
    RECIPE_REVIVE,
    RECIPE_MAX_REVIVE,
    // Utility
    RECIPE_POKE_DOLL,
    // Pokéballs
    RECIPE_PREMIER_BALL,
    RECIPE_HEAVY_BALL,
    RECIPE_LURE_BALL,
    RECIPE_LOVE_BALL,
    RECIPE_LEVEL_BALL,
    RECIPE_MOON_BALL,
    RECIPE_FRIEND_BALL,
    RECIPE_FAST_BALL,
    // Misc
    RECIPE_STAR_PIECE,

    // RECIPE_NONE must after all actual recipes
    RECIPE_NONE,
    ERROR_MISSING_INGREDIENTS,
    ERROR_RECIPE_REQUIRES_UNLOCK,
};

enum IngredientCategories {
    INGREDIENT_CATEGORY_APRICORN,
    INGREDIENT_CATEGORY_FLUID,
    INGREDIENT_CATEGORY_MISC,
    INGREDIENT_CATEGORY_PLANT,

    // Must be last
    NUM_INGREDIENT_CATEGORIES,
};

enum RecipeCategories {
    RECIPE_CATEGORY_MEDICINE,
    RECIPE_CATEGORY_MISC,
    RECIPE_CATEGORY_POKEBALLS,
    RECIPE_CATEGORY_UTILITY,

    // Must be last
    NUM_RECIPE_CATEGORIES,
};

enum EvenCraftingUiTemplates
{
    ECU_DEFAULT,
    // Must be last
    ECU_TEMPLATE_NUMBER,
};

#endif
