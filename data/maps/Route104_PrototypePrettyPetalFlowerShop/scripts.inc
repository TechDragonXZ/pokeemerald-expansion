Route104_PrototypePrettyPetalFlowerShop_MapScripts::
	.byte 0

Route104_PrototypePrettyPetalFlowerShop_EventScript_ShopTeala::
	lock
	faceplayer
	battlepointmart Route104_PrototypePrettyPetalFlowerShop_Shop
	release
	end

Route104_PrototypePrettyPetalFlowerShop_EventScript_ShopBeauty::
	lock
	faceplayer
	coinmart Route104_PrototypePrettyPetalFlowerShop_Shop
	release
	end

Route104_PrototypePrettyPetalFlowerShop_EventScript_ShopWoman::
	lock
	faceplayer
	pokemart Route104_PrototypePrettyPetalFlowerShop_Shop
	release
	end

	.align 2
Route104_PrototypePrettyPetalFlowerShop_Shop:
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	pokemartlistend
