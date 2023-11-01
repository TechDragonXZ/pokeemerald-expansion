# About this branch
This branch adds 5 new pockets to the bag based on changes to it from later generations:
* Medicine (HP, PP and status recovery items)
* Power-Up (Evolution Items, Vitamins, Mints, Candies)
* Battle Items (X items, Pokédoll/FluffyTail and hold items with battle effects)
* Mega Stones
* Z-Crystals

The new order for the pockets is the following:
* Items
* Medicine
* Poké Balls
* Battle Items
* Berries
* Power-Up
* Mega Stones
* Z-Crystals
* TMs & HMs
* Key Items

However, it reuses the original pocket sprites.

# pokeemerald Expansion Base

## What is the pokeemerald Expansion Base?

This base aims to combine some of the features I'd like to my pokeemerald base to have for easy access and use.
You are currently on the master branch which should always be a working (at least compileable version of the base)

## What feature branches are included?

- **[RHH's Battle Engine Upgrade](../tree/battle_engine):** Upgrades the battle engine in pokeemerald to newer Generation games' standards. It also adds newer moves and abilities.
- **[RHH's Pokémon Expansion](../tree/pokemon_expansion):** Adds Pokémon from newer Generations and makes them available in the National Dex. It also updates base stats and other Pokémon info.
- **[RHH's Item Expansion](../tree/item_expansion):** Adds items from newer Generations and also updates item effects for field use. (Removed TM51 - TM100)
- **[TheXaman's PokedexPlus with a HGSS style](https://www.pokecommunity.com/showthread.php?t=441996): had to omit displaying of Tutor Moves** 
- **[ghoulslash's DexNav & Detector Mode](https://www.pokecommunity.com/showthread.php?t=440571):**
- **[Some of ghoulslash's free_saveblock](https://www.pokecommunity.com/showthread.php?p=10168472#post10168472):** Namely FREE_UNION_ROOM_CHAT, FREE_LINK_BATTLE_RECORDS, FREE_RECORD_MIXING_HALL_RECORDS and APPRENTICE_COUNT set to 1 instead of 4 as well as MAIL_COUNT set to (PARTY_SIZE) instead of (10 + PARTY_SIZE)
- **[Prof. Leon Dias' Fully Decapitalized Pokeemerald](https://www.pokecommunity.com/showthread.php?t=451448)**
- **[Fixes and content from the pret tutorials](https://github.com/pret/pokeemerald/wiki/Tutorials):** Indoor running, BW Repel System, Trainer Classed Pokeballs, Map dependent Trainer Battle Music
- **[Content from Pokecommunity Simple Modifications Directory Content](https://www.pokecommunity.com/showthread.php?t=416647):** Setting EVs and Abilities for trainer battles, Nature Coloring and IV/EV Stat screens 

## Pokecommunity Simple Modifications Directory Content
- [Soft Level Cap - PokemonCrazy](https://www.pokecommunity.com/showthread.php?t=435445)
- Set a Trainer's Pokémon's [EVs - lightbox87](https://www.pokecommunity.com/showpost.php?p=10135792), [abilities - Diego Mertens](https://www.pokecommunity.com/showpost.php?p=10127338) and nature
- [Nature Color - DizzyEgg](https://www.pokecommunity.com/showpost.php?p=10024409)
- [Showing IVs/EVs in Summary Screen - PokemonCrazy](https://www.pokecommunity.com/showpost.php?p=10161688) using L, R and Start
- [Item field effect functions to increase/decrease Individual Values - Lunos](https://www.pokecommunity.com/showpost.php?p=10469674) Vitamins affect IVs
- [Restoring the Shred Split Battle Transition - Lunos](https://www.pokecommunity.com/showpost.php?p=10449556)
- [Poisonpoint no Overworld Poison Damage - Lunos](https://www.pokecommunity.com/showpost.php?p=10349195) 
- "Move Pokémon" as first PSS option
- [Improving the Pace of Battles - Mkol103](https://www.pokecommunity.com/showpost.php?p=10266925)
- [Wrapping Summary Screen - Zeturic](https://www.pokecommunity.com/showpost.php?p=10060875)
- [Move Item - Zeturic](https://www.pokecommunity.com/showpost.php?p=10120157)
- [DPPt Bike (with L) - Lunos](https://www.pokecommunity.com/showpost.php?p=10217718)
- [Faster Surfing - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10137446)
- [Berry Trees No Longer Disappear - Buffel Saft](https://www.pokecommunity.com/showpost.php?p=10142996&postcount=63)
- [Remove the need to water berries on rainy Routes - Buffel Saft](https://www.pokecommunity.com/showpost.php?p=10349397&postcount=258)
- [Item Descriptions On First Obtain - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10126502)
- [Custom Battle Music Via Scripting - Anon822](https://www.pokecommunity.com/showpost.php?p=10341282)
- [Power item and Destiny Knot breeding - DarkDown](https://www.pokecommunity.com/showpost.php?p=10488226)

## Pret Tutorial Content

### Fixes to vanilla code:
- Uncommented bugfixes in config.h
- [Surf Dismount Ground Effects - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10184839)
- [Fix Snow Weather - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10182047)
- Seeding the RNG properly on startup
- Keep the Camera from Making Waves
- Not showing dex entries until getting the Pokédex
- Improving the WaitForVBlank function
- [Better Reflection System - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10473906)

### Removing content:
- Update obedience levels to current standards
- Disabling Union Room check when entering Pokémon Centers

### Features from other generations
- [Remove the extra save confirmation - Hiroshi Sotomura](https://www.pokecommunity.com/showpost.php?p=10211835)
- Allow running indoors
- [Trainer Class-Based Poké Balls - Buffel Saft](https://www.pokecommunity.com/showpost.php?p=10038105)
- Prompt for reusing Repels
- [LGPE-Style Bonus Premier Balls - Buffel Saft](https://www.pokecommunity.com/showpost.php?p=10178662)
- Make the keyboard auto-switch to lowercase after the first character
- [Pokemart Items by Badge Count - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10172995&postcount=96)

### pokeemerald Miscellaneous
- [Disable Bag Use in Battle - ghoulslash](https://www.pokecommunity.com/showpost.php?p=10184292&postcount=122)
- Speedy Pokecenter Healing
- Battle music changes depending on the map the player is in
- Extra save space with two lines of code
- Enable the Reset RTC Feature
## What is the pokeemerald Expansion?

The pokeemerald Expansion is a feature branch meant to be integrated into existing Pokémon Emerald hacks based off pret's [pokeemerald](https://github.com/pret/pokeemerald) decompilation project. This is ***NOT*** a standalone romhack, and as such, most features will be unavailable and/or unbalanced if played as is.

## What features are included?
- Configuration files that allows you to choose generation-specific behaviors. Full contents here:
    - [Battle configurations](/include/config/battle.h)
    - [Pokémon configurations](/include/config/pokemon.h)
    - [Item configurations](/include/config/item.h)
    - [Overworld configurations](/include/config/overworld.h)
    - [Debug configurations](/include/config/debug.h)
- Upgraded battle engine.
    - Gen5+ damage calculation.
    - 2v2 Wild battles support.
    - 1v2/2v1 battles support.
    - Fairy Type (configurable).
    - Physical/Special/Status Category Split (configurable).
    - New moves and abilities up to Scarlet and Violet.
        - Custom Contest data up to SwSh, newer moves are WIP. ([source](https://pokemonurpg.com/info/contests/rse-move-list/))
    - [Form change tables](/src/data/pokemon/form_change_tables.h) that allow customizing most form changes.
    - Mega Evolution, Primal Reversion and Ultra Burst.
    - Z-Moves
        - Gen 8+ damaging moves are given power extrapolated from Gen 7.
        - Gen 8+ status moves have no additional effects, like Healing Wish.
    - Initial battle parameters
        - Queueing stat boosts (aka, Totem Boosts)
        - Setting Terrains.
    - Mid-turn speed recalculation.
    - Quick Poké Ball selection in Wild Battles
        - Press `R` to use last selected Poké Ball.
        - Hold `R` to change selection with the D-Pad.
    - Faster battle intro
        - Message and animation/cry happens at the same time.
    - Faster HP drain.
    - Battle Debug menu.
        - Accessed by pressing `Select` on the "Fight/Bag/Pokémon/Run" menu.
    - Option to use AI flags in wild Pokémon battles.
    - FRLG/Gen4+ whiteout money calculation.
    - Configurable experience settings
        - Experience on catch.
        - Splitting experience.
        - Trainer experience.
        - Scaled experience.
        - Unevolved experience boost.
    - Frostbite.
        - Doesn't replace freezing unless a config is enabled, so you can mix and match.
    - Critical capture.
    - Removed badge boosts (configurable).
    - Recalculating stats at the end of every battle.
    - Level 100 Pokémon can earn EVs.
    - Inverse battle support.
    - TONS of other features listed [here](/include/config/battle.h).
- Full Trainer customization
    - Nickname, EVs, IVs, moves, ability, ball, friendship, nature, gender, shininess.
    - Custom tag battle support (teaming up an NPC in a double battle).
    - Sliding trainer messages.
    - Upgraded Trainer AI
        - Considers newer move effects.
        - New flag options to let you customize the intelligence of your trainers.
        - Faster calculations.
    - Specify Poké Balls by Trainer class.
- Pokémon Species from Generations 1-8.
    - Option to disable unwanted generations.
    - Updated sprites to DS style.
    - Updated stats, types, abilities and egg groups (configurable).
    - Updated Hoenn's Regional Dex to match ORAS'.
    - Updated National Dex incorporating the new species.
    - Sprite and animation visualizer.
        - Accesible by pressing `Select` on a Pokémon's Summary screen.
    - Gen4+ evolution methods, with some changes:
        - Mossy Rock, Icy Rock and Magnetic Field locations match ORAS'.
            - Leaf, Ice and Thunder Stones may also be used.
        - Inkay just needs level 30 to evolve.
            - You can't physically have both the RTC and gyroscope, so we skip this requirement.
        - Sylveon uses Gen8+'s evolution method (friendship + Fairy Move).
        - Option to use hold evolution items directly like stones.
    - Hidden Abilities.
        - Available via Ability Patch.
        - Compatible with Ghoul's DexNav branch.
    - All gender differences.
        - Different icons for female Hippopotas and Hippowdon
    - 3 Perfect IVs on Legendaries, Mythicals and Ultra Beasts
- Breeding
    - Incense Baby Pokémon now happen automatically (configurable).
    - Level 1 eggs.
    - Poké Ball inheriting.
    - Egg Move Transfer, including Mirror Herb.
    - Nature inheriting 100% of the time with Everstone
    - Gen6+ Ability inheriting.
- Items from newer Generations. Full list [here](/include/constants/items.h).
    - ***Gen 6+ Exp. Share*** (configurable)
    - Existing item data but missing effects:
        - Mints
        - Dynamax Candy
        - Mulches
        - Rotom Catalog
        - DNA Splicers
        - Zygarde Cube
        - N Solarizer/Lunarizer
        - Reins of Unity
        - Dynamax Band
        - Gimmighoul Coin
        - Booster Energy
        - Tera Shards
        - Tera Orb
- Feature branches incorporated:
    - [RHH intro credits](https://github.com/Xhyzi/pokeemerald/tree/rhh-intro-credits) by Xhyzi.
        - A small signature from all of us to show the collective effort in the project :)
    - [Overworld debug]() by TheXaman
        - Accesible by pressing `R + Start` in the overworld by default.
        - **Additional features**:
            - *Clear Boxes*: cleans every Pokémon from the Boxes.
            - *Hatch an Egg*: lets you choose an Egg in your party and immediatly hatch it.
- Other features
    - Pressing B while holding a Pokémon drops them like in modern games (configurable).
    - Running indoors (configurable).
    - Configurable overworld poison damage.
    - Configurable flags for disabling Wild encounters and Trainer battles.
    - Configurable flags for forcing or disabling Shinies.
    - Reusable TM (configurable).
    - B2W2+ Repel system that also supports LGPE's Lures
    - Gen6+'s EV cap.
    - All bugfixes from pret included.
    - Fixed overworld snow effect.

There are some mechanics, moves and abilities that are missing and being developed. Check [the project's milestones](https://github.com/rh-hideout/pokeemerald-expansion/milestones) to see which ones.


### [Documentation on features can be found here](https://github.com/rh-hideout/pokeemerald-expansion/wiki)

## If I already have a project based on regular pokeemerald, can I use the pokeemerald Expansion
Yes! Keep in mind that we keep up with pret's documentation of pokeemerald, which means that if your project a bit old, you might get merge conflicts that you need to solve manually.
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH master`.

With this, you'll get the latest version of the Expansion, plus a couple of bugfixes that haven't been released into the next patch version :)

## **How do I update my version of the pokeemerald Expansion?**
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH expansion/1.6.0`.

### Please consider crediting the entire [list of contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) in your project, as they have all worked hard to develop this project :)

## There's a bug in the project. How do I let you guys know?
Please submit any issues with the project [here](https://github.com/rh-hideout/pokeemerald-expansion/issues). Make sure that the issue wasn't reported by someone else by searching using the filters.

## Can I contribute even if I'm not a member of ROM Hacking Hideout?

Yes! Contributions are welcome via Pull Requests and they will be reviewed by maintainers. Don't feel discouraged if we take a bit to review your PR, we'll get to it.

## Who maintains the project?

The project was originally started by DizzyEgg alongside other contributors.

The project has now gotten larger and DizzyEgg is now maintaining the project as part of the ROM Hacking Hideout community. Some members of this community are taking on larger roles to help maintain the project.

## What is ROM Hacking Hideout?

A Discord-based ROM hacking community that has many members who hack using the disassembly and decompilation projects for Pokémon. Quite a few contributors to the original feature branches by DizzyEgg were members of ROM Hacking Hideout. You can call it RHH for short!

[Click here to join the RHH Discord Server!](https://discord.gg/6CzjAG6GZk)
