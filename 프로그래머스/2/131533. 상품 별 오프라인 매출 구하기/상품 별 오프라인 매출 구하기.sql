-- 코드를 입력하세요
SELECT PRODUCT_CODE, sum(sales_amount) *PRICE as SALES
from product natural join offline_sale
group by PRODUCT_CODE
order by SALES desc, PRODUCT_CODE
