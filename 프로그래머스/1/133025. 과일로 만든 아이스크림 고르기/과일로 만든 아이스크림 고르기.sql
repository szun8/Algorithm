SELECT first_half.FLAVOR from first_half, icecream_info
where first_half.FLAVOR = icecream_info.FLAVOR and first_half.total_order >= 3000 and icecream_info.ingredient_type = 'fruit_based'
order by first_half.TOTAL_ORDER desc