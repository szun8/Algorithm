select item_info.ITEM_ID, ITEM_NAME, RARITY
from item_info join item_tree on item_info.ITEM_ID = item_tree.ITEM_ID
where PARENT_ITEM_ID in 
    (select ITEM_ID from item_info where rarity = 'rare')
order by item_info.ITEM_ID desc